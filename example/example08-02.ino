void setup()
{
  Serial.begin(9600);
}

void loop()
{
  for(int i=0; i<=255; i++) { // 0부터 255까지 256번 반복
    analogWrite(9, i);        // 아날로그 출력을 통해 LED 밝기제어
    Serial.println(i);
    delay(10);
  }
}
