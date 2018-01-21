int sensorPin = 0;// 사운드 센서를 0번핀에 연결

void setup() {
  Serial.begin(9600); //시리얼 통신을 시작합니다.
}

void loop() {
  int value = analogRead(sensorPin); // 사운드 센서로부터 센서값을 읽어 들입니다.
  
  delay(10);//10ms 동안 대기
  Serial.println(value);//센서값을 시리얼 모니터로 출력하여 현재 센서값을 보여줍니다.
  delay(600);//600ms 동안 대기
}
