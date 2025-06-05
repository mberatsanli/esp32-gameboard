#ifndef DISPLAY_H
#define DISPLAY_H

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// Pin definitions
#define TFT_CS 5 // D5
#define TFT_DC 2 // D2
#define TFT_RST 4 // D4

// Global defination of lcd
extern Adafruit_ILI9341 tft;

// Basic display functions
void initDisplay();
void drawCenteredText(const char* text, int y, uint16_t color, uint8_t size = 2);
void drawMenuItem(const char* text, int index, bool isSelected);
void updateMenuSelection(int previous, int current, const char** items, int itemCount);
void drawTitle(const char* text);

#endif