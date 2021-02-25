#include <Arduino.h>
#include "Test.h"
#include <Ethernet.h>


void setup() {
  Serial.begin(9600);
}

void loop() {

	//Test *test = new Test();

//	test->Foo();

	//char Str6[15] = "arduino";

	//delay(100);

	String s = "ASD";

	String temp = s + "SAD";

	Serial.println(temp);
	delay(1000);

}
