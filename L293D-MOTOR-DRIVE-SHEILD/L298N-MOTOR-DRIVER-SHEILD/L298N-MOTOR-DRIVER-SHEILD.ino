// Motor A connections
int enA = 9; // Enable pin for Motor A
int in1 = 8; // Input 1 pin for Motor A
int in2 = 7; // Input 2 pin for Motor A

// Motor B connections
int enB = 3; // Enable pin for Motor B
int in3 = 5; // Input 3 pin for Motor B
int in4 = 4; // Input 4 pin for Motor B

void setup()
{
    // Set all the motor control pins to outputs
    pinMode(enA, OUTPUT); // Enable pin A as output
    pinMode(enB, OUTPUT); // Enable pin B as output
    pinMode(in1, OUTPUT); // Input 1 pin for Motor A as output
    pinMode(in2, OUTPUT); // Input 2 pin for Motor A as output
    pinMode(in3, OUTPUT); // Input 3 pin for Motor B as output
    pinMode(in4, OUTPUT); // Input 4 pin for Motor B as output

    // Turn off motors - Initial state
    digitalWrite(in1, LOW); // Set Input 1 for Motor A to low
    digitalWrite(in2, LOW); // Set Input 2 for Motor A to low
    digitalWrite(in3, LOW); // Set Input 3 for Motor B to low
    digitalWrite(in4, LOW); // Set Input 4 for Motor B to low
}

// Main loop function
void loop()
{
    // Call directionControl function
    directionControl();
    // Delay for 1 second
    delay(1000);
    // Call speedControl function
    speedControl();
    // Delay for 1 second
    delay(1000);
}

// This function lets you control the spinning direction of motors
void directionControl()
{
    // Set motors to maximum speed
    // For PWM, maximum possible values are 0 to 255
    analogWrite(enA, 255);
    analogWrite(enB, 255);

    // Turn on motor A & B
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    // Delay for 2 seconds
    delay(2000);

    // Now change motor directions
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    // Delay for 2 seconds
    delay(2000);

    // Turn off motors
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

// This function lets you control speed of the motors
void speedControl()
{
    // Turn on motors
    digitalWrite(in1, LOW);  // Set the first motor direction
    digitalWrite(in2, HIGH); // Set the first motor direction
    digitalWrite(in3, LOW);  // Set the second motor direction
    digitalWrite(in4, HIGH); // Set the second motor direction

    // Accelerate from zero to maximum speed
    for (int i = 0; i < 256; i++)
    {
        analogWrite(enA, i); // Set the PWM (Pulse Width Modulation) value for motor A
        analogWrite(enB, i); // Set the PWM (Pulse Width Modulation) value for motor B
        delay(20);           // Delay to control the speed increment
    }

    // Decelerate from maximum speed to zero
    for (int i = 255; i >= 0; --i)
    {
        analogWrite(enA, i); // Set the PWM (Pulse Width Modulation) value for motor A
        analogWrite(enB, i); // Set the PWM (Pulse Width Modulation) value for motor B
        delay(20);           // Delay to control the speed decrement
    }

    // Now turn off motors
    digitalWrite(in1, LOW); // Turn off the first motor
    digitalWrite(in2, LOW); // Turn off the first motor
    digitalWrite(in3, LOW); // Turn off the second motor
    digitalWrite(in4, LOW); // Turn off the second motor
}
