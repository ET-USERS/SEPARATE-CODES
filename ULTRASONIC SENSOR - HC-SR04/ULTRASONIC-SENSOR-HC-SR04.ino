const int trigPin = 9;  // Pin for the trigger signal of the ultrasonic sensor
const int echoPin = 10; // Pin for the echo signal of the ultrasonic sensor

// Variables to store the duration of the echo signal and the calculated distance
long duration;
int distance;

void setup()
{
    // Set the trigPin as an OUTPUT
    pinMode(trigPin, OUTPUT);
    // Set the echoPin as an INPUT
    pinMode(echoPin, INPUT);
    // Initialize serial communication at a baud rate of 9600
    Serial.begin(9600);
}

void loop()
{
    // Ensure the trigger pin is set LOW initially
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // Generate a 10-microsecond HIGH pulse to trigger the ultrasonic sensor
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Measure the duration of the pulse from the echo pin
    duration = pulseIn(echoPin, HIGH);

    // Calculate the distance based on the duration of the echo signal
    // Speed of sound is approximately 0.034 cm/microsecond
    // Divide by 2 because the signal travels to the obstacle and back
    distance = duration * 0.034 / 2;

    // Print the calculated distance to the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);

    // Optional: Add a short delay before the next measurement
    delay(100); // 100 milliseconds
}
