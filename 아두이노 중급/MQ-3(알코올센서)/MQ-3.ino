int alc_din=9; // 알코올 감지센서의 디지털 값을 받아오는 핀 (디지털 값은 0 or 1로써 알콜의 유무 확인)
int alc_ain=A0; // 알코올 감지센서의 아날로그 값을 받아오는 핀 (아날로그 값은 0 ~ 5V 사이 의 값)
int value = 0;

void setup()
{
  pinMode(alc_din,INPUT); // 디지털 값을 받아오는 핀 세팅
  pinMode(alc_ain,INPUT); // 아날로그 값을 받아오는 핀 세팅
  Serial.begin(9600); // 시리얼 통신 세팅
}

void loop()
{
  value = analogRead(alc_ain); // analogRead 함수를 통해 아날로그 값을 디지털 값 (0~1023)으로 변환 후 value 변수에 저장
  alc_din = digitalRead(alc_din); //알콜의 유무를 확인
  
  // 시리얼 모니터로 출력
  Serial.println(alc_din); 
  Serial.println(value);
}
