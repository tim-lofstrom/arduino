
int count;
int incomingByte = 0;   // for incoming serial data

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  count = 0;

}

void loop() {
  // put your main code here, to run repeatedly:


// send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();

                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte, DEC);

          Serial.println(count);
                count++;
        }
  
  

  delay(100);

}
