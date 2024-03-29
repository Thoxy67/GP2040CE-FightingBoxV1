/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: Copyright (c) 2024 Thoxy (thoxy.xyz)
*/

#ifndef PICO_BOARD_CONFIG_H_
#define PICO_BOARD_CONFIG_H_

#include "enums.pb.h"
#define BOARD_CONFIG_LABEL "FightingBox V1"

// Main pin mapping Configuration
//                        // GP2040 | Xinput | Switch  | PS3/4/5  | Dinput | Arcade |
#define PIN_DPAD_UP 1     // UP     | UP     | UP      | UP       | UP     | UP     |
#define PIN_DPAD_DOWN 2   // DOWN   | DOWN   | DOWN    | DOWN     | DOWN   | DOWN   |
#define PIN_DPAD_RIGHT 3  // RIGHT  | RIGHT  | RIGHT   | RIGHT    | RIGHT  | RIGHT  |
#define PIN_DPAD_LEFT 0   // LEFT   | LEFT   | LEFT    | LEFT     | LEFT   | LEFT   |
#define PIN_BUTTON_B1 11  // B1     | A      | B       | Cross    | 2      | K1     |
#define PIN_BUTTON_B2 12  // B2     | B      | A       | Circle   | 3      | K2     |
#define PIN_BUTTON_R2 13  // R2     | RT     | ZR      | R2       | 8      | K3     |
#define PIN_BUTTON_L2 14  // L2     | LT     | ZL      | L2       | 7      | K4     |
#define PIN_BUTTON_B3 7   // B3     | X      | Y       | Square   | 1      | P1     |
#define PIN_BUTTON_B4 8   // B4     | Y      | X       | Triangle | 4      | P2     |
#define PIN_BUTTON_R1 9   // R1     | RB     | R       | R1       | 6      | P3     |
#define PIN_BUTTON_L1 10  // L1     | LB     | L       | L1       | 5      | P4     |
#define PIN_BUTTON_S1 5   // S1     | Back   | Minus   | Select   | 9      | Coin   |
#define PIN_BUTTON_S2 6   // S2     | Start  | Plus    | Start    | 10     | Start  |
#define PIN_BUTTON_L3 21  // L3     | LS     | LS      | L3       | 11     | LS     |
#define PIN_BUTTON_R3 22  // R3     | RS     | RS      | R3       | 12     | RS     |
#define PIN_BUTTON_A1 4   // A1     | Guide  | Home    | PS       | 13     | ~      |
#define PIN_BUTTON_A2 -1  // A2     | ~      | Capture | ~        | 14     | ~      |
#define PIN_BUTTON_FN -1  // Hotkey Function

// Keyboard Mapping Configuration
//                                            // GP2040 | Xinput | Switch  | PS3/4/5  | Dinput | Arcade |
#define KEY_DPAD_UP     HID_KEY_ARROW_UP      // UP     | UP     | UP      | UP       | UP     | UP     |
#define KEY_DPAD_DOWN   HID_KEY_ARROW_DOWN    // DOWN   | DOWN   | DOWN    | DOWN     | DOWN   | DOWN   |
#define KEY_DPAD_RIGHT  HID_KEY_ARROW_RIGHT   // RIGHT  | RIGHT  | RIGHT   | RIGHT    | RIGHT  | RIGHT  |
#define KEY_DPAD_LEFT   HID_KEY_ARROW_LEFT    // LEFT   | LEFT   | LEFT    | LEFT     | LEFT   | LEFT   |
#define KEY_BUTTON_B1   HID_KEY_SHIFT_LEFT    // B1     | A      | B       | Cross    | 2      | K1     |
#define KEY_BUTTON_B2   HID_KEY_Z             // B2     | B      | A       | Circle   | 3      | K2     |
#define KEY_BUTTON_R2   HID_KEY_X             // R2     | RT     | ZR      | R2       | 8      | K3     |
#define KEY_BUTTON_L2   HID_KEY_V             // L2     | LT     | ZL      | L2       | 7      | K4     |
#define KEY_BUTTON_B3   HID_KEY_CONTROL_LEFT  // B3     | X      | Y       | Square   | 1      | P1     |
#define KEY_BUTTON_B4   HID_KEY_ALT_LEFT      // B4     | Y      | X       | Triangle | 4      | P2     |
#define KEY_BUTTON_R1   HID_KEY_SPACE         // R1     | RB     | R       | R1       | 6      | P3     |
#define KEY_BUTTON_L1   HID_KEY_C             // L1     | LB     | L       | L1       | 5      | P4     |
#define KEY_BUTTON_S1   HID_KEY_5             // S1     | Back   | Minus   | Select   | 9      | Coin   |
#define KEY_BUTTON_S2   HID_KEY_1             // S2     | Start  | Plus    | Start    | 10     | Start  |
#define KEY_BUTTON_L3   HID_KEY_EQUAL         // L3     | LS     | LS      | L3       | 11     | LS     |
#define KEY_BUTTON_R3   HID_KEY_MINUS         // R3     | RS     | RS      | R3       | 12     | RS     |
#define KEY_BUTTON_A1   HID_KEY_9             // A1     | Guide  | Home    | PS       | 13     | ~      |
#define KEY_BUTTON_A2   HID_KEY_F2            // A2     | ~      | Capture | ~        | 14     | ~      |
#define KEY_BUTTON_FN   -1                    // Hotkey Function        

