// the output pin channel (mux's input):
const int outputPins[] = { 2, 3, 4, 5, 6 };

void setup() {
  // set up all pins as output:
  for (int thisPin = 2; thisPin < 7; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
    // fade the current channel up:
    for (int brightness = 0; brightness < 256; brightness++) {
      for(int outputPin = 0; outputPin < 5; outputPin++)
      {
          analogWrite(outputPins[outputPin], brightness);
      }
    }
}
