const int row[8] = {2, 7, 19, 5, 13, 18, 12, 16 }; // 열을 연결하는 pin 세팅
const int col[8] = {6, 11, 10, 3, 17, 4, 8, 9 }; // 행을 연결하는 pin 세팅

// Dot Matrix 한 점 씩 출력 해보는 코드 

void setup() 
{
   for (int thisPin = 0; thisPin < 8; thisPin++) 
   {
     pinMode(col[thisPin], OUTPUT);
     pinMode(row[thisPin], OUTPUT);
     digitalWrite(col[thisPin], HIGH);
   }
}

void loop()
{
  for(int thisRow=0; thisRow<8; thisRow++)
  {
    for(int thisCol=0; thisCol<8; thisCol++)
    {
      digitalWrite(row[thisRow],HIGH);
      digitalWrite(col[thisCol],LOW);
      delay(200);
      digitalWrite(row[thisRow],LOW);
      digitalWrite(col[thisCol],HIGH);
      delay(200);  
    }
  }
}
