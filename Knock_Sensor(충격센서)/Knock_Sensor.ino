int shockPin = 4;         //충격감지 센서 pin 세팅
int val;                   //읽어온 센서의 디지털 값 저장 변수

void setup() {
   pinMode(shockPin, INPUT);
   Serial.begin(9600);
}

void loop() {
  val = digitalRead(shockPin);     //충격 값 값 읽어옴
  
  if(val==HIGH) {                 //충격을 감지 하였을시
       Serial.println("Shock");
       }
  else{
       Serial.println("Not Shock");  //충격을 감지하지 못 하였을 시
  }
  delay(500);
}
