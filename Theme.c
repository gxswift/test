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
#include "mygui.h"
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0 (GUI_ID_USER + 0x00)
#define ID_DROPDOWN_0 (GUI_ID_USER + 0x01)
#define ID_BUTTON_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_1 (GUI_ID_USER + 0x03)
#define ID_TEXT_0 (GUI_ID_USER + 0x04)


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
	{ FRAMEWIN_CreateIndirect, "Theme", ID_FRAMEWIN_0, 0, 50, 799, 449, 0, 0x64, 0 },
	{ DROPDOWN_CreateIndirect, "Dropdown", ID_DROPDOWN_0, 35, 51, 120, 80, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "OK", ID_BUTTON_0, 24, 194, 40, 40, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Cancel", ID_BUTTON_1, 122, 196, 40, 40, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "Text", ID_TEXT_0, 62, 15, 80, 20, 0, 0x64, 0 },
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


ColorChange C_Change[]=
{
	{ 0x000FFF, 0x00F0FF},
	{ 0x000FFF, 0x0080FF},
	{ 0x000FFF, 0x00F08F},
	{ 0xF0005F, 0x00F0FF},
	{ 0x800FFF, 0x00F000},
	{ 0x000FFF, 0x0080FF},
	{ 0x800FFF, 0x00F000},
	{ GUI_BLUE, 0x00F000},
	{ 0x800FFF, GUI_LIGHTBLUE}
};

int *BKbmp[] = {&bmapple};

int ColorSet;
static int color;
void Theme_Paint()
{
	GUI_DrawGradientV(0,0,799,449,C_Change[color].C1,C_Change[color].C2);
	
	GUI_SetAlpha(0x90);
	GUI_DrawBitmap(BKbmp[0], 300, 200);
	GUI_SetAlpha(0);
}


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

	// USER START (Optionally insert additional variables)
	// USER END

	switch (pMsg->MsgId) {
	case WM_PAINT:
		Theme_Paint ();


		break;
	case	WM_CREATE:

		WM_DisableMemdev(pMsg->hWin);
		break;
	case WM_INIT_DIALOG:
		//
		// Initialization of 'Framewin'
		//



		hItem = pMsg->hWin;
		FRAMEWIN_SetText(hItem, "Setting");
		FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		FRAMEWIN_SetTitleHeight(hItem, 20);
		FRAMEWIN_SetFont(hItem, GUI_FONT_20B_1);
		//
		// Initialization of 'Dropdown'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0);
		DROPDOWN_AddString(hItem, "Color1");
		DROPDOWN_AddString(hItem, "Color2");
		DROPDOWN_AddString(hItem, "Color3");
		DROPDOWN_AddString(hItem, "Color4");
		DROPDOWN_AddString(hItem, "Color5");
		DROPDOWN_AddString(hItem, "Color6");
		DROPDOWN_AddString(hItem, "Color7");
		DROPDOWN_AddString(hItem, "Color8");
		DROPDOWN_AddString(hItem, "Color9");
		DROPDOWN_SetAutoScroll(hItem, 1);

		DROPDOWN_SetFont(hItem, GUI_FONT_16B_ASCII);
		DROPDOWN_SetItemSpacing(hItem, 5);
		DROPDOWN_SetBkColor(hItem, DROPDOWN_CI_SEL, GUI_LIGHTBLUE);

		DROPDOWN_SetSel(hItem, color);
		//
		// Initialization of 'Text'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
		TEXT_SetFont(hItem, GUI_FONT_20_ASCII);
		TEXT_SetText(hItem, "COLOR");
		TEXT_SetTextColor(hItem, 0x0088C585);
		// USER START (Optionally insert additional code for further widget initialization)
		// USER END
		break;
	case WM_NOTIFY_PARENT:
		Id = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch (Id) {
		case ID_DROPDOWN_0: // Notifications sent by 'Dropdown'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_SEL_CHANGED:
				// USER START (Optionally insert code for reacting on notification message)
				hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0);
				color = DROPDOWN_GetSel(hItem);

				hItem = pMsg->hWin;
				WM_InvalidateWindow(hItem);
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_0: // Notifications sent by 'OK'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0);
				ColorSet = DROPDOWN_GetSel(hItem);
				CreateWinMain();
				hItem = pMsg->hWin;
				WM_DeleteWindow(hItem);
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_1: // Notifications sent by 'Cancel'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				CreateWinMain();
				hItem = pMsg->hWin;
				WM_DeleteWindow(hItem);
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
*       CreateFramewin
*/
WM_HWIN CreateFramewin1(void);
WM_HWIN CreateFramewin1(void) {
	WM_HWIN hWin;

	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
