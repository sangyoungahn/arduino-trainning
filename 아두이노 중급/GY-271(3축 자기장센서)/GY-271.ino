#include <Wire.h> //I2C 아두이노 라이브러리 사용
 
#define address 0x1E //3축 자기장 센서의 주소(12C 7비트 - 0011110b)
 
void setup(){
  Serial.begin(9600); //시리얼 통신 세팅
  Wire.begin();
 
  //올바른 동작 모드를 위한 센서 설정
  Wire.beginTransmission(address); //자기장 센서와 통신을 하기 위한 설정
  Wire.write(0x02); //모드를 선택
  Wire.write(0x00); //계속적으로 측정하는 모드
  Wire.endTransmission(); //통신 종료
}
 
void loop(){
 
  int x,y,z; //3축 표현을 위한 데이터 변수 선언
 
  //센서가 데이터를 읽어오기 위한 통신 설정
  Wire.beginTransmission(address);
  Wire.write(0x03); //x의 최상위 비트 레지스터를 선택
  Wire.endTransmission();
 
 //각 축으로부터 데이터를 읽어옴
  Wire.requestFrom(address, 6);
  if(6<=Wire.available()){
    x = Wire.read()<<8; //x의 최상위 비트
    x |= Wire.read(); //x의 최하위 비트
    z = Wire.read()<<8; //z의 최상위 비트
    z |= Wire.read(); //z의 최하위 비트
    y = Wire.read()<<8; //y의 최상위 비트
    y |= Wire.read(); //y의 최하위 비트
  }
 
  //x,y,z 각 축의 데이터 값 출력
  Serial.print("x: ");
  Serial.print(x);
  Serial.print("  y: ");
  Serial.print(y);
  Serial.print("  z: ");
  Serial.println(z);
 
  delay(100);
}
