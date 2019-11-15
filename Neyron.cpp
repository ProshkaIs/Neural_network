#include "Headers.h"
#include "Neyron.h"

	long double neyron::use(vector<long double>& lefters) {
		out = 0;
		for (int i = 0; i < lefters.size(); ++i) {
			out += lefters[i] * weights[i];
		}

		return out;
	}

	void neyron::ChangeWeight(int num, long double minus) {
		weights[num] -= minus;
	}

	void neyron::AddWeight(long double newweight) {
		weights.push_back(newweight);
	}

	long neyron::GetWeightsSize() {
		return weights.size();
	}

	long double neyron::GetOut() {
		return out;
	}

	long double neyron::GetWeight(int num) {
		return weights[num];
	}
