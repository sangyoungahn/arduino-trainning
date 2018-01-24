const int gasPin = A0;  //가스센서 출력을 아두이노 A0로 설정

void setup()
{
 Serial.begin(9600);  //시리얼포트 설정
}

void loop()
{
 Serial.println(analogRead(gasPin));  //센서값을 시리얼 모니터로 전송
 delay(1000);
} 
