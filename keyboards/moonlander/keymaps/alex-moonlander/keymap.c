#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    _BASE,
    _GAME,
    _NAV,
    _MEDIA,
    _SYMR,
    _NUM,
    _SYML,
    _FUNC
};

enum keycodes {
    RGB_BIZTOG = SAFE_RANGE
};

/*
 * Base Taps
 */
#define M_AW MT(MOD_LGUI, KC_A)
#define M_RA MT(MOD_LALT, KC_R)
#define M_SC MT(MOD_LCTL,KC_S)
#define M_TS MT(MOD_LSFT, KC_T)
#define M_XA MT(MOD_LALT, KC_X)
#define M_OW MT(MOD_RGUI, KC_O)
#define M_IA MT(MOD_RALT, KC_I)
#define M_EC MT(MOD_RCTL, KC_E)
#define M_NS MT(MOD_RSFT, KC_N)
#define M_DOTA MT(MOD_RALT, KC_DOT)
#define LT_ESC LT(_MEDIA, KC_ESC)
#define LT_SPC LT(_SYMR, KC_SPC)
#define LT_TAB LT(_NAV, KC_TAB)
#define TK_NAVMEDIA TD(TDM_NAVMDTSL)
#define LT_DEL LT(_FUNC, KC_DEL)
#define LT_BSPC LT(_NUM, KC_BSPC)
#define LT_ENT LT(_SYML, KC_ENT)
#define TK_NUMFUN TD(TDM_NFUNDTSL)
#define TDK_NOGAME TD(TDM_NOGAMEMO)
#define TDK_5BASE TD(TDM_5BASEMO)

/*
 * Tap Dance Defs
 */

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    TDM_NAVMDTSL,
    TDM_NFUNDTSL,
    TDM_NOGAMEMO,
    TDM_5BASEMO
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the dual layer switch (nav, media) tap dance.
void navmdtsl_finished(qk_tap_dance_state_t *state, void *user_data);
void navmdtsl_reset(qk_tap_dance_state_t *state, void *user_data);

// For the backspace dual layer switch (numpad, functions)
void nfundtsl_finished(qk_tap_dance_state_t *state, void *user_data);
void nfundtsl_reset(qk_tap_dance_state_t *state, void *user_data);

/*
 * Business RGB toggle defs
 */
typedef struct {
    bool    enabled;
    uint8_t mode;
    HSV     color;
} business_state_t;

business_state_t rgb_business_state = {.enabled = false};

