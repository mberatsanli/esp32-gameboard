
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// Pinler
#define TFT_CS 5
#define TFT_DC 2
#define TFT_RST 4

#define BUTTON_UP 12
#define BUTTON_DOWN 13

// Ekran nesnesi
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

const char* menuItems[] = {
  "Battleship",
  "Tic-Tac-Toe",
  "Snake"
};
const int itemCount = sizeof(menuItems) / sizeof(menuItems[0]);
int selected = 0;

void drawCenteredText(const char* text, int y, uint16_t color, uint8_t size = 2) {
  tft.setTextSize(size);
  tft.setTextColor(color);
  int16_t x1, y1;
  uint16_t w, h;
  tft.getTextBounds(text, 0, y, &x1, &y1, &w, &h);
  int x = (tft.width() - w) / 2;
  tft.setCursor(x, y);
  tft.print(text);
}

void drawTitle() {
  tft.fillScreen(ILI9341_BLACK);
  drawCenteredText("ESP32 - Game Board", 20, ILI9341_WHITE, 2);
}

void drawMenuItem(int index, bool isSelected) {
  int x = 20;
  int y = 60 + index * 50;
  int w = tft.width() - 2 * x;
  int h = 35;

  if (isSelected) {
    tft.fillRoundRect(x, y, w, h, 8, ILI9341_YELLOW);
    drawCenteredText(menuItems[index], y + 10, ILI9341_BLACK);
  } else {
    tft.fillRoundRect(x, y, w, h, 8, ILI9341_BLACK);  // Arka planı temizle
    tft.drawRoundRect(x, y, w, h, 8, ILI9341_WHITE);
    drawCenteredText(menuItems[index], y + 10, ILI9341_WHITE);
  }
}

void updateMenuSelection(int previous, int current) {
  drawMenuItem(previous, false);
  drawMenuItem(current, true);
}

void setup() {
  tft.begin();
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  drawTitle();
  for (int i = 0; i < itemCount; i++) {
    drawMenuItem(i, i == selected);
  }
}

void loop() {
  static unsigned long lastPress = 0;
  unsigned long now = millis();

  if (digitalRead(BUTTON_UP) == LOW && now - lastPress > 200) {
    int previous = selected;
    selected = (selected - 1 + itemCount) % itemCount;
    updateMenuSelection(previous, selected);
    lastPress = now;
  }

  if (digitalRead(BUTTON_DOWN) == LOW && now - lastPress > 200) {
    int previous = selected;
    selected = (selected + 1) % itemCount;
    updateMenuSelection(previous, selected);
    lastPress = now;
  }
}