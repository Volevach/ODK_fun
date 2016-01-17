#include "stdafx.h"
#include "ODK_Functions.h"
#include "tchar.h"
#include "WaveProc.h"

WaveProc MyWave;

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
	MyWave = WaveProc();
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


// Setup file handles for IO operation
ODK_RESULT WaveSetup(
	/*IN*/ const ODK_S7STRING inFileName[256],// input wave
	/*IN*/ const ODK_S7STRING outFileName[256]// output to write to
	)
{
	return ODK_SUCCESS;
}

// Get one filter samlple for processing   
ODK_RESULT GetSamplesStereo(
	/*OUT*/ ODK_INT8 inputSamplesL[1024],// input audio samples left
	/*OUT*/ ODK_INT8 inputSamplesR[1024]// input audio samples right
	)
{
	return ODK_SUCCESS;
}

// write processed sample frame into file
ODK_RESULT WriteSamples(
	/*IN*/ const ODK_INT8 filteredSamplesL[1024],// output to write to left chan
	/*IN*/ const ODK_INT8 filteredSamplesR[1024]// output to write to right chan
	)
{
	return ODK_SUCCESS;
}