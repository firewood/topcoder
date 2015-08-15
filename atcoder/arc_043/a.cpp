// A. 

#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	cout.precision(16);
	int N;
	double A, B, S[100000];
	cin >> N >> A >> B;
	for (int i = 0; i < N; ++i) {
		cin >> S[i];
	}
	double min_n = *min_element(S, S + N);
	double max_n = *max_element(S, S + N);
	if (min_n == max_n) {
		cout << "-1" << endl;
		return 0;
	}
	double P = B / (max_n - min_n);
	double sum = accumulate(S, S + N, 0.0) * P;
	double Q = A - sum / N;
	printf("%.7lf %.7lf\n", P, Q);
	return 0;
}