/*
 * Key Maps
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_moonlander(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,    TDK_NOGAME,                             KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      RGB_BIZTOG,
        KC_ESC,   KC_Q,     KC_W,     KC_F,     KC_P,         KC_B,     KC_NO,                                  KC_NO,      KC_J,       KC_L,       KC_U,       KC_Y,       KC_QUOT,    KC_NO,
        KC_BSPC,  M_AW,     M_RA,     M_SC,     M_TS,         KC_G,     KC_MEH,                                 KC_MEH,     KC_M,       M_NS,       M_EC,       M_IA,       M_OW,       KC_NO,
        KC_DEL,   KC_Z,     M_XA,     KC_C,     KC_D,         KC_V,                                                         KC_K,       KC_H,       KC_COMM,    M_DOTA,     KC_SLSH,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_LEFT,  KC_RGHT,                KC_NO,                                  KC_NO,                  KC_UP,      KC_DOWN,    KC_NO,      KC_NO,      KC_NO,
                                                              LT_SPC,   TK_NAVMEDIA, LT_ESC,        KC_LALT,    TK_NUMFUN,  LT_ENT
    ),
    [_GAME] = LAYOUT_moonlander(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,         KC_5,     TDK_5BASE,                              KC_NO,      KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_F1,
        KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,         KC_B,     KC_NO,                                  KC_NO,      KC_J,       KC_L,       KC_U,       KC_Y,       KC_QUOT,    KC_F2,
        KC_LSFT,  KC_A,     KC_R,     KC_S,     KC_T,         KC_G,     KC_MEH,                                 KC_MEH,     KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       KC_F3,
        KC_LCTRL, KC_Z,     KC_X,     KC_C,     KC_D,         KC_V,                                                         KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_F4,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_LALT,                KC_NO,                                  KC_NO,                  KC_UP,      KC_DOWN,    KC_NO,      KC_NO,      KC_NO,
                                                              KC_SPC,   KC_LALT,    KC_LGUI,        KC_LALT,    KC_BSPC,    KC_ENT
    ),
    [_NAV] = LAYOUT_moonlander(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,    KC_NO,                                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,    QK_RBT,   KC_NO,    KC_NO,    KC_NO,        KC_NO,    KC_NO,                                  KC_NO,      KC_AGIN,    KC_UNDO,    KC_CUT,     KC_COPY,    KC_PSTE,    KC_NO,
        KC_NO,    KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,      KC_NO,    KC_NO,                                  KC_NO,      KC_CAPS,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,                                                        KC_INS,     KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                  KC_NO,                                  KC_TRNS,                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                              KC_NO,    KC_NO,      KC_NO,           KC_NO,     KC_NO,      KC_NO
    ),
    [_MEDIA] = LAYOUT_moonlander(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,    KC_NO,                                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,    QK_RBT,   KC_NO,    KC_NO,    KC_NO,        KC_NO,    KC_NO,                                  KC_NO,      RGB_MOD,    RGB_HUI,    RGB_SAI,    RGB_VAI,    RGB_TOG,    KC_NO,
        KC_NO,    KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,      KC_NO,    KC_NO,                                  KC_NO,      KC_NO,      KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,                                                        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                  KC_NO,                                  KC_TRNS,                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                              KC_NO,    KC_NO,      KC_NO,           KC_NO,     KC_MSTP,    KC_MPLY
    ),
    [_SYMR] = LAYOUT_moonlander(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,    KC_NO,                                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,    QK_RBT,   KC_NO,    KC_NO,    KC_NO,        KC_NO,    KC_NO,                                  KC_NO,      KC_PLUS,    KC_LBRC,    KC_RBRC,    KC_BSLS,    KC_DQT,     KC_NO,
        KC_NO,    KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,      KC_NO,    KC_NO,                                  KC_NO,      KC_MINS,    KC_LPRN,    KC_RPRN,    KC_EXLM,    KC_EQL,     KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,                                                        KC_PERC,    KC_LCBR,    KC_RCBR,    KC_PIPE,    KC_UNDS,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                  KC_NO,                                  KC_TRNS,                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                              KC_NO,    KC_NO,      KC_NO,           KC_NO,     KC_NO,      KC_NO
    ),
    [_NUM] = LAYOUT_moonlander(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,    KC_NO,                                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,    KC_LBRC,  KC_7,     KC_8,     KC_9,         KC_RBRC,  KC_NO,                                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      QK_RBT,     KC_NO,
        KC_NO,    KC_SCLN,  KC_4,     KC_5,     KC_6,         KC_EQL,   KC_NO,                                  KC_NO,      KC_NO,      KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,    KC_NO,
        KC_NO,    KC_GRV,   KC_1,     KC_2,     KC_3,         KC_BSLS,                                                      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_0,                   KC_TRNS,                                KC_NO,                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                                              KC_0,     KC_NO,      KC_NO,           KC_NO,     KC_NO,      KC_NO
    ),
    [_SYML] = LAYOUT_moonlander(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,    KC_NO,                                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,    KC_NO,    KC_AMPR,  KC_LABK,  KC_RABK,      KC_CIRC,  KC_NO,                                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      QK_RBT,     KC_NO,
        KC_NO,    KC_NO,    KC_TILD,  KC_COLN,  KC_SCLN,      KC_ASTR,  KC_NO,                                  KC_NO,      KC_NO,      KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,    KC_NO,
        KC_NO,    KC_NO,    KC_AT,    KC_DLR,   KC_PIPE,      KC_HASH,                                                      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                KC_TRNS,                                KC_NO,                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                                              KC_NO,    KC_NO,      KC_NO,           KC_NO,     KC_NO,      KC_NO
    ),
    [_FUNC] = LAYOUT_moonlander(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,    KC_NO,                                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,    KC_F12,   KC_F7,    KC_F8,    KC_F9,        KC_PSCR,  KC_NO,                                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      QK_RBT,     KC_NO,
        KC_NO,    KC_F11,   KC_F4,    KC_F5,    KC_F6,        KC_SLCK,  KC_NO,                                  KC_NO,      KC_NO,      KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,    KC_NO,
        KC_NO,    KC_F10,   KC_F1,    KC_F2,    KC_F3,        KC_BRK,                                                       KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                KC_TRNS,                                KC_NO,                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                                              KC_NO,    KC_NO,      KC_NO,           KC_NO,     KC_NO,      KC_NO
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_BIZTOG:
            if (record->event.pressed) {
                if (rgb_business_state.enabled == false) {
                    // save current state, to restore later
                    rgb_business_state.mode  = rgb_matrix_get_mode();
                    rgb_business_state.color = rgb_matrix_get_hsv();

                    // configure static white
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
                    rgb_matrix_sethsv_noeeprom(HSV_WHITE);
                } else {
                    // restore
                    rgb_matrix_mode_noeeprom(rgb_business_state.mode);
                    rgb_matrix_sethsv_noeeprom(rgb_business_state.color.h, rgb_business_state.color.s, rgb_business_state.color.v);
                }
                rgb_business_state.enabled = !rgb_business_state.enabled;
            }
            return false;

        default:
            return true;
    }
}

/*
 * Tap dance functions credit to https://github.com/danielggordon
 */

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

