#define _XTAL_FREQ 4000000

#include <xc.h>
#include "hd44780.h"

void lcd_init()
{
    LCD_RS = 0;
    LCD_RW = 0;

    //Wait 20ms for good measure
    __delay_ms(20);

    lcd_command(CMD_FUNCSET | 0b00010000); //Set 8.bit mode
    __delay_ms(5);
    lcd_command(CMD_FUNCSET | 0b00010000); //Set 8.bit mode
    __delay_ms(1);
    lcd_command(CMD_FUNCSET | 0b00010000); //Set 8.bit mode

    lcd_command(CMD_FUNCSET | 0b00011000); //Set 8.bit mode, 2 lines, 5x7 font
    lcd_command(CMD_ONOFF); // Display off

    lcd_command(CMD_CLEAR); // Clear display
    lcd_command(CMD_EMODE | 0b00000010); // Increment cursor
    lcd_command(CMD_ONOFF | 0b00000100); // Display on, cursor, and blink off
    lcd_command(CMD_HOME); //Cursor home
}

void lcd_send(char data, unsigned char rs)
{
    LCD_RW = 0; //Write mode
    LCD_RS = rs; //Data or command
    LCD_PORT = data; //put the data to the port

    //Clock the signal into the controller
    LCD_EN = 1;
    __delay_us(10);
    LCD_EN = 0;
    //Clear needs longer processing time
    if (data == CMD_CLEAR)
    {
        __delay_ms(2);
    }
    __delay_us(100);
}

void lcd_address(const char address)
{
    lcd_command(CMD_DDRAM + address);
}

void lcd_puts(const char * s)
{
    while (*s != '\0')
    {
        lcd_char(*s++);
    }
}

void lcd_pos_clear(char position, char length)
{
    lcd_address(position);
    for (char i = 0; i < length; i++)
        lcd_char(' ');
}

void lcd_clear(void)
{
    lcd_command(CMD_CLEAR);
}