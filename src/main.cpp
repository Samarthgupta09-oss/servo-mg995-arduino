#include <Arduino.h>
#include <Servo.h>
Servo myServo;
void setup() {
    // write your initialization code here
    Serial.begin(9600);
    myServo.attach(10);
    Serial.println("Servo initiate");
}

void loop() {
    // write your code here
    for (int angle = 0; angle < 180; angle += 10)
    {
        myServo.write(angle);
        Serial.print("Angle");
        Serial.println(angle);
        delay(500);
    }
    for (int angle = 180; angle >= 0; angle -= 10)
    {
        myServo.write(angle);
        Serial.print("Angle");
        Serial.println(angle);
        delay(500);
    }


}