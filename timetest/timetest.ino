unsigned long time;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Time: ");
  time = micros();
  //prints time since program started
  Serial.println(time / 1000);
  // wait a second so as not to send massive amounts of data
  delayMicroseconds(1000);
  time = micros();

  Serial.println(time / 1000);
  // wait a second so as not to send massive amounts of data
  delayMicroseconds(1000);

  delay (1000);
}
