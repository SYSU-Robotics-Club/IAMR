const int echopin = 3;
const int trigpin = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echopin, INPUT);
  pinMode(trigpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  float distance = pulseIn(echopin, HIGH);
  distance = distance/58.0;
  Serial.print(distance);
  Serial.print("cm\n");
  delay(60);
}
