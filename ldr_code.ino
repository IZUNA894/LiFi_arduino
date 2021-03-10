//ldr code...
int ldrPin=A3;
int Max=0;
int Min=1023;
int avg;

void setup() 
  // put your setup code here, to run once:
  {
    Serial.begin(9600);
    int i=0,val;
    for(i=0;i<5000;i++)
    {
          val=analogRead(ldrPin);
          if(val>Max)
          Max=val;
          if(val<Min)
          Min=val;
          delay(1);
    }
    Serial.println("Calibration Completed");
    Serial.print("Average is:");
    avg=(Max+Min)/2; 
    Serial.println(avg);
    delay(1000);
  }
int led_status(int val)
  {
    if(val>avg)
    return 1;
    else
    return 0;
  }
char char_code(int x)
{
  switch(x)
  {
    case 6 : return 'a';
    case 8 : return 'b';
    case 10 : return 'c';
    case 12 : return 'd';
    case 14 : return 'e';
    case 16 : return 'f';
    case 18 : return 'g';
    case 20 : return 'h';
    case 22 : return 'i';
    case 24 : return 'j';
    case 26 : return 'k';
    case 28 : return 'l';
    case 30 : return 'm';
    case 32 : return 'n';
    case 34 : return 'o';
    case 36 : return 'p';
    case 38 : return 'q';
    case 40 : return 'r';
    case 42 : return 's';
    case 44 : return 't';
    case 46 : return 'u';
    case 48 : return 'v';
    case 50 : return 'w';
    case 52 : return 'x';
    case 54 : return 'y';
    case 56 : return 'z';
    default : return ' ';
  }
}

void loop() {
  // put your main code here, to run repeatedly:analogWrite(ledPin,1000);
   //Serial.println("loop starts");
  int i=0,flag=0;
  int val=0;
  int header=900;
  int count=0;
  int cof=0;
  while(1)
  {
    int status = led_status(analogRead(ldrPin));
    if(status == 1)
    {
      if(cof>100)
      {
        Serial.println('\n');
        cof=0;
      }
      count++;
    }
    else
    {
      cof++;
      Serial.println(count);
      Serial.println(char_code(count));
      count=0;
      //Serial.println("loops breaks");
      break;
    }
    delay(100);
  }
}
