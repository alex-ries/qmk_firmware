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

/*
 * Base Taps
 */
#define M_AW MT(KC_LGUI, KC_A)
#define M_RA MT(KC_LALT, KC_R)
#define M_SC MT(KC_LCTRL,KC_S)
#define M_TS MT(KC_LSFT, KC_T)
#define M_XA MT(KC_RALT, KC_X)
#define M_OW MT(KC_LGUI, KC_O)
#define M_IA MT(KC_LALT, KC_I)
#define M_EC MT(KC_LCTRL, KC_E)
#define M_NS MT(KC_LSFT, KC_N)
#define M_DOTA MT(KC_RALT, KC_DOT)
#define LT_ESC LT(KC_ESC, _MEDIA)
#define LT_TAB LT(KC_TAB, _SYMR)
#define LT_SPC LT(KC_SPC, _NAV)
#define LT_DEL LT(KC_DEL, _FUNC)
#define LT_BSPC LT(KC_BSPC, _SYML)
#define LT_ENT LT(KC_ENT, _NUM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_ESC,         KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,                                           KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,        KC_NO,
    KC_BSPC,        M_AW,           M_RA,           M_SC,           M_TS,           KC_G,                                           KC_M,           M_NS,           M_EC,           M_IA,           M_OW,           KC_NO,
    KC_DEL,         KC_Z,           M_XA,           KC_C,           KC_D,           KC_V,                                           KC_K,           KC_H,           KC_COMM,        M_DOTA,         KC_SLSH,        KC_NO,
                                                    LT_TAB,         LT_SPC,                                         LT_ENT,         LT_BSPC
  ),
  [_GAME] = LAYOUT_voyager(
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,         KC_5,                       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_F1,
    KC_NO,    KC_Q,     KC_W,     KC_F,     KC_P,         KC_B,                       KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    KC_F2,
    KC_LSFT,  KC_A,     KC_R,     KC_S,     KC_T,         KC_G,                       KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       KC_F3,
    KC_LCTRL, KC_Z,     KC_A,     KC_C,     KC_D,         KC_V,                       KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_F4,
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
    KC_NO,    KC_LBRC,    KC_7,       KC_8,     KC_9,     KC_RBRC,                    KC_NO,      KC_NO,      KC_NO,      KC_NO,    QK_RBT,     KC_NO,
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
