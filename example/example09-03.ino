#include <Servo.h>

Servo myServo;

void setup()
{
  // 아두이노의 디지털 9번핀을 서보모터 제어에 사용
  myServo.attach(9);
}

void loop()
{
  // 서보모터의 각도를 0 ~ 180도까지 변경하여 동작
  for(int angle=0; angle<=180; angle++) {
    myServo.write(angle);
    delay(100);
  }
}

