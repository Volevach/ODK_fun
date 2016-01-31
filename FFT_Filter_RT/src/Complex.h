// class for representing a complex number
// 
// implements the real and imaginary representation of a complex number and the conjucate complex output
// includes helper functions for addition, substraction and multiplication


#pragma once
#include "ODK_Types.h"

// helper function returning the sum of two complex numbers
Complex CompAdd(Complex a, Complex b);

// helper function returning the difference between two complex numbers
Complex CompSub(Complex a, Complex b);

// helper function returning the product of two complex numbers
Complex CompMul(Complex a, Complex b);
