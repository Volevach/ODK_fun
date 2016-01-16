#include "Complex.h"

complex ConjCompl(complex a)
{
    return complex(a.re, -a.im);
}

complex compAdd(complex a, complex b)
{
    return complex(a.re + b.re, a.im + b.im);
}

complex compSub(complex a, complex b)
{
    return complex(a.re - b.re, a.im - b.im);
}

complex compMul(complex a, complex b)
{
    return complex((a.re * b.re) - (a.im * b.im), (a.re * b.im) + (a.im * b.re));
}
