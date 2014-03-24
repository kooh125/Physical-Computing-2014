
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  
  matrix.begin(0x70);  // pass in the address
}

static const uint8_t PROGMEM
  one_bmp[] =
  { B11111111,
    B11111111,
    B11101101,
    B11111111,
    B11111111,
    B11111111,
    B00000000,
    B11111111 },
  two_bmp[] =
  { B11111111,
    B11111111,
    B11111111,
    B11101101,
    B11111111,
    B11111111,
    B00000000,
    B11111111 },
  three_bmp[] =
  { B11111111,
    B11111111,
    B11101101,
    B11111111,
    B11111111,
    B11111111,
    B00000000,
    B11111111 },

  four_bmp[] =
  { B11111111,
    B11111111,
    B11111111,
    B11111111,
    B11111111,
    B11111111,
    B11111111,
    B11111111 };

void loop() {
  matrix.clear();
  matrix.drawBitmap(0, 0, one_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, two_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, three_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, one_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, two_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, three_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);


  matrix.clear();
  matrix.drawBitmap(0, 0, one_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, two_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, three_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);
  for (int8_t x=0; x>=-36; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("CHLOE");
    matrix.writeDisplay();
    delay(100);

  }

}
