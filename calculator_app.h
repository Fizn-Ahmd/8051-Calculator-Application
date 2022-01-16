#ifndef calculator_app
#define calculator_app

#include <reg51.h>

#define port0 0
#define port1 1
#define port2 2
#define port3 3

/* standard_definition */
typedef signed char s8;
typedef signed int s16;
typedef signed long int s32;
typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long int u32;

/* key_pad  */
sbit r0 = P2 ^ 0;
sbit r1 = P2 ^ 1;
sbit r2 = P2 ^ 2;
sbit r3 = P2 ^ 3;
sbit c0 = P2 ^ 4;
sbit c1 = P2 ^ 5;
sbit c2 = P2 ^ 6;
sbit c3 = P2 ^ 7;

/* lcd */
sbit rw = P3 ^ 6;
sbit en = P3 ^ 7;
sbit rs = P3 ^ 5;

sfr port = 0x80;

/* delay */
extern void delay_1s(s16);

/* lcd_drivers */
extern void lcd_init();
extern void lcd_cmd(u8);
extern void lcd_input(u8);
extern u8 read_lcd();

/* lcd_Operation */
extern void lcd_integer(u8);
extern void lcd_hex(u8);
extern u8 int_to_hex(u8);
extern u8 hex_to_int(u8);

/* calculator_application */
extern u8 key();

#endif
