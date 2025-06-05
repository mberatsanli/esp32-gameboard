#ifndef SCREEN_H
#define SCREEN_H

#include <Arduino.h>

class Screen {
public:
    virtual void init() = 0;      // Called when screen is first opened
    virtual void loop() = 0;      // Called every frame
    virtual ~Screen() = default;  // Virtual destructor
};

#endif