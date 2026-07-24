#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int PIN_TDS = 34;
const int PIN_TURB = 35;
const int PIN_SOLAR = 32;
const int PIN_RESET = 13;

const int PIN_LED_R = 4;
const int PIN_LED_G = 2;
const int PIN_LED_B = 15;

RTC_DATA_ATTR float superCapCharge = 100.0;

void setup() {
  Serial.begin(115200);
  
  pinMode(PIN_RESET, INPUT_PULLUP);
  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;);
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {
  int rawTDS = analogRead(PIN_TDS);
  int rawTurb = analogRead(PIN_TURB);
  int rawSolar = analogRead(PIN_SOLAR);
  
  // Солнечная батарея
  float solarGain = (rawSolar / 4095.0) * 2.5; 
  superCapCharge = superCapCharge - 0.6 + solarGain; 
  if (superCapCharge > 100.0) superCapCharge = 100.0;
  if (superCapCharge < 0.0) superCapCharge = 0.0;

  // Комплексный износ (TDS + Мутность)
  int totalPollution = (rawTDS / 40) + (rawTurb / 40);
  int filterHealth = 100 - totalPollution;
  if (filterHealth > 100) filterHealth = 100;
  if (filterHealth < 0) filterHealth = 0;

  if (digitalRead(PIN_RESET) == LOW) {
    superCapCharge = 100.0;
  }

  // Логика светодиода
  if (filterHealth > 55) {
    digitalWrite(PIN_LED_R, LOW);
    digitalWrite(PIN_LED_G, HIGH); 
    digitalWrite(PIN_LED_B, LOW);
  } else if (filterHealth > 25) {
    digitalWrite(PIN_LED_R, HIGH); 
    digitalWrite(PIN_LED_G, HIGH); 
    digitalWrite(PIN_LED_B, LOW);
  } else {
    digitalWrite(PIN_LED_R, HIGH); 
    digitalWrite(PIN_LED_G, LOW);
    digitalWrite(PIN_LED_B, LOW);
  }

  // Отрисовка дисплея LNL
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("LNL AIoT WATER V1.0");
  
  display.setCursor(0,16);
  display.printf("Filter Res: %d%%", filterHealth);
  
  display.setCursor(0,32);
  display.printf("PPM: %d | Turb: %d", rawTDS/4, rawTurb/4); 
  
  display.setCursor(0,48);
  display.printf("Solar Batt: %.1f%%", superCapCharge);
  
  display.display();
  delay(300); 
}
