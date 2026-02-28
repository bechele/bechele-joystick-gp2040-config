// configs/BecheleJoystick/BoardConfig.h

#ifndef BOARD_CONFIG_H_
#define BOARD_CONFIG_H_

#include "enums.pb.h"
#include "class/hid/hid.h"

// Board-Identification
#define BOARD_CONFIG_LABEL "Bechele Joystick"

// ===== This is the smoothing factor =====
// For analog Axes - Smoothingfaktor 2
// #define ANALOG_SMOOTHING_FACTOR 2

// ===== PIN-assignment =====

// Joystick-Axes
//#define GPIO_PIN_26  GpioAction::ANALOG_UP     // z.B. GPIO 26
//#define GPIO_PIN_27  GpioAction::ANALOG_DOWN   // z.B. GPIO 27
//#define GPIO_PIN_29  GpioAction::ANALOG_LEFT   // z.B. GPIO 28
//#define GPIO_PIN_29  GpioAction::ANALOG_RIGHT  // z.B. GPIO 29

// Buttons
#define GPIO_PIN_06 GpioAction::BUTTON_PRESS_B1  // GPIO 6
#define GPIO_PIN_07 GpioAction::BUTTON_PRESS_B2  // GPIO 7
#define GPIO_PIN_08 GpioAction::BUTTON_PRESS_B3  // GPIO 8
#define GPIO_PIN_14 GpioAction::BUTTON_PRESS_S2  // Webconfig mode button
#define KEY_DPAD_UP     -1
#define KEY_DPAD_DOWN   -1
#define KEY_DPAD_RIGHT  -1
#define KEY_DPAD_LEFT   -1
#define KEY_BUTTON_R2   -1
#define KEY_BUTTON_L2   -1
#define KEY_BUTTON_B4   -1
#define KEY_BUTTON_R1   -1
#define KEY_BUTTON_L1   -1
#define KEY_BUTTON_S1   -1
#define KEY_BUTTON_L3   -1
#define KEY_BUTTON_R3   -1
#define KEY_BUTTON_A1   -1
#define KEY_BUTTON_A2   -1
#define KEY_BUTTON_FN   -1
#define KEY_BUTTON_S2   HID_KEY_1
#define KEY_BUTTON_B3   HID_KEY_CONTROL_LEFT
#define KEY_BUTTON_B2   HID_KEY_Z
#define KEY_BUTTON_B1   HID_KEY_SHIFT_LEFT


#define GPIO_PIN_26 GpioAction::ASSIGNED_TO_ADDON   // Left analog stick X
#define GPIO_PIN_27 GpioAction::ASSIGNED_TO_ADDON   // Left analog stick Y

#define TURBO_ENABLED 0
#endif