#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

#define MQ2_PIN 34          // Pin analógico del MQ-2
#define DS18B20_PIN 4       // Pin digital del DS18B20
#define BUZZER_PIN 13       // Pin del buzzer
#define LED_R 25            // Rojo del LED RGB
#define LED_G 26            // Verde del LED RGB
#define LED_B 27            // Azul del LED RGB

OneWire oneWire(DS18B20_PIN);
DallasTemperature sensors(&oneWire);
LiquidCrystal_I2C lcd(0x27, 16, 2);

float lastTemperature = 0.0;

void setup() {
  Serial.begin(115200);
  pinMode(MQ2_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  sensors.begin();
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Temp: --.- C");
}

void loop() {
  // Lecturas de sensores
  int mq2_value = analogRead(MQ2_PIN);
  sensors.requestTemperatures();
  float currentTemp = sensors.getTempCByIndex(0);

  // Mostrar temperatura en el LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(currentTemp);
  lcd.print(" C   ");

  // Evaluar condiciones
  bool gas_detected = mq2_value > 600;
  bool temp_rise = (currentTemp - lastTemperature) > 5;

  lcd.setCursor(0, 1);
  lcd.print("                ");

  if (gas_detected) {
    lcd.setCursor(0, 1);
    lcd.print(" ¡EMERGENCIA! ");
    sirenaBomberos();
    setLEDColor(255, 0, 0);
  } else if (temp_rise) {
    lcd.setCursor(0, 1);
    lcd.print(" ¡Aumento Temp! ");
    setLEDColor(50, 50, 0);
  } else {
    noTone(BUZZER_PIN);
    setLEDColor(0, 255, 0);
  }

  lastTemperature = currentTemp;
  delay(1000);
}

// Configuración de LED RGB
void setLEDColor(int r, int g, int b) {
  analogWrite(LED_R, 255 - r);
  analogWrite(LED_G, 255 - g);
  analogWrite(LED_B, 255 - b);
}

// Sirena con ajuste en el tiempo de cada tono
void sirenaBomberos() {
  for (int freq = 500; freq <= 1500; freq += 10) {
    tone(BUZZER_PIN, freq, 5);
    delay(5);
  }
  for (int freq = 1500; freq >= 500; freq -= 10) {
    tone(BUZZER_PIN, freq, 5);
    delay(5);
  }
  noTone(BUZZER_PIN);
}