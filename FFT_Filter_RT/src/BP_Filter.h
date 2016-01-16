#pragma once
#include "ODK_Types.h"
#include "complex.h"
#include "FFT_1024.h"

#define FILT_LEN 31

class BP_Filter
{
public:
    BP_Filter(void);
    ~BP_Filter(void);
    void low_pass(const complex src_sig[BLOCK_LEN][2], complex sink_sig[BLOCK_LEN][2]);
    void low_pass_mono(const complex src_sig[BLOCK_LEN], complex sink_sig[BLOCK_LEN]);
    void high_pass(const complex src_sig[BLOCK_LEN][2], complex sink_sig[BLOCK_LEN][2]);
    void band_pass(const complex src_sig[BLOCK_LEN][2], complex sink_sig[BLOCK_LEN][2]);
    void sig_filter(const complex src_sig[BLOCK_LEN][2], complex sink_sig[BLOCK_LEN][2], complex filter_par[BLOCK_LEN]);

private:
    complex filt_coef_freq[BLOCK_LEN];
    complex flt_scale;
    complex flt_scale_inv;
};

const double filt_coef[FILT_LEN] =
{
    0.0016,    0.0018,    0.0025,    0.0036,    0.0051,    0.0070,    0.0091,    0.0115,
    0.0140,    0.0164,    0.0188,    0.0208,    0.0226,    0.0239,    0.0247,    0.0250,
    0.0247,    0.0239,    0.0226,    0.0208,    0.0188,    0.0164,    0.0140,    0.0115,
    0.0091,    0.0070,    0.0051,    0.0036,    0.0025,    0.0018,    0.0016
};


