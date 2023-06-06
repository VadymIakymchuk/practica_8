#include <Arduino.h>


 uint8_t incomingByte=0;

void setup()
{
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1,16,17);
    
  Serial2.print(incomingByte);
}

 

void loop() {
  // send data only when you receive data:
  while (Serial2.available() > 0) {
    Serial.print(incomingByte);
    
    // read the incoming byte:
    incomingByte = Serial2.read();
    
    Serial.println(incomingByte);
    incomingByte++;
    
    Serial.println(incomingByte);
    Serial2.write(incomingByte);
    // say what you got:

  }
  
    Serial.print("I received: ");
    Serial.println(incomingByte);
  delay(1000);
  
}