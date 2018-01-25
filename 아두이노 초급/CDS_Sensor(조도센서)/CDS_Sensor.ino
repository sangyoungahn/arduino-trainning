void setup() { 

    Serial.begin(9600);  // 시리얼 통신 셋팅
}    

void loop() { 

    int data = analogRead(A0);  // 조도 값 받아서 data 변수에 저장

    // 시리얼 모니터 출력
    Serial.println(data); 
    delay(100); 
}
