//PIC16F877 Nokia 3310 LCD HTC
#define _XTAL_FREQ 4000000

#include <xc.h>
#include "hd44780.h"

// ext reset, no code protect, no watchdog, int RC clock
__CONFIG(MCLRE_ON & CP_OFF & WDTE_OFF & FOSC_INTRC_NOCLKOUT & LVP_OFF);

//Current limit
#define MAX_CURRENT     3.0
//Relay port
#define RELAY   PORTCbits.RC0
//Reset button port
#define RESET   PORTBbits.RB0
//Cycles between LCD updates
#define LCD_CYCLES      50

//If < 1, we are sampling the temperature
unsigned int    Temp_sample = 0;
unsigned char   Temp_bar[17];

//Init lcd ports
void lcd_port_init(void)
{
    //LCD data lines are ouputs
    TRISD = 0;
    PORTD = 0;

    //LCD control lines are outputs
    TRISE = 0;
    PORTE = 0;
}

//Init ADC
void ADC_init(void)
{
    //AN0-AN5 are inputs
    TRISA = 0b00111111;

    // FOSC/8
    ADCON0bits.ADCS = 1;
    //Right justified
    ADCON1bits.ADFM = 1;
    //+VRef = 5V supply
    ADCON1bits.VCFG0 = 0;
    //-VRef = GND
    ADCON1bits.VCFG1 = 0;

    //AN0-AN5 are analog
    ANSEL = 0b00111111;
}

//Init PSU control relay port
void Relay_init(void)
{
    //RC0 is an ouput
    TRISCbits.TRISC0 = 0;
    //Turn off ouput
    RELAY = 0;
}

//Init reset button port
void Reset_init(void)
{
    //Input RB0
    TRISBbits.TRISB0 = 1;
    //Digital
    ANSELH = 0b000000;
    //No weak pull-up
    WPUBbits.WPUB0 = 0;
}

void Temp_init(void)
{
    //RB2 (FAN) is output
    TRISBbits.TRISB2 = 0;
    //Clear temperature bar
    for (unsigned char i = 0; i < 16; i++)
    {
        Temp_bar[i] = ' ';
    }
    Temp_bar[16] = '\0';
}

//Take a sample, the channel must be selected before calling this
unsigned int ADC_sample(void)
{
    //Waky waky.
    ADCON0bits.ADON = 1;
    __delay_ms(1);
    // Go go.
    ADCON0bits.GO = 1;
    while (ADCON0bits.GO)
    {
    }
    return (((unsigned int) ADRESH << 8) + ADRESL);
}

//Get currentr limit pot value
unsigned int get_limit(void)
{
    //Use channel AN0
    ADCON0bits.CHS = 0;
    return (ADC_sample());
}

//Get positive voltage output
unsigned int get_V1(void)
{
    //Use channel AN2
    ADCON0bits.CHS = 2;
    return (ADC_sample());
}

//Get negative voltage output
unsigned int get_V2(void)
{
    //Use channel AN3
    ADCON0bits.CHS = 2;
    return(ADC_sample());
}

//Get current output
unsigned int get_A(void)
{
    //Use channel AN1
    ADCON0bits.CHS = 1;
    return(ADC_sample());
}

//Convert a float in the range 00.00 to 99.99 to a string
void convert_to_ascii(float value, char *temp)
{
    static const float subtractors[] = {10, 1, 0.1, 0.01};
    unsigned char i;

    if (value > 99.99)
    {
        //Overload
        temp[0] = 'o';
        temp[1] = 'o';
        temp[2] = '.';
        temp[3] = 'o';
        temp[4] = 'o';
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            unsigned char n = 0;
            while (value >= subtractors[i])
            {
                n++;
                value -= subtractors[i];
            }
            temp[2] = '.';
            if (subtractors[i] < 1)
            {
                temp[i + 1] = n + '0';
            }
            else
            {
                temp[i] = n + '0';
            }
        }
    }
}

void update_temp(void)
{
    if (Temp_sample == 0)
    {
        Temp_sample = 1;
        //PORTBbits.RB1 = 0;
        PORTBbits.RB2 = 0;
        //RB1 input
        TRISBbits.TRISB1 = 1;
        //PORTBbits.RB1 = 0;
    }
    else
    {
        Temp_sample++;
        //Still charged?
        if (!PORTBbits.RB1)
        {
            //RB 1 output
            TRISBbits.TRISB1 = 0;
            //Charge the capacitor
            PORTBbits.RB1 = 1;
            //FAN on
            PORTBbits.RB2 = 1;
            for (unsigned char i = (Temp_sample / 4); i > 0; i--)
            {
                Temp_bar[16 - i] = '-';
            }
            Temp_sample = 0;
        }
    }
}

//Wait for reset press
void wait_reset(void)
{
    while (RESET)
    {
    }
}

//Update the lce display
void lcd_update(float v1, float v2, float a, float limit)
{
    char limit_str[] = {'0', '0', '.', '0', '0', '\0'};
    char v1_str[] = {'0', '0', '.', '0', '0', '\0'};
    char v2_str[] = {'0', '0', '.', '0', '0', '\0'};
    char a_str[] = {'0', '0', '.', '0', '0', '\0'};


    //Convert values to strings
    convert_to_ascii(limit, limit_str);
    convert_to_ascii(v1, v1_str);
    convert_to_ascii(v2, v2_str);
    convert_to_ascii(a, a_str);

    lcd_address(LINE1);
    lcd_puts("+");
    lcd_puts(v1_str);
    lcd_puts("V ");
    lcd_char(218);
    lcd_puts("-");
    lcd_puts(v2_str);
    lcd_puts("V");

    lcd_puts(" ");
    lcd_puts(a_str);
    lcd_puts("A ");

    lcd_char(218);
    lcd_puts(" ");
    lcd_puts(limit_str);
    lcd_puts("A");

    lcd_address(LINE3);
    lcd_puts(Temp_bar);
    //Clear temperature bar
    for (unsigned char i = 0; i < 16; i++)
    {
        Temp_bar[i] = '*';
    }
    Temp_bar[16] = '\0';
}

void main()
{
    lcd_port_init();
    ADC_init();
    Relay_init();
    Reset_init();
    Temp_init();
    lcd_init();

    float limit = 0;
    float v1 = 0;
    float v2 = 0;
    float a = 0;


    unsigned char lcd_cnt = 0;

    while (1)
    {
        if (lcd_cnt == 0)
        {
            lcd_update(v1, v2, a, limit);
            update_temp();
        }
        lcd_cnt++;
        RELAY = 1;
        limit = (float) (get_limit()) * (0.010); // 0.003 about 3/1024
        v1 = (float) (get_V1()) * (0.048); // 0.003 about 3/1024
        v2 = (float) (get_V2()) * (0.048); // 0.003 about 3/1024
        a = (float) (get_A()) * (0.01); // 0.003 about 3/1024
        
        //check current limit
        if (a > limit)
        {
            RELAY = 0;
            lcd_update(v1, v2, a, limit);
            wait_reset();
        }

        update_temp();
        if (lcd_cnt == LCD_CYCLES)
        {
            lcd_cnt = 0;
            //lcd_clear();
        }
    }
}
