#include <Arduino.h>
#include <BleKeyboard.h>
// Change the below values if desired
#define BUTTON_PIN 14

// define variables
BleKeyboard bleKeyboard;
bool BleMsgSent;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200, SERIAL_8N1);
  Serial.end();
  Serial.begin(115200, SERIAL_8N1);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();

  // configure pin for button
  pinMode(BUTTON_PIN, INPUT_PULLDOWN);

}

void loop() {
   if(bleKeyboard.isConnected()) {
    // put your main code here, to run repeatedly:
    Serial.println("Bluetooth connected!");

    bool buttonPressed = digitalRead(BUTTON_PIN);

    if (buttonPressed == true)
    {
      //Serial.println("Button pressed");
      if (BleMsgSent == false)
      {
        Serial.println("Message Sent");
        // bleKeyboard.print("Hello World");
        bleKeyboard.write(KEY_PAGE_DOWN);
      }
      BleMsgSent = true;
    }
    else
    {
      //Serial.println("Button released");
      BleMsgSent = false;
    }

    delay(100);
   }
}
