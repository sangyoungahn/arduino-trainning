#include <IRremote.h> // 적외선 수신기 라이브러리  

int RECV_PIN = 11;  // 적외선 수신 데이터 pin 세팅

// IRrecev 객체 생성
IRrecv irrecv(RECV_PIN); 

// 수신받은 데이터 저장
decode_results results; 


void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  // 적외선 수신받았을 경우
  if (irrecv.decode(&results)) {  
    // 받은 값을 16진수로 출력한다.
    Serial.println(results.value, HEX); 
    irrecv.resume(); 
  }
}
