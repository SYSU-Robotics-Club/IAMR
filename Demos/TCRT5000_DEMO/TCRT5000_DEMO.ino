// # Connection:
// #       Pin 1 VCC (TCRT5000) -> VCC (Arduino)
// #       Pin 2 GND (TCRT5000) -> GND (Arduino)
// #       Pin 3 OUT (TCRT5000) -> Pin 2 (Arduino)
// #

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin2 as an input
  pinMode(2, INPUT);

}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(2);
  //print out the value of the pushbutton
  Serial.println(sensorVal);
  delay(1000);
}



