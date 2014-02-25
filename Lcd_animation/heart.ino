

const int TxPin = 5;

byte zero = 0;

#include <SoftwareSerial.h>
SoftwareSerial LCD = SoftwareSerial(255, TxPin);

void setup() {
    pinMode(TxPin, OUTPUT);
    digitalWrite(TxPin, HIGH);
    
    LCD.begin(9600); // LCD Screen
    LCD.write(0x0C); // Clear Screen
    delay(5);
    LCD.write(0x11); // Turn Backlight On
    LCD.print("Find different shapes!");
    delay(1000);
    LCD.write(0x0C);
    delay(5);
    LCD.write(0xF8);
    LCD.write(215); // Sound Tone
       
    for(int i = 0; i < 15; i++){
        heart();  
        LCD.write(128+i);
        LCD.write(zero);
        LCD.write(129+i);
        music();
    }
    
for (int i=1; i<15; i++){
        heart();

 LCD.write(148+i);
    }
  
 for (int i=1; i<16; i++){    
      heart();
      LCD.write(148+i);
      LCD.write(zero);
      LCD.write(147+i);
      food();
    
}
   
}

void loop() {
}

void heart(){
    LCD.write(zero);
    delay (100);
    LCD.write(0x1b);
    delay (10);
    LCD.write(0x1f);
    delay (10);
    LCD.write(0x1f);
    delay (100);
    LCD.write(0x1f);
    delay (100);
    LCD.write(0xe);
    delay (100);
    LCD.write(0x4);
    delay (100);
    LCD.write(zero);
}    


void food(){
    LCD.write(zero);
    delay (100);
    LCD.write(zero);
    delay (100);
    LCD.write(zero);
    delay (100);
    LCD.write(0xe0);
    delay (100);
    LCD.write(0xe0);
    delay (100);
    LCD.write(0xe0);
    delay (100);
    LCD.write(zero);
    delay (100);
    LCD.write(zero);
}

void music(){
    LCD.write(228);
    LCD.write(225);
    LCD.write(228);
    LCD.write(225);
    LCD.write(223);
    LCD.write(230);
    LCD.write(227);
    LCD.write(223);
    LCD.write(230);
    LCD.write(227);
    LCD.write(228);
    LCD.write(225);
    LCD.write(255);
    LCD.write(227);
    LCD.write(228);
    LCD.write(288);
    LCD.write(230);
    LCD.write(230);
    LCD.write(220);
    LCD.write(220);
    LCD.write(222);    
}






