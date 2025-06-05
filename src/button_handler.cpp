#include "button_handler.h"

Button::Button(uint8_t buttonPin) : pin(buttonPin), pressed(false), lastPressTime(0) {
    pinMode(pin, INPUT_PULLUP);
}

bool Button::isPressed() {
    unsigned long currentTime = millis();
    int buttonState = digitalRead(pin);
    
    if (buttonState == LOW) {
        if (!pressed && (currentTime - lastPressTime > DEBOUNCE_TIME)) {
            pressed = true;
            lastPressTime = currentTime;
            return true;
        }
    } else {
        pressed = false;
    }

    return false;
}

Buttons::Buttons() : up(BUTTON_UP), down(BUTTON_DOWN), action(BUTTON_ACTION) {}

Buttons buttons;