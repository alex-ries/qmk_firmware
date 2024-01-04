#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_us_international.h"

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

/*
 * Base Mod Taps
 */
#define M_AW MT(KC_A,KC_LGUI)
#define M_RA MT(KC_R,KC_LALT)
#define M_SC MT(KC_S,KC_LCTRL)
#define M_TS MT(KC_T,KC_LSFT)
#define M_XA MT(KC_X,KC_RALT)
#define M_OW MT(KC_O,KC_LGUI)
#define M_IA MT(KC_I,KC_LALT)
#define M_EC MT(KC_E,KC_LCTRL)
#define M_NS MT(KC_N,KC_LSFT)
#define M_DOTA MT(KC_DOT,KC_RALT)
#define LT_ESC LT(KC_ESC, _MEDIA)
#define LT_TAB LT(KC_TAB, _SYMR)
#define LT_SPC LT(KC_SPC, _NAV)
#define LT_DEL LT(KC_DEL, _FUNC)
#define LT_BSPC LT(KC_BSPC, _SYML)
#define LT_ENT LT(KC_ENT, _NUM)

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_74_255_255,
  HSV_169_255_255,
};



enum tap_dance_codes {
  DANCE_0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_voyager(
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,                      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_ESC,   KC_Q,     KC_W,     KC_F,     KC_P,         KC_B,                       KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    KC_NO,
    KC_BSPC,  M_AW,     M_RA,     M_SC,     M_TS,         KC_G,                       KC_M,       M_NS,       M_EC,       M_IA,       M_OW,       KC_NO,
    KC_DEL,   KC_Z,     M_XA,     KC_C,     KC_D,         KC_V,                       KC_K,       KC_H,       KC_COMM,    M_DOTA,     KC_SLSH,    KC_NO,   
                                            LT_TAB,       LT_SPC,                     LT_ENT,     LT_BSPC
  ),
  [_GAME] = LAYOUT_voyager(
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,         KC_5,                       KC_6,       KC_7,       KC_8,       KC_9,       KC_10,      KC_11,
    KC_NO,    KC_Q,     KC_W,     KC_F,     KC_P,         KC_B,                       KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    KC_NO,
    KC_LSFT,  KC_A,     KC_R,     KC_S,     KC_T,         KC_G,                       KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       KC_NO,
    KC_LCTRl, KC_Z,     KC_A,     KC_C,     KC_D,         KC_V,                       KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_NO,   
                                            KC_TAB,       KC_SPC,                     KC_ENT,     KC_BSPC
  ),
  [_NAV] = LAYOUT_voyager(
    KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_NO,    QK_RBT,     KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_AGIN,    KC_UNDO,    KC_CUT,     KC_COPY,    KC_PSTE,    KC_NO,
    KC_NO,    KC_LGUI,    KC_LALT,    KC_LCTL,  KC_LSFT,  KC_NO,                      KC_CAPS,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_NO,
    KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_INS,     KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_NO,
                                                KC_NO,    KC_NO,                      KC_TRNS,    KC_TRNS
  ),
  [_MEDIA] = LAYOUT_voyager(
    KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_NO,    QK_RBT,     KC_NO,      KC_NO,    KC_NO,    KC_NO,                      RGB_MOD,    RGB_HUI,    RGB_SAI,    RGB_VAI,    RGB_TOG,    KC_NO,
    KC_NO,    KC_LGUI,    KC_LALT,    KC_LCTL,  KC_LSFT,  KC_NO,                      KC_NO,      KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,    KC_NO,
    KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                                KC_NO,    KC_NO,                      KC_MSTP,    KC_MPLY
),
  [_SYMR] = LAYOUT_voyager(
    KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,      KC_NO,
    KC_NO,    QK_RBT,     KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_PLUS,    KC_LBRC,    KC_RBRC,    KC_BSLS,  KC_DQT,     KC_NO,
    KC_NO,    KC_LGUI,    KC_LALT,    KC_LCTL,  KC_LSFT,  KC_NO,                      KC_MINS,    KC_LPRN,    KC_RPRN,    KC_EXLM,  KC_EQL,     KC_NO,
    KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_PERC,    KC_LCBR,    KC_RCBR,    KC_PIPE,  KC_UNDS,    KC_NO,
                                                KC_NO,    KC_NO,                      KC_TRNS,    KC_TRNS
  ),
  [_NUM] = LAYOUT_voyager(
    KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,      KC_NO,
    KC_NO,    KC_LBRC,    KC_7,       KC_8,     KC_9,     KC_RPRC,                    KC_NO,      KC_NO,      KC_NO,      KC_NO,    QK_RBT,     KC_NO,
    KC_NO,    KC_SCLN,    KC_4,       KC_5,     KC_6,     KC_EQL,                     KC_NO,      KC_LSFT,    KC_LCTL,    KC_LALT,  KC_LGUI,    KC_NO,
    KC_NO,    KC_GRV,     KC_1,       KC_2,     KC_3,     KC_BSLS,                    KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,      KC_NO,
                                                KC_NO,    KC_NO,                      KC_NO,      KC_NO
  ),
  [_SYMR] = LAYOUT_voyager(
    KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,      KC_NO,
    KC_NO,    KC_NO,      KC_AMPR,    KC_LABK,  KC_RABK,  KC_CIRC,                    KC_NO,      KC_NO,      KC_NO,      KC_NO,    QK_RBT,     KC_NO,
    KC_NO,    KC_NO,      KC_TILD,    KC_COLN,  KC_SCLN,  KC_ASTR,                    KC_NO,      KC_LSFT,    KC_LCTL,    KC_LALT,  KC_LGUI,    KC_NO,
    KC_NO,    KC_NO,      KC_AT,      KC_DLR,   KC_PIPE,  KC_HASH,                    KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,      KC_NO,
                                                KC_NO,    KC_NO,                      KC_NO,      KC_NO
  ),
  [_FUNC] = LAYOUT_voyager(
    KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,      KC_NO,
    KC_NO,    KC_F12,     KC_F7,      KC_F8,    KC_F9,    KC_PSCR,                    KC_NO,      KC_NO,      KC_NO,      KC_NO,    QK_RBT,     KC_NO,
    KC_NO,    KC_F11,     KC_F4,      KC_F5,    KC_F6,    KC_SLCK,                    KC_NO,      KC_LSFT,    KC_LCTL,    KC_LALT,  KC_LGUI,    KC_NO,
    KC_NO,    KC_F10,     KC_F1,      KC_F2,    KC_F3,    KC_BRK,                     KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,      KC_NO,
                                                KC_NO,    KC_NO,                      KC_NO,      KC_NO
  )
};

const uint16_t PROGMEM combo0[] = { MT(MOD_RSFT, KC_QUOTE), MT(MOD_LSFT, KC_BSPACE), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_CAPSLOCK),
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_74_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(74,255,255);
      }
      return false;
    case HSV_169_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(169,255,255);
      }
      return false;
  }
  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[1];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
    }
    if(state->count > 3) {
        tap_code16(KC_EQUAL);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_EQUAL); break;
        case SINGLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_EQUAL); register_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_EQUAL); register_code16(KC_EQUAL);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_EQUAL); break;
        case SINGLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_EQUAL); break;
    }
    dance_state[0].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
};
