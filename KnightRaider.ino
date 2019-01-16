int pinArray[] = {5, 6, 7, 8, 9, 10, 11, 12, 13};
int count = 5;
int timer = 100;
int buttonState=0;
int lastButtonState=0;
int mode=0;
int mode_6=0;
int count_2=13;

void setup(){
  for (count=0;count<10;count++) {
    pinMode(pinArray[count], OUTPUT);
  }
  count=5;
  pinMode(2,INPUT);//intrarea butonului
}

void loop() {

  buttonState= digitalRead(2);
  if(buttonState == HIGH && buttonState != lastButtonState)
    {
      mode++;
    }
  lastButtonState=buttonState;  
  switch(mode%6)
  {
  case 0:
  {
    digitalWrite(5,1);
    count = 5;
    count_2=13;
    break;
  }
  case 1:
  {
   if(count<=13)
   {
   digitalWrite(count, 1);
   delay(timer);
   digitalWrite(count+1,1);
   digitalWrite(count, 0);
   count++;
   }
   else if(count_2>4)
   {
   digitalWrite(count_2, HIGH);
   delay(timer);
   digitalWrite(count_2, LOW);
   count_2--;
   }
   if(count == 14 && count_2==4)
   {
    count=5;
    count_2=13;
   }
     
   break;
  }
  
  case 2:
  {
    if(count>4)
      count=0;
    digitalWrite(13-count,1);
    digitalWrite(5+count,1);
    delay(timer);
    digitalWrite(13-count,0);
    digitalWrite(5+count,0);
    count++;
   break;
  }  
  case 3:
  {
    if(count>4)
      count=0;
    digitalWrite(9+count,1);
    digitalWrite(9-count,1);
    delay(100);
    digitalWrite(9+count,0);
    digitalWrite(9-count,0);
    count++;
    break;
  }
  case 4:
  {
    if(count<5)
      count=5;
    digitalWrite(count,1);
    delay(timer);
    count++;
    if(count>13)
    {
      for(count=13;count>4;count--)
        digitalWrite(count,0);
      count=0;
    } 
    break;
    }
    
  case 5:
  {

    if(mode_6==0)
    {
      for(count=5;count<14;count+=2)
        digitalWrite(count,1);
      delay(timer);
      for(count=5;count<14;count+=2)
        digitalWrite(count,0);
      mode_6++;
      }
    else if(mode_6==1)
    {
    digitalWrite(6,1);
    digitalWrite(12,1);
    delay(100);
    digitalWrite(6,0);
    digitalWrite(12,0);
    
    delay(100);
    mode_6++;
      }
    
    else if(mode_6==2)
    {
    digitalWrite(10,1);
    digitalWrite(8,1);
    delay(timer);
    digitalWrite(10,0);
    digitalWrite(8,0);

    delay(100);
    mode_6=0;
      }
    
    break;
    }
  }
}
