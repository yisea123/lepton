/*
The contents of this file are subject to the Mozilla Public License Version 1.1
(the "License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at http://www.mozilla.org/MPL/

Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License for the
specific language governing rights and limitations under the License.

The Original Code is Lepton.

The Initial Developer of the Original Code is Chauvin-Arnoux.
Portions created by Chauvin-Arnoux are Copyright (C) 2011. All Rights Reserved.

Alternatively, the contents of this file may be used under the terms of the eCos GPL license
(the  [eCos GPL] License), in which case the provisions of [eCos GPL] License are applicable
instead of those above. If you wish to allow use of your version of this file only under the
terms of the [eCos GPL] License and not to allow others to use your version of this file under
the MPL, indicate your decision by deleting  the provisions above and replace
them with the notice and other provisions required by the [eCos GPL] License.
If you do not delete the provisions above, a recipient may use your version of this file under
either the MPL or the [eCos GPL] License."
*/

/*============================================
| Includes
==============================================*/
#include "kernel/core/types.h"
#include "kernel/core/interrupt.h"
#include "kernel/core/kernel.h"
#include "kernel/core/system.h"
#include "kernel/core/fcntl.h"
#include "kernel/core/ioctl_lcd.h"
#include "kernel/core/ioctl_fb.h"


#include "kernel/fs/vfs/vfsdev.h"

#include "kernel/dev/arch/arm9/at91sam9261/dev_at91sam9261_lcd/at91sam9261_lcd_lut.h"
#include "kernel/dev/arch/arm9/at91sam9261/dev_at91sam9261_lcd/at91sam9261_lcd.h"
#include "kernel/dev/arch/arm9/at91sam9261/dev_at91sam9261_lcd/dev_at91sam9261_lcd.h"

#if defined(USE_SEGGER)
   #include <ioat91sam9261.h>
   #include "kernel/core/ucore/embOSARM7_332/arch/cpu_at91sam9261/at91sam9261_init.h"
#endif

#include "kernel/dev/arch/arm9/at91sam9261/dev_at91sam9261_cpu/dev_at91sam9261_cpu.h"


/*============================================
| Global Declaration
==============================================*/
static int dev_at91sam9261_ek_lcd_load(void);

dev_map_t dev_at91sam9261_ek_lcd_map={
   dev_at91sam9261_lcd_name,
   S_IFBLK,
   dev_at91sam9261_ek_lcd_load,
   dev_at91sam9261_lcd_open,
   dev_at91sam9261_lcd_close,
   __fdev_not_implemented,
   __fdev_not_implemented,
   dev_at91sam9261_lcd_read,
   dev_at91sam9261_lcd_write,
   dev_at91sam9261_lcd_seek,
   dev_at91sam9261_lcd_ioctl
};

//240x320x8
static const dev_panel_info_t atmel_at91sam9261_ek_panel_info = {
   240, //640,      //  vl_col:    Number of columns (i.e. 640)
   320, //480,      //  vl_row:    Number of rows (i.e. 480)
   64, //132,      //  vl_width:  Width of display area in millimeters
   86, //99,       //  vl_height: Height of display area in millimeters
   25000000, //4965000,//25000000,    //  vl_pixclock:

   /* LCD configuration register */
   0, // vl_clkp;  Clock polarity   => Normal
   0, // vl_oep;   Output Enable polarity   => Normal
      //FB_SYNC_HOR_HIGH_ACT,  //   vl_hsp:     Horizontal Sync polarity   => Normal
   0,  //   vl_hsp:     Horizontal Sync polarity   => Inversed
   0, // vl_vsp:     Vertical Sync polarity   => Inversed
      //FB_SYNC_VERT_HIGH_ACT, //   vl_vsp:     Vertical Sync polarity   => Normal
   0,   //  vl_dp;    Data polarity   => Normal
   3,   //  vl_bpix;  Bits per pixel, 0 = 1, 1 = 2, 2 = 4, 3 = 8, 4 = 16   => 8 bits
   0,   //  vl_lbw;   LCD Bus width, 0 = 4, 1 = 8
   0,   //  vl_splt;  Split display, 0 = single-scan, 1 = dual-scan
   1, //0,//1,   //  vl_clor;   Color, 0 = mono, 1 = color
   1,   //  vl_tft:     0 = passive, 1 = TFT

   /* Horizontal control Timing */
   5,  //   vl_hpw:  Horiz pulse width  =>  5 x t_clk
   1,  //   vl_blw:  Horiz back porch   => 10 x t_clk (Optrex)     0 x t_clk (Nec)
   33,  //  vl_elw:  Horiz front porch  => 33 x t_clk (Optrex)   160 x t_clk (Nec)
   /* Vertical control Timing */
   1, //4,   //    vl_vpw:  Vertic pulse width =>  4 x t_ligne
   1, //20,   //   vl_bfw:  Vertic back porch  => 20 x t_ligne (Optrex)    45 x t_clk (Nec)
   0 //20,   // vl_efw:  Vertic front porch => 20 x t_ligne (Optrex)     0 x t_clk (Nec)
};

/*===========================================
Implementation
=============================================*/
/*--------------------------------------------
| Name:        dev_at91sam9261_ek_eth_dm9000_load
| Description:
| Parameters:  none
| Return Type: none
| Comments:
| See:
----------------------------------------------*/
static int dev_at91sam9261_ek_lcd_load(void){
   return dev_at91sam9261_lcd_load((dev_panel_info_t *)&atmel_at91sam9261_ek_panel_info);
}


/*============================================
| End of Source  : dev_at91sam9261-ek_lcd.c
==============================================*/
