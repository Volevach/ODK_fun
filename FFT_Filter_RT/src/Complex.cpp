#include "Complex.h"

complex ConjCompl(complex a)
{
	complex c;
	c.re = a.re;
	c.im = -a.im;
	return c;
}

complex compAdd(complex a, complex b)
{
	complex c;
	c.re = a.re + b.re;
	c.im = a.im + b.im;
	return c;
}

complex compSub(complex a, complex b)
{
	complex c;
	c.re = a.re - b.re;
	c.im = a.im - b.im;
	return c;
}

complex compMul(complex a, complex b)
{
	complex c;
	c.re = (a.re * b.re) - (a.im * b.im);
	c.im = (a.re * b.im) + (a.im * b.re);
	return c;
}
