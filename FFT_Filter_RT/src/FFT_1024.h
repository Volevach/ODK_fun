#pragma once
#include <Math.h>
#include "ODK_Types.h"
#include "defines.h"
#include "Complex.h"


class FFT_1024
{
public:
    FFT_1024(void);
    ~FFT_1024(void);

    void FFT_1024_stereo(const short time_coef[BLOCK_LEN][2], complex freq_coef[BLOCK_LEN][2]);
    void IFFT_1024_stereo(const complex freq_coef[BLOCK_LEN][2],  short time_coef[BLOCK_LEN][2]);
    void FFT_1024_mono(const short time_coef[BLOCK_LEN], complex freq_coef[BLOCK_LEN]);
    void IFFT_1024_mono(const complex freq_coef[BLOCK_LEN],  short time_coef[BLOCK_LEN]);

private:
    unsigned short bitRevInd[BLOCK_LEN];
    complex twiddle_fac[STAGES];
    complex w_0;
    int d_fac[STAGES];

    void bitReverse(const complex a[BLOCK_LEN], complex b[BLOCK_LEN]);
    void bitReverse2(const complex a[BLOCK_LEN][2], complex b[BLOCK_LEN][2]);
    void bitReverse_to_complx2(const short a[BLOCK_LEN][2], complex b[BLOCK_LEN][2]);
    void bitReverse_to_complx(const short a[BLOCK_LEN], complex b[BLOCK_LEN]);
};

static const double PI = 3.1415926;
