#pragma once
#include "Headers.h"
#include "Neyron.h"

class layer1 {
private:
	vector<neyron> neyrons;
	vector<long double> outs;
	vector<long double> sigm_shtrix;
	vector<long double> margins;

public:
	void start(vector<long double>& ins);

	void inic(long double neyro_count, long double matrix_width);

	void CorrectWeights(vector<long double>& in, long double LearnTemp);

	vector<long double>& GetOuts();

	void Cleaner();

	int GetNeyroCount();

	void PushMargin(long double mar);
};