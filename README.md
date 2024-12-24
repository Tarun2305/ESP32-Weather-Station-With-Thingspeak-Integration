# ESP32 Weather Station With Thingspeak Integration
A weather monitoring station using ESP32 and DHT11 sensor that uploads temperature and humidity data to ThingSpeak.

## Components Used
- ESP32 Development Board
- DHT11 Temperature & Humidity Sensor
- Jumper Wires

## Setup
1. Install required libraries:
   - DHT11
   - ThingSpeak
   - WiFi
2. Configure your WiFi credentials
3. Set up a free ThingSpeak account and create a channel
4. Update the code with your ThingSpeak channel details

## Configuration
Before uploading the code, update these variables:
- WiFi SSID and password
- ThingSpeak channel number
- ThingSpeak API key

## Features
- Reads temperature and humidity every minute (can be changed, of course)
- Automatically reconnects to WiFi if connection is lost
- Non-blocking code using millis() for timing
As a side note, there is a 15 second delay between the upload of the temperature and the humidity, this is because ThingSpeak requires a minimum of 15 seconds between entries.
