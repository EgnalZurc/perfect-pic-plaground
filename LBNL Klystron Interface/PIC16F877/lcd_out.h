// lcd_out.h
// header file for lcd_out.c
//
// copyright, Peter H. Anderson, Baltimore, MD, Dec, '00

void delay_10us(byte t);   // max of 255 * 10 us
void delay_ms(long t);   // delays t millisecs - max of 65,535 ms

void lcd_char(byte c);
void lcd_data_nibble(byte c);
void lcd_cmd_byte(byte c);
void lcd_cmd_nibble(byte c);

void lcd_shift_out(byte x);

void lcd_init(void);
void lcd_clr(void);
void lcd_clr_line(byte line);
void lcd_cursor_pos(byte line, byte pos);

void lcd_str(char *s);
void lcd_dec_byte(byte val, byte digits);
void lcd_hex_byte(byte val);
char num_to_char(byte val);