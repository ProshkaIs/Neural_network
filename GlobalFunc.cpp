#include "Headers.h"

long double fRand(long double fMin, long double fMax)
{

	long double f = (long double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

long double Active(long double arg) {
	long double rez = 1 / (1 + exp(-arg));
	return rez;
}


long double ActiveD(long double arg) {
	long double rez = Active(arg) * (1 - Active(arg));
	return rez;
}