#ifndef __MINISTM32_LCD_H__
#define __MINISTM32_LCD_H__

#define Set_Cs  GPIOC->BSRR = GPIO_Pin_8;
#define Clr_Cs  GPIOC->BRR = GPIO_Pin_8;

#define Set_Rs  GPIOC->BSRR = GPIO_Pin_9;
#define Clr_Rs  GPIOC->BRR = GPIO_Pin_9;

#define Set_nWr GPIOC->BSRR = GPIO_Pin_10;
#define Clr_nWr GPIOC->BRR = GPIO_Pin_10;

#define Set_nRd GPIOC->BSRR = GPIO_Pin_11;
#define Clr_nRd GPIOC->BRR = GPIO_Pin_11;

#define Set_Rst GPIOC->BSRR = GPIO_Pin_12;
#define Clr_Rst GPIOC->BRR = GPIO_Pin_12;

#define Lcd_Light_ON   GPIOC->BSRR = GPIO_Pin_13;
#define Lcd_Light_OFF  GPIOC->BRR = GPIO_Pin_13;


/* LCD color */
#define LCD_White          0xFFFF
#define LCD_Black          0x0000
#define LCD_Blue           0x001F
#define LCD_Orange         0xFA20
#define LCD_Red            0xF800
#define LCD_Magenta        0xF81F
#define LCD_Green          0x07E0
#define LCD_Cyan           0x07FF
#define LCD_Yellow         0xFFE0
#define LCD_DarkBlue       0x0003
#define LCD_Gray		   0x7BEF

#define LCD_NCS_GPIO_PORT	GPIOC
#define LCD_NCS_PIN			GPIO_Pin_8

/**
 * @brief  LCD orientation and limits
 */

typedef enum {
	LCD_PORTRAIT_TOP_DOWN,
	LCD_PORTRAIT_BOTTOM_UP,
	LCD_LANDSCAPE_TOP_DOWN,
	LCD_LANDSCAPE_BOTTOM_UP,
} LCD_OrientationMode_t;

#define LCD_WIDTH_HW         240
#define LCD_HEIGHT_HW        320

#define LCD_PORTRAIT           0
#define LCD_LANDSCAPE          1
// #define LCD_ORIENTATION        LCD_PORTRAIT
#define LCD_ORIENTATION        LCD_LANDSCAPE

#if LCD_ORIENTATION == LCD_PORTRAIT
	#define LCD_WIDTH              240
	#define LCD_HEIGHT             320
	#define LCD_CHARS_PER_LINE      10
	#define LCD_CHAR_LINES          13
	#define LCD_ENTRY_MODE_DEFAULT 0x1030 /* Entry Mode BGR=1,AM=0,ID1/0=1/1 */
	#define LCD_ORIENTATION_DEFAULT LCD_PORTRAIT_TOP_DOWN
#else
	#define LCD_WIDTH              320
	#define LCD_HEIGHT             240
	#define LCD_CHARS_PER_LINE      15
	#define LCD_CHAR_LINES          10
	#define LCD_ENTRY_MODE_DEFAULT 0x1018 /* Entry Mode BGR=1,AM=1,ID1/0=1/0 */
	#define LCD_ORIENTATION_DEFAULT LCD_LANDSCAPE_TOP_DOWN
#endif

#define LCD_LINE_HORIZONTAL     0x00
#define LCD_LINE_VERTICAL       0x01

/* Exported_Functions */
void LCD_Init(void);
void LCD_Configuration(void);
void LCD_Reset(void);
void LCD_WriteRegister(u16 index,u16 dat);
void LCD_SetCursor(u16 x,u16 y);
void LCD_SetWindows(u16 StartX,u16 StartY,u16 EndX,u16 EndY);
void LCD_DrawPicture(u16 StartX,u16 StartY,u16 EndX,u16 EndY,u16 *pic);
void LCD_SetPoint(u16 x,u16 y,u16 point);
void LCD_PutChar(u16 x,u16 y,u8 c,u16 charColor,u16 bkColor);
void LCD_Text(u16 x, u16 y, const char *text, u16 charColor, u16 bkColor);
void LCD_Text2(u16 x, u16 y, char *text, u16 charColor, u16 bkColor);
void LCD_Clear(u16 bkColor);
void LCD_ClearArea(u16 x0, u16 y0, u16 x1, u16 y1, u16 bkColor);
void LCD_Delay(u32 nCount);
void LCD_Test(void);
void LCD_WriteData(u16 dat);
void LCD_WriteIndex(u16 idx);

void LCD_DrawMonoPict(unsigned char *Pict);

void LCD_BackLight(u8 status);

u16 LCD_BGR2RGB(u16 c);

u16 LCD_GetPoint(u16 x,u16 y);
u16 LCD_ReadData(void);
u16 LCD_ReadRegister(u16 index);

static __INLINE uint16_t LCD_RGB2Pixel565(uint8_t r, uint8_t g, uint8_t b)
{
	/* RGB2PIXEL565 from a Macro in Greg Haerr's Nano-X, MPL license */
	return ((((r) & 0xf8) << 8) | (((g) & 0xfc) << 3) | (((b) & 0xf8) >> 3));
}

void LCD_SetOrientation(LCD_OrientationMode_t m);
LCD_OrientationMode_t LCD_GetOrientation(void);
uint16_t LCD_GetWidth(void);
uint16_t LCD_GetHeight(void);

void LCD_DrawLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length, uint8_t Direction);
void LCD_DrawRect(uint16_t Xpos, uint16_t Ypos, uint16_t Height, uint16_t Width);
void LCD_DrawBox(uint16_t Xpos, uint16_t Ypos, uint16_t Height, uint16_t Width);

#endif	// __MINISTM32_LCD_H__

