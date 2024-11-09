

//#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>


const int oneWireBusPin = 4;     
const int relayPin = 8;           
const int button1Pin = 2;         
const int button2Pin = 3;         


OneWire oneWire(oneWireBusPin);
DallasTemperature sensors(&oneWire);
LiquidCrystal_I2C lcd(0x27, 16, 2);  

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Suhu: ");
  lcd.setCursor(0, 1);
  lcd.print("Relay: OFF");
  lcd.backlight();

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);  // Matikan relay saat memulai

  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);

  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();  // Minta sensor untuk membaca suhu

  // Baca suhu dalam Celsius dan Fahrenheit
  float celsius = sensors.getTempCByIndex(0);
  float fahrenheit = sensors.toFahrenheit(celsius);

  Serial.print("Suhu Celsius: ");
  Serial.print(celsius);
  Serial.print("°C | Suhu Fahrenheit: ");
  Serial.print(fahrenheit);
  Serial.println("°F");

  // Tampilkan suhu di LCD
  lcd.setCursor(6, 0);
  lcd.print(celsius);
  lcd.print(" C  ");

  // Kontrol relay berdasarkan suhu
  if (celsius < 28) {
    digitalWrite(relayPin, HIGH); 
    lcd.setCursor(7, 1);
    lcd.print("ON ");
  } else if (celsius >= 30) {
    digitalWrite(relayPin, LOW);  
    lcd.setCursor(7, 1);
    lcd.print("OFF");
  }

  // Baca tombol dan kontrol relay
  if (digitalRead(button1Pin) == LOW) {
    digitalWrite(relayPin, HIGH);  
    lcd.setCursor(7, 1);
    lcd.print("ON ");
  }

  if (digitalRead(button2Pin) == LOW) {
    digitalWrite(relayPin, LOW);   
    lcd.setCursor(7, 1);
    lcd.print("OFF");
  }

  delay(1000); }
