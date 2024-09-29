#include <LiquidCrystal.h>

int motor1Dir1 = 2; // Direction pin 1 for Motor 1 (Front Left)
int motor1Dir2 = 3; // Direction pin 2 for Motor 1

int motor2Dir1 = 4; // Direction pin 1 for Motor 2 (Front Right)
int motor2Dir2 = 5; // Direction pin 2 for Motor 2

int motor3Dir1 = 6; // Direction pin 1 for Motor 3 (Back Left)
int motor3Dir2 = 7; // Direction pin 2 for Motor 3

int motor4Dir1 = 8; // Direction pin 1 for Motor 4 (Back Right)
int motor4Dir2 = 9; // Direction pin 2 for Motor 4

int buzzerPin = 12; // Buzzer pin
int led1Pin = 13;   // LED 1 pin (for example, indicate movement)
int led2Pin = 14;   // LED 2 pin (for example, indicate stopping)

char command; // Variable to store received command from Bluetooth

LiquidCrystal Icd(10, 11, 15, 16, 17, 18); // LCD pins

void setup() {
    Serial.begin(9600); // Initialize serial communication with a baud rate of 9600

    // Motor pin configurations
    pinMode(motor1Dir1, OUTPUT);
    pinMode(motor1Dir2, OUTPUT);
    pinMode(motor2Dir1, OUTPUT);
    pinMode(motor2Dir2, OUTPUT);
    pinMode(motor3Dir1, OUTPUT);
    pinMode(motor3Dir2, OUTPUT);
    pinMode(motor4Dir1, OUTPUT);
    pinMode(motor4Dir2, OUTPUT);

    // Buzzer and LED pin configurations
    pinMode(buzzerPin, OUTPUT);
    pinMode(led1Pin, OUTPUT);
    pinMode(led2Pin, OUTPUT);

    // Initialize LCD
    Icd.begin(16, 2);
    Icd.print("Power: 12V"); // Indicate power requirement
    delay(2000); // Show for 2 seconds
    Icd.clear();
    Icd.print("Bluetooth Robot");
}

void loop() {
    if (Serial.available() > 0) {
        command = Serial.read(); // Read the incoming command from Bluetooth

        // Perform action based on the received command
        switch (command) {
            case '1':
                // Forward
                Icd.clear();
                Icd.print("Moving Forward");
                digitalWrite(led1Pin, HIGH); // Turn on LED 1 for movement
                digitalWrite(led2Pin, LOW);  // Turn off LED 2
                digitalWrite(buzzerPin, HIGH); // Turn on buzzer
                delay(100); // Buzzer duration
                digitalWrite(buzzerPin, LOW);  // Turn off buzzer
                moveForward();
                break;

            case '2':
                // Backward
                Icd.clear();
                Icd.print("Moving Backward");
                digitalWrite(led1Pin, HIGH); // Turn on LED 1 for movement
                digitalWrite(led2Pin, LOW);  // Turn off LED 2
                digitalWrite(buzzerPin, HIGH); // Turn on buzzer
                delay(100); // Buzzer duration
                digitalWrite(buzzerPin, LOW);  // Turn off buzzer
                moveBackward();
                break;

            case '3':
                // Left
                Icd.clear();
                Icd.print("Turning Left");
                digitalWrite(led1Pin, HIGH); // Turn on LED 1 for movement
                digitalWrite(led2Pin, LOW);  // Turn off LED 2
                turnLeft();
                break;

            case '4':
                // Right
                Icd.clear();
                Icd.print("Turning Right");
                digitalWrite(led1Pin, HIGH); // Turn on LED 1 for movement
                digitalWrite(led2Pin, LOW);  // Turn off LED 2
                turnRight();
                break;

            case '5':
                // Stop
                Icd.clear();
                Icd.print("Stopping");
                digitalWrite(led1Pin, LOW); // Turn off LED 1
                digitalWrite(led2Pin, HIGH); // Turn on LED 2 to indicate stop
                stopMotors();
                break;

            default:
                // Stop for unrecognized command
                Icd.clear();
                Icd.print("Invalid Command");
                digitalWrite(led1Pin, LOW); // Turn off LED 1
                digitalWrite(led2Pin, HIGH); // Turn on LED 2 to indicate stop
                stopMotors();
                break;
        }
    }
}

// Function to move motors forward
void moveForward() {
    digitalWrite(motor1Dir1, HIGH);
    digitalWrite(motor1Dir2, LOW);
    digitalWrite(motor2Dir1, HIGH);
    digitalWrite(motor2Dir2, LOW);
    digitalWrite(motor3Dir1, HIGH);
    digitalWrite(motor3Dir2, LOW);
    digitalWrite(motor4Dir1, HIGH);
    digitalWrite(motor4Dir2, LOW);
}

// Function to move motors backward
void moveBackward() {
    digitalWrite(motor1Dir1, LOW);
    digitalWrite(motor1Dir2, HIGH);
    digitalWrite(motor2Dir1, LOW);
    digitalWrite(motor2Dir2, HIGH);
    digitalWrite(motor3Dir1, LOW);
    digitalWrite(motor3Dir2, HIGH);
    digitalWrite(motor4Dir1, LOW);
    digitalWrite(motor4Dir2, HIGH);
}

// Function to turn motors left
void turnLeft() {
    digitalWrite(motor1Dir1, LOW);
    digitalWrite(motor1Dir2, HIGH);
    digitalWrite(motor2Dir1, HIGH);
    digitalWrite(motor2Dir2, LOW);
    digitalWrite(motor3Dir1, LOW);
    digitalWrite(motor3Dir2, HIGH);
    digitalWrite(motor4Dir1, HIGH);
    digitalWrite(motor4Dir2, LOW);
}

// Function to turn motors right
void turnRight() {
    digitalWrite(motor1Dir1, HIGH);
    digitalWrite(motor1Dir2, LOW);
    digitalWrite(motor2Dir1, LOW);
    digitalWrite(motor2Dir2, HIGH);
    digitalWrite(motor3Dir1, HIGH);
    digitalWrite(motor3Dir2, LOW);
    digitalWrite(motor4Dir1, LOW);
    digitalWrite(motor4Dir2, HIGH);
}

// Function to stop all motors
void stopMotors() {
    digitalWrite(motor1Dir1, LOW);
    digitalWrite(motor1Dir2, LOW);
    digitalWrite(motor2Dir1, LOW);
    digitalWrite(motor2Dir2, LOW);
    digitalWrite(motor3Dir1, LOW);
    digitalWrite(motor3Dir2, LOW);
    digitalWrite(motor4Dir1, LOW);
    digitalWrite(motor4Dir2, LOW);
}
