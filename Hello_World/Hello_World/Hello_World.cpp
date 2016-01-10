#include "stdafx.h"
#include "resource.h"
#include "ODK_Functions.h"
#include "ODK_StringHelper.h"


extern HINSTANCE g_hInst;

// Global variables to store two strings
char g_strCaption[256];
char g_strMessage[256];

/*
 * OnLoad() is invoked after the application binary was loaded.
 * @return ODK_SUCCESS       notify, that no error occurs
 *                            - OnRun() will be invoked automatically
 *         any other value   notify, that an error occurs (user defined)
 *                            - OnUnload() will be invoked automatically
 *                            - ODK application will be unloaded automatically
 */
EXPORT_API ODK_RESULT OnLoad (void)
{
    // place your code here
    return ODK_SUCCESS;
}

/*
 * OnUnload() is invoked before the application binary is unloaded or when
 *            ODK-Host terminates.
 * @return ODK_SUCCESS       notify, that no error occurs
 *         any other value   notify, that an error occurs (user defined)
 *                            - ODK application will be unloaded anyway
 */
EXPORT_API ODK_RESULT OnUnload (void)
{
    // place your code here
    return ODK_SUCCESS;
}

/*
 * OnRun() is invoked when the CPU transitions to the RUN state and
 *         after OnLoad().
 * @return Does not affect the load operation or state transition.
 */
EXPORT_API ODK_RESULT OnRun (void)
{
    // place your code here
    return ODK_SUCCESS;
}

/*
 * OnStop() is invoked when the CPU transitions to the STOP/SHUTDOWN state
 *          or before unloading the ODK application.
 * @return Does not affect the load operation or state transition.
 */
EXPORT_API ODK_RESULT OnStop (void)
{
    // place your code here
    return ODK_SUCCESS;
}


/*
 * DialogProc() processes messages to ad from the dialog window
 * @param hDlg Handle to the dialog box
 * @param uMsg The message to the dialog box
 * @param wParam Additional message-specific information
 * @param lParam Additional message-specific information
 * @return returns true when function was successful, false when not
 */
INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  
  switch(uMsg)
  {
      // Dialog initialization
      case WM_INITDIALOG:
        SetDlgItemText(hDlg, IDC_EDIT1, (LPWSTR)g_strMessage);
        SetWindowText(hDlg, (LPCWSTR)g_strCaption);
        return TRUE;
      // Button press
      case WM_COMMAND:
        switch(LOWORD(wParam))
        {
        // OK Button is pressed
        case IDOK:
             GetDlgItemText(hDlg, IDC_EDIT1, (LPWSTR)g_strMessage, sizeof(g_strMessage));
             SendMessage(hDlg, WM_CLOSE, 0, 0);
             return TRUE;
        }
        break;
      // Dialog is closed
      case WM_CLOSE:
        DestroyWindow(hDlg);
        return TRUE;

      case WM_DESTROY:
        return TRUE;
      }

      return FALSE;
    }


/*
 * HelloWorld_Win32() shows a dialog window with two strings, where one is editable and will be returned
 *                  after the call
 * @param[in] strCaption String, which will be the name of the dialog window
 * @param[in,out] strMessage String, which will show in the text edit field of the dialog and will be returned to the PLC 
 * @return returns ODK_SUCCESS when the function finishes
 */
ODK_RESULT HelloWorld_Win32 (const ODK_S7STRING strCaption[256], ODK_S7STRING strMessage[256])
{

    // Convert ODK_S7STRING myString to char array
	Convert_S7STRING_to_SZSTR (strCaption, g_strCaption, 256);
   
    // Convert ODK_S7STRING myMessage to char array
    Convert_S7STRING_to_SZSTR (strMessage, g_strMessage, 256);
    
    // Create dialog
    LRESULT res = DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, &DialogProc);

    // Convert char array to ODK_S7STRING
    Convert_SZSTR_to_S7STRING (g_strMessage, strMessage);

   return ODK_SUCCESS;
}
