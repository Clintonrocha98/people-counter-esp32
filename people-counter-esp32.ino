#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "";
const char* password = "";

const char* URL = "";

const int ledRedPin = 23; 
const int ledGreenPin = 12;

const int ECHO_one = 27;
const int TRIG_one = 26;

const int ECHO_two = 18;
const int TRIG_two = 17;

float TimeEcho_one = 0;
float TimeEcho_two = 0;

int numberOfPeople = 0;

void ultrasonicPulse(int pin){
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
}

void ledFlashing(int led){
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
}

void requestApi(String path) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(URL + path);
    http.addHeader("Content-Type", "application/json");
  
    int httpResponseCode = http.GET();

    String response = http.getString();
    Serial.println(httpResponseCode);
    Serial.println(response);

    http.end();
  }
}

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }

  Serial.println("Conectado ao WiFi");

  pinMode(TRIG_one, OUTPUT);
  pinMode(ECHO_one, INPUT);

  pinMode(TRIG_two, OUTPUT);
  pinMode(ECHO_two, INPUT);

  pinMode(ledRedPin, OUTPUT);  
  pinMode(ledGreenPin, OUTPUT);

  delay(100);
}


void loop() {
  ultrasonicPulse(TRIG_one);
  TimeEcho_one = pulseIn(ECHO_one, HIGH);

  delayMicroseconds(50);

  ultrasonicPulse(TRIG_two);
  TimeEcho_two = pulseIn(ECHO_two, HIGH);

  if(TimeEcho_one < TimeEcho_two){
    numberOfPeople++;

    requestApi("/increment");

    ledFlashing(ledGreenPin);
  } 
  if(TimeEcho_one > TimeEcho_two){
    numberOfPeople--;
    
    requestApi("/decrement");

    ledFlashing(ledRedPin);
  }  
}
