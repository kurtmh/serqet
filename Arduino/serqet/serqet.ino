/*
Serqet prototype code to be ported to STM32F205RGT6
*/

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

#define nHGB	A1
#define nHGA	A0
#define Vcntl	A2
//#define nPD
#define ADC_D0	2 //D2
#define ADC_D1	3 //D3
#define ADC_D2	4 //D4
#define ADC_D3	5 //D5
#define ADC_D4	6 //D6
#define ADC_D5	7 //D7
#define ADC_D6	8 //B0
#define ADC_D7	9 //B1

void setup(void);
void loop(void);
void print_ADC(void);

// ADC values
int ADC_bits [8]= {};

void setup()
{
	Serial.begin(57600);
	Serial.println("\n\nSerqet Prototype Demo\n");
	Serial.flush();

	// Pin modes
	pinMode(nHGA, OUTPUT);
	pinMode(nHGB, OUTPUT);
	pinMode(Vcntl, OUTPUT);
	pinMode(ADC_D0, INPUT);
	pinMode(ADC_D1, INPUT);
	pinMode(ADC_D2, INPUT);
	pinMode(ADC_D3, INPUT);
	pinMode(ADC_D4, INPUT);
	pinMode(ADC_D5, INPUT);
	pinMode(ADC_D6, INPUT);
	pinMode(ADC_D7, INPUT);

	// Safe default values (Voltage levels of Digital and Analog Output?)
	digitalWrite(Vcntl, LOW);

	// Set VGA default gain

	// Set ...


}

void print_ADC(){
	// Grab ADC Value, direct register access for speed?
	// Values from (0, 1023)
	for(int i=0; i<8; i++){
		ADC_bits[i] = digitalRead(ADC_D0+i);
	}
/*	ADC_bits[0] = digitalRead(ADC_D0);
	ADC_bits[1] = digitalRead(ADC_D1);
	ADC_bits[2] = digitalRead(ADC_D2);
	ADC_bits[3] = digitalRead(ADC_D3);
	ADC_bits[4] = digitalRead(ADC_D4);
	ADC_bits[5] = digitalRead(ADC_D5);
	ADC_bits[6] = digitalRead(ADC_D6);
	ADC_bits[7] = digitalRead(ADC_D7);*/

	for(int adcbit=0; adcbit<8; adcbit++){
		Serial.print(adcbit, DEC);
		Serial.print(": ");
		Serial.print(ADC_bits[adcbit], DEC);
		Serial.print("\n");	
	}
	Serial.flush();
}

void loop()
{
	print_ADC();

	delay(2000);
}
