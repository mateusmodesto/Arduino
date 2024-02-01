int pino_trigger = 12;
int pino_echo = 11;
int distancia = 0;
int tempo = 0;
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(pino_trigger, OUTPUT);
  pinMode(pino_echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  //Sensor:
  digitalWrite(pino_trigger, LOW);
  digitalWrite(pino_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pino_trigger, LOW);
  tempo = pulseIn(pino_echo, HIGH);
  distancia = int(tempo * 0.0175);
  Serial.println(distancia);
  //Leds:

  if (distancia >= 25){
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  }
  else{
    if (distancia >= 15 && distancia <25) {
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(2, LOW);
    }
    else{
      if (distancia < 15){
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(2, HIGH);
      }
    }
  }
}
