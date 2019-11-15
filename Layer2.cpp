#include "Headers.h"
#include "Layer2.h"


	void layer2::start(vector<long double>& ins, vector<long double>& answers) {
		for (int i = 0; i < neyrons.size(); ++i) {
			long double out_it = neyrons[i].use(ins);
			sum += exp(out_it);
		}
		for (int i = 0; i < neyrons.size(); ++i) {
			outs.push_back(exp(neyrons[i].GetOut()) / sum);
			sigm_shtrix.push_back((exp(neyrons[i].GetOut()) / sum) * (1 - exp(neyrons[i].GetOut()) / sum));
			margins.push_back(exp(neyrons[i].GetOut()) / sum - answers[i]);
		}
		sum = 0;
	}

	void layer2::inic(long double neyro_count, long double hid_count) {
		for (int i = 0; i < neyro_count; ++i) neyrons.push_back(neyron());
		for (int i = 0; i < neyrons.size(); ++i) {
			for (int ii = 0; ii < hid_count; ++ii) neyrons[i].AddWeight(fRand(-0.5, 0.5));
		}
	}

	void layer2::CorrectWeights(vector<long double> prev_outs, long double LearnTemp) {
		for (int i = 0; i < neyrons.size(); ++i) {
			for (int k = 0; k < neyrons[i].GetWeightsSize(); ++k) {
				neyrons[i].ChangeWeight(k, LearnTemp * margins[i] * sigm_shtrix[i] * prev_outs[k]);
			}
		}
	}
	void layer2::Cleaner() {
		outs.clear();
		sigm_shtrix.clear();
		margins.clear();
	}

	int layer2::GetNeyroCount() {
		return neyrons.size();
	}

	long double layer2::GetNeyroWeight(int neyroId, int weightId) {
		return neyrons[neyroId].GetWeight(weightId);
	}

	long double layer2::GetMargin(int num) {
		return margins[num];
	}

	long double layer2::GetSigm(int num) {
		return sigm_shtrix[num];
	}

	long double layer2::GetOut(int num) {
		return outs[num];
	}

	int layer2::GetOutSize() {
		return outs.size();
	}