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


/* ***** DEFINES ***** */

/* Define custom keycodes.
 *
 * Actually these are just shortcuts to fit into the layer keymap without
 * overly destroying the neat columns.
 */
#define CC_LMOVE MO(LAYER_MOVE)  // read: Custom Code Layer Move
#define CC_LEDIT MO(LAYER_EDIT)  // read: Custom Code Layer Edit
#define CC_LCTRL MO(LAYER_CTRL)  // read: Custom Code Layer Control

/* Define colors for layer indication. */
/* SEMANTIC */
#define COLOR_BASE            RGB_WHITE
#define COLOR_MOVE            RGB_GREEN
#define COLOR_MOVE_SECONDARY  RGB_CYAN
#define COLOR_EDIT            RGB_RED
#define COLOR_CTRL            RGB_BLUE
#define COLOR_CTRL_SECONDARY  RGB_GOLD

/* Define the LED position of given keys */
#define LED_KEY_ESC 0
#define LED_KEY_RCTRL 61
#define LED_KEY_TAB 14
#define LED_KEY_BSPC 13

#define LED_KEY_1 1
#define LED_KEY_2 2
#define LED_KEY_3 3
#define LED_KEY_4 4
#define LED_KEY_5 5
#define LED_KEY_6 6
#define LED_KEY_7 7
#define LED_KEY_8 8
#define LED_KEY_9 9
#define LED_KEY_0 10
#define LED_KEY_MINS 11
#define LED_KEY_EQL 12

#define LED_KEY_A 28
#define LED_KEY_D 30
#define LED_KEY_E 17
#define LED_KEY_F 31
#define LED_KEY_H 33
#define LED_KEY_I 22
#define LED_KEY_J 34
#define LED_KEY_K 35
#define LED_KEY_L 36
#define LED_KEY_M 49
#define LED_KEY_N 48
#define LED_KEY_Q 15
#define LED_KEY_R 18
#define LED_KEY_S 29
#define LED_KEY_U 21
#define LED_KEY_V 46
#define LED_KEY_W 16


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
 * TODO: Use ``LAYER_EDIT`` for basic editing operations
 *         - ``KC_INS``, ``KC_DEL``
 *           - ``KC_DEL`` might be placed **additionally** on
 *             ``LAYER_MOVE`` -> ``D`` as this is a quite common thing...
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
        _______,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  _______,  _______,  KC_HOME,  KC_END,   _______,  _______,  _______,  _______,
        _______,  KC_LEFT,  KC_DOWN,  _______,  KC_RGHT,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  KC_PGDN,  _______,  KC_PGUP,  KC_PGDN,  _______,  _______,  _______,            _______,
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

/* ***** PROTOTYPES ***** */
static void custom_layer_indicator(uint8_t red, uint8_t green, uint8_t blue);
void keyboard_post_init_user(void);
bool rgb_matrix_indicators_user(void);


/* Activate pre-defined LEDs on every layer. */
static void custom_layer_indicator(uint8_t red, uint8_t green, uint8_t blue) {
    rgb_matrix_set_color(LED_KEY_ESC, red, green, blue);
    rgb_matrix_set_color(LED_KEY_RCTRL, red, green, blue);
}


/* Custom keyboard initialization code. */
void keyboard_post_init_user(void) {

    /* Set a common baseline for the lighting.
     *
     * Ref: https://docs.qmk.fm/#/feature_rgb_matrix?id=indicators-without-rgb-matrix-effect
     */
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}


/* Control the LED lightning of the keyboard.
 *
 * All pre-defined RGB matrix effects are disabled in ``rules.mk``. The purpose
 * of this function is to indicate the currently active layer using the RGB
 * matrix.
 *
 * TODO: Use the LED color to indicate the actual layer, but only apply it to
 *       relevant keys.
 * FIXME: ``RGB_TOG``/``RGB_MOD`` are not working.
 */
bool rgb_matrix_indicators_user(void) {

    switch (biton32(layer_state)) {
        case LAYER_BASE:
            rgb_matrix_set_color_all(RGB_OFF);
            custom_layer_indicator(COLOR_BASE);
            break;
        case LAYER_MOVE:
            rgb_matrix_set_color_all(RGB_OFF);
            custom_layer_indicator(COLOR_MOVE);

            // layer-specific lighting (see layer definition above)
            rgb_matrix_set_color(LED_KEY_H, COLOR_MOVE);
            rgb_matrix_set_color(LED_KEY_J, COLOR_MOVE);
            rgb_matrix_set_color(LED_KEY_K, COLOR_MOVE);
            rgb_matrix_set_color(LED_KEY_L, COLOR_MOVE);

            rgb_matrix_set_color(LED_KEY_W, COLOR_MOVE);
            rgb_matrix_set_color(LED_KEY_A, COLOR_MOVE);
            rgb_matrix_set_color(LED_KEY_S, COLOR_MOVE);
            rgb_matrix_set_color(LED_KEY_F, COLOR_MOVE);

            rgb_matrix_set_color(LED_KEY_U, COLOR_MOVE_SECONDARY);
            rgb_matrix_set_color(LED_KEY_I, COLOR_MOVE_SECONDARY);
            rgb_matrix_set_color(LED_KEY_Q, COLOR_MOVE_SECONDARY);
            rgb_matrix_set_color(LED_KEY_E, COLOR_MOVE_SECONDARY);
            rgb_matrix_set_color(LED_KEY_R, COLOR_MOVE_SECONDARY);
            rgb_matrix_set_color(LED_KEY_V, COLOR_MOVE_SECONDARY);
            rgb_matrix_set_color(LED_KEY_N, COLOR_MOVE_SECONDARY);
            rgb_matrix_set_color(LED_KEY_M, COLOR_MOVE_SECONDARY);

            rgb_matrix_set_color(LED_KEY_D, COLOR_EDIT);
            break;
        case LAYER_EDIT:
            rgb_matrix_set_color_all(RGB_OFF);
            custom_layer_indicator(COLOR_EDIT);

            // layer-specific lighting (see layer definition above)
            break;
        case LAYER_CTRL:
            rgb_matrix_set_color_all(RGB_OFF);
            custom_layer_indicator(COLOR_CTRL);

            // layer-specific lighting (see layer definition above)
            rgb_matrix_set_color(LED_KEY_1, COLOR_CTRL);
            rgb_matrix_set_color(LED_KEY_2, COLOR_CTRL);
            rgb_matrix_set_color(LED_KEY_3, COLOR_CTRL);
            rgb_matrix_set_color(LED_KEY_4, COLOR_CTRL);
            rgb_matrix_set_color(LED_KEY_5, COLOR_CTRL);
            rgb_matrix_set_color(LED_KEY_6, COLOR_CTRL);
            rgb_matrix_set_color(LED_KEY_7, COLOR_CTRL);
            rgb_matrix_set_color(LED_KEY_8, COLOR_CTRL);
            rgb_matrix_set_color(LED_KEY_9, COLOR_CTRL);
            rgb_matrix_set_color(LED_KEY_0, COLOR_CTRL);
            rgb_matrix_set_color(LED_KEY_MINS, COLOR_CTRL);
            rgb_matrix_set_color(LED_KEY_EQL, COLOR_CTRL);

            rgb_matrix_set_color(LED_KEY_TAB, COLOR_CTRL_SECONDARY);
            rgb_matrix_set_color(LED_KEY_BSPC, COLOR_CTRL_SECONDARY);
            break;
        default:
            // This should not be reached, but if the keyboard is PINK,
            // something went wrong! ;)
            rgb_matrix_set_color_all(RGB_PINK);
            break;
    }

    return false;
}
