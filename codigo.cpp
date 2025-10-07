#include <LiquidCrystal.h>


LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

const int LED = 13;
const int FAN = 10;
const int SENSOR_PIN = A0;

float temperature = 0.0;
unsigned long lastBlink = 0;
const unsigned long blinkInterval = 500;
bool ledState = LOW;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(FAN, OUTPUT);
  digitalWrite(LED, LOW);
  digitalWrite(FAN, LOW);

  lcd_1.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  
  int sensor_value = analogRead(SENSOR_PIN);
  float voltage = sensor_value * (5.0 / 1023.0);
  temperature = voltage * 100.0; 

  
  lcd_1.setCursor(0, 0);
  lcd_1.print("Temp: ");
  lcd_1.print(temperature, 1);
  lcd_1.print((char)223);
  lcd_1.print("C   "); 

  
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println(" °C");

  unsigned long now = millis();

  
  if (temperature <= 10.0) {
    if (now - lastBlink >= blinkInterval) {
      lastBlink = now;
      ledState = !ledState;
      digitalWrite(LED, ledState);
    }
    digitalWrite(FAN, LOW);
  }

  
  else if (temperature >= 11.0 && temperature <= 25.0) {
    digitalWrite(LED, LOW);
    digitalWrite(FAN, LOW);
  }

  
  else if (temperature >= 26.0) {
    digitalWrite(LED, HIGH);
    digitalWrite(FAN, HIGH);
  }

  delay(100); 
}

