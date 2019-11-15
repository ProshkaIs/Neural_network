#include "Headers.h"
#include "NeyroNet.h"



int main()
{

	ifstream f("mnist_train.csv");
	vector<long double> pixels;
	vector<long double> answ;
	int counter = 40000;
	string zn;
	getline(f, zn);
	NeyroNet n;
	n.Inic(150, 10, 784);

	while (counter > 0)
	{
		string num;
		getline(f, num, ',');
		for (int i = 0; i < 783; ++i) {
			getline(f, zn, ',');
			pixels.push_back(stoi(zn));
		}

		getline(f, zn);
		pixels.push_back(stoi(zn));
		counter--;
		for (int ii = 0; ii < pixels.size(); ++ii) {
			pixels[ii] = Active(pixels[ii]);
		}

		answ = { 0,0,0,0,0,0,0,0,0,0 };
		answ[stoi(num)] = 1;
		cout << 40000 - counter << " ";
		n.Train(pixels, answ);
		pixels.clear();
	}

	cout << "-----------------------------------\n";
	counter = 1000;
	int good = 0;
	int bad = 0;
	while (counter > 0) {
		string num;
		getline(f, num, ',');
		for (int i = 0; i < 783; ++i) {
			getline(f, zn, ',');
			pixels.push_back(stoi(zn));
		}

		getline(f, zn);
		pixels.push_back(stoi(zn));
		counter--;
		cout << "NUM IS " << num << "\n";
		for (int ii = 0; ii < pixels.size(); ++ii) {
			pixels[ii] = Active(pixels[ii]);
		}
		if (stoi(num) == n.TryIt(pixels, answ)) good += 1;
		cout << "------------------------" << "\n";

		pixels.clear();
	}
	cout << "good: " << good << "\n" << "accuracy: " << good / 10 << "%";



	return 0;
}