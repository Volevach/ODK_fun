#include "ODK_Functions.h"
#include <stdlib.h>
#include "complex.h"
#include "FFT_1024.h"
#include "BP_Filter.h"

BP_Filter MyFiler;
FFT_1024 MyFFT;

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
	MyFiler = BP_Filter();
	MyFFT = FFT_1024();
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



ODK_RESULT FFT1024p (const ODK_INT16 timeCoef[BLOCK_LEN], complex freqCoef[1024])
{

	MyFFT.FFT_1024_mono(timeCoef, freqCoef);
	// place your code here
	return ODK_SUCCESS;
}

ODK_RESULT LP_Filter (const  complex src[BLOCK_LEN], complex sink[BLOCK_LEN])
{
	MyFiler.low_pass_mono(src, sink);
	return ODK_SUCCESS;
}

ODK_RESULT IFFT1024p (const complex freqCoef[BLOCK_LEN], ODK_INT16 timeCoef[BLOCK_LEN])
{
	MyFFT.IFFT_1024_mono(freqCoef, timeCoef);
	return ODK_SUCCESS;
}

