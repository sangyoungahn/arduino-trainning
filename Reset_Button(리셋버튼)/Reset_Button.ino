int buttonPin = 4;                    //리셋 버튼 모듈
int val;                             //읽어온 버튼의 디지털 값 저장 변수

void setup() {
   pinMode(buttonPin, INPUT);
   Serial.begin(9600);             // 시리얼 통신 세팅
}

void loop() {
  
  val = digitalRead(buttonPin);     //버튼 값 읽어옴
  if(val==LOW) {                    //버튼이 눌린 동안
       Serial.println("Pushed");
       delay(100);
     }
  else{                              //버튼이 안 눌린동안
       Serial.println("Not Pushed");                    
  }
  delay(100);
}
