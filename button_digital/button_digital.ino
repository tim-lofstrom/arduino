/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor

 This example code is in the public domain.
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
}

unsigned long duration;
char bitstream[79];
byte counter = 0;

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);

  duration = pulseIn(pushButton, HIGH, 250000);

  if(duration <= 2000){
    bitstream[counter] = '0';
    counter++;
  } else if(duration <= 5000){
    bitstream[counter] = '1';
    counter++;
  } else if(duration <= 8000){
    counter = 0;
    Serial.println(bitstream);  
  }

}












