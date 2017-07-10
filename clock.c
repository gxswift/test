/*
*********************************************************************************************************
*	                                  
*
*********************************************************************************************************
*/
#include "GUI.h"
#include <math.h>
#include <stddef.h>
#include "DIALOG.h"
#include "stdio.h"

#define countof(Obj) (sizeof(Obj) / sizeof(Obj[0]))
#define DEG2RAD      (3.1415926f / 180)
#define MAG          4

static const GUI_POINT _aNeedle[] = {
  { MAG * ( -2), MAG * (  0 ) },
  { MAG * (-2), MAG * (-80 ) },
  { MAG * (0), MAG * (-105 ) },
  { MAG * ( 2), MAG * (-80 ) },
  { MAG * ( 2), MAG * (0 ) },
};

static const GUI_POINT _aNeedle1[] = {
  { MAG * ( -2), MAG * (  0 ) },
  { MAG * (-4), MAG * (-50 ) },
  { MAG * (0), MAG * (-65 ) },
  { MAG * ( 4), MAG * (-50 ) },
  { MAG * ( 2), MAG * (0 ) },
};

static const GUI_POINT _aNeedle2[] = {
  { MAG * ( -2), MAG * (  0 ) },
  { MAG * (-3), MAG * (-40 ) },
  { MAG * (0), MAG * (-55 ) },
  { MAG * ( 3), MAG * (-40 ) },
  { MAG * ( 2), MAG * (0 ) },
};

/*
*********************************************************************************************************
*                                       ????
*********************************************************************************************************
*/ 
typedef struct {
  GUI_AUTODEV_INFO AutoDevInfo;  // Information about what has to be displayed
  GUI_POINT        aPoints[7];   // Polygon data
  float            Angle;
  
  GUI_POINT        aPoints1[7];   // Polygon data
  float            Angle1;
	
  GUI_POINT        aPoints2[7];   // Polygon data
  float            Angle2;
} PARAM;

int Select;
static void _Draw(void * p) {
	PARAM * pParam;

	pParam = (PARAM *)p;

//»­±íÅÌ
	
	GUI_DrawGradientV(0,0,239,240, 0x00FFFF, 0x0000FF);
	GUI_SetColor(GUI_DARKYELLOW);
//	GUI_ClearRect(15,45,225,275);
GUI_DrawRoundedFrame(13,19,227,233,40,3);
	//	  GUI_SelectLayer(1);
	 
//	GUI_FillCircle(120,143,105);
//	GUI_SetFont(GUI_FONT_32_ASCII);
//	GUI_DispStringHCenterAt("CLOLK", LCD_GetXSize()/2, 2);
	/* ??????? ************************************************************/


	}

/*
*********************************************************************************************************
*	? ? ?: _DemoScale
*	????: ????
*	?    ?:?
*	? ? ?: ?
*********************************************************************************************************
*/
GUI_AUTODEV AutoDev;      /* ???? */
	PARAM       Param;        /* PARAM???? */

static   int         t0 = 36000;   /* ????????? */
	 static int         t1 = 36000;
    static float        t2 = 36000;
static int flag = 0;







/********************************************************************************************************/



#define ID_FRAMEWIN_0 (GUI_ID_USER + 0x00)
#define ID_BUTTON_0 (GUI_ID_USER + 0x01)
#define ID_PROGBAR_0 (GUI_ID_USER + 0x02)

// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "CLOCK", ID_FRAMEWIN_0, 0, 0, 240, 320, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 100, 250, 40, 40, 0, 0x0, 0 },
	  { PROGBAR_CreateIndirect, "Progbar", ID_PROGBAR_0, 10, 290, 220, 20, 0, 0x0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/

extern WM_HWIN CreateWindow(void);
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
//	char pnt[20];
//	static WM_HTIMER hTimerTime; 
//	GUI_RECT pRect = {15,45,225,275};
  // USER START (Optionally insert additional variables)
  // USER END
	//	GUI_RECT pRect = { 2, 40, 100, 60 };
  switch (pMsg->MsgId) {
		
//				  case WM_DELETE:
//    WM_DeleteTimer(hTimerTime);
//    break;
//		  case WM_CREATE:
//    
//    /* Create timer */
//    hTimerTime = WM_CreateTimer(pMsg->hWin, 0, 30, 0);
//    break;
		case WM_INIT_DIALOG:
			hItem = WM_GetDialogItem(pMsg->hWin,ID_PROGBAR_0);
	PROGBAR_SetFont(hItem,&GUI_Font16B_ASCII);
		PROGBAR_SetTextColor(hItem,0,0x0000FF);
		PROGBAR_SetTextColor(hItem,1,0xFF0000);
		break;
		case WM_PAINT:
//WM_SetDesktopColor(GUI_LIGHTBLUE);
	GUI_DrawGradientV(0,0,239,319, 0x00FFFF, 0x0000FF);
	GUI_SetColor(GUI_DARKYELLOW);
//	GUI_ClearRect(15,45,225,275);
GUI_DrawRoundedFrame(13,19,227,233,40,3);
				Param.Angle= t0;
		Param.Angle *= 3.1415926f / 18000;
		GUI_RotatePolygon(Param.aPoints, _aNeedle, countof(_aNeedle), Param.Angle);

		/* ??????? */
		Param.Angle1= t1;
		Param.Angle1 *= 3.1415926f / 18000;
		GUI_RotatePolygon(Param.aPoints1, _aNeedle1, countof(_aNeedle1), Param.Angle1);

		/* ??????? */
		Param.Angle2= t2;
		Param.Angle2 *= 3.1415926f / 18000;
		GUI_RotatePolygon(Param.aPoints2, _aNeedle2, countof(_aNeedle2), Param.Angle2);
		
			
	GUI_SetColor(GUI_WHITE|0x50000000);
	GUI_AA_FillPolygon(Param.aPoints2, countof(_aNeedle2), MAG * 120, MAG * 126);

	GUI_SetColor(GUI_BLUE|0x30000000);
	GUI_AA_FillPolygon(Param.aPoints1, countof(_aNeedle1), MAG * 120, MAG * 126);	
	
	GUI_SetColor(GUI_GREEN|0x20000000);
	GUI_AA_FillPolygon(Param.aPoints, countof(_aNeedle), MAG * 120, MAG * 126);
	
	GUI_SetColor(GUI_LIGHTBLUE);
	GUI_AA_FillCircle(MAG * 120, MAG * 126,MAG * 4);
	
	if (Select == 1)
	{
	GUI_SetColor(GUI_RED);
	GUI_AA_DrawArc(MAG * 120, MAG * 126,MAG *100,MAG *100,0,360);
	}
	if (Select == 2)
	{
	GUI_SetColor(GUI_GREEN);
	GUI_AA_DrawArc(MAG * 120, MAG * 126,100,60,0,360);
	}
		
		break;
		
	case WM_TIMER:
//			GUI_MEMDEV_CreateAuto(&AutoDev);
			WM_RestartTimer(pMsg->Data.v,60);
		t0-= 120;
		if(t0 < 0)
		{
			t0 = 36000;
		}

		t1-= 10;
		if(t1 < 0)
		{
			t1 = 36000;
		}

		t2-= 1;
		if(t2 < 0)
		{
			t2 = 36000;
		}

		
//						GUI_MEMDEV_CreateAuto(&AutoDev);
//		GUI_MEMDEV_DrawAuto(&AutoDev, &Param.AutoDevInfo, &_Draw, &Param);
//					GUI_MEMDEV_DeleteAuto(&AutoDev);
		
		PROGBAR_SetValue(WM_GetDialogItem(pMsg->hWin, ID_PROGBAR_0),100-t0/360);
//WM_InvalidateArea(&pRect);
WM_InvalidateWindow(pMsg->hWin);
			break;

  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
			hItem = pMsg->hWin;
		
			//WM_DeleteWindow(hItem);			
	//		WM_DeleteTimer(hTimer);	
			GUI_EndDialog(hItem,1);
			CreateWinMain();
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateCLOCK
*/
WM_HWIN CreateCLOCK(void);
WM_HWIN CreateCLOCK(void) {
  WM_HWIN hWin;
WM_HTIMER          hTimer;
  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	hTimer = WM_CreateTimer(WM_GetClientWindow(hWin),0,100,0);
  return hWin;
}

void Clock_Fun()
{
	t0 = 36000;  
    t1 = 36000;
   t2 = 36000;
//		  GUI_SelectLayer(0);
//	GUI_SetBkColor(GUI_BLACK); 
//	GUI_SelectLayer(1); 
		/* ????? */
	GUI_AA_EnableHiRes();
	/* ??????? */
	GUI_AA_SetFactor(MAG);
	CreateCLOCK();
	

//	while(1)
//	{
//		GUI_Exec();
//		GUI_X_ExecIdle();
//	}
}
