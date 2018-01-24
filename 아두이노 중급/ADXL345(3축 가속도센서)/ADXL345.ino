#include <Wire.h> // 아두이노에서 제공하는 header file

#define DEVICE (0x53) // device의 주소를 지정

byte _buff[6];

char POWER_CTL = 0x2D; // Power Control Register
char DATA_FORMAT = 0x31;  // 데이터 값 세팅

char DATAX0 = 0x32; // x축 데이터가 없으면 데이터 값이 0x32로 바뀜
char DATAX1 = 0x33; // x축 데이터가 있으면 데이터 값이 0x33로 바뀜

char DATAY0 = 0x34; // y축 데이터가 없으면 데이터 값이 0x34로 바뀜
char DATAY1 = 0x35; // y축 데이터가 없으면 데이터 값이 0x35로 바뀜

char DATAZ0 = 0x36; // z축 데이터가 없으면 데이터 값이 0x36로 바뀜
char DATAZ1 = 0x37; // z축 데이터가 없으면 데이터 값이 0x37로 바뀜

void setup()
{
  Wire.begin();        // I2C 통신을 위한 버스 사용
  Serial.begin(9600);  // 시리얼 모니터 시작 (Baud Rate 9600)
  Serial.print("init"); // 시리얼 모니터에 출력

  // writeTo() 함수 호출(DATA_FORMAT 레지스터에 0x01 값을 씀으로써 ADXL345를 '-4G ~ +4G' 범위에 놓음)
  writeTo(DATA_FORMAT, 0x01);
  
  // writeTo() 함수 호출(POWER_CTL 레지스터에 0x08을 기록하여 ADXL345를 측정 모드로 전환)
  writeTo(POWER_CTL, 0x08);
}

void loop()
{
  readAccel(); // 구현해놓은 readAccel() 함수를 호출
  
  delay(500); // 0.5초 지연시킴
}

void readAccel() {
  uint8_t howManyBytesToRead = 6;
  
  readFrom( DATAX0, howManyBytesToRead, _buff); //ADXL345 센서로부터 가속도 데이터를 읽어옴
  
  // 두 바이트를 하나의 int로 변환(LSB 우선)
  int x = (((int)_buff[1]) << 8) | _buff[0];
  int y = (((int)_buff[3]) << 8) | _buff[2];
  int z = (((int)_buff[5]) << 8) | _buff[4];

  Serial.print("x: ");
  Serial.print( x );  // x값 시리얼 모니터에 출력
  
  Serial.print(" y: ");
  Serial.print( y );  // y값 시리얼 모니터에 출력
  
  Serial.print(" z: ");
  Serial.println( z );  // z값 시리얼 모니터에 출력
}

void writeTo(byte address, byte val) {
  Wire.beginTransmission(DEVICE); // dvice에 전송을 시작
  Wire.write(address);             // register의 주소값을 전송
  Wire.write(val);                 // 쓰기 위한 값을 보냄
  Wire.endTransmission();         // 전송 종료
}

// 장치의 주소 레지스터에서 시작하여 _buff 배열로 num 바이트를 읽음
void readFrom(byte address, int num, byte _buff[]) {
  Wire.beginTransmission(DEVICE); // dvice에 전송을 시작
  Wire.write(address);             // 데이터를 읽어올 곳의 주소를 보냄
  Wire.endTransmission();         // 전송 종료
  Wire.beginTransmission(DEVICE); // dvice에 전송을 시작
  Wire.requestFrom(DEVICE, num);    // device에서 6바이트를 요청
  
  int i = 0;
  
  while(Wire.available())         //device가 사용 가능하다고 하면
  { 
    _buff[i] = Wire.read();    // _buf 배열에 한 바이트 씩 읽음
    i++;
  }
  
  Wire.endTransmission();         // 전송 종료
}
