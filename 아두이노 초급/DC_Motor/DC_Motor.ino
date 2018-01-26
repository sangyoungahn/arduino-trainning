const int motorPin = 9;     // dc 모터 데이터 값

void setup()
{
  pinMode(motorPin, OUTPUT);      
  Serial.begin(9600);             //시리얼 통신 셋팅
}

void loop()
{
     activeMotor();              //모터 작동시키는 함수 호출
}

void activeMotor()
{
  int speed;        
  Serial.println("Write speed : 0 ~ 255 and click send");   
 
  while(true)    
  {   
    while (Serial.available() > 0)    
    {     
     speed = Serial.parseInt();     // 사용자로 부터 받은 입력 값 speed 변수에 저장  
     speed = constrain(speed, 0, 255);     // 입력받은 값 pwm 값으로 변환4     
     analogWrite(motorPin, speed);         // 변환 값 dc 모터로 전달
 
     Serial.print("speed : ");
     Serial.println(speed);
    }
   }
 }
