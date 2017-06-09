/*
 * 示例引脚接线
 * IN3 …… uno的 pin5
 * IN4 …… uno的 pin6
 * ENB …… uno的 pin3
 */

int in3 = 5;
int in4 = 6;
int pwm_enb = 3;

void setup() {
  //初始化各IO,模式为OUTPUT 输出模式
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(pwm_enb,OUTPUT);
}

/* 
 *  调整PWM占空比来调整速度
 *  以rate%的占空比（rate: 0-100）
 *  运行msec毫秒
 */
void PWM(int rate, int msec) {
  int i = 0;
  rate = rate * 10;
  for (; i < msec; i++) {
    digitalWrite(pwm_enb, HIGH);
    delayMicroseconds(rate);
    digitalWrite(pwm_enb, LOW);
    delayMicroseconds(1000 - rate);
  }
}

void loop() {
  //forward 向前转
  digitalWrite(in3,HIGH); //给高电平
  digitalWrite(in4,LOW);  //给低电平
  PWM(70, 3000);   // 以70%的占空比运行3秒

  //stop 停止 
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);  
  delay(1000);  //延时1秒

  //back 向后转
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  PWM(100, 3000);  // 以100%的占空比运行3秒
  
  //stop 停止 
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);  
  delay(1000);  //延时1秒
}
