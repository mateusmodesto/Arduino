
void setup() {
  pinMode(A1, INPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(A1));
  if (analogRead(A1) > 999){
    digitalWrite(2, HIGH);
  }
  else{
    digitalWrite(2, LOW);
  }                                                               
}
