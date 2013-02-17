/**
 * \file
 * <!--
 * This file is part of BeRTOS.
 *
 * Bertos is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As a special exception, you may use this file as part of a free software
 * library without restriction.  Specifically, if other files instantiate
 * templates or use macros or inline functions from this file, or you compile
 * this file and link it with other files to produce an executable, this
 * file does not by itself cause the resulting executable to be covered by
 * the GNU General Public License.  This exception does not however
 * invalidate any other reasons why the executable file might be covered by
 * the GNU General Public License.
 *
 * Copyright 2008 Develer S.r.l. (http://www.develer.com/)
 *
 * -->
 *
 * \brief Configuration file for the AX25 protocol module.
 *
 * \author Francesco Sacchi <batt@develer.com>
 */

#ifndef CFG_AX25_H
#define CFG_AX25_H

#include <avr/io.h>

/**
 * Module logging level.
 *
 * $WIZ$ type = "enum"
 * $WIZ$ value_list = "log_level"
 */
#define AX25_LOG_LEVEL      LOG_LVL_WARN

/**
 * Module logging format.
 *
 * $WIZ$ type = "enum"
 * $WIZ$ value_list = "log_format"
 */
#define AX25_LOG_FORMAT     LOG_FMT_TERSE

/**
 * AX25 frame buffer lenght.
 *
 * $WIZ$ type = "int"
 * $WIZ$ min = 18
 */
#define CONFIG_AX25_FRAME_BUF_LEN 330


/**
 * Enable repeaters listing in AX25 frames.
 * If enabled use 56 addtional bytes of RAM
 * for each message received.
 *
 * $WIZ$ type = "boolean"
 */
#define CONFIG_AX25_RPT_LST 1

/* Define strobe pins
 * * 0 = PortB0 = Arduino D08
 * * 1 = PortB1 = Arduino D09
 * * 2 = PortB2 = Arduino D10
 * * 3 = PortB3 = Arduino D11
 * * 4 = PortB4 = Arduino D12
 * * 5 = PortB5 = Arduino D13 (On-board LED)
 * */
#define AX25_STROBE_1 5
/*
 *  * Activate strobe pin. We use it for debugging purposes. If you don't use it, simply
 * leave empty the following macros
 */
#define AX25_DCD_STROBE_INIT() do { DDRB |= BV(AX25_STROBE_1); } while (0)

/*
 * Set the pin high. This macro is called at the beginning of the interrupt routine
 */
#define AX25_DCD_STROBE_ON() do { PORTB |= BV(AX25_STROBE_1); } while (0)

/*
 * Set the pin low. This macro is called at the end of the interrupt routine
 */
#define AX25_DCD_STROBE_OFF() do { PORTB &= ~BV(AX25_STROBE_1); } while (0)

#endif /* CFG_AX25_H */
