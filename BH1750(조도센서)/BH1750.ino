#include <Wire.h>
#include <BH1750.h> // 조도 센서를 사용하기 위한 header file 

BH1750 lightMeter; // BH1750 오브젝트 생성

void setup(){
    Serial.begin(9600); // 시리얼 통신 세팅
    lightMeter.begin(); // begin 함수를 통해 조도 센서 세팅

    Serial.println("Running…");

}

void loop() {
    //readLightlevel이 uint16_t (unsigned short형)으로 리턴하기 때문에 unit16_t 변수 선언
    uint16_t lux = lightMeter.readLightLevel();

    // 조도 센서 값 출력
    Serial.print("Light: ");
    Serial.print(lux);
    Serial.println(" lx");
    
    delay(1000);
}
