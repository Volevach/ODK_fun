// class for representing a complex number
// 
// implements the real and imaginary representation of a complex number and the conjucate complex output
// includes helper functions for addition, substraction and multiplication

#include "Complex.h"


// helper function returning the sum of two complex numbers
Complex CompAdd(Complex a, Complex b)
{
	Complex c;
	c.re = a.re + b.re;
	c.im = a.im + b.im;
    return c;
}

// helper function returning the difference between two complex numbers
Complex CompSub(Complex a, Complex b)
{
	Complex c;
	c.re = a.re - b.re;
	c.im = a.im - b.im;
	return c;
}

// helper function returning the product of two complex numbers
Complex CompMul(Complex a, Complex b)
{
	Complex c;
	c.re = (a.re * b.re) - (a.im * b.im);
	c.im = (a.re * b.im) + (a.im * b.re);
    return c;
}
