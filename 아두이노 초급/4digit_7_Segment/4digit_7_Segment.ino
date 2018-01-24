#include "SevSeg.h"   // 7-segment 라이브러리 추가

SevSeg sevseg; // 오브젝트 생성

  void setup() {
  
  byte numDigits = 4;
  
  byte digitPins[] = {2, 3, 4, 5};
  
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins); // begin 함수를 통해 pin들을 active하게
  // Display에 에러표시로 '8888'이 출력 될 시에는 COMMON_ANODE -> COMMON_CATHODE
  
  sevseg.setBrightness(90); // segment 밝기 조절

}

void loop() {

sevseg.setNumber(2134, 0); // setNumber는 숫자를 출력하기 위한 함수 (A, B) => A는 출력 원하는 값, B는 소수점 위치 (3,2,1,0 순이다)

//sevseg.setChars("BBB");  // setChars는 문자를 출력하기 위한 함수 " " 안에 출력 원하는 값을 넣어주면 된다.

sevseg.refreshDisplay(); // 화면 리셋(Must run repeatedly)

}
