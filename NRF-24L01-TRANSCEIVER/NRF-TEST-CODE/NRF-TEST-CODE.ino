/*
 If your serial output has these values same then your NRF24L01 module is in working
 condition:

 EN_AA = 0x3f
 EN_RXADDR = 0x02
 RF_CH = 0x4c
 RF_SETUP = 0x03
 CONFIG = 0x0f
*/

#include <SPI.h>    // Include the SPI library
#include <RF24.h>   // Include the RF24 library
#include <printf.h> // Include the printf library

// Create an RF24 object with CE and CSN pins
RF24 radio(7, 8);

// Define addresses for the two nodes
byte addresses[][6] = {"1Node", "2Node"};

void setup()
{
    // Initialize the radio
    radio.begin();

    // Set the power level to low
    radio.setPALevel(RF24_PA_LOW);

    // Open a writing pipe on the first address
    radio.openWritingPipe(addresses[0]);

    // Open a reading pipe on the second address
    radio.openReadingPipe(1, addresses[1]);

    // Start listening on the opened reading pipe
    radio.startListening();

    // Initialize serial communication at a baud rate of 115200
    Serial.begin(115200);

    // Initialize printf function for RF24 library
    printf_begin();

    // Print the details of the radio module to the serial monitor
    radio.printDetails();
}

void loop()
{
    // The loop function is empty in this example
    // Add code here if you want to perform any actions in the main loop
}
