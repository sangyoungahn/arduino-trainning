int sensor = A0;    // 센서 데이터 핀 설정
int val = 0;  // 센서 데이터 저장 변수

void setup() {
  
   Serial.begin(9600);  // 시리얼 통신 세팅
   
}

void loop() {
  
  val = analogRead(sensor); // 센서 값 읽어서 저장   
  delay(1000);      
      
  //시리얼 모니터 출력
  Serial.print("Sensor = " );                       
  Serial.println(val); 
                    
}
