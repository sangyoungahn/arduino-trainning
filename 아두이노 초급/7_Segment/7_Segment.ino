byte seven_seg_digits[10][8] =  //7세그먼트 LED에 표시할 숫자를 디지털IO핀 ON/OFF 어레이로 변환
{
  { 0,1,1,1,1,0,1,1 },  // = 0
  { 0,1,1,0,0,0,0,0 },  // = 1
  { 0,0,1,1,0,1,1,1 },  // = 2
  { 0,1,1,1,0,1,0,1 },  // = 3
  { 0,1,1,0,1,1,0,0 },  // = 4
  { 0,1,0,1,1,1,0,1 },  // = 5
  { 0,1,0,1,1,1,1,1 },  // = 6
  { 0,1,1,1,0,0,0,0 },  // = 7
  { 0,1,1,1,1,1,1,1 },  // = 8
  { 0,1,1,1,1,1,0,1 }   // = 9
 };

void setup()  // 7 segment pin 셋팅
{
  pinMode(4, OUTPUT);   
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}
   
void sevenSegWrite(byte digit) // 7 segment에 출력함수
{
  byte pin = 4;
  for (byte segCount = 0; segCount < 8; ++segCount) {
    digitalWrite(pin, seven_seg_digits[digit][segCount]);
    ++pin;
  }
}

void loop() 
{
  for (byte count = 10; count > 0; --count) {
   delay(1000);
   sevenSegWrite(count - 1); 
  }
  delay(2000);
}
