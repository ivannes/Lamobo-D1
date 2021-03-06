#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
    
#include "AkFontLib.h"
    



typedef struct tag_FONT_LIST_ 
{
	T_FONT_CODE charcode;
	T_U8 *font16Data;
	T_U8 *font32Data;
}struct_font_list;


#define CODE_FONT(n)        {UNI_CODE_##n,CODE_##n##_FONT16,CODE_##n##_FONT32}

#define UNI_CODE_0     ('0')
#define UNI_CODE_1     ('1')
#define UNI_CODE_2     ('2')
#define UNI_CODE_3     ('3')
#define UNI_CODE_4     ('4')
#define UNI_CODE_5     ('5')
#define UNI_CODE_6     ('6')
#define UNI_CODE_7     ('7')
#define UNI_CODE_8     ('8')
#define UNI_CODE_9     ('9')
#define UNI_CODE_colon (':')
#define UNI_CODE_slash ('/')
#define UNI_CODE_Y     ('Y')
#define UNI_CODE_M     ('M')
#define UNI_CODE_D     ('D')
#define UNI_CODE_space (' ')


static const T_U8 CODE_0_FONT16[] = {//Font Size is 16
	0,6,1,255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x78,0x00,0x84,0x00,0x84,0x00,0x84,0x00,
	0x84,0x00,0x84,0x00,0x84,0x00,0x84,0x00,
	0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// Unicode:0x30
};



static const T_U8 CODE_0_FONT32[] = {//Font Size is 16
	1, 12, 1, 255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x1f,0x80,0x00,0x00,0x3f,0xc0,0x00,0x00,
	0x70,0xe0,0x00,0x00,0x70,0xe0,0x00,0x00,
	0x60,0x60,0x00,0x00,0xe0,0x70,0x00,0x00,
	0xe0,0x70,0x00,0x00,0xe0,0x70,0x00,0x00,
	0xe0,0x70,0x00,0x00,0xe0,0x70,0x00,0x00,
	0xe0,0x70,0x00,0x00,0xe0,0x70,0x00,0x00,
	0xe0,0x70,0x00,0x00,0xe0,0x70,0x00,0x00,
	0x60,0x60,0x00,0x00,0x70,0xe0,0x00,0x00,
	0x70,0xe0,0x00,0x00,0x3f,0xc0,0x00,0x00,
	0x1f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//0x0030
};

static const T_U8 CODE_1_FONT16[] = {//Font Size is 16 
	1,5,1,255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x20,0x00,0xe0,0x00,0x20,0x00,0x20,0x00,
	0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,
	0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// Unicode:0x31
};



static const T_U8 CODE_1_FONT32[] = {//Font Size is 32
	3, 9, 2, 255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x0c,0x00,0x00,0x00,0x1c,0x00,0x00,0x00,
	0x3c,0x00,0x00,0x00,0xfc,0x00,0x00,0x00,
	0xfc,0x00,0x00,0x00,0x1c,0x00,0x00,0x00,
	0x1c,0x00,0x00,0x00,0x1c,0x00,0x00,0x00,
	0x1c,0x00,0x00,0x00,0x1c,0x00,0x00,0x00,
	0x1c,0x00,0x00,0x00,0x1c,0x00,0x00,0x00,
	0x1c,0x00,0x00,0x00,0x1c,0x00,0x00,0x00,
	0x1c,0x00,0x00,0x00,0x1c,0x00,0x00,0x00,
	0x1c,0x00,0x00,0x00,0xff,0x80,0x00,0x00,
	0xff,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//0x0031
};


static const T_U8 CODE_2_FONT16[] = {//Font Size is 16 
	0,6,1,255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x78,0x00,0x84,0x00,0x04,0x00,0x04,0x00,
	0x08,0x00,0x30,0x00,0x40,0x00,0x80,0x00,
	0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// Unicode:0x32
};



