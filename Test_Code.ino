#include <LiquidCrystal.h>
#define joyX A1 //this is the x-axis
#define joyY A0 //this is the y-axis
LiquidCrystal lcd(8,9,10,11,12,2);

int button = 3;
int buttonState = 0;
int buttonState1 = 0;
int led1 = 5;
int led2 = 4;
int led3 = 6;
int led4 = 7;

void setup() {
  pinMode(7,OUTPUT);
  pinMode(button,INPUT);
  digitalWrite(button, HIGH);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  lcd.begin(16,2);
  lcd.print("     Hello");//I added spaces before the 'hello' to put it in the middle. Alternatively I could have used lcd.Cursor but this was easier.
  Serial.begin(9600);
}
 
void loop() {
 int xValue = analogRead(joyX);
 int yValue = analogRead(joyY);
  Serial.print(xValue); //allows you to see the x values in serial monitor.
  Serial.print("\t");
  Serial.println(yValue);
  buttonState = digitalRead(button);
  Serial.println(buttonState);
  if (xValue>=1000 && yValue>=500 && yValue<1000)
  {
    digitalWrite(led1, HIGH);
    lcd.begin(16,1);
    lcd.print("    Red Light");
  }
  else{digitalWrite(led1, LOW);}

  if (xValue>=0 && yValue<=100)
  {
    digitalWrite(led2, HIGH);
    lcd.begin(16,2);
    lcd.print("   Blue Light");
  }
  else{digitalWrite(led2, LOW);}

  if (xValue<=100 && yValue>=450 && yValue<950)
  {
    digitalWrite(led3, HIGH);
    lcd.begin(16,2);
    lcd.print("   White Light");
  }
  else{digitalWrite(led3, LOW);}

  if (xValue>=0 && yValue>=950)
  {
    digitalWrite(led4, HIGH);
    lcd.begin(16,2);
    lcd.print("   Green Light");
  }
  else{digitalWrite(led4, LOW);}
  if (buttonState == LOW)
  {
    Serial.println("Switch = High");
    digitalWrite(led4, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led1, HIGH);
    lcd.begin(16,2);
    lcd.print("   ALL LIGHTS");
  }
  
}
