/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4B44
#define PRODUCT_ID      0x5170
#define DEVICE_VER      0x0001
#define MANUFACTURER    Kiser Designs
#define PRODUCT         Queso

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 8

#define MATRIX_ROW_PINS { GP0, GP9, GP6, GP19, GP1, GP5, GP10, GP14 }
#define MATRIX_COL_PINS { GP2, GP3, GP4, GP11, GP12, GP13, GP17, GP18 }

#define DIODE_DIRECTION COL2ROW

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define ENCODER_RESOLUTION 4
#define ENCODERS_PAD_A { GP15, GP20 }
#define ENCODERS_PAD_B { GP16, GP21 }
