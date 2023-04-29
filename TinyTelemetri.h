#ifndef TinyTelemetri_h
#define TinyTelemetri_h
#endif

#ifdef RoketAviyonigi
#include <SoftwareSerial.h>
#include <Wire.h>
#define Roket
#endif

#ifdef YukAviyonigi
#include <HardwareSerial.h>
#define YukAviyonik
#endif

#ifdef YerIstasyonu
#define GCS
#endif


#include <Stream.h>
/*Geliştirme kartların dahili Serial'nı kütüphane içerisinde tanımlama, aktif edilen debug mesajlarının hangi serialda olacağını belirtiyor.*/
#define Debugger Serial

#if ARDUINO >= 100
#include "Arduino.h"
#endif

class TinyTelemetri
{
private:
byte Txpin;
byte Rxpin;
byte GpsRxpin;
byte GpsTxpin;
long gpsbaudrate;
long loraBaudrate;
byte m0;
byte m1;
    /* data */
public:
#ifdef Roket
void Lora(byte TXpin=9, byte RXpin=10,byte m0=2, byte m1=8, long baudrate=9600);
void GPS(byte TXpin=9, byte RXpin=10, long baudrate=9600);
void MI2C(int no);
#endif
#ifdef GCS
void Lora(byte TXpin=9, byte RXpin=10,byte m0,byte m1, long baudrate=9600);
void GPS(byte TXpin=9, byte RXpin=10, long baudrate=9600);
#endif
#ifdef YukAviyonigi
void HLora(byte Txpin=10, byte Rxpin=11 ,byte m0=3,byte m1=6, long baudrate=9600);
void GPS(byte TXpin=9, byte RXpin=10, long baudrate=9600);
#endif
void baslat(int a);
void MesajGonder(byte Low,byte High, byte Kanal ,void *data, int size);
void Oku(void *data, int size);
void gonderimbekletici(unsigned long timeout);
};

