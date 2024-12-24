#include <WiFi.h>
#include <DHT11.h>
#include "ThingSpeak.h"

DHT11 dht11(2); //Set this to whatever the pin number it is that is  connected to the Data pin of the sensor.

char* ssid = ""; //Replace with your Wifi's SSID
char* password = ""; //Replace with your Wifi's Password, another solution to this would be using a secret header file, but I wanted to  keep it light

WiFiClient client;

unsigned long my_channel_number = ; //From your thingspeak channel
const char* my_write_api_key = "";
unsigned long lastUpdate = 0;
const unsigned long updateInterval = 60000; // 1 minute

void setup() {
    Serial.begin(115200);
    dht11.setDelay(500);
    WiFi.mode(WIFI_STA);
    ThingSpeak.begin(client);
}

int temp_int;
int hum_int;

void loop() {
    if(WiFi.status() != WL_CONNECTED) {
        Serial.print("Attempting to connect");
        int timeout = 0;
        while(WiFi.status() != WL_CONNECTED && timeout < 20) {
            WiFi.begin(ssid, password);
            delay(5000);    
            timeout++;
        }
        if(timeout >= 20) {
            Serial.println("\nFailed to connect to WiFi");
            return;
        }
        Serial.println("\nConnected.");
    }

    if (millis() - lastUpdate >= updateInterval) {
        int result = dht11.readTemperatureHumidity(temp_int, hum_int);
        
        if(result != 0) {
            Serial.println("DHT11 reading error");
            return;
        }

        int x = ThingSpeak.writeField(my_channel_number, 1, temp_int, my_write_api_key);
        delay(15000); 
        int y = ThingSpeak.writeField(my_channel_number, 2, hum_int, my_write_api_key);
        
        if(x == 200) {
            Serial.println("Temperature uploaded");
        } else {
            Serial.println("Temperature upload unsuccessful");
        }
        
        if(y == 200) {
            Serial.println("Humidity uploaded");
        } else {
            Serial.println("Humidity upload unsuccessful");
        }
        
        lastUpdate = millis();
    }
}