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
#define ID_MULTIEDIT_0 (GUI_ID_USER + 0x21)

#define ID_BUTTON_0 (GUI_ID_USER + 0x24)
#define ID_BUTTON_1 (GUI_ID_USER + 0x25)
#define ID_BUTTON_2 (GUI_ID_USER + 0x26)
#define ID_BUTTON_3 (GUI_ID_USER + 0x27)

#define MSG_PIN_CHANGED (WM_USER+1)
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
  { BUTTON_CreateIndirect, "cancle", ID_BUTTON_0, 600, 300, 60, 60, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "OK", ID_BUTTON_2, 600, 80, 60, 60, 0, 0x0, 0 },

  { BUTTON_CreateIndirect, "Visible", ID_BUTTON_3, 250, 300, 60, 45, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "NUM", ID_BUTTON_1, 80, 300, 60, 45, 0, 0x0, 0 },

  { MULTIEDIT_CreateIndirect, "Multiedit", ID_MULTIEDIT_0, 50, 70, 300, 68, 0, 0x0, 0 }


  // USER START (Optionally insert additional widgets)
  // USER END
};
static const GUI_WIDGET_CREATE_INFO _bDialogCreate[] = {
	{ FRAMEWIN_CreateIndirect, "Number Pad", GUI_ID_USER + 12, 400, 130, 170, 250, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "7", GUI_ID_USER + 7, 10, 10, 40, 40 },
	{ BUTTON_CreateIndirect, "8", GUI_ID_USER + 8, 60, 10, 40, 40 },
	{ BUTTON_CreateIndirect, "9", GUI_ID_USER + 9, 110, 10, 40, 40 },
	{ BUTTON_CreateIndirect, "4", GUI_ID_USER + 4, 10, 60, 40, 40 },
	{ BUTTON_CreateIndirect, "5", GUI_ID_USER + 5, 60, 60, 40, 40 },
	{ BUTTON_CreateIndirect, "6", GUI_ID_USER + 6, 110, 60, 40, 40 },
	{ BUTTON_CreateIndirect, "1", GUI_ID_USER + 1, 10, 110, 40, 40 },
	{ BUTTON_CreateIndirect, "2", GUI_ID_USER + 2, 60, 110, 40, 40 },
	{ BUTTON_CreateIndirect, "3", GUI_ID_USER + 3, 110, 110, 40, 40 },
	{ BUTTON_CreateIndirect, "0", GUI_ID_USER + 0, 10, 160, 40, 40 },
	{ BUTTON_CreateIndirect, ".", GUI_ID_USER + 10, 60, 160, 40, 40 },
	{ BUTTON_CreateIndirect, "Del", GUI_ID_USER + 11, 110, 160, 40, 40 }
};
/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

char num[7];
int cnt;
char Pass_Flag;
static int Numpad_Flag;
static void _cbDialogNumPad(WM_MESSAGE * pMsg)
{
	int NCode;
	int Id;
	WM_HWIN hItem;
	int Pressed = 0;
	int Key;
	char acBuffer[10];
	switch (pMsg->MsgId) {
	case WM_PAINT:
		Theme_Paint();


		break;
	case WM_INIT_DIALOG:
	//	hItem = WM_GetDialogItem(pMsg->hWin, GUI_ID_USER + 12);
		hItem = pMsg->hWin;
		FRAMEWIN_SetTextColor(hItem,GUI_BLUE);
		FRAMEWIN_SetTextAlign(hItem,GUI_TA_HCENTER);
		FRAMEWIN_SetTitleHeight(hItem, 30);
		FRAMEWIN_SetFont(hItem,&GUI_Font16B_1);
		FRAMEWIN_AddMinButton(hItem, FRAMEWIN_BUTTON_RIGHT,0);
		FRAMEWIN_SetMoveable(hItem, 1);
		FRAMEWIN_SetBorderSize(hItem,10);
	//	FRAMEWIN_SetResizeable(hItem, 1);
	//	FRAMEWIN_SetText(hItem,"NUMBER PAD");
		break;
	case WM_NOTIFY_PARENT:
		Id = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch (Id) {
		case GUI_ID_USER + 11:
			switch (NCode)
			{
			case WM_NOTIFICATION_CLICKED:
				Pressed = 1;
				break;
			case WM_NOTIFICATION_RELEASED:
				if (cnt != 0)
				num[--cnt] = 0;

				WM_SendMessageNoPara(WM_GetParent(pMsg->hWin), MSG_PIN_CHANGED);
				break;
			}
			break;
		case GUI_ID_USER:
		case GUI_ID_USER + 1:
		case GUI_ID_USER + 2:
		case GUI_ID_USER + 3:
		case GUI_ID_USER + 4:
		case GUI_ID_USER + 5:
		case GUI_ID_USER + 6:
		case GUI_ID_USER + 7:
		case GUI_ID_USER + 8:
		case GUI_ID_USER + 9:
			switch (NCode)
			{
			case WM_NOTIFICATION_CLICKED:
				Pressed = 1;
				break;
			case WM_NOTIFICATION_RELEASED:

				BUTTON_GetText(pMsg->hWinSrc, acBuffer, sizeof(acBuffer));
				Key = acBuffer[0];
				//num[cnt++] = Key - '0';
				if (cnt < 6)
				num[cnt++] = Key;
				//if (cnt > 5)cnt = 0;
			//	GUI_SendKeyMsg(Key, Pressed);
				WM_SendMessageNoPara(WM_GetParent(pMsg->hWin), MSG_PIN_CHANGED);
				Pressed = 0;
				break;
			}
			break;
		}
	}

}
// USER START (Optionally insert additional static code)
// USER END

