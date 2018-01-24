const int Trigger = 8; //Trig 핀 할당
const int Echo = 9; //Echo 핀 할당
long Duration = 0; // Echo 핀으로 들어오는 펄스 시간을 측정하기 위한 전역변수

void setup() {
  
  pinMode(Trigger, OUTPUT); // Trigger 핀을 output으로 세팅
  pinMode(Echo, INPUT); // Echo 핀을 input으로 세팅
  Serial.begin(9600); // 시리얼 초기화
}

void loop() {
  
  digitalWrite(Trigger, LOW); // Trigger 핀 Low
  delayMicroseconds(2); // 2us delay 세팅 
  digitalWrite(Trigger, HIGH); // Trigger 핀 HIGH
  delayMicroseconds(10); // 10us delay 세팅
  digitalWrite(Trigger, LOW); // Trigger 핀 HIGH

  Duration = pulseIn(Echo, HIGH); // pulseIn 함수를 통해 펄스가 입력될 때까지의 시간을 측정 후 us단위로 리턴

  long Distance_mm = Distance(Duration); // us단위로 리턴 된 값을 통해 Distance 함수를 통해 실제 거리 계산

  // 시러얼 모니터로 출력
  Serial.print("Distance = "); 
  Serial.print(Distance_mm);
  Serial.println(" mm");
  
  delay(1000); // 10초간 delay를 주어 다음 값 측정
}

long Distance(long time)
{
  long DistanceCalc; // Calculation variable
  DistanceCalc = ((time / 2.9) / 2);  // 실제 거리를 mm단위로 계산
  
  return DistanceCalc; // 계산 된 값 다시 리턴
}
