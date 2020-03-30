# SatelitesDIY
Proyecto Satélites caseros para estudios medioambientales de Madrid. Desarrollándose en Medialab-Prado, Madrid.

Colaboradores/as: 

Damián René, Steve Woolsens, Tania Netsvetaylova, Manuel Patiño, Pablo Fernández Robledo, Alvaro Redondo.
Alumnado y profesorado (Felipe Yebes e Isabel Blázquez de Paz) del IES Gómez Moreno.
Alumnado del IES Cervantes.

https://www.medialab-prado.es/proyectos/satelites-diy

Dentro de este proyecto, se desarrollan actualmente varios prototipos:

- El alumnado del IES Gómez Moreno desarrolla un medidor de contaminación que geolocaliza la posición de medida y que tiene forma de botellín de bicicleta. 
- El alumnado del IES Cervantes desarrolla un medidor de la contaminación que muestra los datos en una pantalla LCD, es una caja hecha con corte láser y se llama Laika II.

El video del proceso de los primeros prototipos, LAIKA II y Botellín de bici, puede visitarse aquí: https://vimeo.com/379979688

- Como parte de la investigación, se están desarrollando en Medialab varios prototipos que se nombran como los dioses griegos del viento. Estos son:

  - NOTOS (Νότος), viento del sur: Este sistema mide partículas volátiles PM2.5, PM10 y compuestos orgánicos volátiles (VOC). Los geolocaliza y almacena en una tarjeta SD. https://github.com/silviatelo/NOTOS
  - AIR_BOREAS (Βορέας), viento del norte: Este sistema mide partículas volátiles, muestra sus valores en pantalla y los simplifica con luz de colores acorde a los límites recomentados por la OMS. Se instala en una maceta autorregante para calidad del aire en interiores. https://github.com/silviatelo/AIR_BOREAS

Estos scripts para Arduino son material de apoyo para el alumnado que desarrolla en sus aulas un sistema geolocalizado de medición del botellín:

GPS_LatLong.ino -  Este programa usa SoftwareSerial para comunicarse con el módulo GPS, a través de los pines 8 y 9.
  Utiliza la biblioteca TinyGPS++ para transformar las cadenas de texto NMEA del GPS en información
  comprensible.
  
GPS_serialport.ino - Se comunica con el módulo GPS y envía a través del puerto serie los datos brutos (sin transformar en datos comprensibles).

GPS_SDcard.ino - Almacena los datos de GPS en un archivo y lo guarda en la tarjeta uSD.