#define PIN_BUTTON_TURBO 18  // Turbo

#define HAS_I2C_DISPLAY 1
#define I2C_SDA_PIN 26
#define I2C_SCL_PIN 27
#define I2C_BLOCK i2c1
#define I2C_SPEED 400000

#define BUTTON_LAYOUT BUTTON_LAYOUT_STICKLESS
#define BUTTON_LAYOUT_RIGHT BUTTON_LAYOUT_STICKLESSB
#define SPLASH_MODE SPLASH_MODE_STATIC
#define SPLASH_DURATION 2000

// For details on this, see:
// https://gp2040-ce.info/#/development?id=i2c-display-splash
#define DEFAULT_SPLASH                                                     \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x80,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x01, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0x1E,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x07, 0xFE, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFC, 0x3F, 0xC0, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x7F,  \
  0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x18, 0x7F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0xFF, 0xC0, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0xFF,  \
  0x87, 0x00, 0x00, 0x01, 0x80, 0x01, 0xC0, 0x00, 0x18, 0x00, 0x00, 0x00,  \
  0x00, 0x7F, 0xC0, 0x7F, 0x87, 0x80, 0x03, 0xF9, 0xC0, 0x01, 0xC0, 0x00,  \
  0x38, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xF0, 0x1F, 0x0F, 0xE0, 0x03, 0xF9,  \
  0xC0, 0x01, 0xC0, 0x0C, 0x38, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFC, 0x06,  \
  0x1F, 0xE0, 0x03, 0xF8, 0x00, 0x01, 0xC0, 0x1C, 0x00, 0x00, 0x00, 0x00,  \
  0x01, 0xFF, 0xFF, 0x00, 0x1F, 0xE0, 0x03, 0x81, 0xC7, 0xF9, 0xFE, 0x3F,  \
  0x39, 0xFE, 0x0F, 0x60, 0x03, 0xFF, 0xFF, 0xC0, 0x3F, 0xE0, 0x03, 0x81,  \
  0xCF, 0xF9, 0xFF, 0x3F, 0xB9, 0xFF, 0x1F, 0xE0, 0x03, 0xFF, 0xFF, 0xF0,  \
  0x7F, 0xC3, 0x83, 0xF9, 0xCF, 0x79, 0xE7, 0x1C, 0x39, 0xE7, 0x3C, 0xE0,  \
  0x07, 0xFF, 0xFF, 0xF0, 0x7F, 0xC7, 0xE3, 0xF9, 0xCE, 0x39, 0xC7, 0x1C,  \
  0x39, 0xE7, 0xB8, 0xE0, 0x0F, 0xFF, 0xFF, 0xF0, 0xFF, 0x87, 0xF3, 0xF9,  \
  0xCE, 0x39, 0xC7, 0x1C, 0x39, 0xC7, 0xB8, 0x60, 0x0F, 0xFF, 0xFF, 0xE1,  \
  0xFF, 0x0F, 0xF3, 0x81, 0xCE, 0x39, 0xC7, 0x1C, 0x39, 0xC7, 0xB8, 0x60,  \
  0x1F, 0xFF, 0xFF, 0xE1, 0xFF, 0x1F, 0xF3, 0x81, 0xCE, 0x39, 0xC7, 0x1C,  \
  0x39, 0xC7, 0xBC, 0xE0, 0x3F, 0xFF, 0xFF, 0x83, 0xFE, 0x1F, 0xF3, 0x81,  \
  0xCF, 0xF9, 0xC7, 0x1F, 0x39, 0xC7, 0x9F, 0xE0, 0x3F, 0xF0, 0x00, 0x01,  \
  0xFC, 0x3F, 0xE3, 0x81, 0xC7, 0xF9, 0xC7, 0x1F, 0xB9, 0xC7, 0x9F, 0xE0,  \
  0x3F, 0xF0, 0x00, 0x00, 0xFC, 0x7F, 0xC3, 0x01, 0xC3, 0xB9, 0xC7, 0x0F,  \
  0x38, 0xC3, 0x0F, 0xE0, 0x3F, 0xFC, 0x00, 0x00, 0x38, 0x7F, 0xC0, 0x00,  \
  0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x1F, 0xFF, 0xFC, 0x38,  \
  0x00, 0xFF, 0x80, 0x00, 0x0E, 0x78, 0x00, 0x00, 0x00, 0x00, 0x1D, 0xE0,  \
  0x0F, 0xFF, 0xFE, 0x3E, 0x00, 0xFF, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0x00,  \
  0x00, 0x00, 0x1F, 0xC0, 0x07, 0xFF, 0xFE, 0x1F, 0x80, 0x7F, 0x00, 0x00,  \
  0x07, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x80, 0x07, 0xFF, 0xFF, 0x1F,  \
  0xF0, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x03, 0xFF, 0xFF, 0x0F, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0x8F, 0xFF, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x87,  \
  0xFF, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0xFF, 0xFF, 0xC7, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xC3, 0xFF, 0xFF, 0x80, 0x00,  \
  0x00, 0x0F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xE3,  \
  0xFF, 0xFF, 0x80, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x1F, 0xFF, 0xE1, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x0E, 0x78, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xFF, 0xF1, 0xFF, 0xFF, 0x80, 0x00,  \
  0x00, 0x0E, 0x38, 0x7E, 0x71, 0xC0, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xF0,  \
  0xFF, 0xFF, 0x80, 0x00, 0x00, 0x0E, 0x38, 0xFF, 0x3B, 0xC0, 0x00, 0x00,  \
  0x00, 0x07, 0xFF, 0xF8, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x0F, 0xF1, 0xE7,  \
  0x3F, 0x80, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xF8, 0x7F, 0xFF, 0x80, 0x00,  \
  0x00, 0x0F, 0xF9, 0xC7, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFC,  \
  0x7F, 0xFF, 0x00, 0x00, 0x00, 0x0E, 0x39, 0xC7, 0x0F, 0x00, 0x00, 0x00,  \
  0x00, 0x01, 0xFF, 0xFC, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x0E, 0x3D, 0xC7,  \
  0x1F, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00,  \
  0x00, 0x0E, 0x3D, 0xC7, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF,  \
  0xFF, 0xFC, 0x00, 0x00, 0x00, 0x0F, 0xF9, 0xFF, 0x3B, 0xC0, 0x00, 0x00,  \
  0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x0F, 0xF0, 0xFE,  \
  0x79, 0xC0, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00,  \
  0x00, 0x0F, 0xC0, 0x3C, 0x70, 0xC0, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF,  \
  0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF,  \
  0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFF,  \
  0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xFF,  \
  0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF,  \
  0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0x00

#endif