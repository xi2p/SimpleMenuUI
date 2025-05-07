/*
* @author  :  xi2p
* This file is based on the work of the following authors:
* @file	:  OLED_UI.h https://github.com/bdth-7777777/OLED_UI
*/
#ifndef __OLED_UI_H
#define __OLED_UI_H

#define OLED_UI 

#ifdef OLED_UI

#include "OLED_UI_Driver.h"
#include "OLED.h"


extern uint8_t OLED_DisplayBuf[OLED_HEIGHT/8][OLED_WIDTH];

#define TILES_STARTPOINT_Y			(6)
#define TILES_SCROLLBAR_Y			(4)
#define TILES_BOTTOM_DISTANCE		(0)
#define LINE_SLIP_SPEED			(0.5)
#define IF_DRAW_ARROR			(true)

#define FUNCTION_PREFIX			    "~"
#define SUBMENU_PREFIX				">"
#define RADIO_PREFIX				"*"
#define NONE_PREFIX					"-"

#define LINEPERFIX_DISTANCE			(2)
#define IF_WAIT_ANIMATION_FINISH          (true)

#define IF_START_UP_AND_DOWN_LONG_PRESS    (false)
#define PRESS_TIME                      (0.6)
#define CONTINUE_PRESS_TIME             (2.0)
#define PRESS_MOVE_SPEED                (5)
#define CONTINUE_PRESS_MOVE_SPEED       (1)

#define WINDOW_DATA_TEXT_DISTANCE           (4)
#define FADEOUT_TIME					(40)

#define FLOAT_POINT_LENGTH			(2)

#define REVERSE_RECTANGLE 				(0)
#define REVERSE_ROUNDRECTANGLE 		(1)
#define HOLLOW_RECTANGLE 					(2)
#define HOLLOW_ROUNDRECTANGLE 			(3)
#define REVERSE_BLOCK						(4)
#define NOT_SHOW							(5)

#define OLED_UI_FONT_8	   		 (8)
#define OLED_UI_FONT_12			  	(12)
#define OLED_UI_FONT_16		  		(16)
#define OLED_UI_FONT_20		  		(20)

#define CHINESE						(0)
#define ASCII						(1)
#define DARKMODE						true
#define LIGHTMODE						false

#define FLAGEND			  	      (0)
#define FLAGSTART		      (1)
#define ENTER_FLAGSTART	   		      (1)
#define BACK_FLAGSTART		      (2)

#define FULLSCREEN      1,1,OLED_WIDTH-2,OLED_HEIGHT-2

#define OLED_UI_BACK    			(0)
#define OLED_UI_ENTER   			(1)

#define MENU_TYPE_LIST				(0)
#define MENU_TYPE_TILES				(1)

#define UNLINEAR 			      (0)
#define PID_CURVE     	 	      (1)

#define WINDOW_RECTANGLE			(0)
#define WINDOW_ROUNDRECTANGLE		(1)

#define WINDOW_DATA_STYLE_NONE	    (0)
#define WINDOW_DATA_STYLE_FLOAT		(1)
#define WINDOW_DATA_STYLE_INT8		(2)
#define WINDOW_DATA_STYLE_INT16		(3)
#define WINDOW_DATA_STYLE_INT32		(4)
#define WINDOW_DATA_STYLE_INT64		(5)

typedef int8_t MenuStyle;
typedef int16_t MenuID;
typedef float MenuMovingSpeed;
typedef int8_t OLED_Font;
typedef int8_t MutexFlag;

typedef struct MenuID_Type{
	MenuID Safe;
	MenuID Unsafe;
}MenuID_Type;

typedef struct OLED_Point{
	float X;
	float Y;
} OLED_Point;

typedef struct  OLED_Area{
    float X;
    float Y;
    float Width;
    float Height;
} OLED_Area;

typedef struct OLED_Key{
	uint8_t Enter;
	uint8_t Back;
	uint8_t Up;
	uint8_t Down;
} OLED_Key;

typedef struct OLED_ChangeArea{
	OLED_Area CurrentArea;
	OLED_Area TargetArea;
	OLED_Area Error;
	OLED_Area LastError;
	OLED_Area Integral;
	OLED_Area Derivative;
}OLED_ChangeArea;

typedef struct OLED_ChangePoint{
	OLED_Point CurrentPoint;
	OLED_Point TargetPoint;
	OLED_Point Error;
	OLED_Point LastError;
	OLED_Point Integral;
	OLED_Point Derivative;
}OLED_ChangePoint;

typedef struct OLED_ChangeDistance{
	float CurrentDistance;
	float TargetDistance;
	float Error;
	float LastError;
	float Integral;
	float Derivative;
}OLED_ChangeDistance;

