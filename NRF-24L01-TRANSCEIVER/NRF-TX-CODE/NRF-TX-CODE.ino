#include <Arduino.h> // Include the Arduino core library
#include <SPI.h>     // Include the SPI library
#include <RF24.h>    // Include the RF24 library

// Define RF24 radio object with CE and CSN pins
RF24 radio(7, 8); // CE, CSN pins

// Define the address for the radio communication
const byte address[6] = "00001"; // 5-byte address

// Function to send a message via the radio
void sendMessage(String msg)
{
    radio.stopListening();                  // Stop listening before sending
    radio.write(msg.c_str(), msg.length()); // Send the message
    radio.startListening();                 // Start listening again after sending
}

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
    // Send and print "F" to the serial monitor
    sendMessage("F");
    Serial.println("F");
    delay(500);

    // Send and print "B" to the serial monitor
    sendMessage("B");
    Serial.println("B");
    delay(500);

    // Send and print "L" to the serial monitor
    sendMessage("L");
    Serial.println("L");
    delay(500);

    // Send and print "R" to the serial monitor
    sendMessage("R");
    Serial.println("R");
    delay(500);

    // Send and print "S" to the serial monitor
    sendMessage("S");
    Serial.println("S");
    delay(500);
}
