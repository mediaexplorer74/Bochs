/////////////////////////////////////////////////////////////////////////
// $Id: voodoo_main.h 13418 2017-12-29 11:18:45Z vruppert $
/////////////////////////////////////////////////////////////////////////
/*
 *  Portion of this software comes with the following license
 */


#ifndef VOODOO_MAIN_H
#define VOODOO_MAIN_H

/* enumeration specifying which model of Voodoo we are emulating */
enum
{
  VOODOO_1,
  VOODOO_2,
  VOODOO_BANSHEE,
  VOODOO_3,
  MAX_VOODOO_TYPES
};


#define STD_VOODOO_1_CLOCK       50000000.0
#define STD_VOODOO_2_CLOCK       90000000.0
#define STD_VOODOO_BANSHEE_CLOCK 90000000.0
#define STD_VOODOO_3_CLOCK      132000000.0


/***************************************************************************
    TYPE DEFINITIONS
***************************************************************************/

#define VOODOO_MEM 0x60000000
#define VOODOO_REG_PAGES 1024
#define VOODOO_LFB_PAGES 1024
#define VOODOO_TEX_PAGES 2048
#define VOODOO_PAGES (VOODOO_REG_PAGES+VOODOO_LFB_PAGES+VOODOO_TEX_PAGES)

#define Voodoo_UpdateScreenStart() theVoodooDevice->update_screen_start()
#define Voodoo_Output_Enable(x)    theVoodooDevice->output_enable(x)
#define Voodoo_get_retrace(a)      theVoodooDevice->get_retrace(a)
#define Voodoo_update_timing()     theVoodooDevice->update_timing()
#define Voodoo_reg_write(a,b)      theVoodooDevice->reg_write(a,b)
#define Banshee_2D_write(a,b)      theVoodooDevice->blt_reg_write(a,b)
#define Banshee_LFB_write(a,b,c)   theVoodooDevice->mem_write_linear(a,b,c)

#endif
