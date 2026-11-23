# GP2040-CE Board Configuration for Bitfunx FightingBox V1.0

Stickless (hitbox-style) controller based on a Raspberry Pi Pico (RP2040) with a 128x64 I2C OLED.

## Pin mapping

| GPIO | Action | GPIO | Action |
|-----:|--------|-----:|--------|
| 0  | Left  | 11 | B1 |
| 1  | Up    | 12 | B2 |
| 2  | Down  | 13 | R2 |
| 3  | Right | 14 | L2 |
| 4  | A1 (Home) | 21 | L3 |
| 5  | S1 (Select) | 22 | R3 |
| 6  | S2 (Start)  | 28 | A2 (Capture) |
| 7  | B3 | 26 | OLED SDA (I2C1) |
| 8  | B4 | 27 | OLED SCL (I2C1) |
| 9  | R1 | | |
| 10 | L1 | | |

## Display

- SSD1306 128x64, address `0x3C`, I2C1 @ 400 kHz
- Custom board layouts (left/right) matching the physical button positions
- Custom static splash screen (2.5 s)

![Splash screen](assets/splash.png)

`assets/splash.png` is the 128x64 1-bit source of `DEFAULT_SPLASH` (row-major, MSB = leftmost pixel).
