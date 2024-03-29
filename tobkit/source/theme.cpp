/*
 * TobKit - A simple user interface toolkit for Nintendo DS homebrew
 *                   Copyright 2005-2009 Tobias Weyand (me@tobw.net)
 *                                   http://code.google.com/p/tobkit
 *
 * TobKit is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * TobKit is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with TobKit.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include "tobkit/theme.h"

Theme::Theme(void)
{
	// Set default colors
	col_bg                  = RGB15(4,6,15)|BIT(15);
	col_dark_bg             = col_bg;
	col_medium_bg           = RGB15(9,11,17)|BIT(15);
	col_light_bg            = RGB15(16,18,24)|BIT(15);
	col_lighter_bg          = RGB15(23,25,31) | BIT(15);
	col_light_ctrl          = RGB15(31,31,0)|BIT(15); // RGB15(26,26,26)|BIT(15)
	col_dark_ctrl           = RGB15(31,18,0)|BIT(15); // RGB15(31,31,31)|BIT(15)
	col_light_ctrl_disabled = col_light_bg;
	col_dark_ctrl_disabled  = col_medium_bg;
	col_list_highlight1     = RGB15(28,15,0)|BIT(15);
	col_list_highlight2     = RGB15(28,28,0)|BIT(15);
	col_outline             = RGB15(0,0,0)|BIT(15);
	col_sepline             = RGB15(31,31,0)|BIT(15);
	col_icon                = RGB15(0,0,0)|BIT(15);
	col_text                = RGB15(0,0,0)|BIT(15);
	col_signal              = RGB15(31,0,0)|BIT(15);

	precalcGradient(&gradient_ctrl, col_dark_ctrl, col_light_ctrl);
    precalcGradient(&gradient_ctrl_disabled, col_dark_ctrl_disabled, col_light_ctrl_disabled);
    precalcGradient(&gradient_bg, col_medium_bg, col_light_bg);
    precalcGradient(&gradient_bg_bright, col_light_bg, col_lighter_bg);
}

void Theme::precalcGradient(std::vector<u16> *gradient, const u16 col1, const u16 col2)
{
    /*
     // this is the old code that did this
     u8 r1,g1,b1,r2,g2,b2,rn,gn,bn;
     r1 = col1 & 0x001F;
     g1 = (col1 >> 5) & 0x001F;
     b1 = (col1 >> 10) & 0x001F;
     r2 = col2 & 0x001F;
     g2 = (col2 >> 5) & 0x001F;
     b2 = (col2 >> 10) & 0x001F;
     rn = r1*alpha/255 + r2-r2*alpha/255;
     gn = g1*alpha/255 + g2-g2*alpha/255;
     bn = b1*alpha/255 + b2-b2*alpha/255;
     return RGB15(rn,gn,bn)|BIT(15);
     */
    gradient->resize(256);
    for (u16 alpha = 0; alpha < 256; ++alpha) {
        // This is the above code in 1 Line (faster)
        gradient->operator [](alpha) = RGB15((col1 & 0x001F)*alpha/255 + (col2 & 0x001F)-(col2 & 0x001F)*alpha/255,
                ((col1 >> 5) & 0x001F)*alpha/255 + ((col2 >> 5) & 0x001F)-((col2 >> 5) & 0x001F)*alpha/255,
                ((col1 >> 10) & 0x001F)*alpha/255 + ((col2 >> 10) & 0x001F)-((col2 >> 10) & 0x001F)*alpha/255
        ) | BIT(15);
    }
}
