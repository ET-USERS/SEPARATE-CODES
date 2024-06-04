//==========================Libraries========================================
#include <DWIN.h>
#include <Servo.h>

//========================DWIN HMI PINS BUAD RATE=========================
#define DGUS_BAUD 115200
#define DGUS_RX 10 // Digital
#define DGUS_TX 11 // Digital

//=========================== ULTRASONIC SENSOR PINS========================
#define TRIGGER_PIN 47 // Digital
#define ECHO_PIN 45    // Digital

//===================== VP ADDRESSES=======================================
long SONAR_VP_ADDRESS_Int = 0x1000;
String SERVO_VP_ADDRESS = "1054";

//========================== OBJECTS INITIALIZATION=========================
DWIN hmi(DGUS_RX, DGUS_TX, DGUS_BAUD);
Servo myServo; // Initialize Servo object
// Servo object needs to be declared before using it.

//===================== CALL BACK FUNCTION=================================
void onHMIEvent(String address, int lastByte, String messege, String response)
{
    Serial.println("OnEvent : [ A : " + address + " | D : " + String(lastByte, HEX) + " | M : " + messege + " | R : " + response + " ]");
}

//=========================SETUP===================================
void setup()
{
    hmi.echoEnabled(false);
    hmi.setPage(3);
    hmi.hmiCallBack(onHMIEvent);
    int arg = hmi.getPage();
    Serial.begin(115200);
    Serial.print("HMI PAGE IS: ");
    Serial.println(hmi.getPage());

    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    myServo.attach(9); // Attach servo to pin 9
}

void loop()
{
    //*****************************ULTRASONIC SENSOR********************************
    if (hmi.getPage() == 14)
    {
        digitalWrite(TRIGGER_PIN, LOW);
        delayMicroseconds(2);
        digitalWrite(TRIGGER_PIN, HIGH);
        delayMicroseconds(10);
        digitalWrite(TRIGGER_PIN, LOW);
        float duration = pulseIn(ECHO_PIN, HIGH);
        float distance = duration * 0.034 / 2.000;
        hmi.setVP(SONAR_VP_ADDRESS_Int, distance);
        // Serial.print("SONAR_VP_ADDRESS_Int :");
        // Serial.println(distance);
    }
}
