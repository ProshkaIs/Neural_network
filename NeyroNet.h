#pragma once
#include "Headers.h"
#include "Layer1.h"
#include "Layer2.h"

class NeyroNet {
private:
	layer1 lay1;
	layer2 lay2;
	int neyron_count;
	long double LearnTemp = 0.1;

public:
	void Inic(long double hidcount, long double lastlay, long double matrix_width);

	void WeightCorrect(vector<long double>& in);

	void Train(vector<long double>& train_set, vector<long double>& answ);

	void StepBack();

	int TryIt(vector<long double>& train_set, vector<long double>& answ);

};