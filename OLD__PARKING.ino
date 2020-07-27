#include <Servo.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

Servo servo1;
Servo servo2;

const int analogInPin1 = A0;
const int analogInPin2 = A1;
const int analogInPin3 = A2;
const int analogInPin4 = A3;

const int servo_sensor_in = A4;

const int servo_sensor_exit = A5;

int led = 8;
int led1 = 9;
int led2 = 10;
int led3 = 13;

const int servo_1 =6;
const int servo_2 =7;


int count=4;
int value_1 =0;
int value_2 =0;
void setup()
{
    lcd.begin(16,2);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SMART PARKING");
    lcd.setCursor(0,1);
    lcd.print("SYSTEM");
    delay(3000);
    lcd.begin(16,2);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("MCA SCIENCE");
    lcd.setCursor(0,1);
    lcd.print("MINI PROJECT");
    lcd.setCursor(0,0);
    delay(3000);
    lcd.begin(16,2);
    lcd.print("MENTOR");
    lcd.setCursor(0,1);
    lcd.print("DR C H PATIL");
    delay(3000);






     lcd.clear();
    lcd.setCursor(0,0);  
    lcd.print("AVAILABLE");
    lcd.setCursor(0,1);
    lcd.print("SLOTS");
    delay(1000);
    lcd.setCursor(6,6);
    lcd.print(count);
  
   

    
    pinMode (analogInPin1,INPUT);
    pinMode (analogInPin2,INPUT);
    pinMode (analogInPin3,INPUT);
    pinMode (analogInPin4,INPUT);
  
  pinMode(servo_sensor_in,INPUT);
  pinMode(servo_sensor_exit,INPUT);
  
  servo1.attach(servo_1);
  servo2.attach(servo_2);

    pinMode (led,OUTPUT);
    pinMode (led1,OUTPUT);
    pinMode (led2,OUTPUT);
    pinMode (led3,OUTPUT);
  
}

void loop()
{  
  value_1 = analogRead(servo_sensor_in);
  value_2 = analogRead(servo_sensor_exit);

      // servo 1 Entry Gate code //
      
  {
    if(count >=1 &&  analogRead(A4)<500 )
      {
        servo1.write(90);
        delay(1000);
           count--;
         lcd.clear();    
    lcd.setCursor(0,0);  
    lcd.print("AVAILABLE");
    lcd.setCursor(0,1);
    lcd.print("SLOTS");
    delay(1000);
    lcd.setCursor(6,6);
    lcd.print(count);
      }
      else if(count==0 && analogRead(A4)<500)
      {
         servo1.write(0);
        delay(1000);
         lcd.clear();    
    lcd.setCursor(0,0);  
    lcd.print("PARKING");
    lcd.setCursor(0,1);
    lcd.print("FULL");
    delay(1000);
      }
       else
      {
        servo1.write(0);
        delay(60); 
      }
    }
 

        // servo 2 Exit Gate code //
{
    if(count < 4 &&  analogRead(A5)<500 )
      {
        servo2.write(90);
        delay(1000);
           count++;
         lcd.clear();    
    lcd.setCursor(0,0);  
    lcd.print("AVAILABLE");
    lcd.setCursor(0,1);
    lcd.print("SLOTS");
    delay(1000);
    lcd.setCursor(6,6);
    lcd.print(count);
      }
    else
      {
        servo2.write(0);
        delay(60); 
      }
   }
  
      // Parking Slot 1 IR & Led
 if (analogRead(A0)<500)  // if the IR sensor value is < 500 then the motor will start rotating     
               {
                 digitalWrite(led, HIGH);
               }

          else if (analogRead(A0)>500)  // if the IR sensor value is < 500 then the motor will start rotating     
               {
                 digitalWrite(led, LOW);
               }
               
  // Parking Slot 2 IR & Led
 if (analogRead(A1)<500)  // if the IR sensor value is < 500 then the motor will start rotating     
               {
                 digitalWrite(led1, HIGH);
               }

          else if (analogRead(A1)>500)  // if the IR sensor value is < 500 then the motor will start rotating     
               {
                 digitalWrite(led1, LOW);
               }

  // Parking Slot 3 IR & Led
 if (analogRead(A2)<500)  // if the IR sensor value is < 500 then the motor will start rotating     
               {
                 digitalWrite(led2, HIGH);
               }

          else if (analogRead(A2)>500)  // if the IR sensor value is < 500 then the motor will start rotating     
               {
                 digitalWrite(led2, LOW);
               } 

  // Parking Slot 4 IR & Led
 if (analogRead(A3)<500)  // if the IR sensor value is < 500 then the motor will start rotating     
               {
                 digitalWrite(led3, HIGH);
               }

          else if (analogRead(A3)>500)  // if the IR sensor value is < 500 then the motor will start rotating     
               {
                 digitalWrite(led3, LOW);
               }
}
