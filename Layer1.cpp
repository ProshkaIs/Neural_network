#include "Headers.h"
#include "Neyron.h"
#include "Layer1.h"




	void layer1::start(vector<long double>& ins) {
		for (int i = 0; i < neyrons.size(); ++i) {
			long double out_it = neyrons[i].use(ins);
			outs.push_back(Active(out_it));
			sigm_shtrix.push_back(ActiveD(out_it));
		}

	}

	void layer1::inic(long double neyro_count, long double matrix_width) {
		for (int i = 0; i < neyro_count; ++i) neyrons.push_back(neyron());
		for (int i = 0; i < neyrons.size(); ++i) {
			for (int ii = 0; ii < matrix_width; ++ii) neyrons[i].AddWeight(fRand(-0.5, 0.5));
		}
	}

	void layer1::CorrectWeights(vector<long double>& in, long double LearnTemp) {
		for (int i = 0; i < neyrons.size(); ++i) {
			for (int k = 0; k < neyrons[i].GetWeightsSize(); ++k) {
				neyrons[i].ChangeWeight(k, LearnTemp * margins[i] * sigm_shtrix[i] * in[k]);
			}
		}
	}

	vector<long double>& layer1::GetOuts() {
		return outs;
	}

	void layer1::Cleaner() {
		outs.clear();
		sigm_shtrix.clear();
		margins.clear();
	}

	int layer1::GetNeyroCount() {
		return neyrons.size();
	}

	void layer1::PushMargin(long double mar) {
		margins.push_back(mar);
	}


