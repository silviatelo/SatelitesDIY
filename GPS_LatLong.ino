/******************************************************************************
  Proyecto Satélites DIY - Medialab-Prado
  Basado en:
  https://github.com/sparkfun/GPS_Shield

  Este programa usa SoftwareSerial para comunicarse con el módulo GPS, a través de los pines 8 y 9.
  Utiliza la biblioteca TinyGPS++ para transformar las cadenas de texto NMEA del GPS en información
  comprensible.

  Una vez subido el código al Arduino, configura la velocidad a 9600 baudios. Te devolverá Latitud, Longitud, Altitud,
  Rumbo, Velocidad, Fecha, Hora en UTC+00:00 (Una hora menos que en Madrid), y el número de Satélites de los que recibe señal.

  Fuentes:
  TinyGPS++ Library  - https://github.com/mikalhart/TinyGPSPlus/releases
  SoftwareSerial Library

  GPS Logger Shield v2.0 - Asegurate de que el switch del GPS Logger, está en SW-UART.
  
******************************************************************************/

#include <TinyGPS++.h>
TinyGPSPlus tinyGPS; // Crea un objeto TinyGPSPlus

#define GPS_BAUD 9600

#include <SoftwareSerial.h>
#define ARDUINO_GPS_RX 9 // GPS TX, pin Arduino RX
#define ARDUINO_GPS_TX 8 // GPS RX, pin Arduino TX
SoftwareSerial ssGPS(ARDUINO_GPS_TX, ARDUINO_GPS_RX); // Crea SoftwareSerial

#define gpsPort ssGPS 
#define SerialMonitor Serial

void setup()
{
  //definimos el puerto serie a 9600 baudios (número de símbolos por segundo en un medio de transmisión digital)
  SerialMonitor.begin(9600);
  gpsPort.begin(GPS_BAUD);
}

void loop()
{
  printGPSInfo();  // print posición, altitud, velocidad, hora/fecha y satélites
  
  smartDelay(1000); // "Smart delay" busca datos cuando el Arduino está sin actividad 
}

void printGPSInfo()
{
  SerialMonitor.print("Lat: "); SerialMonitor.println(tinyGPS.location.lat(), 6);
  SerialMonitor.print("Long: "); SerialMonitor.println(tinyGPS.location.lng(), 6);
  SerialMonitor.print("Alt: "); SerialMonitor.println(tinyGPS.altitude.feet());
  SerialMonitor.print("Rumbo: "); SerialMonitor.println(tinyGPS.course.deg());
  SerialMonitor.print("Velocidad: "); SerialMonitor.println(tinyGPS.speed.mph());
  SerialMonitor.print("Fecha: "); printDate();
  SerialMonitor.print("Hora: "); printTime();
  SerialMonitor.print("Sats: "); SerialMonitor.println(tinyGPS.satellites.value());
  SerialMonitor.println();
}

// This custom version of delay() ensures that the tinyGPS object
// is being "fed". From the TinyGPS++ examples.
static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do
  {
    // If data has come in from the GPS module
    while (gpsPort.available())
      tinyGPS.encode(gpsPort.read()); // Send it to the encode function
    // tinyGPS.encode(char) continues to "load" the tinGPS object with new
    // data coming in from the GPS module. As full NMEA strings begin to come in
    // the tinyGPS library will be able to start parsing them for pertinent info
  } while (millis() - start < ms);
}

// printDate() formats the date into dd/mm/yy.
void printDate()
{
  SerialMonitor.print(tinyGPS.date.day());
  SerialMonitor.print("/");
  SerialMonitor.print(tinyGPS.date.month());
  SerialMonitor.print("/");
  SerialMonitor.println(tinyGPS.date.year());
}

// printTime() formats the time into "hh:mm:ss", and prints leading 0's
// where they're called for.
void printTime()
{
  SerialMonitor.print(tinyGPS.time.hour());
  SerialMonitor.print(":");
  if (tinyGPS.time.minute() < 10) SerialMonitor.print('0');
  SerialMonitor.print(tinyGPS.time.minute());
  SerialMonitor.print(":");
  if (tinyGPS.time.second() < 10) SerialMonitor.print('0');
  SerialMonitor.println(tinyGPS.time.second());
}
