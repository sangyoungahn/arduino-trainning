#include <SFE_BMP180.h> // 기압 센서를 위한 header file
#include <Wire.h>        // 아두이노에서 제공하는 header file

SFE_BMP180 pressure;   // presseure라는 SFE_BMP180 object 생성

#define ALTITUDE 1655.0 // 임의의 고도 설정

void setup()
{
  Serial.begin(9600); //시리얼 통신 세팅
  Serial.println("REBOOT");

  //  센서 초기화 (연결 확인 과정)
  if (pressure.begin())
    Serial.println("BMP180 init success");
  else
  {
    Serial.println("BMP180 init fail\n\n");
    while(1); 
  }
}

void loop()
{
  char status;
  double T,P,p0,a;

    // "가상 고도" 시리얼 모니터 출력 
  Serial.println();
  Serial.print("provided altitude: ");
  Serial.print(ALTITUDE,0);
  Serial.print(" meters, ");
 
  status = pressure.startTemperature(); // 온도 측정을 위해 센서 상태 변경 
  
  if (status != 0)
  {
     delay(status);
    
    status = pressure.getTemperature(T);  // 온도 측정 후 T (섭씨 온도) 리턴

    if (status != 0)
    {
      // "온도" 시리얼 모니터에 출력
      Serial.print("temperature: ");
      Serial.print(T,2);
      Serial.print(" deg C, ");
      Serial.print((9.0/5.0)*T+32.0,2);
      Serial.println(" deg F");
      
      status = pressure.startPressure(3); // oversampling을 3으로 세팅 후 기압 측정 상태로 센서 변경

      if (status != 0)
      {
        delay(status);

        status = pressure.getPressure(P,T); // 측정한 온도 T와 측정한 기압을 저장 할 P를 통해 기압 측정
        
        if (status != 0)
        {
          // "기압" 시리얼 모니터에 출력
          
          Serial.print("absolute pressure: ");
          Serial.print(P,2);
          Serial.print(" mb, ");
          Serial.print(P*0.0295333727,2);
          Serial.println(" inHg");

        }
        else Serial.println("error retrieving pressure measurement\n");
      }
      else Serial.println("error starting pressure measurement\n");
    }
    else Serial.println("error retrieving temperature measurement\n");
  }
  else Serial.println("error starting temperature measurement\n");

  delay(5000);  
}