static const T_U8 CODE_2_FONT32[] = {//Font Size is 16 
	1, 12, 1, 255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x3f,0x00,0x00,0x00,0xff,0xc0,0x00,0x00,
	0xe1,0xc0,0x00,0x00,0x80,0xe0,0x00,0x00,
	0x00,0xe0,0x00,0x00,0x00,0xe0,0x00,0x00,
	0x00,0xe0,0x00,0x00,0x00,0xe0,0x00,0x00,
	0x01,0xc0,0x00,0x00,0x03,0xc0,0x00,0x00,
	0x03,0x80,0x00,0x00,0x07,0x00,0x00,0x00,
	0x0e,0x00,0x00,0x00,0x1c,0x00,0x00,0x00,
	0x38,0x00,0x00,0x00,0x70,0x00,0x00,0x00,
	0xe0,0x00,0x00,0x00,0xff,0xf0,0x00,0x00,
	0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//0x0032
};




static const T_U8 CODE_3_FONT16[] = {//Font Size is 16
	0,6,1,255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x78,0x00,0x84,0x00,0x04,0x00,0x04,0x00,
	0x38,0x00,0x04,0x00,0x04,0x00,0x84,0x00,
	0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// Unicode:0x33
};

static const T_U8 CODE_3_FONT32[] = {//Font Size is 16
	1, 11, 2, 255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x1f,0x00,0x00,0x00,0x7f,0xc0,0x00,0x00,
	0x61,0xe0,0x00,0x00,0x40,0xe0,0x00,0x00,
	0x00,0xe0,0x00,0x00,0x00,0xe0,0x00,0x00,
	0x00,0xc0,0x00,0x00,0x01,0xc0,0x00,0x00,
	0x0f,0x00,0x00,0x00,0x0f,0x80,0x00,0x00,
	0x01,0xc0,0x00,0x00,0x00,0xe0,0x00,0x00,
	0x00,0xe0,0x00,0x00,0x00,0xe0,0x00,0x00,
	0x00,0xe0,0x00,0x00,0x81,0xe0,0x00,0x00,
	0xc3,0xc0,0x00,0x00,0xff,0x80,0x00,0x00,
	0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//0x0033
};


static const T_U8 CODE_4_FONT16[] = {//Font Size is 16
	0,6,1,255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x08,0x00,0x18,0x00,0x28,0x00,0x48,0x00,
	0x88,0x00,0xfc,0x00,0x08,0x00,0x08,0x00,
	0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// Unicode:0x34
};


static const T_U8 CODE_4_FONT32[] = {//Font Size is 16
	1, 13, 0, 255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0xe0,0x00,0x00,0x01,0xe0,0x00,0x00,
	0x03,0xe0,0x00,0x00,0x06,0xe0,0x00,0x00,
	0x0c,0xe0,0x00,0x00,0x18,0xe0,0x00,0x00,
	0x18,0xe0,0x00,0x00,0x30,0xe0,0x00,0x00,
	0x60,0xe0,0x00,0x00,0xc0,0xe0,0x00,0x00,
	0xff,0xf8,0x00,0x00,0xff,0xf8,0x00,0x00,
	0x00,0xe0,0x00,0x00,0x00,0xe0,0x00,0x00,
	0x00,0xe0,0x00,0x00,0x00,0xe0,0x00,0x00,
	0x00,0xe0,0x00,0x00,0x00,0xe0,0x00,0x00,
	0x00,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//0x0034
};


static const T_U8 CODE_5_FONT16[] = {//Font Size is 16
	0,6,1,255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xfc,0x00,0x80,0x00,0x80,0x00,0xf8,0x00,
	0x04,0x00,0x04,0x00,0x04,0x00,0x84,0x00,
	0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// Unicode:0x35
};


static const T_U8 CODE_5_FONT32[] = {//Font Size is 16
	2, 11, 1, 255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x7f,0xe0,0x00,0x00,0x7f,0xe0,0x00,0x00,
	0x70,0x00,0x00,0x00,0x70,0x00,0x00,0x00,
	0x70,0x00,0x00,0x00,0x70,0x00,0x00,0x00,
	0x70,0x00,0x00,0x00,0x7f,0x00,0x00,0x00,
	0x7f,0xc0,0x00,0x00,0x01,0xc0,0x00,0x00,
	0x00,0xe0,0x00,0x00,0x00,0xe0,0x00,0x00,
	0x00,0xe0,0x00,0x00,0x00,0xe0,0x00,0x00,
	0x00,0xe0,0x00,0x00,0x81,0xc0,0x00,0x00,
	0xe3,0xc0,0x00,0x00,0xff,0x80,0x00,0x00,
	0x3e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//0x0035
};


