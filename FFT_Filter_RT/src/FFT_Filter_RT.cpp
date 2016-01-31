#include "ODK_Functions.h"
#include "FFT_Trans.h"
#include "BP_Filter.h"

#ifdef _DEBUG
#include "debug_param.h"
#include <stdio.h>
#endif

BP_Filter MyFiler;
FFT_Trans MyFFT;

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
	MyFFT = FFT_Trans();
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
    for(int i = 0; i < 10; i++)
    {
    	short test_output[BLOCK_LEN];
    	ret = FFT_Filt(&(test_input[i*BLOCK_LEN]), test_output);
    	for(int j = 0; j < BLOCK_LEN; j++)
    	{
    		printf("%d, \n",test_output[j]);
    	}
    }

    ret = OnStop();
    // error handling
    ret = OnUnload();
    // error handling
    return ret;
}
#endif // _DEBUG



ODK_RESULT FFT1024p (const ODK_INT16 timeCoef[BLOCK_LEN], Complex freqCoef[1024])
{

	MyFFT.FFT_Mono(timeCoef, freqCoef);
	// place your code here
	return ODK_SUCCESS;
}

ODK_RESULT LP_Filter (const  Complex src[BLOCK_LEN], Complex sink[BLOCK_LEN])
{
	MyFiler.FilterMono(src, sink);
	return ODK_SUCCESS;
}

ODK_RESULT IFFT1024p (const Complex freqCoef[BLOCK_LEN], ODK_INT16 timeCoefOut[BLOCK_LEN])
{
	MyFFT.IFFT_Mono(freqCoef, timeCoefOut);
	return ODK_SUCCESS;
}

ODK_RESULT FFT_Filt (const ODK_INT16 timeCoef[BLOCK_LEN], ODK_INT16 timeCoefOut[BLOCK_LEN])
{
	Complex freqCoef[BLOCK_LEN];
	Complex freqCoefFilt[BLOCK_LEN];

	MyFFT.FFT_Mono(timeCoef, freqCoef);
	MyFiler.FilterMono(freqCoef, freqCoefFilt);
	MyFFT.IFFT_Mono(freqCoefFilt, timeCoefOut);

	return ODK_SUCCESS;
}