typedef struct OLED_UI_Counter{
	int16_t count;
	int16_t value;
	int16_t step;
}OLED_UI_Counter;

typedef struct OLED_UI_WindowSustainCounter{
	bool SustainFlag;
}OLED_UI_WindowSustainCounter;

typedef struct MenuWindow{
	int16_t General_Width;
	int16_t General_Height;
	uint8_t General_WindowType;

	const char* Text_String;
	OLED_Font Text_FontSize;
	int16_t Text_FontSideDistance;
	int16_t Text_FontTopDistance;

	float* Prob_Data_Float;
	int8_t* Prob_Data_Int_8;
	int16_t* Prob_Data_Int_16;
	int32_t* Prob_Data_Int_32;
	int64_t* Prob_Data_Int_64;
	float Prob_DataStep;
	float Prob_MinData;
	float Prob_MaxData;
	int16_t Prob_BottomDistance;
	int16_t Prob_SideDistance;
	int16_t Prob_LineHeight;

	float _LineSlip;
}MenuWindow;

typedef struct MenuPage {
    MenuStyle General_MenuType;
    uint8_t General_CursorStyle;
    OLED_Font General_FontSize;
    struct MenuPage* General_ParentMenuPage;
	int16_t General_LineSpace;
    uint8_t General_MoveStyle;
	MenuMovingSpeed General_MovingSpeed;
    void (*General_ShowAuxiliaryFunction)();
	struct MenuItem* General_MenuItems;

    OLED_Area List_MenuArea;
    bool List_IfDrawFrame;
    bool List_IfDrawLinePerfix;
	int16_t List_StartPointX;
    int16_t List_StartPointY;

    int16_t Tiles_ScreenWidth;
    int16_t Tiles_ScreenHeight;
    int16_t Tiles_TileWidth;
    int16_t Tiles_TileHeight;

    MenuID _ActiveMenuID;
    MenuID _Slot;
    OLED_Point _StartPoint;
	bool _IfInit;
} MenuPage;

typedef struct MenuItem {
    const char* General_item_text;
    void (*General_callback)();
    MenuPage* General_SubMenuPage;

    bool* List_BoolRadioBox;
    const uint8_t* Tiles_Icon;

    float _LineSlip;
} MenuItem;

void GetFPS();
void OLED_UI_ShowFPS();
OLED_Font GetOLED_Font(OLED_Font fontsize,bool style);
void ReverseCoordinate(int16_t X, int16_t Y, int16_t Width, int16_t Height,uint8_t Style);
void OLED_UI_FadeOut_Masking(int16_t x0, int16_t y0, int16_t width, int16_t height, int8_t fadeLevel);
void OLED_UI_FadeoutCurrentArea(int16_t x, int16_t y, int16_t width, int16_t height);
void OLED_UI_FadeoutAllArea();
MenuID GetMenuItemNum(MenuItem * items);
void ChangeFloatNum(float *CurrentNum, float *TargetNum, float *ErrorNum, float *LastErrorNum, float * IntegralNum, float *DerivativeNum);
void ChangeDistance(OLED_ChangeDistance *distance);
void ChangePoint(OLED_ChangePoint *point);
void ChangeArea(OLED_ChangeArea *area);
void CurrentMenuPageInit();
void CurrentMenuPageBackUp();
void OLED_UI_Init(MenuPage* Page);
bool GetEnterFlag();
bool GetFadeoutFlag();
int16_t CalcStringWidth(int16_t ChineseFont, int16_t ASCIIFont, const char *format, ...);
int8_t GetWindowProbDataStyle(MenuWindow* window);
void OLED_DrawWindow();
void MenuItemsMoveUp();
void MenuItemsMoveDown();
void MenuItemsMoveLeft();
void MenuItemsMoveRight();
int16_t GetCurrentMenuPageMaxSlotNum();
void SetTargetCursor();
void SetTargetMenuFrame();
void SetLineSplitZero();
void SetTargetScrollBarHeight();
void DrawLinePermix(MenuPage* page,MenuID i,OLED_Point* CursorPoint,OLED_Font ChineseFont,OLED_Font ASCIIFont);
void PrintMenuElements();
MenuID_Type OLED_KeyAndEncoderRecord();
void SetEnterFlag();
void ResetEnterFlag();
void SetFadeOutFlag(MutexFlag action);
void ResetFadeOutFlag();
void EnterEventMenuItem();
void BackEventMenuItem();
void OLED_UI_Back();
void RunCurrentCallBackFunction();
void SetCursorZero();
void OLED_UI_CreateWindow(MenuWindow* window);
void RunFadeOut();
void OLED_WindowDataDispose();
void MoveMenuElements();
void OLED_UI_MainLoop();
void OLED_UI_InterruptHandler();


#endif

#endif