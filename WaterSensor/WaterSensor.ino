int analogPin = 0;    // 워터센서 analog port 0 연결 선언
int val = 0;          // 전류변화값 변수선언
 
void setup ()
{
   Serial.begin (9600);           // 시리얼모니터 설정
}
 
void loop()
{
  val = analogRead(analogPin);   // analogPin 의 변화값(전류값)을 읽음
  Serial.println(val);      // 시리얼모니터에 전류값 표시
  delay (500);
}
