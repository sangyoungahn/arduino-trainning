#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2                                                // Data Pin 2을 oneWire 정의 

OneWire oneWire(ONE_WIRE_BUS);                                        // Data Pin 2을 One Wire Bus로 설정
DallasTemperature sensors(&oneWire);                                  // DT 라이브러리에 oneWire 정보 전달
void setup(void)
{
  Serial.begin(9600);                                                 // 시리얼 모니터 시작 (Baud Rate 9600)
  Serial.println("Dallas Temperature IC Control Library Demo");       // 시리얼 모니터에 출력
  sensors.begin();                                                    // 센서 라이브러리 시작 
}
void loop(void)
{ 
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures();                                      // 온도 값을 얻는 명령 전달
  Serial.println("DONE");                                             // 시리얼 모니터에 출력
  Serial.print("Temperature for Device 1 is: ");                      // 시리얼 모니터에 출력
  Serial.print(sensors.getTempCByIndex(0));                           // 측정 된 온도 값을 가져 옴
}