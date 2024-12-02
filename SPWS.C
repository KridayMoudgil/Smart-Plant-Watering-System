#include <LiquidCrystal.h>

const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int soilMoisturePin = A0;
const int pumpPin = 6;
const int moistureThreshold = 400;

int soilMoistureValue = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Plant Watering");
  delay(2000);
  lcd.clear();
  
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);
  Serial.begin(9600);
}

void loop() {
  soilMoistureValue = analogRead(soilMoisturePin);
  
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(soilMoistureValue);
  
  Serial.print("Soil Moisture Value: ");
  Serial.println(soilMoistureValue);

  if (soilMoistureValue < moistureThreshold) {
    lcd.setCursor(0, 1);
    lcd.print("Watering...     ");
    digitalWrite(pumpPin, HIGH);
    delay(5000);
    digitalWrite(pumpPin, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Watered         ");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Soil is Moist   ");
  }

  delay(2000);
}
