#include <Arduino.h>
#include <Bounce2.h>


// For ESP8266 boards (NodeMCU or Feather HUZZAH)
#define LED_GREEN_PIN 13

unsigned long breathe_time = millis();
int i = 0;
int breathe_delay = 10; // delay between loops

void breath(uint8_t ledPin)
{
  if ((breathe_time + breathe_delay) < millis())
  {
    breathe_time = millis();
    float val = min(255.0, max(20.0, (exp(sin(i / 3000.0 * PI * 10)) - 0.36787944) * 108.0));
    // this is the math function recreating the effect
    analogWrite(LED_GREEN_PIN, val); // PWM
    i = i + 1;
  }
}

void setup()
{
  // setup_common(connection_config, remote_url_config);
  pinMode(LED_GREEN_PIN, OUTPUT);
}

void loop()
{
  // loop_common();
  breath(LED_GREEN_PIN);
}
