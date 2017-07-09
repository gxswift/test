///*********************************************************************
//*                                                                    *
//*                SEGGER Microcontroller GmbH & Co. KG                *
//*        Solutions for real time microcontroller applications        *
//*                                                                    *
//**********************************************************************
//*                                                                    *
//* C-file generated by:                                               *
//*                                                                    *
//*        GUI_Builder for emWin version 5.28                          *
//*        Compiled Jan 30 2015, 16:41:06                              *
//*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
//*                                                                    *
//**********************************************************************
//*                                                                    *
//*        Internet: www.segger.com  Support: support@segger.com       *
//*                                                                    *
//**********************************************************************
//*/

//// USER START (Optionally insert additional includes)
//// USER END

//#include "DIALOG.h"

///*********************************************************************
//*
//*       Defines
//*
//**********************************************************************
//*/
//#define ID_FRAMEWIN_0 (GUI_ID_USER + 0x0B)
//#define ID_BUTTON_0 (GUI_ID_USER + 0x0C)
//#define ID_BUTTON_1 (GUI_ID_USER + 0x0D)


//// USER START (Optionally insert additional defines)
//// USER END

///*********************************************************************
//*
//*       Static data
//*
//**********************************************************************
//*/

//// USER START (Optionally insert additional static data)
//// USER END

///*********************************************************************
//*
//*       _aDialogCreate
//*/
//static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
//  { FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 240, 320, 0, 0x0, 0 },
//  { BUTTON_CreateIndirect, "Button1", ID_BUTTON_0, 160, 240, 50, 50, 0, 0x0, 0 },
//  { BUTTON_CreateIndirect, "Button0", ID_BUTTON_1, 30, 240, 50, 50, 0, 0x0, 0 },
//  // USER START (Optionally insert additional widgets)
//  // USER END
//};

///*********************************************************************
//*
//*       Static code
//*
//**********************************************************************
//*/

//// USER START (Optionally insert additional static code)
//// USER END

///*********************************************************************
//*
//*       _cbDialog
//*/
//static void _cbDialog(WM_MESSAGE * pMsg) {
//  int NCode;
//  int Id;
//  // USER START (Optionally insert additional variables)
//  // USER END

//  switch (pMsg->MsgId) {
//  case WM_NOTIFY_PARENT:
//    Id    = WM_GetId(pMsg->hWinSrc);
//    NCode = pMsg->Data.v;
//    switch(Id) {
//    case ID_BUTTON_0: // Notifications sent by 'Button1'
//      switch(NCode) {
//      case WM_NOTIFICATION_CLICKED:
//        // USER START (Optionally insert code for reacting on notification message)
//        // USER END
//        break;
//      case WM_NOTIFICATION_RELEASED:
//        // USER START (Optionally insert code for reacting on notification message)
//        // USER END
//        break;
//      // USER START (Optionally insert additional code for further notification handling)
//      // USER END
//      }
//      break;
//    case ID_BUTTON_1: // Notifications sent by 'Button0'
//      switch(NCode) {
//      case WM_NOTIFICATION_CLICKED:
//        // USER START (Optionally insert code for reacting on notification message)
//        // USER END
//        break;
//      case WM_NOTIFICATION_RELEASED:
//        // USER START (Optionally insert code for reacting on notification message)
//        // USER END
//        break;
//      // USER START (Optionally insert additional code for further notification handling)
//      // USER END
//      }
//      break;
//    // USER START (Optionally insert additional code for further Ids)
//    // USER END
//    }
//    break;
//  // USER START (Optionally insert additional message handling)
//  // USER END
//  default:
//    WM_DefaultProc(pMsg);
//    break;
//  }
//}

///*********************************************************************
//*
//*       Public code
//*
//**********************************************************************
//*/
///*********************************************************************
//*
//*       CreateFramewin
//*/
//WM_HWIN CreateFramewin(void);
//WM_HWIN CreateFramewin(void) {
//  WM_HWIN hWin;

//  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
//  return hWin;
//}

//// USER START (Optionally insert additional public code)

//void MainTask()
//{
//	CreateFramewin();
//	while(1)
//	{
//		GUI_Exec();
//	}
//	
//}



//// USER END

///*************************** End of file ****************************/