static const T_U8 CODE_6_FONT16[] = {//Font Size is 16
	0,6,1,255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x38,0x00,0x40,0x00,0x80,0x00,0xf8,0x00,
	0x84,0x00,0x84,0x00,0x84,0x00,0x84,0x00,
	0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// Unicode:0x36
};


static const T_U8 CODE_6_FONT32[] = {//Font Size is 16
	1, 12, 1, 255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x07,0xc0,0x00,0x00,0x1f,0xc0,0x00,0x00,
	0x3c,0x40,0x00,0x00,0x38,0x00,0x00,0x00,
	0x70,0x00,0x00,0x00,0x70,0x00,0x00,0x00,
	0xe0,0x00,0x00,0x00,0xef,0x80,0x00,0x00,
	0xff,0xe0,0x00,0x00,0xf0,0xe0,0x00,0x00,
	0xe0,0x70,0x00,0x00,0xe0,0x70,0x00,0x00,
	0xe0,0x70,0x00,0x00,0xe0,0x70,0x00,0x00,
	0xe0,0x70,0x00,0x00,0x70,0xe0,0x00,0x00,
	0x78,0xe0,0x00,0x00,0x3f,0xc0,0x00,0x00,
	0x0f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//0x0036
};


static const T_U8 CODE_7_FONT16[] = {//Font Size is 16
	0,6,1,255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xfc,0x00,0x04,0x00,0x08,0x00,0x08,0x00,
	0x10,0x00,0x10,0x00,0x20,0x00,0x20,0x00,
	0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// Unicode:0x37
};


static const T_U8 CODE_7_FONT32[] = {//Font Size is 16
	1, 12, 1, 255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xff,0xf0,0x00,0x00,0xff,0xf0,0x00,0x00,
	0x00,0x70,0x00,0x00,0x00,0x70,0x00,0x00,
	0x00,0xe0,0x00,0x00,0x00,0xe0,0x00,0x00,
	0x01,0xc0,0x00,0x00,0x01,0xc0,0x00,0x00,
	0x03,0x80,0x00,0x00,0x03,0x80,0x00,0x00,
	0x07,0x00,0x00,0x00,0x07,0x00,0x00,0x00,
	0x0e,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,
	0x1c,0x00,0x00,0x00,0x1c,0x00,0x00,0x00,
	0x38,0x00,0x00,0x00,0x38,0x00,0x00,0x00,
	0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//0x0037
};


static const T_U8 CODE_8_FONT16[] = {//Font Size is 16
	0,6,1,255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x78,0x00,0x84,0x00,0x84,0x00,0x84,0x00,
	0x78,0x00,0x84,0x00,0x84,0x00,0x84,0x00,
	0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// Unicode:0x38
};


static const T_U8 CODE_8_FONT32[] = {//Font Size is 16
	1, 12, 1, 255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x1f,0x80,0x00,0x00,0x3f,0xe0,0x00,0x00,
	0x70,0xe0,0x00,0x00,0xe0,0x70,0x00,0x00,
	0xe0,0x70,0x00,0x00,0xe0,0x70,0x00,0x00,
	0xf0,0x70,0x00,0x00,0x78,0xe0,0x00,0x00,
	0x3f,0xc0,0x00,0x00,0x3f,0xc0,0x00,0x00,
	0x71,0xe0,0x00,0x00,0xe0,0xf0,0x00,0x00,
	0xe0,0x70,0x00,0x00,0xe0,0x70,0x00,0x00,
	0xe0,0x70,0x00,0x00,0xf0,0x70,0x00,0x00,
	0x70,0xe0,0x00,0x00,0x3f,0xc0,0x00,0x00,
	0x1f,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//0x0038
};


static const T_U8 CODE_9_FONT16[] = {//Font Size is 16
	0,6,1,255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x78,0x00,0x84,0x00,0x84,0x00,0x84,0x00,
	0x84,0x00,0x7c,0x00,0x04,0x00,0x08,0x00,
	0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// Unicode:0x39
};


