
#include <DHT.h>
#include <SD.h>

#define DHTPIN 7
#define DHTTYPE DHT22
DHT dhtobj(DHTPIN, DHTTYPE);

const int heaterPin = 8; 
const int fanPin = 9;    

void setup() {
  Serial.begin(9600);
  Serial.println("DHT, Heater, Fan Simulation started...");

  dhtobj.begin();
  pinMode(heaterPin, OUTPUT);
  pinMode(fanPin, OUTPUT);

//   sd card insertion
  if (SD.begin(4)) {
    Serial.println("SD card initialized");
  } else {
    Serial.println("SD card initialization failed");
    return;
  }

  logHeader(); 
}

void loop() {
  float temp = dhtobj.readTemperature();
  float humidity = dhtobj.readHumidity();

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("°C  Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  if (temp < 20.0) {
    digitalWrite(heaterPin, HIGH); 
    Serial.println("Heater is ON");
  } else {
    digitalWrite(heaterPin, LOW); 
    Serial.println("Heater is OFF");
  }

  if (humidity > 70.0) {
    digitalWrite(fanPin, HIGH); 
    Serial.println("Fan is ON");
  } else {
    digitalWrite(fanPin, LOW);
  }

  logDataToSDCard(temp, humidity, digitalRead(heaterPin), digitalRead(fanPin));

  delay(60000);
  Serial.println("Temperature, Humidity, Heater, Fan after 1 minute");
}

void logHeader() {
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.println("Time, Temperature (°C), Humidity (%), Heater Status, Fan Status");
    dataFile.close();
  } else {
    Serial.println("Error opening datalog.txt");
  }
}

void logDataToSDCard(float temp, float humidity, int heaterStatus, int fanStatus) {
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.print(millis());
    dataFile.print(", ");
    dataFile.print(temp);
    dataFile.print(", ");
    dataFile.print(humidity);
    dataFile.print(", ");
    dataFile.print(heaterStatus);
    dataFile.print(", ");
    dataFile.println(fanStatus);
    dataFile.close();
  } else {
    Serial.println("Error opening datalog.txt");
  }
}
