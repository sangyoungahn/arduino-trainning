int touchSensor = 8;  // 터치센서 핀 설정
 
void setup() {
  Serial.begin(9600); 
  pinMode(touchSensor, INPUT);
}
 
void loop() {
  //터치값 읽음
  int touchValue = digitalRead(touchSensor);
   
  if (touchValue == HIGH){      // 터치됨   
    Serial.println("TOUCHED");
  } else {                      //터치 안됨   
    Serial.println("NOT TOUCHED");
  }
 
  delay(1000);
}
