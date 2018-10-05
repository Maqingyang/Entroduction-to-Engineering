#define SIGNAL 3
#define MACHINE 4

void pour_setup()
{
  pinMode(SIGNAL, INPUT);
  pinMode(MACHINE,OUTPUT);
  pinMode(PUSH1,INPUT_PULLUP);
  attachInterrupt(PUSH1,pour,CHANGE);
  digitalWrite(MACHINE,LOW);

}
void pour_loop()
{
  if(digitalRead(SIGNAL))
  {
    pour();
    delay(5000);
  }
}

void pour()
{
  digitalWrite(MACHINE, HIGH);
  delay(1000);
  digitalWrite(MACHINE, LOW);
  return;
}

