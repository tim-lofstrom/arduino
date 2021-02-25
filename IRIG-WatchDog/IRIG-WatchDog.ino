#include <IRIG.h>


/* Initializes IRIG-B on digital pin 2 */
IRIG irig;

/**
 * Set up watch dog stuff for the IRIG-B reader.
 */
void setup() {

  irig = new IRIG(2);
  
  /* Start serial reading to print debug data etc. */
  Serial.begin(9600);

}


/**
 * Main program loop
 */
void loop() {

  String temp = irig.ReadTimeFrame();

  Serial.println(temp);
  
}
