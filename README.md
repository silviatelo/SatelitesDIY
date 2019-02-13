# SatelitesDIY
Proyecto Satélites caseros para estudios medioambientales de Madrid. Desarrollándose en Medialab-Prado, Madrid.

GPS_LatLong.ino -  Este programa usa SoftwareSerial para comunicarse con el módulo GPS, a través de los pines 8 y 9.
  Utiliza la biblioteca TinyGPS++ para transformar las cadenas de texto NMEA del GPS en información
  comprensible.
  
GPS_serialport.ino - Se comunica con el módulo GPS y envía a través del puerto serie los datos brutos (sin transformar en datos comprensibles).

GPS_SDcard.ino - Almacena los datos de GPS en un archivo y lo guarda en la tarjeta uSD.
