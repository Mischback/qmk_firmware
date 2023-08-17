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
#include "keymap_german.h"

/* ***** DEFINES ***** */

/* Define custom keycodes.
 *
 * Actually these are just shortcuts to fit into the layer keymap without
 * overly destroying the neat columns.
 */
#define CC_CLMO  LT(LAYER_MOVE, KC_CAPS )  // read: Custom Code Hold: Move, Tap: CapsLock
#define CC_CLSY  MO(LAYER_SYS_DE)          // read: Custom Code Activate SYSTEM_DE layer
#define CC_SSFT  MO(LAYER_SYS_DE_SFT)      // read: Custom Code Shift for SYSTEM_DE layer
#define CC_CLCT  MO(LAYER_CTRL)            // read: Custom Code Activate CTRL_LAYER

// Dedicated keycodes for the left and right space buttons
#define CC_LSPC   KC_SPC                   // read: Custom Code Left Space
#define CC_RSPC   KC_SPC                   // read: Custom Code Right Space

/* Create common reference to the defined layers.
 *
 * Note: Order does matter here, as the layers are stacked above each other.
 *       LAYER_BASE is the root or default layer.
 *
 * Note: LAYER_SYS_DE / LAYER_SYS_DE_SFT
 *       The keyboard will be attached to systems with German language settings
 *       while having ANSI (US) keycaps applied. This is not really an issue
 *       for acutal typing, but some of the more obscure special characters
 *       *may* need visual reference.
 *       The LAYER_BASE uses standard keycodes, so to match the special
 *       characters with the keycaps' labels, ``DE_`` keycodes are used on a
 *       dedicated layer including a dedicated *shifted* layer.
 */
enum layers {
    LAYER_BASE,
    LAYER_MOVE,
    LAYER_SYS_DE,
    LAYER_SYS_DE_SFT,
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
        KC_HOME, KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_END,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,      KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        CC_CLSY, CC_CLMO, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
                 KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_NUBS,
                 KC_LCTL,          KC_LALT,          CC_LSPC,          KC_LGUI,   CC_RSPC,          KC_RALT,                   KC_RCTL
    ),
    [LAYER_MOVE] = LAYOUT_alice(
        _______, KC_GRV,  _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______,   KC_HOME, KC_END,  _______, _______, _______, _______, _______,
        _______, _______, KC_LEFT, KC_DOWN, _______, KC_RGHT, _______, KC_LEFT,   KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,
                 _______, _______, _______, _______, KC_PGDN, _______, _______,   KC_PGUP, KC_PGDN, _______, _______, _______, _______, _______,
                 _______,          _______,          _______,          _______,   _______,          _______,                   _______
    ),
    [LAYER_SYS_DE] = LAYOUT_alice(
        _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, DE_MINS, DE_EQL,  _______,
        _______, _______, _______, _______, _______, _______, _______, DE_Y,      _______, _______, _______, _______, DE_LBRC, DE_RBRC, DE_BSLS,
        _______, CC_CLCT, _______, _______, _______, _______, _______, _______,   _______, _______, _______, DE_SCLN, DE_QUOT,          _______,
                 CC_SSFT, DE_Z,    _______, _______, _______, _______, _______,   _______, _______, DE_COMM, DE_DOT,  DE_SLSH, _______, _______,
                 _______,          _______,          _______,          _______,   _______,          _______,                   _______
    ),
    [LAYER_SYS_DE_SFT] = LAYOUT_alice(
        _______, _______, DE_EXLM, DE_AT,   DE_HASH, DE_DLR,  DE_PERC, DE_CIRC,   DE_AMPR, DE_ASTR, DE_LPRN, DE_RPRN, DE_UNDS, DE_PLUS, _______,
        _______, _______, _______, _______, _______, _______, _______, S(DE_Y),   _______, _______, _______, _______, DE_LCBR, DE_RCBR, DE_PIPE,
        _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, DE_COLN, DE_DQUO,          _______,
                 _______, S(DE_Z), _______, _______, _______, _______, _______,   _______, _______, DE_LABK, DE_RABK, DE_QUES, _______, _______,
                 _______,          _______,          _______,          _______,   _______,          _______,                   _______
    ),
    [LAYER_CTRL] = LAYOUT_alice(
        _______, KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______,          _______,
                 _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
                 _______,          _______,          _______,          _______,   _______,          _______,                   _______
    ),
};

// clang-format on
