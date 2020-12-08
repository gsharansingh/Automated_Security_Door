#define BLYNK_PRINT Serial
#define BLYNK_MAX_SENDBYTES 256

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int sw1;
int i=0 , x = 0 , right=0 , light , sw  , t = 6000;  
  char gur[14] = {' ','5','4','0','0' ,'2','F','8','B','3','1','C','1',' '}; // 5825
  char sim[14] = {' ','2','0','0','0' ,'6','3','C','0','D','4','5','7',' '}; // 7428  
  int gurp , simp;
  char ref[14]; // reference
  int kk=0;
char auth[] = "5ebb5dd6340f49f794bedcb369e5b77e";
char ssid[] = "Andriod_gursharn";
char pass[] = "QwertY2525!!";

void setup()
{
  // put your setup code here, to run once:
  pinMode(D1,INPUT); //for weight (we are using switch instead of a weight sensor)
  pinMode(D2,INPUT); //it will be manipulated over the internet to override security
  pinMode(D5,OUTPUT); //for closing door
  pinMode(D6,OUTPUT); //for opening door
  pinMode(D7,OUTPUT); //for beeper
  pinMode(D8,OUTPUT); //for red alert (red led)Serial.begin(9600);
  Serial.begin(9600);
  Blynk.begin(auth , ssid , pass);
}

void loop()
{
   Blynk.run();
  // put your main code here, to run repeatedly:
  sw1 = digitalRead(D1);t = 6000;
  Serial.println("waiting for customer");
  while(sw1 == 0) //IR Sensor detection
  {
      if(Serial.available()>0)
      {
          ref[i] =Serial.read(); 
          Serial.print(ref[i]); 
          i++;delay(100); 
      }
      else if(t>20)
      {
          t = t-10;delay(10); // to check if the card is scanned within time or not.
      }
      else
      {
          breach();
          break;
      }
      if(i == 14)
      {   
          t = 6000; // after we read card number setting time to 6 seconds
          for(x = 1 ; x <13 ; x++)
          {
              if(gur[x] == ref[x])
              {
                  Serial.println(gurp);gurp++;
              }
              if(sim[x] == ref[x])
              {
                  Serial.println(simp);simp++;
              }
          }
          if(gurp == 12)
          {//Serial.println(ref);
              Serial.println("Gursharan");           
              gurp = 0;simp = 0;i=0;char ref[]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0'};         
          }
          else if(simp ==12)
          {//Serial.println(ref);
              Serial.println("Simran");               
              gurp = 0;simp = 0;i=0;char ref[]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
          }  
          
          else
          {
              Serial.println(ref);
              Serial.println("Wrong card");           
              gurp = 0;simp = 0;i=0;char ref[]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
              breach();
              break;
          }
          delay(500);
          Serial.print("ENDING");
          while(t>20){t = t-10;delay(10);}  // this portion is to provide a pause after the card is matched.
           
          delay(500); // delay is compulsory otherwise comparison on cards will be ignored
          Serial.end();
          delay(1000);
          Serial.begin(9600);
          i=0;break;
      }
  }    
  delay(1000);
}
void breach()
{
  Blynk.email("g.sharanbp@gmail.com","Security Breach","Check out as soon as possible 'cause someone has had break-in!!!");
  Serial.println("b"); //just to check whether the program is working properly
  digitalWrite(D5,HIGH); //closes the doors
  digitalWrite(D2,LOW);
  delay(50);
  digitalWrite(D5,LOW);
  digitalWrite(D7,HIGH);  //Beeper will be started
  digitalWrite(D8,HIGH);  //LED will be turned on
  delay(300);
  kk = digitalRead(D2);
  Serial.print("sw = ");
  Serial.println(kk);
  while(kk==0) //Doors remains closed until security is overrided
  {
    Blynk.run();
    Serial.println("in loop");
      kk = digitalRead(D2);
     // ll=kk+oo;
      delay(10);
      if(kk !=0) //when security will be overrided
      {
        Serial.println("breaking loop");
        break;
      }
  }
  delay(2000);
  digitalWrite(D6,HIGH); //Doors will be opened
  delay(50);
  digitalWrite(D6,LOW);
  digitalWrite(D7,LOW); //Beeper will be stoped
  digitalWrite(D8,LOW); //LED will be turned off
  digitalWrite(D2,LOW);
  delay(5000);  //for security's move for entering into room
}
