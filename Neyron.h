#pragma once
#include "Headers.h"

class neyron {
private:
	vector<long double> weights;
	long double out = 0;
public:
	long double use(vector<long double>& lefters);

	void ChangeWeight(int num, long double minus);

	void AddWeight(long double newweight);

	long GetWeightsSize();

	long double GetOut();

	long double GetWeight(int num);
};