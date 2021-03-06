/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.32                          *
*        Compiled Oct  8 2015, 11:59:02                              *
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
#define ID_WINDOW_0 (GUI_ID_USER + 0x00)
#define ID_LISTVIEW_0 (GUI_ID_USER + 0x01)
#define ID_BUTTON_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_1 (GUI_ID_USER + 0x03)
#define ID_BUTTON_2 (GUI_ID_USER + 0x04)
#define ID_BUTTON_3 (GUI_ID_USER + 0x05)
#define ID_BUTTON_4 (GUI_ID_USER + 0x06)
#define ID_BUTTON_5 (GUI_ID_USER + 0x07)
#define ID_BUTTON_6 (GUI_ID_USER + 0x08)
#define ID_BUTTON_7 (GUI_ID_USER + 0x09)
#define ID_PROGBAR_0 (GUI_ID_USER + 0x0A)
#define ID_PROGBAR_1 (GUI_ID_USER + 0x0B)


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
	{ WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 50, 800, 430, 0, 0x0, 0 },
	{ LISTVIEW_CreateIndirect, "Listview", ID_LISTVIEW_0, 20, 20, 400, 380, 0, 0x0, 0 },

	{ BUTTON_CreateIndirect, "Stop", ID_BUTTON_0, 681, 340, 60, 40, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "EXIT", ID_BUTTON_1, 480, 280, 100, 80, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Start", ID_BUTTON_4, 680, 270, 60, 40, 0, 0x0, 0 },



	{ PROGBAR_CreateIndirect, "Progbar", ID_PROGBAR_0, 440, 20, 310, 20, 0, 0x0, 0 },
	{ PROGBAR_CreateIndirect, "Progbar", ID_PROGBAR_1, 440, 60, 310, 20, 0, 0x0, 0 },
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
static const char * _aTable_1[][3] = {
	{ "2017-1-1", "10:20", "Item 1" },
	{ "2017-1-2", "10:20", "Item 2" },
	{ "2017-1-3", "10:52", "Item 3" },
	{ "2017-1-4", "10:56", "Item 4" },
	{ "2017-1-5", "10:22", "Item 5" },
	{ "2017-1-6", "10:20", "Item 6" },
	{ "2017-1-7", "10:20", "Item 7" },
	{ "2017-1-8", "10:20", "Item 8" },
	{ "2017-2-5", "10:22", "Item 9" },
	{ "2017-2-6", "10:20", "Item 10" },
	{ "2017-2-7", "10:20", "Item 11" },
	{ "2017-2-8", "10:20", "Item 12" },
	{ "2017-3-5", "10:22", "Item 13" },
	{ "2017-3-6", "10:20", "Item 14" },
	{ "2017-3-7", "10:20", "Item 15" },
	{ "2017-3-8", "10:20", "Item 16" }
};

// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
	WM_HWIN hItem;
	static WM_HTIMER hTimer;
	SCROLLBAR_Handle hScrb;
	int     NCode;
	int     Id;
	int	i;
	static int cnt = 0;
	static int Start_Flag;
	// USER START (Optionally insert additional variables)
	// USER END

	switch (pMsg->MsgId) {
	case WM_CREATE:
		Start_Flag = 0;
		cnt = 0;
		break;
	case WM_PAINT:
		Theme_Paint();


		break;
	case WM_INIT_DIALOG:
		//
		// Initialization of 'Listview'
		//
		cnt = 0;
		Start_Flag = 0;
		hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTVIEW_0);
		LISTVIEW_AddColumn(hItem, 130, "date", GUI_TA_HCENTER | GUI_TA_VCENTER);
		LISTVIEW_AddColumn(hItem, 70, "time", GUI_TA_HCENTER | GUI_TA_VCENTER);
		LISTVIEW_AddColumn(hItem, 200, "data", GUI_TA_HCENTER | GUI_TA_VCENTER);
		LISTVIEW_SetGridVis(hItem, 1);
		// USER START (Optionally insert additional code for further widget initialization)
		hScrb = SCROLLBAR_CreateAttached(hItem, GUI_ID_VSCROLL);
		SCROLLBAR_SetWidth(hScrb, 20);

		for (i = 0; i < GUI_COUNTOF(_aTable_1); i++) {
			LISTVIEW_AddRow(hItem, _aTable_1[i]);
		}
		LISTVIEW_SetFont(hItem, &GUI_Font24_ASCII);
		LISTVIEW_SetHeaderHeight(hItem, 30);
		LISTVIEW_SetBkColor(hItem, LISTVIEW_CI_UNSEL, GUI_LIGHTCYAN);
		LISTVIEW_SetRowHeight(hItem, 30);

		hItem = WM_GetDialogItem(pMsg->hWin, ID_PROGBAR_0);
		PROGBAR_SetFont(hItem, &GUI_Font20B_1);

		hItem = WM_GetDialogItem(pMsg->hWin, ID_PROGBAR_1);
		PROGBAR_SetFont(hItem, &GUI_Font20B_1);

		// USER END
		break;
	case WM_TIMER:
		//Music_timer(pMsg);

		hItem = WM_GetDialogItem(pMsg->hWin, ID_PROGBAR_1);
		PROGBAR_SetValue(hItem, cnt);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_PROGBAR_0);
		PROGBAR_SetValue(hItem, cnt / 10 * 10);
		if (cnt++ == 100)
			cnt = 0;
		WM_RestartTimer(pMsg->Data.v, 50);
		break;

	case WM_NOTIFY_PARENT:
		Id = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch (Id) {
		case ID_LISTVIEW_0: // Notifications sent by 'Listview'
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
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_0: // Notifications sent by 'Stop'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				if (Start_Flag)
				{
					WM_DeleteTimer(hTimer);
					Start_Flag = 0;
				}
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
		case ID_BUTTON_1: // Notifications sent by 'Control'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				WM_DeleteWindow(pMsg->hWin);
				CreateWinMain();
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_4: // Notifications sent by 'Start'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				if (!Start_Flag)
				{
					Start_Flag = 1;
					hTimer = WM_CreateTimer(pMsg->hWin, 0, 10, 0);
				}
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
WM_HWIN CreateWin1(void);
WM_HWIN CreateWin1(void) {
	WM_HWIN hWin;

	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
