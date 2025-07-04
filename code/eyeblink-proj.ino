#include <ESP8266WiFi.h>

const char* ssid = "YOUR_WIFI_DETAILS";
const char* password = "YOUR_WIFI_PASSWORD";

const char* host = "api.thingspeak.com";
String apiKey = "YOUR_WRITE_API";

#define EYE_SENSOR_PIN 5
#define BUZZER_PIN 4

int flag = 0;
unsigned long t1 = 0, t2=0;

void setup() 
{
  pinMode(EYE_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
}

void loop() 
{
  int sensorVal = digitalRead(EYE_SENSOR_PIN);
  t1 = millis();
  
    while(sensorVal == 1)
    {
      sensorVal = digitalRead(EYE_SENSOR_PIN);
      t2 = millis();
      if(t2-t1>2000)
      {
        digitalWrite(BUZZER_PIN, HIGH);
        sendToThingSpeak();
        delay(1000);
        digitalWrite(BUZZER_PIN, LOW);      
      }
    }
}


void sendToThingSpeak() 
{
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) 
  {
    Serial.println("Connection failed");
    return;
  }

  String url = "/update?api_key=" + apiKey + "&field1=Drowsiness%20Detected";
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  Serial.println("Data sent to ThingSpeak");
}



