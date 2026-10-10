/*
 * File:   keypad.c
 * Author: Dell
 *
 * Created on 30 September, 2026, 3:34 PM
 */


#include <xc.h>
#define RS RD0 // or #define RS PORTDbits.RD0
#define RW RD1
#define EN RD2
#define R1 RB0
#define R2 RB1
#define R3 RB2
#define R4 RB3
#define C1 RB5
#define C2 RB6
#define C3 RB7
#define _XTAL_FREQ 20000000

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


void lcd_data(unsigned char data ){
    PORTC = data; //pass the data to port 
    RS = 1; //make data to the data register 
    RW = 0; // writing data
    EN =1; // enable the clock of lcd
     __delay_ms(5);
    EN=0;//disable the clock of lcd
}

void lcd_command(unsigned char cmd){
    PORTC = cmd ;
    RS = 0; //make data to the instruction register
    RW = 0; //writing data
    EN =1; // enable the clock of lcd
     __delay_ms(5);
    EN=0;//disable the clock of lcd
}

//passing a string of data to the LCD
void lcd_string(const unsigned char *str , unsigned char num)
{
    for(int i =0;i<num;i++){
        lcd_data(str[i]);
    }
}
void lcd_initialise(){
    lcd_command(0x38); // used for setting the lcd in 16x2 
    lcd_command(0x06);// auto increment for lcd when current element is printing
    lcd_command(0x0c);//lcd on cursor off 
    lcd_command(0x01);//clear screen 
}


void keypad(){
    C1=1; C2=0; C3=0;
    if(R1==1){
        lcd_data('1');
        while(R1==1);
    }
    if(R2==1){
        lcd_data('4');
        while(R2==1);
    }
    if(R3==1){
        lcd_data('7');
        while(R3==1);
    }
    if(R4==1){
        lcd_data('*');
        while(R4==1);
    }
    
    
    C1=0; C2=1; C3=0;
    if(R1==1){
        lcd_data('2');
        while(R1==1);
    }
    if(R2==1){
        lcd_data('5');
        while(R2==1);
    }
    if(R3==1){
        lcd_data('8');
        while(R3==1);
    }
    if(R4==1){
        lcd_data('0');
        while(R4==1);
    }
    
    C1=0; C2=0; C3=1;
    if(R1==1){
        lcd_data('3');
        while(R1==1);
    }
    if(R2==1){
        lcd_data('6');
        while(R2==1);
    }
    if(R3==1){
        lcd_data('9');
        while(R3==1);
    }
    if(R4==1){
        lcd_data('#');
        while(R4==1);
    }
}

void main(void) {
    
    TRISC = 0x00; // output for data pins
    TRISD = 0x00; //output for RW, RS, EN
    TRISB = 0x0f; // input rows & output columns
    lcd_initialise();
    while(1){
        lcd_command(0x80);
        lcd_string("KEYPAD:",7);
        lcd_command(0xc0);
        while(1){
            keypad();
        }
        
    }
    
    return;
}