/*hItem = WM_GetDialogItem(pMsg->hWin, ID_SPINBOX_2);
SPINBOX_SetValue();
SPINBOX_SetBkColor();*/

/*********************************************************************
*
*       _cbDialog
*/

extern WM_HWIN CreateWin1(void);
static void _cbDialog(WM_MESSAGE * pMsg) {
  int NCode;
  int Id;
  WM_HWIN hItem;
	static   WM_HWIN hNum;

  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_CREATE:

	  break;
  case MSG_PIN_CHANGED:
	  //hItem = WM_GetDialogItem(pMsg->hWin, ID_SPINBOX_0);
	  //SPINBOX_SetValue(hItem, num[0] * 10 + num[1]);

	  //hItem = WM_GetDialogItem(pMsg->hWin, ID_SPINBOX_1);
	  //SPINBOX_SetValue(hItem, num[2] * 10 + num[3]);

	  //hItem = WM_GetDialogItem(pMsg->hWin, ID_SPINBOX_2);
	  //SPINBOX_SetValue(hItem, num[4] * 10 + num[5]);
	  hItem = WM_GetDialogItem(pMsg->hWin, ID_MULTIEDIT_0);
	 MULTIEDIT_SetText(hItem, num);

	  break;
  case WM_PAINT:

	  Theme_Paint();

	  break;
  case WM_INIT_DIALOG:
	  //Numpad_Flag = 0;
	  //num[0] = Hour / 10;
	  //num[1] = Hour % 10;
	  //num[2] = Min / 10;
	  //num[3] = Min % 10;
	  //num[4] = Sec / 10; 
	  //num[5] = Sec % 10;

	  //hItem = WM_GetDialogItem(pMsg->hWin, ID_SPINBOX_0);
	  //SPINBOX_SetButtonSize(hItem, 30);
	  //SPINBOX_SetFont(hItem, &GUI_Font24B_1);
	  //SPINBOX_SetRange(hItem,0,23);
	  //SPINBOX_EnableBlink(hItem,500,1);
	  //SPINBOX_SetEditMode(hItem, SPINBOX_EM_EDIT);
	  //SPINBOX_SetValue(hItem, num[0] * 10 + num[1]);
//	  GUI_FillCircle(120, 64, 40);
	  hItem = WM_GetDialogItem(pMsg->hWin, ID_MULTIEDIT_0);
	  MULTIEDIT_SetFont(hItem, &GUI_FontD48x64);
	  MULTIEDIT_EnableBlink(hItem,0,0);

	  break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
	case ID_BUTTON_1: // Notifications sent by 'NUM'
		switch (NCode) {
		case WM_NOTIFICATION_CLICKED:
			// USER START (Optionally insert code for reacting on notification message)
			// USER END
			break;
		case WM_NOTIFICATION_RELEASED:
			// USER START (Optionally insert code for reacting on notification message)
			if (!Numpad_Flag)
			{
				hNum = GUI_CreateDialogBox(_bDialogCreate, GUI_COUNTOF(_bDialogCreate), _cbDialogNumPad, pMsg->hWin, 0, 0);
				WM_SetStayOnTop(hNum, 1);
				Numpad_Flag = 1;
			}
			else
			{
			//	WM_DeleteWindow(hNum);
				GUI_EndDialog(hNum,1);
			//	WM_InvalidateWindow(pMsg->hWin);
				Numpad_Flag = 0;
			}

			// USER END
			break;
			// USER START (Optionally insert additional code for further notification handling)
			// USER END
		}
		break;
	case ID_BUTTON_2: // Notifications sent by 'return'
		switch (NCode) {
		case WM_NOTIFICATION_CLICKED:
			// USER START (Optionally insert code for reacting on notification message)
			// USER END
			break;
		case WM_NOTIFICATION_RELEASED:
			// USER START (Optionally insert code for reacting on notification message)
			//hItem = WM_GetDialogItem(pMsg->hWin, ID_SPINBOX_0);
			//Hour = SPINBOX_GetValue(hItem);
			//hItem = WM_GetDialogItem(pMsg->hWin, ID_SPINBOX_1);
			//Min = SPINBOX_GetValue(hItem);
			//hItem = WM_GetDialogItem(pMsg->hWin, ID_SPINBOX_2);
			//Sec = SPINBOX_GetValue(hItem);

			WM_DeleteWindow(pMsg->hWin);
			CreateWinMain();
			// USER END
			break;
			// USER START (Optionally insert additional code for further notification handling)
			// USER END
		}
		break;
	case ID_BUTTON_3: // Notifications sent by 'return'
		switch (NCode) {
		case WM_NOTIFICATION_CLICKED:
			// USER START (Optionally insert code for reacting on notification message)
			// USER END
			break;
		case WM_NOTIFICATION_RELEASED:
			hItem = WM_GetDialogItem(pMsg->hWin, ID_MULTIEDIT_0);
			Pass_Flag ^= 1;
			MULTIEDIT_SetPasswordMode(hItem, Pass_Flag);
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

			WM_DeleteWindow(pMsg->hWin);
			CreateWinMain();
			// USER END
			break;
			// USER START (Optionally insert additional code for further notification handling)
			// USER END
		}
		break;
	case ID_MULTIEDIT_0: // Notifications sent by 'Spinbox'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_MOVED_OUT:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
	  case WM_NOTIFICATION_SCROLL_CHANGED:
		  break;
      case WM_NOTIFICATION_VALUE_CHANGED:
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
WM_HWIN CreateWin4(void);
WM_HWIN CreateWin4(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  GUI_ZEROFILL(num,7);
  cnt = 0;
  Numpad_Flag = 0;
  Pass_Flag = 0;
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
