#include <xc.h>

#ifndef LCD_HD44780_H
#define	LCD_HD44780_H

//Commands
#define CMD_CLEAR   (0b00000001)
#define CMD_HOME    (0b00000011)
#define CMD_EMODE   (0b00000100)
#define CMD_ONOFF   (0b00001000)
#define CMD_SHIFT   (0b00010000)
#define CMD_FUNCSET (0b00100000)
#define CMD_CGRAM   (0b01000000)
#define CMD_DDRAM   (0b10000000)

#define LCD_PORT (PORTD)

//lcd control lines
#define LCD_EN (PORTEbits.RE0)
#define LCD_RW (PORTEbits.RE1)
#define LCD_RS (PORTEbits.RE2)

//Line offsets
#define LINE1   0
#define LINE2   16
#define LINE3   40
#define LINE4   56

void lcd_init();
void lcd_address(const char address);
void lcd_puts(const char * s);
void lcd_pos_clear(char position, char length);
void lcd_clear(void);

void lcd_send(char data, unsigned char rs);
#define lcd_command(command)    lcd_send(command, 0)
#define lcd_char(data)          lcd_send(data, 1)

#endif	/* LCD_HD44780_H */

