#define p 5//power will be 1/p of the maximum
void forward_setup()
{}

void forward_loop()
{
  if(run == 1)
  {
    if(dir == 0)
    {
      
      digitalWrite(CTL1, HIGH);
      delay(10);
      digitalWrite(CTL1, LOW); 
      delay((p-1)*10);
    }
    
  }
  
}
