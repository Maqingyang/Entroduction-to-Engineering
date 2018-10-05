#define q 5 //power will be 1/q of the maximum
void backward_setup()
{
}

void backward_loop()
{
  if(run == 1)
  {
    if(dir == 1)
    {
      
      digitalWrite(CTL2, HIGH);
      delay(10);
      digitalWrite(CTL2, LOW); 
      delay((q-1)*10);
    }
  }
} 