/*
 * Double tap hold TAB Dual Layer switch
 * If key is pressed: tab
 * If held: switch nav layer
 * If tap held: switch media layer
 */
static td_tap_t navmdtsl_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void navmdtsl_finished(qk_tap_dance_state_t *state, void *user_data) {
    navmdtsl_tap_state.state = cur_dance(state);
    switch (navmdtsl_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_TAB);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_NAV);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_TAB);
            register_code(KC_TAB);
            break;
        case TD_DOUBLE_HOLD:
            layer_on(_MEDIA);
            break;
        default:
            break;
    }
}

void navmdtsl_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (navmdtsl_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_NAV);
    }
    if (navmdtsl_tap_state.state == TD_DOUBLE_HOLD) {
        layer_off(_MEDIA);
    }
    navmdtsl_tap_state.state = TD_NONE;
}

/*
 * Double tap hold TAB Dual Layer switch
 * If key is pressed: tab
 * If held: switch nav layer
 * If tap held: switch media layer
 */
static td_tap_t nfundtsl_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void nfundtsl_finished(qk_tap_dance_state_t *state, void *user_data) {
    nfundtsl_tap_state.state = cur_dance(state);
    switch (navmdtsl_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_BSPC);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_NUM);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_BSPC);
            register_code(KC_BSPC);
            break;
        case TD_DOUBLE_HOLD:
            layer_on(_FUNC);
            break;
        default:
            break;
    }
}

void nfundtsl_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (nfundtsl_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_NUM);
    }
    if (nfundtsl_tap_state.state == TD_DOUBLE_HOLD) {
        layer_off(_FUNC);
    }
    nfundtsl_tap_state.state = TD_NONE;
}

/*
 * Switch to Gaming Layer
 * If key is pressed: Nothing
 * If key is double tapped: switch to gaming layer
 */

// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    [TDM_NAVMDTSL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, navmdtsl_finished, navmdtsl_reset),
    [TDM_NFUNDTSL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nfundtsl_finished, nfundtsl_reset),
    [TDM_NOGAMEMO] = ACTION_TAP_DANCE_LAYER_MOVE(KC_NO, _GAME),
    [TDM_5BASEMO] = ACTION_TAP_DANCE_LAYER_MOVE(KC_5, _BASE)
};


