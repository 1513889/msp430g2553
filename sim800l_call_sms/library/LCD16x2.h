/*
 * LCD16x2.h
 *
 *  Created on: 28-09-2017
 *      Author: KILLER
 */

#ifndef LCD16X2_H_
#define LCD16X2_H_

//#define USE_WAIT
#define lcd_delay 	500
//Set PIN DATA
#define DDRLCD 		P2DIR
#define PORTLCD 	P2OUT
#define PINLCD		P2IN
#define PRENLCD		P2REN
#define PSELLCD		P2SEL
#define PSEL2LCD	P2SEL2
#define SHIFT_DATA	4		// vi tri dich trai so voi vi tri goc 0xF0
//Set PIN RS
#define DDR_RS		P2DIR
#define PORT_RS		P2OUT
#define PIN_RS		P2IN
#define RS   		BIT5
//Set PIN E
#define DDR_E		P2DIR
#define PORT_E		P2OUT
#define PIN_E		P2IN
#define E    		BIT4

//set led
#define LED			BIT7
#define LED_DIR 	P1DIR
#define LED_OUT		P1OUT


//switch
#define SWITCH			BIT3
#define	PORT_VECTOR_SWITCH		PORT1_VECTOR

#define PSEL_SWITCH		P1SEL
#define PSEL2_SWITCH	P1SEL2
#define PDIR_SWITCH		P1DIR
#define PREN_SWITCH		P1REN
#define POUT_SWITCH		P1OUT
#define PIE_SWITCH		P1IE
#define PIES_SWITCH		P1IES
#define PIFG_SWITCH		P1IFG

/* Chon kieu hien thi tang/giam, shift hoac khong shift */
#define LCD_DEC_CUR_SHIFT_ON()	LCD_Command(0x05);
#define LCD_DEC_CUR_SHIFT_OFF()	LCD_Command(0x04);
#define LCD_INC_CUR_SHIFT_ON()	LCD_Command(0x07);
#define LCD_INC_CUR_SHIFT_OFF()	LCD_Command(0x06);	// khuyen khich su dung cach nay

/******************************************************************************\
*					Prototype (nguyen mau ham)    						       *
\******************************************************************************/

unsigned char dao_data(unsigned char data_in);
void config_LCD();
void LCD_Init_write(unsigned char b);
//Ham goi lenh vao LCD
void LCD_Command(unsigned char chr);
//Xoa LCD
void LCD_Clear();
//Dua con tro ve home
void LCD_Home();
//Hien thi ki tu
void LCD_Display(unsigned char chr);
/* Di chuyen con tro toi vi tri hang row, cot column */
void LCD_Goto(unsigned char row, unsigned char column);
/* Dich chuyen con tro sang trai(direct=0) hoac sang phai(direct=1) "step" vi tri */
void LCD_CursorShift(unsigned char direct, unsigned char step);
/* In ra man hinh xau ki tu str[] */
void LCD_PrintString(char *str);
/* In ra man hinh so nguyen n voi so cho hien thi bang length(chua ke vi tri cua dau) */
void LCD_PrintDecimal(long n, unsigned char length);
void LCD_PrintUnDecimal(long n, unsigned char length);
/* In ra man hinh so thuc x voi so cho hien thi = length, so chu so sau dau phay la coma */
void LCD_PrintFloat(float x, unsigned char length, unsigned char coma);


void config_switch_interup(void);
void config_LED(void);

#endif /* LCD16X2_H_ */
