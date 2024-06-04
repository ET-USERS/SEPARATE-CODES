#include <tcs3200.h> // Include the TCS3200 library

// Variables to store color values
int r, g, b;

// Create a TCS3200 object with specified pins
// (S0, S1, S2, S3, output pin)
tcs3200 tcs(4, 5, 6, 7, 8);

void setup()
{
    // Initialize serial communication at a baud rate of 9600
    Serial.begin(9600);
}

void loop()
{
    // Read the red color value from the sensor
    r = tcs.colorRead('r');
    Serial.print("R= ");
    Serial.print(r);
    Serial.print(" ");

    // Read the green color value from the sensor
    g = tcs.colorRead('g');
    Serial.print("G= ");
    Serial.print(g);
    Serial.print(" ");

    // Read the blue color value from the sensor
    b = tcs.colorRead('b');
    Serial.print("B= ");
    Serial.print(b);
    Serial.print(" ");

    // Determine the dominant color and print its name
    String colorName = getDominantColorName(r, g, b);
    Serial.println(colorName);

    // Wait for 200 milliseconds before repeating the loop
    delay(200);
}

// Function to determine the dominant color
String getDominantColorName(uint8_t r, uint8_t g, uint8_t b)
{
    if (r > g && r > b)
    {
        return "RED";
    }
    else if (g > r && g > b)
    {
        return "GREEN";
    }
    else if (b > r && b > g)
    {
        return "BLUE";
    }
    else
    {
        return "Unknown";
    }
}
