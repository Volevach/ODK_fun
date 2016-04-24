#include "stdafx.h"
#include "ODK_Functions.h"
#include "tchar.h"
#include "WaveProc.h"

WaveProc MyWave;
FILE *inFile;
FILE *outFile;
ODK_INT16 buffer[BLOCK_LEN - NET_LEN][2];

unsigned int loopCnt;

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
	fclose(inFile);
	fclose(outFile);
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

// Test setup file handles for IO operation no Name
ODK_RESULT WaveSetupNoName()
{
	inFile = fopen("D:/Data/test_in.wav", "rb");
	outFile = fopen("D:/Data/test_out.wav", "wb");
	
	char wavPreface[44];


	for (int i = 0; i < 44; i++)
	{
		wavPreface[i] = (char)getc(inFile);
	}

	// initialize the Wave processing class
	MyWave = WaveProc(wavPreface);


	// currently supporting only stereo wave
	if ((MyWave.GetFormatType() != 1) && (MyWave.GetChannelNum() != 2))
	{
		return -1;                   // not stereo wave    
	}

	// get the amount of 994 samples blocks and the amount of remainder samples
	int len = MyWave.GetDataLen() / 4;
	unsigned int rem = len % NET_LEN;
	loopCnt = (int)((len - rem) / NET_LEN);

	MyWave.WriteHeader(outFile, (loopCnt + 1) * 4 * NET_LEN);


	return ODK_SUCCESS;
}


// Setup file handles for IO operation
ODK_RESULT WaveSetup(
	/*IN*/ const ODK_S7STRING inFileName[256],// input wave
	/*IN*/ const ODK_S7STRING outFileName[256]// output to write to
	)
{
	inFile = fopen((const char*)inFileName, "rb");
	outFile = fopen((const char*)outFileName, "wb");

	
    char wavPreface[44];

    
    for(int i = 0; i < 44; i++)
    {
        wavPreface[i] = (char)getc(inFile);
    }

	// initialize the Wave processing class
	MyWave = WaveProc(wavPreface);


	// currently supporting only stereo wave
	if ((MyWave.GetFormatType() != 1) && (MyWave.GetChannelNum() != 2))
	{
		return -1;                   // not stereo wave    
	}

	// get the amount of 994 samples blocks and the amount of remainder samples
	int len = MyWave.GetDataLen() / 4;
	unsigned int rem = len % NET_LEN;
	loopCnt = (int)((len - rem) / NET_LEN);

	MyWave.WriteHeader(outFile, (loopCnt + 1) * 4 * NET_LEN);


	return ODK_SUCCESS;
}

// Get one filter samlple for processing   
ODK_RESULT GetSamplesStereo(
	/*OUT*/ ODK_INT16 inputSamplesL[1024],// input audio samples left
	/*OUT*/ ODK_INT16 inputSamplesR[1024],// input audio samples right
	/*OUT*/ ODK_BOOL& lastSample // last sample indication
	)
{
	unsigned short i = 0;
	
	if (loopCnt--)
	{
		for (i = 0; i < NET_LEN; i++)
		{
			inputSamplesL[i] = MyWave.ReadWord(inFile);
			inputSamplesR[i] = MyWave.ReadWord(inFile);
		}

		// zero pad
		for (i = NET_LEN; i < BLOCK_LEN; i++)
		{
			inputSamplesL[i] = 0;
			inputSamplesR[i] = 0;
		}
	}
	else
	{
		return -1;
	}

	lastSample = (loopCnt == 0);

	return ODK_SUCCESS;
}

// write processed sample frame into file
ODK_RESULT WriteSamples(
	/*IN*/ const ODK_INT16 filteredSamplesL[1024],// output to write to left chan
	/*IN*/ const ODK_INT16 filteredSamplesR[1024]// output to write to right chan
	)
{
	unsigned short i = 0;

	// write first 30 samples with overlap buffer added
	for (i = 0; i < (BLOCK_LEN - NET_LEN); i++)
	{
		MyWave.WriteWord(outFile, filteredSamplesL[i] + buffer[i][0]);
		MyWave.WriteWord(outFile, filteredSamplesR[i] + buffer[i][1]);
	}

	// write the next 964 samles unaltered
	for (i = (BLOCK_LEN - NET_LEN); i < NET_LEN; i++)
	{
		MyWave.WriteWord(outFile, filteredSamplesL[i]);
		MyWave.WriteWord(outFile, filteredSamplesR[i]);
	}

	// store the last 30 samples into overlap add buffer
	for (i = NET_LEN; i < BLOCK_LEN; i++)
	{
		buffer[i - NET_LEN][0] = filteredSamplesL[i];
		buffer[i - NET_LEN][1] = filteredSamplesR[i];
	}

	return ODK_SUCCESS;
}