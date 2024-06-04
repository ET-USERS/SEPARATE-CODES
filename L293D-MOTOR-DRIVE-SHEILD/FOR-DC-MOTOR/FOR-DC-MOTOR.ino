#include <AFMotor.h> // Include the Adafruit Motor Shield library

AF_DCMotor motor(4); // Create an instance of the motor on port 4

void setup()
{
    // Set the initial speed of the motor and stop it
    motor.setSpeed(200);
    motor.run(RELEASE);
}

void loop()
{
    uint8_t i; // Variable to use in the loops

    // Turn on the motor and run it forward
    motor.run(FORWARD);

    // Accelerate from zero to maximum speed
    for (i = 0; i < 255; i++)
    {
        motor.setSpeed(i);
        delay(10);
    }

    // Decelerate from maximum speed to zero
    for (i = 255; i != 0; i--)
    {
        motor.setSpeed(i);
        delay(10);
    }

    // Change motor direction to backward
    motor.run(BACKWARD);

    // Accelerate from zero to maximum speed
    for (i = 0; i < 255; i++)
    {
        motor.setSpeed(i);
        delay(10);
    }

    // Decelerate from maximum speed to zero
    for (i = 255; i != 0; i--)
    {
        motor.setSpeed(i);
        delay(10);
    }

    // Turn off the motor
    motor.run(RELEASE);
    delay(1000); // Wait for a second before repeating the loop
}
