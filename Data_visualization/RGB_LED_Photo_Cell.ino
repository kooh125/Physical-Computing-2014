
 
int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

int redPin2 = 6;
int greenPin2 = 5;
int bluePin2 = 4;

void setup(void) {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  pinMode(redPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(bluePin2, OUTPUT);

  Serial.begin(9600);   
}
 
void loop(void) {
  photocellReading = analogRead(photocellPin);  
  Serial.println(photocellReading);
  setColor(photocellReading);
}

void setColor(int pr)
{
  if (pr < 10) {
    Serial.println(" - Very bright");
  } else if (pr > 10 && pr < 200) {
    Serial.println("red zone");
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
    
    analogWrite(redPin2, 0);
    analogWrite(greenPin2, 255);
    analogWrite(bluePin2, 255);
  } else if (pr > 200 && pr < 500) {
    Serial.println("purple zone");
    analogWrite(redPin, 0x87);
    analogWrite(greenPin, 0xCE);
    analogWrite(bluePin, 0xEB);
    
    analogWrite(redPin2, 0x87);
    analogWrite(greenPin2, 0xCE);
    analogWrite(bluePin2, 0xEB);
  } else if (pr > 500 && pr < 800) {
    Serial.println("blue zone");
    analogWrite(redPin, 0x4B);
    analogWrite(greenPin, 0x0);
    analogWrite(bluePin, 0x82);
    
    analogWrite(redPin2, 0x4B);
    analogWrite(greenPin2, 0x0);
    analogWrite(bluePin2, 0x82);
  } else if(pr > 800) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);

    analogWrite(redPin2, 0);
    analogWrite(greenPin2, 0);
    analogWrite(bluePin2, 0);

    Serial.println(" - Dark");
  }
  delay(1000);
}

\
