/*    >Combination Lock<
 *
 * with 4 pushbuttons, make a program that functions as a combination lock.
 * when the 3 buttons are pressed in the right order, a green LED goes on
 * if the wrong order is pushed, a red LED goes on
 * extra credit >>> make it so the combination can be reset with the pushbuttons!
 *
 * copyleft: Joel Murphy 2/27/2007
 *
 */ 

int RED = 7;			// red LED connected to digital pin 7
int GREEN = 8;                  // green LED connected to digital pin 8

int Button1 = 9;		// PushButton connected to pin 9
int Button2 = 10;		// PushButton connected to pin 10
int Button3 = 11;		// PushButton connected to pin 11
int Button4 = 12;                // PushButton connected to pin 12
int debounce = 10;		// Length of time to debounce switch in milliseconds
int B1Value; 		// used to feel current button state
int B2Value; 		// used to feel current button state
int B3Value; 		// used to feel current button state
int B4Value; 		// used to feel current button state

int Combo[4] = {1,2,3,4};        // THIS IS THE COMBINATION TO OPEN THE LOCK
int Guess[4];                    // used to hold the combination guess
int Position = 0;                // used to hold the position we're on in the array				
	
boolean LastB1Value = LOW;	// used to remember last button state
boolean LastB2Value = LOW;	// used to remember last button state
boolean LastB3Value = LOW;	// used to remember last button state
boolean LastB4Value = LOW;	// used to remember last button state


void setup()			
{
  pinMode(RED, OUTPUT);      	
  pinMode(GREEN, OUTPUT);
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(Button3, INPUT);
  pinMode(Button3, INPUT);	
}


void loop(){
  
  B1Value = digitalRead(Button1); 
    if (B1Value != LastB1Value){ 
      delay(debounce);            
      B1Value = digitalRead(Button1);
        if (B1Value != LastB1Value){
          if (B1Value == HIGH){       //IF THE BUTTON HAS JUST BEEN PRESSED 
            Guess[Position] = 1;      //PUT THE VALUE OF THE BUTTON INTO THE CORRECT POSITION IN THE ARRAY
            Position++;               //INCRIMENT THE POSITION COUNTER TO RECORD THE NEXT BUTTON PRESS
          }
        LastB1Value = B1Value;        //KEEP TRACK OF THE BUTTON STATE TO COMPARE NEXT TIME WE LOOP
      }
    }

  B2Value = digitalRead(Button2); 
    if (B2Value != LastB2Value){ 
      delay(debounce);            
      B2Value = digitalRead(Button2);
        if (B2Value != LastB2Value){
          if (B2Value == HIGH){       //IF THE BUTTON HAS JUST BEEN PRESSED 
            Guess[Position] = 2;      //PUT THE VALUE OF THE BUTTON INTO THE CORRECT POSITION IN THE ARRAY
            Position++;               //INCRIMENT THE POSITION COUNTER TO RECORD THE NEXT BUTTON PRESS
          }
        LastB2Value = B2Value;        //KEEP TRACK OF THE BUTTON STATE TO COMPARE NEXT TIME WE LOOP
      }
    }
    
  B3Value = digitalRead(Button3); 
    if (B3Value != LastB3Value){ 
      delay(debounce);            
      B3Value = digitalRead(Button3);
        if (B3Value != LastB3Value){
          if (B3Value == HIGH){       //IF THE BUTTON HAS JUST BEEN PRESSED 
            Guess[Position] = 3;      //PUT THE VALUE OF THE BUTTON INTO THE CORRECT POSITION IN THE ARRAY
            Position++;               //INCRIMENT THE POSITION COUNTER TO RECORD THE NEXT BUTTON PRESS
          }
        LastB3Value = B3Value;        //KEEP TRACK OF THE BUTTON STATE TO COMPARE NEXT TIME WE LOOP
      }
    }
    
    B4Value = digitalRead(Button4); 
    if (B4Value != LastB4Value){ 
      delay(debounce);            
      B4Value = digitalRead(Button4);
        if (B4Value != LastB4Value){
          if (B4Value == HIGH){       //IF THE BUTTON HAS JUST BEEN PRESSED 
            Guess[Position] = 4;      //PUT THE VALUE OF THE BUTTON INTO THE CORRECT POSITION IN THE ARRAY
            Position++;               //INCRIMENT THE POSITION COUNTER TO RECORD THE NEXT BUTTON PRESS
          }
        LastB4Value = B4Value;        //KEEP TRACK OF THE BUTTON STATE TO COMPARE NEXT TIME WE LOOP
      }
    }
       

 if (Position == 4){       //CHECK TO SEE IF WE'VE GOT 4 PRESSES
   Position = 0;           //RESET THE POSITION COUNTER FOR THE NEXT GO-AROUND
   if (Combo[0]==Guess[0] && Combo[1]==Guess[1] && Combo[2]==Guess[2] && Combo[3]==Guess[3]){
     digitalWrite (GREEN,HIGH);
     delay (1000);
     digitalWrite (GREEN,LOW);
   }else{
     digitalWrite (RED,HIGH);
     delay (1000);
     digitalWrite (RED,LOW);
   }
 }



}
