# Arduino Temperature and Humidity Monitoring

This Arduino project simulates a smart home scenario where temperature, humidity, a virtual heater, and a virtual fan are monitored and controlled. The project is designed to run on an ESP8266-based board with a DHT22 sensor.

## Features

- Temperature and humidity monitoring using a DHT22 sensor.
- Simulation of a virtual heater and fan based on temperature and humidity thresholds.
- Logging of data to the Serial monitor and an SD card.

## Prerequisites

- Arduino IDE or PlatformIO for VS Code installed.
- ESP8266 board support installed in your Arduino IDE or PlatformIO.

## Setup

1. Clone or download the project to your local machine.
2. Open the Arduino IDE or VS Code with PlatformIO extension.
3. Create a new folder for the project and copy the code into a new `.ino` file.
4. (Optional) Create a `platformio.ini` file if using PlatformIO.

## Wiring

- Connect the DHT22 sensor to the specified pin (DHTPIN) in the code.
- Connect the virtual heater and fan to the specified digital pins (heaterPin and fanPin).
- Ensure the SD card module is properly connected to your ESP8266.

## Running the Code

1. Connect your ESP8266 to your computer.
2. Upload the code to the ESP8266 using the Arduino IDE or PlatformIO.
3. Open the Serial monitor to view the output.

## Troubleshooting

- If you encounter issues with SD card initialization, check the wiring and ensure the SD card is properly inserted.
- Ensure that the SD card is formatted correctly (FAT16 or FAT32) and is not write-protected.
- Check the power supply to the SD card module for any voltage issues.



