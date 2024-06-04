#include <Servo.h> // Include the Servo library

Servo myservo; // Create a servo object to control a servo
int pos = 0;   // Variable to store the servo position

void setup()
{
    // Attach the servo on pin 10 to the servo object
    myservo.attach(10);
}

void loop()
{
    // Sweep from 0 degrees to 180 degrees
    for (pos = 0; pos <= 180; pos += 1)
    {
        myservo.write(pos); // Set the servo position
        delay(15);          // Wait for a short period
    }

    // Sweep from 180 degrees to 0 degrees
    for (pos = 180; pos >= 0; pos -= 1)
    {
        myservo.write(pos); // Set the servo position
        delay(15);          // Wait for a short period
    }
}
