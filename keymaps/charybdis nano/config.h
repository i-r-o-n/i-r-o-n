#pragma once


/* handedness */
#define MASTER_RIGHT


/* trackball duration terms */
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE // enable auto pointer
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8 // layer activation sensitivity
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 6

// Enable use of pointing device on slave split.
// #define SPLIT_POINTING_ENABLE
// Pointing device is on the right split.
// #define POINTING_DEVICE_RIGHT
// Limits the frequency that the sensor is polled for motion.
// #define POINTING_DEVICE_TASK_THROTTLE_MS 1
// Invert X axis on mouse reports.
// #define POINTING_DEVICE_INVERT_X

/* keyboard duration terms */
//#define QUICK_TAP_TERM 0
#define TAPPING_TERM 150
#define COMBO_TERM 20
#define COMBO_MUST_HOLD_MODS
#define COMBO_HOLD_TERM 25


/* tri-layer config */
#define TRI_LAYER_LOWER 1 // extension layer
#define TRI_LAYER_UPPER 2 // symbol layer
#define TRI_LAYER_ADJUST 5 // media layer

#define TAPPING_TOGGLE 1 // tap-toggle keys must be pressed one time to do tap action
//#define PERMISSIVE_HOLD

/* miscellaneous */
//#define DEBOUNCE 5

// /* SPI & PMW3360 settings. */
// #define SPI_DRIVER SPID0
// #define SPI_SCK_PIN GP22
// #define SPI_MISO_PIN GP20
// #define SPI_MOSI_PIN GP23
// #define POINTING_DEVICE_CS_PIN GP16

// /* reset settings */
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U