static const T_U8 CODE_9_FONT32[] = {
	1, 12, 1, 255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x0f,0x00,0x00,0x00,0x3f,0xc0,0x00,0x00,
	0x71,0xe0,0x00,0x00,0x70,0xe0,0x00,0x00,
	0xe0,0x70,0x00,0x00,0xe0,0x70,0x00,0x00,
	0xe0,0x70,0x00,0x00,0xe0,0x70,0x00,0x00,
	0xe0,0x70,0x00,0x00,0x70,0xf0,0x00,0x00,
	0x7f,0xf0,0x00,0x00,0x1f,0x70,0x00,0x00,
	0x00,0x70,0x00,0x00,0x00,0xe0,0x00,0x00,
	0x00,0xe0,0x00,0x00,0x01,0xc0,0x00,0x00,
	0x23,0xc0,0x00,0x00,0x3f,0x80,0x00,0x00,
	0x3e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//0x0039
};


static const T_U8 CODE_colon_FONT16[] = {//Font Size is 16
	2,1,2,255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x80,0x00,0x80,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,
	0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// Unicode:0x3a
};


static const T_U8 CODE_colon_FONT32[] = {//Font Size is 16
	3, 3, 3, 255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xe0,0x00,0x00,0x00,
	0xe0,0x00,0x00,0x00,0xe0,0x00,0x00,0x00,
	0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xe0,0x00,0x00,0x00,
	0xe0,0x00,0x00,0x00,0xe0,0x00,0x00,0x00,
	0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//0x003a
};


static const T_U8 CODE_slash_FONT16[] = {//Font Size is 16
	0,5,0,255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,
	0x08,0x00,0x10,0x00,0x10,0x00,0x10,0x00,
	0x20,0x00,0x20,0x00,0x40,0x00,0x40,0x00,
	0x40,0x00,0x80,0x00,0x80,0x00,0x00,0x00,// Unicode:0x2f
};

static const T_U8 CODE_slash_FONT32[] = {
	0, 10, 0, 255,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0xc0,0x00,0x00,
	0x01,0xc0,0x00,0x00,0x01,0x80,0x00,0x00,
	0x01,0x80,0x00,0x00,0x03,0x80,0x00,0x00,
	0x03,0x00,0x00,0x00,0x03,0x00,0x00,0x00,
	0x07,0x00,0x00,0x00,0x06,0x00,0x00,0x00,
	0x06,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,
	0x0c,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,
	0x1c,0x00,0x00,0x00,0x18,0x00,0x00,0x00,
	0x18,0x00,0x00,0x00,0x38,0x00,0x00,0x00,
	0x30,0x00,0x00,0x00,0x30,0x00,0x00,0x00,
	0x70,0x00,0x00,0x00,0x60,0x00,0x00,0x00,
	0x60,0x00,0x00,0x00,0xe0,0x00,0x00,0x00,
	0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//0x002f
};
//---------


#define FONT_NUM          (sizeof(font_list)/sizeof(struct_font_list))
#define FONT16_SIZE         (32)//32 Bytes per Font
#define FONT16_HEIGHT       (16)

static const struct_font_list font_list[] = {
		CODE_FONT(0),
		CODE_FONT(1),
		CODE_FONT(2),
		CODE_FONT(3),
		CODE_FONT(4),
		CODE_FONT(5),
		CODE_FONT(6),
		CODE_FONT(7),
		CODE_FONT(8),
		CODE_FONT(9),
		CODE_FONT(colon),
		CODE_FONT(slash),
};



T_U8 *FontLib_GetDataByCode(T_FONT_CODE code, T_eFONT_SIZE fontsize)
{
	T_S32 i = 0;

	for (i=0;i< FONT_NUM;i++)
	{
		if (code == font_list[i].charcode)
		{
			if (FONT_SIZE_32 == fontsize)
			{
				return font_list[i].font32Data;
			}
			
			else if (FONT_SIZE_16 == fontsize)
			{
				return font_list[i].font16Data;
			}
			else
			{
				return AK_NULL;
			}
		}
	}

	return AK_NULL;
}


