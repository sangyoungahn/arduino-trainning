int val = 0;                    // 센서 신호의 판별을 위한 변수 
int state = LOW;
int input = 5;
 
void setup() {
  
  Serial.begin(9600); // 시러얼 통신 셋팅
  pinMode(input, INPUT);
  
}
 
void loop(){
  
  val = digitalRead(input);  // 센서 값을 읽어 변수에 저장

  // 인체 감지 시
  if (val == HIGH) {        
    if (state == LOW){                         
         Serial.println("Detect!");    // 시리얼 모니터 출력
         state = HIGH;
         }    
  }
  else {                             // 인체 감지 없을 시
    if (state == HIGH){                
        Serial.println("End");   // 시리얼 모니터 출력
        state = LOW;
    }
  }
}
