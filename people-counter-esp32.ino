const int ledRedPin = 23; 
const int ledGreenPin = 12;

const int ECHO_one =27;
const int TRIG_one =26;

const int ECHO_two =18;
const int TRIG_two =17;

const float VelocidadeSom_mpors = 340;
const float VelocidadeSom_mporus = 0.000340; 

float TimeEcho_one = 0;
float TimeEcho_two = 0;

int Pessoas = 0;


float CalculaDistancia(float tempo_us){
  return((tempo_us*VelocidadeSom_mporus)/2);
}

void DisparaPulsoUltrassonico(int TRIG){
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  
  pinMode(TRIG_one, OUTPUT);
  pinMode(ECHO_one, INPUT);

  pinMode(TRIG_two, OUTPUT);
  pinMode(ECHO_two, INPUT);

  pinMode(ledRedPin, OUTPUT);  
  pinMode(ledGreenPin, OUTPUT);
  
  delay(100);
}

void piscaLed(int led){
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
}

void loop() {
  
  DisparaPulsoUltrassonico(TRIG_one);
  TimeEcho_one = pulseIn(ECHO_one, HIGH);

  delayMicroseconds(50);

  DisparaPulsoUltrassonico(TRIG_two);
  TimeEcho_two = pulseIn(ECHO_two, HIGH);

  Serial.print("TimeEcho_one: ");
  Serial.println(TimeEcho_one);
  Serial.print("TimeEcho_two: ");
  Serial.println(TimeEcho_two);

  const float distancia_one = CalculaDistancia(TimeEcho_one);
  const float distancia_two = CalculaDistancia(TimeEcho_two);

  if(TimeEcho_one < TimeEcho_two){
    Pessoas++;
    Serial.println("Alguem entrou!");
    Serial.print("Numero de pessoas na sala: ");
    Serial.println(Pessoas);
    piscaLed(ledGreenPin);
    
  } else {
    Pessoas--;
    Serial.println("Alguem saiu!");
    Serial.print("Numero de pessoas na sala: ");
    Serial.println(Pessoas);
    piscaLed(ledRedPin);
  }  
}
