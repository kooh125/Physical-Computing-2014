// put the address pin numbers in an array
// so they're easier to iterate over:
const int channel[] = {
  2, 3};

// the output pin channel (mux's input):
const int outputPins[] = { 4, 5, 6 };

void setup() {
  // set up all pins as output:
  for (int thisPin = 2; thisPin < 7; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
  // iterate over the 16 channels of the multiplexer:
  for (int thisChannel = 0; thisChannel < 16; thisChannel++) {
    // set the channel pins based on the channel you want:
    muxWrite(thisChannel);

    // fade the current channel up:
    for (int brightness = 0; brightness < 256; brightness++) {
      for(int outputPin = 0; outputPin < 3; outputPin++)
      {
          analogWrite(outputPins[outputPin], brightness);

      }
    }
  }
}

void muxWrite(int whichChannel) {
  // iterate over the number of pins you're using:
  for (int thisPin = 0; thisPin < 4; thisPin++) {
    // calculate the state of this pin based on 
    // its bit value in whichChannel:
    int pinState = bitRead(whichChannel, thisPin);
    // turn the pin on or off:
    digitalWrite(channel[thisPin],pinState);
  }
}
