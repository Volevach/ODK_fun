#include "BP_Filter.h"
#include "defines.h"
#include "Complex.h"

BP_Filter::BP_Filter(void)
{
    unsigned int i = 0;
    FFT_1024 MyFFT = FFT_1024();

    flt_scale = complex(65536.0, 65536.0);
    flt_scale_inv = complex(1.0/65536.0, 1.0/65536.0);

    // zero pad the filter coef
    short filt_coef_zero[BLOCK_LEN] = {0};
    for(i = 0; i < FILT_LEN; i++)
    {
        filt_coef_zero[i] = (unsigned short)(filt_coef[i] * 65536.0);
    }

    // transform into frequency domain

    MyFFT.FFT_1024_mono(filt_coef_zero,filt_coef_freq);

    for(i = 0; i < BLOCK_LEN; i++)
    {
        filt_coef_freq[i] = compMul(filt_coef_freq[i], flt_scale_inv);
    }
}


BP_Filter::~BP_Filter(void)
{
}

void BP_Filter::low_pass(const complex src_sig[BLOCK_LEN][2], complex sink_sig[BLOCK_LEN][2])
{
    unsigned int i;
    for(i = 0; i < BLOCK_LEN; i++)
    {
        sink_sig[i][0] = compMul(src_sig[i][0], filt_coef_freq[i]);
        sink_sig[i][1] = compMul(src_sig[i][1], filt_coef_freq[i]);
    }
}

void BP_Filter::high_pass(const complex src_sig[BLOCK_LEN][2], complex sink_sig[BLOCK_LEN][2])
{

}

void BP_Filter::band_pass(const complex src_sig[BLOCK_LEN][2], complex sink_sig[BLOCK_LEN][2])
{

}

void BP_Filter::sig_filter(const complex src_sig[BLOCK_LEN][2], complex sink_sig[BLOCK_LEN][2], complex filter_par[BLOCK_LEN])
{

}
