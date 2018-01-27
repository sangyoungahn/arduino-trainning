#include <Servo.h>  // 서보모터 헤더파일

Servo servo;      // 객체생성
 
int servoPin = 5;
int angle = 0;    // 서보모터 최초 각 = 0 

void setup() 
{ 
  servo.attach(servoPin);   // 서보모터 초기화
} 
 
void loop() 
{ 
  for(angle = 0; angle < 180; angle++)
  { 
    servo.write(angle);  // 서보모터 각도 제어
    delay(15); 
  } 
}
