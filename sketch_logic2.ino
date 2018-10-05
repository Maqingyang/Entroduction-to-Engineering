//this program aims to control a intellectual rotation of shelter board
#include <Wire.h>
#include <math.h>


#define refine1 29
#define refine2 30

#define CTL1 39
#define CTL2 40
#define RATE_UPDATE 5//milliseconds


void Stop();
boolean IsLimited(int refine1_or_refine2);
boolean IsIntense();
boolean IsLowest(int Lowest);
int RecordTheLowest(int Lowest);

volatile int dir = 0;
volatile int run = 0;
volatile uint16_t val = 0;

const bool back = 0;
const bool forward = 1;
const int intense_level = 1200;
const int deta = 100;//  ， in IsLowest to limit the range

void setup()
{
  // put your setup code here, to run once:
  pinMode(CTL1, OUTPUT);
  digitalWrite(CTL1, LOW);
  pinMode(CTL2, OUTPUT);
  digitalWrite(CTL2, LOW);
  pinMode(refine1, INPUT);
  pinMode(refine2, INPUT);


}

void loop()
{
  //rotate back to the origin spot
  digitalWrite(RED_LED,LOW);
  digitalWrite(BLUE_LED,LOW);
  if(!IsLimited(refine1)){
    dir = back;
    run = 1;
    while(!IsLimited(refine1)){
    delay(RATE_UPDATE);
    }

    Stop();
  }
  //start rotating
  //stop when the light is intense or hit the refine2 limit
  int Lowest = 0; //record the lowest light;
  dir = forward;
  run =1;
  while((!IsIntense() )&&!IsLimited(refine2 )){
    Lowest = RecordTheLowest(Lowest);
    delay(RATE_UPDATE);
  }
  Stop();
  //if hit the refine2 limit, rotate back
  //stop at the direction of the lowest light comes 
  if(IsLimited(refine2)){
    dir = back;
    run = 1;
    while((IsLowest(Lowest) != true) && !IsLimited(refine1)){
      delay(RATE_UPDATE);
    }
    Stop();
  }
  //sleep
  delay(10000);
}
boolean IsLimited(int refine)
{
  return digitalRead(refine);
}
boolean IsIntense()
{
  if(val >= intense_level)
  {
    digitalWrite(RED_LED,HIGH);
  }
  else digitalWrite(RED_LED,LOW);
  return (val >= intense_level) ;
  
}
boolean IsLowest(int Lowest){
  if(val <= Lowest + deta)
  {
    digitalWrite(BLUE_LED,HIGH);
  }
  else digitalWrite(BLUE_LED,LOW);
  return  (val <= Lowest + deta);
}
int RecordTheLowest(int Lowest){
  if(val < Lowest&&val>Lowest - 20) return val;
  else return Lowest;
}

void Stop(){
  run = 0;
  delay(1000);
  return;
}

