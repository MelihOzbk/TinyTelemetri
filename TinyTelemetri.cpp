// Creator: Melih ÖZÜBEK
// Last edit: 2021.07.02 18:00:00
// Title: TinyTelemetri
//
#define YukAviyonigi
#include <TinyTelemetri.h>
#ifdef Roket
void TinyTelemetri::MI2C(int no)
{
    Wire.begin(no);
}
void TinyTelemetri::Lora(byte TXpin, byte RXpin, byte m0, byte m1, long baudrate)
{
    this->Txpin = TXpin;
    this->Rxpin = RXpin;
    this->m0 = m0;
    this->m1 = m1;
    pinMode(m0, OUTPUT);
    pinMode(m1, OUTPUT);
    digitalWrite(m0, LOW);
    digitalWrite(m1, LOW);
}

void TinyTelemetri::GPS(byte TXpin, byte RXpin, long baudrate)
{
    this->GpsTxpin = TXpin;
    this->GpsRxpin = RXpin;
    SoftwareSerial* GPS = new SoftwareSerial((uint8_t)this->GpsTxpin, (uint8_t)this->GpsRxpin);
}
void TinyTelemetri::baslat(int a){
switch (a)
{
case 1:
SoftwareSerial* Lora = new SoftwareSerial((uint8_t)this->Txpin, (uint8_t)this->Rxpin);
SoftwareSerial* GPS = new SoftwareSerial((uint8_t)this->GpsTxpin, (uint8_t)this->GpsRxpin);
break;
case 2:
SoftwareSerial* GPS = new SoftwareSerial((uint8_t)this->GpsTxpin, (uint8_t)this->GpsRxpin);
break;
case 3:
SoftwareSerial* Lora = new SoftwareSerial((uint8_t)this->Txpin, (uint8_t)this->Rxpin);
break;
}
}
#endif

#ifdef YukAviyonik
HardwareSerial Lora(1);
void TinyTelemetri::HLora(byte Txpin, byte Rxpin, byte m0, byte m1, long baudrate)
{
    this->Txpin = Txpin;
    this->Rxpin = Rxpin;
    this->m0 = m0;
    this->m1 = m1;
    this->loraBaudrate = baudrate;
    pinMode(m0, OUTPUT);
    pinMode(m1, OUTPUT);
    digitalWrite(m0, LOW);
    digitalWrite(m1, LOW);
}
HardwareSerial Gps(2);
void TinyTelemetri::GPS(byte TXpin, byte RXpin, long baudrate)
{
    this->GpsTxpin = TXpin;
    this->GpsRxpin = RXpin;
    this->gpsbaudrate = baudrate;
}
void TinyTelemetri::baslat(int a){
switch (a)
{
case 1:
Gps.begin(this->gpsbaudrate, SERIAL_8N1, this->GpsTxpin, this->GpsRxpin);
Lora.begin(this->loraBaudrate, SERIAL_8N1, this->Rxpin, this->Txpin);
break;
case 2:
Gps.begin(this->gpsbaudrate, SERIAL_8N1, this->GpsTxpin, this->GpsRxpin);
break;
case 3:
Lora.begin(this->loraBaudrate, SERIAL_8N1, this->Rxpin, this->Txpin);
break;
default:
break;
}
}
#endif

#ifdef GCS
void TinyTelemetri::Lora(byte TXpin, byte RXpin, byte m0, byte m1, long baudrate)
{
    this->Txpin = TXpin;
    this->Rxpin = RXpin;
    this->m0 = m0;
    this->m1 = m1;
    pinMode(m0, OUTPUT);
    pinMode(m1, OUTPUT);
    digitalWrite(m0, LOW);
    digitalWrite(m1, LOW);
}
void TinyTelemetri::baslat(int a){
SoftwareSerial* Lora = new SoftwareSerial((uint8_t)this->Txpin, (uint8_t)this->Rxpin);
}
void TinyTelemetri::
#endif