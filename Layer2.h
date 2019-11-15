#pragma once
#include "Headers.h"
#include "Neyron.h"

class layer2 {
private:
	vector<neyron> neyrons;
	vector<long double> outs;
	vector<long double> sigm_shtrix;
	vector<long double> margins;
	vector<long double> rrr;
	long double sum = 0;

public:
	void start(vector<long double>& ins, vector<long double>& answers);

	void inic(long double neyro_count, long double hid_count);

	void CorrectWeights(vector<long double> prev_outs, long double LearnTemp);
	void Cleaner();
	int GetNeyroCount();

	long double GetNeyroWeight(int neyroId, int weightId);

	long double GetMargin(int num);

	long double GetSigm(int num);

	long double GetOut(int num);

	int GetOutSize();
};
