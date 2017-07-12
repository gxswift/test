/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.28                          *
*        Compiled Jan 30 2015, 16:41:06                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"
#include "GUI.h"
#include "stdint.h"
#include "mygui.h"
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0 (GUI_ID_USER + 0x06)
#define ID_BUTTON_0 (GUI_ID_USER + 0x08)
#define ID_BUTTON_1 (GUI_ID_USER + 0x09)
// USER START (Optionally insert additional defines)
// USER END


#ifndef GUI_CONST_STORAGE
#define GUI_CONST_STORAGE const
#endif



// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
	{ WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 50, 800, 430, 0, 0x0, 0 },
	// { BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 210, 0, 25, 25, 0, 0x0, 0 },
	//  { BUTTON_CreateIndirect, "Button1", ID_BUTTON_1, 160, 260, 50, 50, 0, 0x0, 0 },
	// USER START (Optionally insert additional widgets)
	// USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

/* 用于桌面ICONVIEW图标的创建 */
typedef struct {
	const GUI_BITMAP * pBitmap;
	const char       * pText;
} BITMAP_ITEM;

/* 用于桌面ICONVIEW图标的创建 */
static const BITMAP_ITEM _aBitmapItem[] = {
	{ &bmgame, "Game" },
	{ &bmgit, "Git" },
	{ &bmkeil, "Keil MDK" },
	{ &bmmail, "Mail" },

	{ &bmQQ, "QQ" },
	{ &bmwechat, "WeChat" },
	{ &bmapple, "Apple" },
	{ &bmreturn, "Return" }
};
/*********************************************************************
*
*       _GetImageById
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
extern GUI_CONST_STORAGE GUI_BITMAP bmapple;
extern int Select;
extern int ColorSet;
extern void Clock_Fun();
extern void CreateWindow2();
extern WM_HWIN CreateTEXT(void);
extern WM_HWIN CreateFramewin1(void);
extern WM_HWIN CreatePalette(void);
//extern WM_HWIN Auto1(void);
//extern WM_HWIN Auto2(void);
int Dis_Flag;

static void _cbDialog(WM_MESSAGE * pMsg) {
	WM_HWIN      hItem;
	int          NCode;
	int          Id;
	ICONVIEW_Handle hIcon;
	//	int sel;

	// USER START (Optionally insert additional variables)
	// USER END

	switch (pMsg->MsgId) {

	case WM_PAINT:
		Theme_Paint();


		break;

	case WM_INIT_DIALOG:

		// USER START (Optionally insert additional code for further widget initialization)
		//	 hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
		//	BUTTON_SetText(hItem, "Press");


		// USER END
		break;
	case WM_NOTIFY_PARENT:
		Id = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch (Id) {
		case GUI_ID_ICONVIEW1:
			switch (NCode)
			{
			case WM_NOTIFICATION_CLICKED:

				switch (ICONVIEW_GetSel(pMsg->hWinSrc))//pMsg->hWinSrc
				{

				default: break;
				}

				break;

			case WM_NOTIFICATION_SCROLL_CHANGED:

				break;
			case WM_NOTIFICATION_RELEASED:

				switch (ICONVIEW_GetSel(pMsg->hWinSrc))//pMsg->hWinSrc
				{
				case 7:
					hItem = pMsg->hWin;
					GUI_EndDialog(hItem, 1);
					CreateWinMain();

					break;
				default:
					break;
				}
				break;
			}
			break;
		case ID_BUTTON_0: // Notifications sent by 'Button0'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				//						hItem = pMsg->hWin;
				//			WM_DeleteWindow(hItem);
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_1: // Notifications sent by 'Button1'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
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
*       CreateWindow
*/

WM_HWIN CreateWin6(void);
WM_HWIN CreateWin6(void) {
	WM_HWIN hWin;
	ICONVIEW_Handle hIcon;

	SCROLLBAR_Handle hScbar;
	int i;
	GUI_SetOrientation(0);
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);


	hIcon = ICONVIEW_CreateEx(0, 					/* 小工具的最左像素（在父坐标中）*/
		0, 					/* 小工具的最上像素（在父坐标中）*/
		800,    /* 小工具的水平尺寸（单位：像素）*/
		450, 	/* 小工具的垂直尺寸（单位：像素）*/
		hWin,//WM_HBKWIN, 				        /* 父窗口的句柄。如果为0 ，则新小工具将成为桌面（顶级窗口）的子窗口 */
		WM_CF_SHOW | WM_CF_HASTRANS,       /* 窗口创建标记。为使小工具立即可见，通常使用 WM_CF_SHOW */
		0,//ICONVIEW_CF_AUTOSCROLLBAR_V, 	/* 默认是0，如果不够现实可设置增减垂直滚动条 */
		GUI_ID_ICONVIEW1, 			        /* 小工具的窗口ID */
		180,//64, 				    /* 图标的水平尺寸 */
		190);/* 图标的垂直尺寸 */

	ICONVIEW_SetSpace(hIcon, GUI_COORD_X, 20);
	ICONVIEW_SetSpace(hIcon, GUI_COORD_Y, 30);
	ICONVIEW_SetFont(hIcon, &GUI_Font32B_ASCII);

	ICONVIEW_SetIconAlign(hIcon, ICONVIEW_IA_TOP);

	for (i = 0; i < GUI_COUNTOF(_aBitmapItem); i++)
	{

		ICONVIEW_AddBitmapItem(hIcon, _aBitmapItem[i].pBitmap, _aBitmapItem[i].pText);
	}
	ICONVIEW_SetTextColor(hIcon, ICONVIEW_CI_UNSEL, GUI_BLUE);
	ICONVIEW_SetTextColor(hIcon, ICONVIEW_CI_SEL, GUI_RED);

	ICONVIEW_SetBkColor(hIcon, ICONVIEW_CI_BK, GUI_LIGHTBLUE | 0x30000000);
	ICONVIEW_SetBkColor(hIcon, ICONVIEW_CI_SEL, GUI_LIGHTGREEN | 0x80000000);
	ICONVIEW_SetBkColor(hIcon, ICONVIEW_CI_DISABLED, GUI_LIGHTCYAN | 0xa0000000);

	return hWin;
}
