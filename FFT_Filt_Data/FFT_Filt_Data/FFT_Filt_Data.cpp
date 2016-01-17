#include "stdafx.h"
#include "ODK_Functions.h"
#include "tchar.h"

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
 * SampleFunction() is defined in ODK_Functions.h.
 * ODK_Functions.h is automatically generated from Interface.odk.
 */
ODK_RESULT SampleFunction (const ODK_INT32& myInt, ODK_BOOL& myBool, ODK_DOUBLE& myReal)
{
    // place your code here
	
    _TCHAR szLog[1024];
    const int bufferSize = sizeof(szLog)/sizeof(szLog[0]) - 1;
    int len = _sntprintf_s(szLog, bufferSize, _T("SampleFunction(myInt=%d, myBool=%d, myReal=%lf)"), myInt, myBool, myReal);
    if (0 < len)
    {
        szLog[len] = 0;
        OutputDebugString(szLog);
    }
	
    return ODK_SUCCESS;
}
