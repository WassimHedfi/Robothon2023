/*
ROBOTHON ELECTRONIX ENSTAB
Workshop 1 : IR Sensor
Copy and Paste this code on your Arduino IDE


This code is delicately typed by the ELECTRONIX Club for whom this may be of concern
HEDFI Wassim.
*/


#include <SoftwareSerial.h>

#define DEBUG_ENABLE // Comment this line before putting the code in the robot to remove serial printing 
                     // otherwise may slow down the performance of your robot

#ifdef DEBUG_ENABLE
  #define DEBUG_MACRO(STRING) Serial.println(STRING)
#else
  #define DEBUG_MACRO(STRING) // DO Nothing
#endif


#define ENABLE_1_PIN          10  // same as we did in the previous workshop (3)
#define MOTOR_1_INPUT_1       9
#define MOTOR_1_INPUT_2       8
#define MOTOR_2_INPUT_1       7
#define MOTOR_2_INPUT_2       6
#define ENABLE_2_PIN          5

#define SERIAL_RX_PIN         0  // Connected to the Blutooth module's TX
#define SERIAL_TX_PIN         1  // Connected to the Blutooth module's RX ; don't forget the voltage divider !



#define MAX_MOTOR_SPEED       255
#define NORMAL_MOTOR_SPEED    150
#define SLOW_MOTOR_SPEED      80

// Software serial instance 
SoftwareSerial bluetoothSerial(SERIAL_RX_PIN, SERIAL_TX_PIN); // RX_PIN, TX_PIN
char incomingData = 'r';

/* Functions prototypes */
void forward(uint8_t speed);
void reverse(uint8_t speed);
void right(uint8_t speed);
void left(uint8_t speed);
void sharpRightTurn(uint8_t speed);
void sharpLeftTurn(uint8_t speed);
void stopBot(uint8_t speed);
void scanBluetooth();

/* ---------------------------------------------------------- */
void setup() {
  #ifdef DEBUG_ENABLE
    Serial.begin(9600);
  #endif
  
  bluetoothSerial.begin(9600); // This is the serial port we'll communicate with the bluetooth module through
  DEBUG_MACRO("--- Bluetooth RC robot started ---");
  
  pinMode(MOTOR_1_INPUT_1, OUTPUT);
  pinMode(MOTOR_1_INPUT_2, OUTPUT);
  pinMode(MOTOR_2_INPUT_1, OUTPUT);
  pinMode(MOTOR_2_INPUT_2, OUTPUT);
  pinMode(ENABLE_1_PIN, OUTPUT);
  pinMode(ENABLE_2_PIN, OUTPUT);
}

void loop() {
  scanBluetooth(); // Check if there's any incoming data through bluetooth
  
  switch(incomingData){ // Choose appropriate action
    case 'S': 
      stopBot(NORMAL_MOTOR_SPEED);
      DEBUG_MACRO("STOPPING");
      break;
    
    case 'F': 
      forward(NORMAL_MOTOR_SPEED); 
      DEBUG_MACRO("FORWARD");
      break;
      
    case 'L': 
      sharpLeftTurn(NORMAL_MOTOR_SPEED); 
      DEBUG_MACRO("LEFT");
      break;
    
    case 'R': 
      sharpRightTurn(NORMAL_MOTOR_SPEED);
      DEBUG_MACRO("RIGHT");
      break;
      
    case 'B':
      reverse(NORMAL_MOTOR_SPEED);
      DEBUG_MACRO("REVERSE");
      break;
      
    default: 
      DEBUG_MACRO("UNKNOWN COMMAND");
      break;
  }
/*
  forward(100);
  delay(1500);
  sharpRightTurn(100);
  delay(1500);
  sharpLeftTurn(100);
  delay(1500);
  reverse(100);
  delay(1500);*/
}
/* ---------------------------------------------------------- */

