/* Copyright 2019
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

#pragma once

#include "config_common.h"

#define MATRIX_COL_PINS { A0, A1, A2, A3, A4, A5, A6, A7, B0, B1, C14, B10 }
#define MATRIX_ROW_PINS { B6, B7, B8, B9 }
#define UNUSED_PINS

/* encoder */
#define ENCODERS_PAD_A { A8 }
#define ENCODERS_PAD_B { B15 }
#define ENCODER_RESOLUTION 4
#define TAP_CODE_DELAY 20

/*
#define BACKLIGHT_PIN           A0
#define BACKLIGHT_PWM_DRIVER    PWMD2
#define BACKLIGHT_PWM_CHANNEL   1

#define RGB_DI_PIN A1

#define ADC_PIN A0
*/
