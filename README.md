# ESP32-Weather-Station-With-Thingspeak-Integration

An ESP32-based weather station that reads temperature and humidity from a DHT11 sensor and uploads the data to ThingSpeak.

## Hardware Required
- ESP32 Development Board
- DHT11 Temperature & Humidity Sensor
- Jumper wires

## Setup
1. Connect the DHT11 sensor to your ESP32:
   - VCC to 3.3V
   - GND to GND
   - Data to GPIO2 (or change pin in code)

2. Install required libraries (Arduino IDE):
   - DHT11
   - ThingSpeak

3. Fill in your credentials in the code:
   - WiFi SSID and password
   - ThingSpeak channel number
   - ThingSpeak write API key

## Features
- Reads temperature and humidity every minute
- Automatic WiFi reconnection
- Non-blocking code using millis()
