#include <LiquidCrystal.h>

int motor1Dir1 = 2; // Direction pin 1 for Motor 1 (Front Left)
int motor1Dir2 = 3; // Direction pin 2 for Motor 1

int motor2Dir1 = 4; // Direction pin 1 for Motor 2 (Front Right)
int motor2Dir2 = 5; // Direction pin 2 for Motor 2

int motor3Dir1 = 6; // Direction pin 1 for Motor 3 (Back Left)
int motor3Dir2 = 7; // Direction pin 2 for Motor 3

int motor4Dir1 = 8; // Direction pin 1 for Motor 4 (Back Right)
int motor4Dir2 = 9; // Direction pin 2 for Motor 4

char command; // Variable to store received command from Bluetooth

LiquidCrystal Icd(10, 11, 12, 13, 14, 15); // LCD pins

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
                digitalWrite(motor1Dir1, HIGH);  // Motor 1 (Front Left) forward
                digitalWrite(motor1Dir2, LOW);   
                digitalWrite(motor2Dir1, HIGH);  // Motor 2 (Front Right) forward
                digitalWrite(motor2Dir2, LOW);   
                digitalWrite(motor3Dir1, HIGH);  // Motor 3 (Back Left) forward
                digitalWrite(motor3Dir2, LOW);   
                digitalWrite(motor4Dir1, HIGH);  // Motor 4 (Back Right) forward
                digitalWrite(motor4Dir2, LOW);   
                break;

            case '2':
                // Backward
                Icd.clear();
                Icd.print("Moving Backward");
                digitalWrite(motor1Dir1, LOW);   
                digitalWrite(motor1Dir2, HIGH);  // Motor 1 (Front Left) backward
                digitalWrite(motor2Dir1, LOW);   
                digitalWrite(motor2Dir2, HIGH);  // Motor 2 (Front Right) backward
                digitalWrite(motor3Dir1, LOW);   
                digitalWrite(motor3Dir2, HIGH);  // Motor 3 (Back Left) backward
                digitalWrite(motor4Dir1, LOW);   
                digitalWrite(motor4Dir2, HIGH);  // Motor 4 (Back Right) backward
                break;

            case '3':
                // Left
                Icd.clear();
                Icd.print("Turning Left");
                digitalWrite(motor1Dir1, LOW);   
                digitalWrite(motor1Dir2, HIGH);  // Motor 1 (Front Left) backward
                digitalWrite(motor2Dir1, HIGH);  
                digitalWrite(motor2Dir2, LOW);   
                digitalWrite(motor3Dir1, LOW);   
                digitalWrite(motor3Dir2, HIGH);  // Motor 3 (Back Left) backward
                digitalWrite(motor4Dir1, HIGH);  
                digitalWrite(motor4Dir2, LOW);   
                break;

            case '4':
                // Right
                Icd.clear();
                Icd.print("Turning Right");
                digitalWrite(motor1Dir1, HIGH);  
                digitalWrite(motor1Dir2, LOW);   
                digitalWrite(motor2Dir1, LOW);   
                digitalWrite(motor2Dir2, HIGH);  // Motor 2 (Front Right) backward
                digitalWrite(motor3Dir1, HIGH);  
                digitalWrite(motor3Dir2, LOW);   
                digitalWrite(motor4Dir1, LOW);   
                digitalWrite(motor4Dir2, HIGH);  // Motor 4 (Back Right) backward
                break;

            case '5':
                // Stop
                Icd.clear();
                Icd.print("Stopping");
                digitalWrite(motor1Dir1, LOW);   
                digitalWrite(motor1Dir2, LOW);   
                digitalWrite(motor2Dir1, LOW);   
                digitalWrite(motor2Dir2, LOW);   
                digitalWrite(motor3Dir1, LOW);   
                digitalWrite(motor3Dir2, LOW);   
                digitalWrite(motor4Dir1, LOW);   
                digitalWrite(motor4Dir2, LOW);   
                break;

            default:
                // Stop for unrecognized command
                Icd.clear();
                Icd.print("Invalid Command"); 
                digitalWrite(motor1Dir1, LOW);   
                digitalWrite(motor1Dir2, LOW);   
                digitalWrite(motor2Dir1, LOW);   
                digitalWrite(motor2Dir2, LOW);   
                digitalWrite(motor3Dir1, LOW);   
                digitalWrite(motor3Dir2, LOW);   
                digitalWrite(motor4Dir1, LOW);   
                digitalWrite(motor4Dir2, LOW);   
                break;
        }
    }
}