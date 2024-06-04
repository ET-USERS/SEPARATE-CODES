// Define constants for the pin numbers
#define s1 2
#define s2 3
#define s3 4
#define s4 5
#define s5 6

// Setup function runs once when the microcontroller starts
void setup()
{
    // Initialize serial communication at a baud rate of 9600
    Serial.begin(9600);

    // Set the pin modes for the sensor pins to INPUT_PULLUP
    // This configures the pins to read input and enables the internal pull-up resistors
    pinMode(s1, INPUT_PULLUP);
    pinMode(s2, INPUT_PULLUP);
    pinMode(s3, INPUT_PULLUP);
    pinMode(s4, INPUT_PULLUP);
    pinMode(s5, INPUT_PULLUP);
}

// Loop function runs continuously after setup
void loop()
{
    // Read the value from sensor pin s1
    int ReadS1 = digitalRead(s1);
    // Print the value read from sensor s1 to the serial monitor
    Serial.print("S1 value is=");
    Serial.println(ReadS1);

    // Read the value from sensor pin s2
    int ReadS2 = digitalRead(s2);
    // Print the value read from sensor s2 to the serial monitor
    Serial.print("S2 value is=");
    Serial.println(ReadS2);

    // Read the value from sensor pin s3
    int ReadS3 = digitalRead(s3);
    // Print the value read from sensor s3 to the serial monitor
    Serial.print("S3 value is=");
    Serial.println(ReadS3);

    // Read the value from sensor pin s4
    int ReadS4 = digitalRead(s4);
    // Print the value read from sensor s4 to the serial monitor
    Serial.print("S4 value is=");
    Serial.println(ReadS4);

    // Read the value from sensor pin s5
    int ReadS5 = digitalRead(s5);
    // Print the value read from sensor s5 to the serial monitor
    Serial.print("S5 value is=");
    Serial.println(ReadS5);

    // Wait for 100 milliseconds before repeating the loop
    delay(100);
}
