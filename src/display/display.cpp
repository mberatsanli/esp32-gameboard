#include "display/display.h"

// Global ekran nesnesi
Adafruit_ILI9341 tft(TFT_CS, TFT_DC, TFT_RST);

void initDisplay() {
    tft.begin();
    tft.setRotation(0); // Landscape mode
    tft.fillScreen(ILI9341_BLACK);
}

void drawCenteredText(const char* text, int y, uint16_t color, uint8_t size) {
    tft.setTextSize(size);
    tft.setTextColor(color);
    int16_t x1, y1;
    uint16_t w, h;
    tft.getTextBounds(text, 0, y, &x1, &y1, &w, &h);
    int x = (tft.width() - w) / 2;
    tft.setCursor(x, y);
    tft.print(text);
}

void drawMenuItem(const char* text, int index, bool isSelected) {
    int x = 20;
    int y = 60 + index * 40;  // Less vertical spacing on screen
    int w = tft.width() - 2 * x;
    int h = 30;  // Smaller buttons on vertical screen

    if (isSelected) {
        tft.fillRoundRect(x, y, w, h, 8, ILI9341_YELLOW);
        drawCenteredText(text, y + 8, ILI9341_BLACK);  // Text pozisyonunu ayarla
    } else {
        tft.fillRoundRect(x, y, w, h, 8, ILI9341_BLACK);
        tft.drawRoundRect(x, y, w, h, 8, ILI9341_WHITE);
        drawCenteredText(text, y + 8, ILI9341_WHITE);  // Text pozisyonunu ayarla
    }
}

void updateMenuSelection(int previous, int current, const char** items, int itemCount) {
    drawMenuItem(items[previous], previous, false);
    drawMenuItem(items[current], current, true);
}