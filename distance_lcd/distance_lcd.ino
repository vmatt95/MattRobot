/* Simple counter for LCD */
#include <SerialLCD.h>
#include <SoftwareSerial.h>
#include <Servo.h>

const uint8_t ULTRASONIC_PIN = 9;

const uint8_t SERVO_PIN = 10;

const uint8_t LCD_RX_PIN = 8;
const uint8_t LCD_TX_PIN = 13;   // collide with LED

// initialize the library
SerialLCD slcd(LCD_RX_PIN, LCD_TX_PIN);


Servo s;            // create servo objet;
int pos = 80;        // position

void setup() {
    s.attach(SERVO_PIN);
    slcd.begin();
    
    s.write((int)pos);
}

float distance() {
  long duration = 0; 
  float cm = 0;

  pinMode(ULTRASONIC_PIN, OUTPUT);
  digitalWrite(ULTRASONIC_PIN, LOW);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_PIN, HIGH);
  delayMicroseconds(5);
  
  pinMode(ULTRASONIC_PIN, INPUT);
  duration = pulseIn(ULTRASONIC_PIN, HIGH);
  cm = duration / 57.8;   // v_s = 346 m / s
  return cm;
}

void loop() {
     float cm = distance();
     slcd.setCursor(0, 1);
     slcd.print(cm, DEC);
   
     delay(500);
}

