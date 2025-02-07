#include <Servo.h>

// Define LDR pins
const int LDR_Left = A0;   // Left LDR
const int LDR_Right = A1;  // Right LDR

// Define Servo motor
Servo solarServo;
const int servoPin = 9;

// Define variables
int pos = 90; // Initial position
int threshold = 20; // Sensitivity threshold

void setup() {
    solarServo.attach(servoPin); // Attach servo to pin
    solarServo.write(pos); // Move servo to initial position
    pinMode(LDR_Left, INPUT);
    pinMode(LDR_Right, INPUT);
    Serial.begin(9600);
}

void loop() {
    int leftValue = analogRead(LDR_Left);
    int rightValue = analogRead(LDR_Right);
    
    Serial.print("Left LDR: ");
    Serial.print(leftValue);
    Serial.print(" | Right LDR: ");
    Serial.println(rightValue);

    // Compare LDR values and move servo accordingly
    if (abs(leftValue - rightValue) > threshold) {
        if (leftValue > rightValue) {
            if (pos < 180) pos += 2; // Move right
        } else {
            if (pos > 0) pos -= 2; // Move left
        }
        solarServo.write(pos); // Update servo position
        delay(100);
    }
}
