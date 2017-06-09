/*
 * 示例引脚接线
 * IN3 …… uno的 pin5
 * IN4 …… uno的 pin6
 * ENB …… uno的 pin3  只能连PWM模式引脚
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

void loop() {
  //forward 向前转
  digitalWrite(in3,HIGH); //给高电平
  digitalWrite(in4,LOW);  //给低电平
  analogWrite(pwm_enb, 178);   // 以70%的占空比
  delay(3000);  // 运行3秒

  //stop 停止 
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  analogWrite(pwm_enb, 0);
  delay(1000);  //延时1秒

  //back 向后转
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(pwm_enb, 255);   // 以100%的占空比
  delay(3000);  // 运行3秒
  
  //stop 停止 
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  analogWrite(pwm_enb, 0);
  delay(1000);  //延时1秒
}

