#include <ESP8266WiFi.h>

const char* ssid = "KOWALSKI1807";
const char* password = "qwerty123";

const char* host = "api.thingspeak.com";
String apiKey = "5RI5MMCRUQ5Y7CH4";

#define EYE_SENSOR_PIN 5
#define BUZZER_PIN 4
#define LED_PIN 2


void setup() 
{
  pinMode(EYE_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
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



