int ledPin=3;
void setup() {
  // put your setup code here, to run once
  
    Serial
    .begin(9600);
    //delay(0);
    analogWrite(ledPin, 150 );
    delay(2000);
    pinMode(ledPin, OUTPUT);
    analogWrite(ledPin, 0 );
    

    /*analogWrite(ledPin,0);
   // delay(2000);
    int i=0;
    int j=0;
    while(i<5)
    {
      j=0;
      while(j<3)
      { 
        
        analogWrite(ledPin,1000);
        Serial.println(j+1);
        delay(5000);
        analogWrite(ledPin,0);
        delay(2000);
        j++;
      }
      Serial.println(i+1);
    
    delay(3000);
    i++;
    }
  }*/
}
int char_code(char x)
{
  switch(x)
  {
    case 'a' : return 30;
    case 'b' : return 40;
    case 'c' : return 50;
    case 'd' : return 60;
    case 'e' : return 70;
    case 'f' : return 80;
    case 'g' : return 90;
    case 'h' : return 100;
    case 'i' : return 110;
    case 'j' : return 120;
    case 'k' : return 130;
    case 'l' : return 140;
    case 'm' : return 150;
    case 'n' : return 160;
    case 'o' : return 170;
    case 'p' : return 180;
    case 'q' : return 190;
    case 'r' : return 200;
    case 's' : return 210;
    case 't' : return 220;
    case 'u' : return 230;
    case 'v' : return 240;
    case 'w' : return 250;
    case 'x' : return 260;
    case 'y' : return 270;
    case 'z' : return 280;
    case ' ' : return 320;
  }
}
void loop() {

  String a;
  //Serial.println("waiting for input");
  while(Serial.available()) {

  a = Serial.readString();// read the incoming data as string
  Serial.println("input recieved...");

  Serial.println(a);


  delay(1000);


int str_len= a.length();

for(int i=0; i < str_len; i++)
{
    Serial.println("now sending ..");
    Serial.println(a[i]);
    int char_delay = char_code(a[i]);
    analogWrite(ledPin,150);
    delay(char_delay);
    analogWrite(ledPin,0);
    Serial.println("sent...");

    delay (100);
} 
Serial.println("whole msg sent.."); 
  analogWrite(ledPin,150);
delay(300);
analogWrite(ledPin,0);

 }

}
