#include <LiquidCrystal.h>    // LiquidCrystal.h 라이브러리 포함

LiquidCrystal disp(3, 4, 8, 9, 10, 11);   // LCD가 연결된 핀을 설정
 
void setup() {
  disp.begin(16, 2);  // LCD의 크기를 설정
}
 
void loop() {  
  disp.setCursor(0,0);        // 첫 번째 줄, 첫 번째 칸부터 출력
  // disp.setCursor(1,1);     // 두 번째 줄, 두 번째 칸부터 출력
  disp.print("Hello RNU");    // LCD에 출력할 내용 설정
  delay(1000);             
  disp.clear();               // LCD 문자열 삭제  
}
