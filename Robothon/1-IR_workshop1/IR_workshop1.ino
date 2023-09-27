/*
ROBOTHON ELECTRONIX ENSTAB
Workshop 1 : IR Sensor
Copy and Paste this code on your Arduino IDE


This code is delicately typed by the ELECTRONIX Club for whom this may be of concern
HEDFI Wassim.
*/


#define sensor 9   // Call the sensor's output pin(9) as sensor, this will help when you need to change the pin, for any reason
                  // if you want to change the pin number you want have to do so for all the code (wherever you used the pin 9), but just change it here
                  // you want to call the sensor pin in the code ? just type sensor !
int sensorValue ; // Create an empty variable to store the sonsor's reading

void setup() {

pinMode(sensor,INPUT); // Set the pin 'sensor'(9) to INPUT Mode; our Arduino will receive data from the sensor, hence this pin should be input
Serial.begin(9600); // This will set the our Arduino to cmmunicate with the Serial Monitor of the Arduino IDE with a bandwidth of 9600
}

void loop() {
  // put your main code here, to run repeatedly:
sensorValue=digitalRead(sensor); // the function "digitalRead" reads the value on the pin 'sensor'(9) and return a value of 0 or 1
Serial.println(sensorValue); // The function 'Serial.println' will write the value on the Serial Monitor

}
