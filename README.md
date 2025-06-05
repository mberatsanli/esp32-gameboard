# Game Board Project

> 🚧 This project is currently under development. Features and documentation may change.

This project implements a game board using an ESP32 microcontroller with an ILI9341 LCD display and button controls.

## Setup and Build Commands

```bash
# Upload firmware to device
pio run --target upload

# Clean build files
pio run --target clean

# List available serial ports
ls /dev/tty.*
```

## Hardware Connections

### LCD ILI9341 Display

![ILI9341 Pin Connections](docs/images/hardware/ili9341-pins.png)

| Pin name | Target Pin |
| -------- | ---------- |
| Led      | 3.3v       |
| SCK      | D18        |
| SDI      | D23        |
| DC       | D2         |
| Reset    | D4         |
| CS       | D5         |
| GND      | GND        |
| VCC      | 3.3v       |

### Button Controls

#### Navigation Buttons
- **Up Button**: D12
- **Down Button**: D13
- **Action Button**: D14

## Development

This project is built using PlatformIO. Make sure you have PlatformIO installed in your development environment before building or uploading the firmware.