#include<Servo.h>

int flame_sensor = 6;
int buzzer = 4;
int smoke_sensor = A1;
int LDR = A0;

Servo myservo;
float temp_smoke_sensor;
int flame_sensor_read;

void setup()
{
  Serial.begin(9600);
  pinMode(flame_sensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LDR, INPUT);
  myservo.attach(3);
  myservo.write(0);
  digitalWrite(buzzer, LOW);
}

void loop()
{
  Serial.println();
  int cahaya = analogRead(LDR);
  Serial.println();
  flame_sensor_read = digitalRead(flame_sensor);
  Serial.print("Flame Status: ");
  Serial.println(flame_sensor_read);

  temp_smoke_sensor = analogRead(smoke_sensor);
  Serial.print("Current Gas Level: ");
  Serial.println(temp_smoke_sensor);

  cahaya = analogRead(LDR);
  Serial.print("Intensitas cahaya = ");
  Serial.println(cahaya);
  delay(2000);
   
  if (temp_smoke_sensor > 350)
  {
    digitalWrite(buzzer, HIGH);
    myservo.write(90);
    Serial.print("GAS BOCOR!!");
    tone(buzzer, 1000, 200);
    delay(6000);
  }
  else
  {
    digitalWrite(buzzer, LOW);
    Serial.print("GAS AMAN");
    myservo.write(0);
  }

  if (flame_sensor_read == 0)
  {
    digitalWrite(buzzer, HIGH);
    Serial.print("AMAN");
    myservo.write(0);
  }
  else
  {
    digitalWrite(buzzer, LOW);
    Serial.print("KEBAKARAN !!!  ");
    myservo.write(180);
  }
}
