// SPDX-License-Identifier: GPL-2.0-or-later
// SPDX-FileCopyrightText: 2023 Mischback <dev@mischback.de>
// SPDX-FileType: SOURCE

/* This is a personal keymap for the Keychron V4 (ISO) keyboard.
 *
 * The source code is directly based on Keychron's contribution to the official
 * QMK repository (https://github.com/qmk/qmk-firmware) and customized to my
 * personal requirements.
 */

#include QMK_KEYBOARD_H

/* Create common reference to the defined layers.
 *
 * Note: Order does matter here, as the layers are stacked above each other.
 *       LAYER_BASE is the root or default layer.
 */
enum layers {
    LAYER_BASE,
    LAYER_MOVE,
    LAYER_EDIT,
    LAYER_CTRL
};

/* Define custom keycodes.
 *
 * Actually these are just shortcuts to fit into the layer keymap without
 * overly destroying the neat columns.
 */
#define CC_LMOVE MO(LAYER_MOVE)  // read: Custom Code Layer Move
#define CC_LEDIT MO(LAYER_EDIT)  // read: Custom Code Layer Edit
#define CC_LCTRL MO(LAYER_CTRL)  // read: Custom Code Layer Control

// clang-format off

/* The actual definition of the layers.
 *
 * ``LAYER_BASE`` is just a slight modification of the original layer as
 * provided by Keychron's default keymap for the keyboard (originally named
 * ``WIN_BASE``):
 *   - [CapsLock] toggles ``LAYER_MOVE``
 *   - [fn] toggles ``LAYER_MOVE``
 *   - [fn1] toggles ``LAYER_EDIT``
 *   - [fn + fn1] toggles ``LAYER_CTRL``
 *
 * As the DIP switch is disabled, the Mac-specific layers were removed.
 *
 * TODO: Use ``LAYER_MOVE`` for the movement function layer:
 *         - ``KC_LEFT``, ``KC_RGHT``, ``KC_DOWN``, ``KC_UP``
 *           - *VI like movement*: ``hjkl``
 *           - *Gamer movement*: ``wasf`` (Yeah, I know... Crazy!)
 *         - ``KC_HOME``, ``KC_END``, ``KC_PGUP``, ``KC_PGDN``
 * TODO: Use ``LAYER_EDIT`` for basic editing operations
 * TODO: Use ``LAYER_CTRL`` for F-keys and control commands, including keyboard
 *       specific configuration keys (lighting, ...):
 *         - ``NK_TOGG``: Toggles NKRO (check docs again!)
 *
 * Reference EMPTY LAYER

    [LAYER_NAME] = LAYOUT_iso_62(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT_iso_62(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,
        CC_LMOVE, KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,
        KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  CC_LMOVE, CC_LEDIT, KC_RCTL),

    [LAYER_MOVE] = LAYOUT_iso_62(
        KC_GRV,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  CC_LCTRL, _______),

    [LAYER_EDIT] = LAYOUT_iso_62(
        KC_TILD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  CC_LCTRL, _______,  _______),

    [LAYER_CTRL] = LAYOUT_iso_62(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   RGB_MOD,
        RGB_TOG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),
};

// clang-format on
