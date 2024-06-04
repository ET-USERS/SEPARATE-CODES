// Include the necessary libraries
#include <SPI.h>
#include <RF24.h>

// Define RF24 radio object with CE and CSN pins
RF24 radio(7, 8);

// Define the address for the radio communication
const byte address[6] = "00001";

// Global variables
char signalMessage[100]; // Buffer to store the received message
String condition = "";   // String to store the processed message

// Function to receive and process messages
void receiveMessage()
{
    // Create a temporary buffer for the received message
    char tempMessage[sizeof(signalMessage)];

    // Read the message into the temporary buffer
    radio.read(tempMessage, sizeof(tempMessage));

    // Check if the received message is not an empty string
    if (strlen(tempMessage) > 0)
    {
        // If the message is not empty, update signalMessage and perform any other processing
        strcpy(signalMessage, tempMessage);
        condition = signalMessage;
        condition.toLowerCase();

        // Place any additional processing code here that should only execute when the message is not empty
    }
}

// Define constants for BLACK and WHITE (can be used for additional processing)
#define BLACK 0
#define WHITE 1

void setup()
{
    // Initialize serial communication at a baud rate of 9600
    Serial.begin(9600);

    // Initialize the radio
    radio.begin();

    // Open a writing pipe on the defined address
    radio.openWritingPipe(address);

    // Open a reading pipe on the defined address
    radio.openReadingPipe(1, address);

    // Set the power level to low
    radio.setPALevel(RF24_PA_LOW);

    // Start listening on the opened reading pipe
    radio.startListening();
}

void loop()
{
    // Check if there is data available to read from the radio
    if (radio.available())
    {
        // If data is available, receive and process the message
        receiveMessage();

        // Print the processed message to the serial monitor
        Serial.println(condition);
    }
}
