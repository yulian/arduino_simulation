void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(1);                 // 듀티 사이클을 10%로 조절
  
  digitalWrite(13, LOW);
  delay(9);
}
