#include "ODK_Functions.h"
#include "SobelOp.h"
#include <stdlib.h>

SobelOp MySobel;

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
	MySobel = SobelOp();

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
 * In case of a CPU transition RUN->STOP this function will be canceled,
 * when execution overruns a reaction time of more than ~20ms.
 * @return Does not affect the load operation or state transition.
 */
EXPORT_API ODK_RESULT OnStop (void)
{
    // place your code here
    return ODK_SUCCESS;
}

/*
 * main() is defined for windows debugging, only.
 * Therefore all automatically invoked functions (OnLoad, OnRun, OnStop, OnUnload)
 * have to be called manually.
 */
#ifdef _DEBUG
int main (int argc, char* argv[])
{
    ODK_RESULT ret = ODK_SUCCESS;
    ret = OnLoad();
    // error handling
    ret = OnRun();
    // error handling

    // place your test code here

    ret = OnStop();
    // error handling
    ret = OnUnload();
    // error handling
    return ret;
}
#endif // _DEBUG


// SobelOperation on a 150x150 greyscale image
ODK_RESULT SobelFiltImage (
  /*IN*/ const ODK_UINT8 image[22500],// input image
  /*OUT*/ ODK_UINT8 image_filt[22500]// filtered output
)
{
	MySobel.SobelFiltImage(image, image_filt);
	return ODK_SUCCESS;
}

