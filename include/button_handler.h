#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H

#include <Arduino.h>

#define BUTTON_UP 12     // D12
#define BUTTON_DOWN 13   // D13
#define BUTTON_ACTION 14 // D14
#define BUTTON_LEFT 27   // D27
#define BUTTON_RIGHT 26  // D26

class Button {
  private:
    uint8_t pin;
    bool pressed;
    unsigned long lastPressTime;
    static const unsigned long DEBOUNCE_TIME = 200;

  public:
    Button(uint8_t buttonPin);
    bool isPressed();
};

class Buttons {
  public:
    Button up;
    Button down;
    Button left;
    Button right;
    Button action;
    Buttons();
};

extern Buttons buttons;

#endif