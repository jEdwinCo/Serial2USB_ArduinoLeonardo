/*
  leo_usb2serial
  Allows to use an Arduino Leonardo as an usb to serial converter.
 */

 #include <SoftwareSerial.h>

//SoftwareSerial mySerial(8, 9); // RX, TX

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);

  // set the data rate for the SoftwareSerial port
  //mySerial.begin(115200);
  
}

void loop() {
  
  // copy from virtual serial line to uart and vice versa
  if (Serial.available()) {
    char c = (char)Serial.read();
    Serial1.write(c);
  }
  if (Serial1.available()) {
    char c = (char)Serial1.read();
    Serial.write(c);
  }
  /*
  if (mySerial.available()) {
    char c = (char)Serial1.read();
    Serial1.write(c);
    //Serial.write(mySerial.read());
  }
  */
}
