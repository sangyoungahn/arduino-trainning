int Buzzer = 9; // 수동부저 pin 세팅

void setup() {
    pinMode(Buzzer,OUTPUT);
}

void loop()
{
    tone(Buzzer,100);   // 주파수 100의 소리를 출력
    delay(500);

    tone(Buzzer,200);   // 주파수 200의 소리를 출력
    delay(500);

    tone(Buzzer,300);   // 주파수 300의 소리를 출력
    delay(500);

    tone(Buzzer,400);   // 주파수 400의 소리를 출력
    delay(500);
}