void forward(uint8_t speed){
  /* The pin numbers and high, low values might be different depending on your connections */
  analogWrite(ENABLE_1_PIN, speed); //Left Motor Speed
  analogWrite(ENABLE_2_PIN, speed); //Right Motor Speed
  digitalWrite(MOTOR_1_INPUT_1, LOW);
  digitalWrite(MOTOR_1_INPUT_2, HIGH);
  digitalWrite(MOTOR_2_INPUT_1, LOW);
  digitalWrite(MOTOR_2_INPUT_2, HIGH);
}

void reverse(uint8_t speed){
  /* The pin numbers and high, low values might be different depending on your connections */
  analogWrite(ENABLE_1_PIN, speed); //Left Motor Speed
  analogWrite(ENABLE_2_PIN, speed); //Right Motor Speed
  digitalWrite(MOTOR_1_INPUT_1, HIGH);
  digitalWrite(MOTOR_1_INPUT_2, LOW);
  digitalWrite(MOTOR_2_INPUT_1, HIGH);
  digitalWrite(MOTOR_2_INPUT_2, LOW);
}

void right(uint8_t speed){
  /* The pin numbers and high, low values might be different depending on your connections */
  analogWrite(ENABLE_1_PIN, speed); //Left Motor Speed
  analogWrite(ENABLE_2_PIN, speed); //Right Motor Speed
  digitalWrite(MOTOR_1_INPUT_1, LOW);
  digitalWrite(MOTOR_1_INPUT_2, HIGH);
  digitalWrite(MOTOR_2_INPUT_1, LOW);
  digitalWrite(MOTOR_2_INPUT_2, LOW);
}

void left(uint8_t speed){
  /* The pin numbers and high, low values might be different depending on your connections */
  analogWrite(ENABLE_1_PIN, speed); //Left Motor Speed
  analogWrite(ENABLE_2_PIN, speed); //Right Motor Speed
  digitalWrite(MOTOR_1_INPUT_1, LOW);
  digitalWrite(MOTOR_1_INPUT_2, LOW);
  digitalWrite(MOTOR_2_INPUT_1, LOW);
  digitalWrite(MOTOR_2_INPUT_2, HIGH);
}

void sharpRightTurn(uint8_t speed){
  /* The pin numbers and high, low values might be different depending on your connections */
  analogWrite(ENABLE_1_PIN, speed); //Left Motor Speed
  analogWrite(ENABLE_2_PIN, speed); //Right Motor Speed
  digitalWrite(MOTOR_1_INPUT_1, LOW);
  digitalWrite(MOTOR_1_INPUT_2, HIGH);
  digitalWrite(MOTOR_2_INPUT_1, HIGH);
  digitalWrite(MOTOR_2_INPUT_2, LOW);
}

void sharpLeftTurn(uint8_t speed){
  /* The pin numbers and high, low values might be different depending on your connections */
  analogWrite(ENABLE_1_PIN, speed); //Left Motor Speed
  analogWrite(ENABLE_2_PIN, speed); //Right Motor Speed
  digitalWrite(MOTOR_1_INPUT_1, HIGH);
  digitalWrite(MOTOR_1_INPUT_2, LOW);
  digitalWrite(MOTOR_2_INPUT_1, LOW);
  digitalWrite(MOTOR_2_INPUT_2, HIGH);
}

void stopBot(uint8_t speed){
  /* The pin numbers and high, low values might be different depending on your connections */
  analogWrite(ENABLE_1_PIN, speed); //Left Motor Speed
  analogWrite(ENABLE_2_PIN, speed); //Right Motor Speed
  digitalWrite(MOTOR_1_INPUT_1, LOW);
  digitalWrite(MOTOR_1_INPUT_2, LOW);
  digitalWrite(MOTOR_2_INPUT_1, LOW);
  digitalWrite(MOTOR_2_INPUT_2, LOW);
}

void scanBluetooth(){
  // There's data in the serial buffer (available() returns the number of bytes available)
  if(bluetoothSerial.available() > 0) incomingData = bluetoothSerial.read(); // Read a byte
  else Serial.println(incomingData);
}
