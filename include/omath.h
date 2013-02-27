#ifndef MATH_H_
#define MATH_H_

#include <math.h>

#define PI 3.14159265358
#define PI2 1.57079632679
#define PIX2 6.28318530716

class Math
{
public:
	static inline float SafeInverse(float x)
	{
		return x != 0 ? 1/x : 0;
	}
};

#endif /*MATH_H_*/