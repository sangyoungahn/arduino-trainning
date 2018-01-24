int light_Pin = A0;        // 조도 센서 값 pin 세팅
int light_sense;           // 조도 값 받아서 저장 할 변수


void setup(void) {

    Serial.begin(9600);   //시러얼 통신 세팅
}

void loop(void) {
    light_sense = analogRead(light_Pin);   // 조도 값 저장
    
    Serial.print("Valore letto = ");   
    Serial.println(light_sense); 
    delay(1000);
}
