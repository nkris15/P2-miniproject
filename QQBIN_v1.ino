



/* switch
 * 
 * Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
 * press), the output pin is toggled from LOW to HIGH or HIGH to LOW.  There's
 * a minimum delay between toggles to debounce the circuit (i.e. to ignore
 * noise).  
 *
 * David A. Mellis
 * 21 November 2006
 */

int inPin = 6;         // the number of the input pin
int outPin = 13;       // the number of the output pin

int state = HIGH;      // the current state of the output pin
int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

void switchModeSetup()
{
  pinMode(inPin, INPUT);
  pinMode(outPin, OUTPUT);
}

void switchModeLoop()
{
  reading = digitalRead(inPin);

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH)
      state = LOW;
    else
      state = HIGH;

    time = millis();    
  }

  digitalWrite(outPin, state);

  previous = reading;
}


void switchMode(){
  switchModeLoop()
  switchModeSetup()
  }


int switchState = 0;
int switchMode = 0;
int i = 0;
int b = 0;

void setup() {

  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, INPUT);

}

void loop() {
  switchState = digitalRead(2);
  switchMode = digitalRead(6);

  // Shift mode, ved tryk på knap pin 6, så skiftes der mellem game/queing.
  void switchMode

  // Game system, ved aktivering af tiltsensor pin 2, så føres målregnskab.


  // Queing system,
  // pin 3 grøn lyser hvis man er nummer 1 i køen;
  // pin 4 gul lyser hvis man er nummer 2 i køen;
  // pin 5 rød lyser hvis man er nummer 3 op til n i køen.

 do {

    if (switchState == LOW) {

      //digitalWrite(3, LOW);
      //digitalWrite(4, LOW);
      //digitalWrite(5, LOW);

      i = 1;
    }

    else {
      //digitalWrite(3, HIGH);
    }


    if (i == 1)
    {
      digitalWrite(3, HIGH);
    }

  } while (switchMode == HIGH);
}
