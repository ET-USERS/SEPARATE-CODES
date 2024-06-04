#include <AFMotor.h> // Include the Adafruit Motor Shield library

// Number of steps per output rotation
// Change this as per your motor's specification, 200 for NEMA-17
const int stepsPerRevolution = 200;

// Create an instance of the stepper motor on port #2 (M3 and M4)
AF_Stepper motor(stepsPerRevolution, 2);

void setup()
{
    Serial.begin(9600); // Initialize serial communication at a baud rate of 9600
    Serial.println("Stepper test!");

    motor.setSpeed(10); // Set the motor speed to 10 rpm
}

void loop()
{
    Serial.println("Single coil steps");
    motor.step(100, FORWARD, SINGLE);  // Move 100 steps forward with single coil activation
    motor.step(100, BACKWARD, SINGLE); // Move 100 steps backward with single coil activation

    Serial.println("Double coil steps");
    motor.step(100, FORWARD, DOUBLE);  // Move 100 steps forward with double coil activation
    motor.step(100, BACKWARD, DOUBLE); // Move 100 steps backward with double coil activation

    Serial.println("Interleave coil steps");
    motor.step(100, FORWARD, INTERLEAVE);  // Move 100 steps forward with interleaved coil activation
    motor.step(100, BACKWARD, INTERLEAVE); // Move 100 steps backward with interleaved coil activation

    Serial.println("Microstep steps");
    motor.step(100, FORWARD, MICROSTEP);  // Move 100 steps forward with microstep activation
    motor.step(100, BACKWARD, MICROSTEP); // Move 100 steps backward with microstep activation
}
