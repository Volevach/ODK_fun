/*
 * This file is AUTO GENERATED - DO NOT MODIFY this file. 
 * This file contains the function prototypes of ODK 1500S.
 *
 * File created by ODK_CodeGenerator version 200.0.2304.1
 * at Sun April 24 18:35:15 2016 
*/

#if !defined    ODK_Functions_H
#define ODK_Functions_H

#include "ODK_Types.h"

#ifdef DLL_EXPORT
  #define EXPORT_API extern "C" __declspec(dllexport)
#else
  #define EXPORT_API extern "C"
#endif

// Setup file handles for IO operation
ODK_RESULT WaveSetup (
  /*IN*/const ODK_S7STRING inFileName[256], // input wave
  /*IN*/const ODK_S7STRING outFileName[256]); // output to write to
#define _ODK_FUNCTION_WAVESETUP  ODK_RESULT WaveSetup (/*IN*/const ODK_S7STRING inFileName[256], /*IN*/const ODK_S7STRING outFileName[256])

// Test Setup file handles without name
ODK_RESULT WaveSetupNoName (
);
#define _ODK_FUNCTION_WAVESETUPNONAME  ODK_RESULT WaveSetupNoName ()

// Get one filter samlple for processing   
ODK_RESULT GetSamplesStereo (
  /*OUT*/ODK_INT16 inputSamplesL[1024], // input audio samples left
  /*OUT*/ODK_INT16 inputSamplesR[1024], // input audio samples right
  /*OUT*/ODK_BOOL& lastSample); // last sample indicator
#define _ODK_FUNCTION_GETSAMPLESSTEREO  ODK_RESULT GetSamplesStereo (/*OUT*/ODK_INT16 inputSamplesL[1024], /*OUT*/ODK_INT16 inputSamplesR[1024], /*OUT*/ODK_BOOL& lastSample)

// write processed sample frame into file
ODK_RESULT WriteSamples (
  /*IN*/const ODK_INT16 filteredSamplesL[1024], // output to write to left chan
  /*IN*/const ODK_INT16 filteredSamplesR[1024]); // output to write to right chan
#define _ODK_FUNCTION_WRITESAMPLES  ODK_RESULT WriteSamples (/*IN*/const ODK_INT16 filteredSamplesL[1024], /*IN*/const ODK_INT16 filteredSamplesR[1024])

#endif