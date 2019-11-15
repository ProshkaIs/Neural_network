#include "Headers.h"
#include "NeyroNet.h"

	void NeyroNet::Inic(long double hidcount, long double lastlay, long double matrix_width) {
		neyron_count = hidcount;
		lay1.inic(hidcount, matrix_width);
		lay2.inic(lastlay, hidcount);
	}

	void NeyroNet::WeightCorrect(vector<long double>& in) {
		//cout << *min_element(lay2.margins.begin(), lay2.margins.end()) << " " << *max_element(lay2.margins.begin(), lay2.margins.end()) << "\n";
		cout << "Corrected";
		lay1.CorrectWeights(in, LearnTemp);
		lay2.CorrectWeights(lay1.GetOuts(), LearnTemp);
	}

	void NeyroNet::Train(vector<long double>& train_set, vector<long double>& answ) {
		lay1.start(train_set);
		lay2.start(lay1.GetOuts(), answ);
		StepBack();
		WeightCorrect(train_set);
		cout << "\n";
		lay1.Cleaner();
		lay2.Cleaner();

	}

	void NeyroNet::StepBack() {
		for (int i = 0; i < lay1.GetNeyroCount(); ++i) {
			long double sigma_sh = 0;
			for (int k = 0; k < lay2.GetNeyroCount(); ++k) {
				sigma_sh += lay2.GetMargin(k) * lay2.GetSigm(k) * lay2.GetNeyroWeight(k, i);
			}
			lay1.PushMargin(sigma_sh);
		}
	}

	int NeyroNet::TryIt(vector<long double>& train_set, vector<long double>& answ) {
		lay1.start(train_set);
		lay2.start(lay1.GetOuts(), answ);
		int predict = -1;
		long double predictVal = -10;
		for (int i = 0; i < lay2.GetOutSize(); ++i) {
			cout << i << ": " << lay2.GetOut(i) << "\n";
			if (lay2.GetOut(i) > predictVal) {
				predictVal = lay2.GetOut(i);
				predict = i;
			}
		}
		lay1.Cleaner();
		lay2.Cleaner();
		return predict;
	}
