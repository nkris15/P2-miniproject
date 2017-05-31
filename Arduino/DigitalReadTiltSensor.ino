// digital pin 4 has a pushbutton attached to it
int pushButton = 4;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);

  if(buttonState == HIGH)
  {
    // print out a tilt string
    Serial.println("Tilt");
    delay(5000);
  }
  
  
  delay(1); // delay in between reads for stability
}



