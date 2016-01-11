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



ODK_RESULT FFT1024p (const ODK_UINT16 timeCoef[BLOCK_LEN], ODK_FLOAT freqCoefRe[BLOCK_LEN], ODK_FLOAT freqCoefIm[1024])
{
	Complex freqCoef[BLOCK_LEN];
	MyFFT.FFT_1024_mono(timeCoef, freqCoef);
	// place your code here
	for(int i = 0; i < BLOCK_LEN; i++)
	{
		freqCoefRe[i] = freqCoef[i].GetReal();
		freqCoefIm[i] = freqCoef[i].GetImag();
	}

	return ODK_SUCCESS;
}

