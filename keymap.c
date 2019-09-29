/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  AUTOFIND,
  MAC,
  WIN,
  MUSE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | MUSE |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |Space |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    MUSE,              LCTL_T(KC_1), LALT_T(KC_2), LGUI_T(KC_3), KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_SPC,
    LT(_RAISE,KC_TAB), KC_Q,         KC_W,         KC_E,         KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
    LT(_LOWER,KC_ESC), KC_A,         KC_S,         KC_D,         KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_LSFT,           KC_Z,         KC_X,         KC_C,         KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT 
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Find |      |      |      |      |      |      |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |  ~   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Cmd  | Alt  | Cmd  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    AUTOFIND, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______,  _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TILD,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, KC_LCTL, KC_LALT, KC_LGUI
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |  Up  |  `   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_UP, KC_GRV,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Mute |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Reset | Win  |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Mac  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, RESET,   WIN,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, MAC,     _______, _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool mac_mode = true;
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;
float mac_song[][2] = SONG(PLANCK_SOUND);
float win_song[][2] = SONG(PREONIC_SOUND);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case MUSE:
      if (record->event.pressed) {
        if(muse_mode){
			muse_mode = false;
		}
		else{
			muse_mode = true;
		}
      }
	  return false;
      break;
    case MAC:
      if (record->event.pressed) {
        mac_mode = true;
		#ifdef AUDIO_ENABLE
			PLAY_SONG(mac_song);
		#endif
      }
	  return false;
      break;
    case WIN:
      if (record->event.pressed) {
        mac_mode = false;
		#ifdef AUDIO_ENABLE
			PLAY_SONG(win_song);
		#endif
      }
	  return false;
      break;
    case AUTOFIND:
      if (record->event.pressed) {
		if(mac_mode){
			/*
			 * Copy
			 */
			register_code(KC_LGUI);
			register_code(KC_C);
			unregister_code(KC_C);
			unregister_code(KC_LGUI);
			/*
			 * Find
			 */
			register_code(KC_LGUI);
			register_code(KC_F);
			unregister_code(KC_F);
			unregister_code(KC_LGUI);
			/*
			 * Paste
			 */
			register_code(KC_LGUI);
			register_code(KC_V);
			unregister_code(KC_V);
			unregister_code(KC_LGUI);
			/*
			 * Enter
			 */
			tap_code(KC_ENT);
		}
		else{
			/*
			 * Copy
			 */
			register_code(KC_LCTL);
			register_code(KC_C);
			unregister_code(KC_C);
			unregister_code(KC_LCTL);
			/*
			 * Find
			 */
			register_code(KC_LCTL);
			register_code(KC_F);
			unregister_code(KC_F);
			unregister_code(KC_LCTL);
			/*
			 * Paste
			 */
			register_code(KC_LCTL);
			register_code(KC_V);
			unregister_code(KC_V);
			unregister_code(KC_LCTL);
			/*
			 * Enter
			 */
			tap_code(KC_ENT);
		}
      }
      return false;
      break;
  }
  return true;
}

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } 
  else {


	if(mac_mode){
		if(IS_LAYER_ON(_ADJUST)){
			/*
			 * Volume Up/Down
			 */
			if (clockwise) {
				tap_code(KC__VOLDOWN);
			}
			else {
				tap_code(KC__VOLUP);
			}
		}
		else{
			/*
			 * Find previous/next
			 */
			if (IS_LAYER_ON(_RAISE)) {
				if (clockwise) {
					register_code(KC_LGUI);
					register_code(KC_LSHIFT);
					register_code(KC_G);
					unregister_code(KC_G);
					unregister_code(KC_LSHIFT);
					unregister_code(KC_LGUI);
				}
				else {
					register_code(KC_LGUI);
					register_code(KC_G);
					unregister_code(KC_G);
					unregister_code(KC_LGUI);
				}
			}
			else{
				/*
				 * Undo/Redo
				 */
				if (IS_LAYER_ON(_LOWER)) {
					if (clockwise) {
						register_code(KC_LGUI);
						register_code(KC_Z);
						unregister_code(KC_Z);
						unregister_code(KC_LGUI);
					}
					else {
						register_code(KC_LGUI);
						register_code(KC_LSHIFT);
						register_code(KC_Z);
						unregister_code(KC_Z);
						unregister_code(KC_LSHIFT);
						unregister_code(KC_LGUI);
					}
				}
				else{
					/*
					 * Mouse Scroll Down/Up
					 */
					if (clockwise) {
						#ifdef MOUSEKEY_ENABLE
							tap_code(KC_MS_WH_DOWN);
						#else
							tap_code(KC_PGDN);
						#endif
					}
					else {
						#ifdef MOUSEKEY_ENABLE
						  tap_code(KC_MS_WH_UP);
						#else
						  tap_code(KC_PGUP);
						#endif
					}
				}
			}  
		}
	}
	else{
		if(IS_LAYER_ON(_ADJUST)){
			/*
			 * Volume Up/Down
			 */
			if (clockwise) {
				tap_code(KC_VOLD);
			}
			else {
				tap_code(KC_VOLU);
			}
		}
		else{
			/*
			 * Find previous/next
			 */
			if (IS_LAYER_ON(_RAISE)) {
				if (clockwise) {
					register_code(KC_LCTL);
					register_code(KC_LSHIFT);
					register_code(KC_G);
					unregister_code(KC_G);
					unregister_code(KC_LSHIFT);
					unregister_code(KC_LCTL);
				}
				else {
					register_code(KC_LCTL);
					register_code(KC_G);
					unregister_code(KC_G);
					unregister_code(KC_LCTL);
				}
			}
			else{
				/*
				 * Undo/Redo
				 */
				if (IS_LAYER_ON(_LOWER)) {
					if (clockwise) {
						register_code(KC_LCTL);
						register_code(KC_Z);
						unregister_code(KC_Z);
						unregister_code(KC_LCTL);
					}
					else {
						register_code(KC_LCTL);
						register_code(KC_LSHIFT);
						register_code(KC_Z);
						unregister_code(KC_Z);
						unregister_code(KC_LSHIFT);
						unregister_code(KC_LCTL);
					}
				}
				else{
					/*
					 * Mouse Scroll Down/Up
					 */
					if (clockwise) {
						#ifdef MOUSEKEY_ENABLE
							tap_code(KC_MS_WH_DOWN);
						#else
							tap_code(KC_PGDN);
						#endif
					}
					else {
						#ifdef MOUSEKEY_ENABLE
						  tap_code(KC_MS_WH_UP);
						#else
						  tap_code(KC_PGUP);
						#endif
					}
				}
			}  
		}
	}
    /*
     * Volume Down/Up
     */
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
