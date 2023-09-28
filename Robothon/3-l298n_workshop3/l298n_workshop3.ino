/*
ROBOTHON ELECTRONIX ENSTAB
Workshop 3 : Motors and drivers
Copy and Paste this code on your Arduino IDE


This code is delicately typed by the ELECTRONIX Club for whom this may be of concern
HEDFI Wassim.
*/



#define ENABLE_1_PIN        10      // This should be a pwm (~) pin
#define MOTOR_1_INPUT_1     9     
#define MOTOR_1_INPUT_2     8
#define MOTOR_2_INPUT_1     7  
#define MOTOR_2_INPUT_2     6 
#define ENABLE_2_PIN        5       // This should be a pwm (~) pin




#define MAX_MOTOR_SPEED       200
#define SLOW_MOTOR_SPEED      80
#define NORMAL_MOTOR_SPEED      100



void setup() {
  pinMode(MOTOR_1_INPUT_1, OUTPUT);       // DEFINE
  pinMode(MOTOR_1_INPUT_2, OUTPUT);       // MOTOR
  pinMode(MOTOR_2_INPUT_1, OUTPUT);       // DRIVER
  pinMode(MOTOR_2_INPUT_2, OUTPUT);       // PINS
  pinMode(ENABLE_1_PIN, OUTPUT);          // AS
  pinMode(ENABLE_2_PIN, OUTPUT);          // OUTPUT
}

void forward(uint8_t speed){
  analogWrite(ENABLE_1_PIN, speed); //Left Motor Speed
  analogWrite(ENABLE_2_PIN, speed); //Right Motor Speed
  digitalWrite(MOTOR_1_INPUT_1, LOW);
  digitalWrite(MOTOR_1_INPUT_2, HIGH);
  digitalWrite(MOTOR_2_INPUT_1, LOW);
  digitalWrite(MOTOR_2_INPUT_2, HIGH);
}

void reverse(uint8_t speed){
  analogWrite(ENABLE_1_PIN, speed); //Left Motor Speed
  analogWrite(ENABLE_2_PIN, speed); //Right Motor Speed
  digitalWrite(MOTOR_1_INPUT_1, HIGH);
  digitalWrite(MOTOR_1_INPUT_2, LOW);
  digitalWrite(MOTOR_2_INPUT_1, HIGH);
  digitalWrite(MOTOR_2_INPUT_2, LOW);
}

void sharpleft(uint8_t speed){
  analogWrite(ENABLE_1_PIN, speed); //Left Motor Speed
  analogWrite(ENABLE_2_PIN, speed); //Right Motor Speed
  digitalWrite(MOTOR_1_INPUT_1, LOW);
  digitalWrite(MOTOR_1_INPUT_2, HIGH);
  digitalWrite(MOTOR_2_INPUT_1, HIGH);
  digitalWrite(MOTOR_2_INPUT_2, LOW);
}
void left(uint8_t speed){
  analogWrite(ENABLE_1_PIN, speed); //Left Motor Speed
  analogWrite(ENABLE_2_PIN, speed); //Right Motor Speed
  digitalWrite(MOTOR_1_INPUT_1, LOW);
  digitalWrite(MOTOR_1_INPUT_2, HIGH);
  digitalWrite(MOTOR_2_INPUT_1, LOW);
  digitalWrite(MOTOR_2_INPUT_2, LOW);
}

void sharpright(uint8_t speed){
  analogWrite(ENABLE_1_PIN, speed); //Left Motor Speed
  analogWrite(ENABLE_2_PIN, speed); //Right Motor Speed
  digitalWrite(MOTOR_1_INPUT_1, HIGH);
  digitalWrite(MOTOR_1_INPUT_2, LOW);
  digitalWrite(MOTOR_2_INPUT_1, LOW);
  digitalWrite(MOTOR_2_INPUT_2, HIGH);
}
void right(uint8_t speed){
  analogWrite(ENABLE_1_PIN, speed); //Left Motor Speed
  analogWrite(ENABLE_2_PIN, speed); //Right Motor Speed
  digitalWrite(MOTOR_1_INPUT_1, LOW);
  digitalWrite(MOTOR_1_INPUT_2, LOW);
  digitalWrite(MOTOR_2_INPUT_1, LOW);
  digitalWrite(MOTOR_2_INPUT_2, HIGH);
}
void stopBot(uint8_t speed){
  analogWrite(ENABLE_1_PIN, speed); //Left Motor Speed
  analogWrite(ENABLE_2_PIN, speed); //Right Motor Speed
  digitalWrite(MOTOR_1_INPUT_1, LOW);
  digitalWrite(MOTOR_1_INPUT_2, LOW);
  digitalWrite(MOTOR_2_INPUT_1, LOW);
  digitalWrite(MOTOR_2_INPUT_2, LOW);
}


  
void loop() {
forward(NORMAL_MOTOR_SPEED);
delay(2000);
sharpright(NORMAL_MOTOR_SPEED);
delay(2000);
sharpleft(NORMAL_MOTOR_SPEED);
delay(2000);
reverse(NORMAL_MOTOR_SPEED);
delay(2000);
}
