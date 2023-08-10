// SPDX-License-Identifier: GPL-2.0-or-later
// SPDX-FileCopyrightText: 2023 Mischback <mischback.dev@googlemail.com>
// SPDX-FileType: SOURCE

/* This is a personal keymap for *kb_elmo*'s **Sesame Ergo** keyboard.
 *
 * The **Sesame** is a 60% Alice-style keyboard.
 *
 * This source is directly based on Elmo's original contribution to the
 * official QMK repository (https://github.com/qmk/qmk_firmware) and customized
 * for my personal requirements.
 */

#include QMK_KEYBOARD_H

/* ***** DEFINES ***** */

/* Define custom keycodes.
 *
 * Actually these are just shortcuts to fit into the layer keymap without
 * overly destroying the neat columns.
 */
#define CC_CLMOV  LT(LAYER_MOVE, KC_CAPS)  // read: Custom Code Hold: Move, Tap: CapsLock

// Dedicated keycodes for the left and right space buttons
#define CC_LSPC   KC_SPC                   // read: Custom Code Left Space
#define CC_RSPC   KC_SPC                   // read: Custom Code Right Space

/* Create common reference to the defined layers.
 *
 * Note: Order does matter here, as the layers are stacked above each other.
 *       LAYER_BASE is the root or default layer.
 */
enum layers {
    LAYER_BASE,
    LAYER_MOVE,
    LAYER_CTRL
};


// clang-format off

/*
 *
 * Reference empty layer (yank 7)
    [LAYER_NAME] = LAYOUT_alice(
        _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______,          _______,
                 _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
                 _______,          _______,          _______,          _______,   _______,          _______,                   _______
    ),
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [LAYER_BASE] = LAYOUT_alice(
        KC_HOME, KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_END,  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,      KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        _______, CC_CLMOV, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
                 KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_NUBS,
                 KC_LCTL,          KC_LALT,          CC_LSPC,          KC_LGUI,   CC_RSPC,          KC_RALT,                   KC_RCTL
    ),
    [LAYER_MOVE] = LAYOUT_alice(
        _______, KC_GRV,  _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______,   KC_HOME, KC_END,  _______, _______, _______, _______, _______,
        _______, _______, KC_LEFT, KC_DOWN, _______, KC_RGHT, _______, KC_LEFT,   KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,
                 _______, _______, _______, _______, KC_PGDN, _______, _______,   KC_PGUP, KC_PGDN, _______, _______, _______, _______, _______,
                 _______,          _______,          _______,          _______,   _______,          _______,                   _______
    )
};

// clang-format on
