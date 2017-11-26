// D.

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef pair<int, int> II;

int main(int argc, char *argv[]) {
	cout.precision(10);
	int n, k, w, p;
	cin >> n >> k;
	vector<II> v;
	for (int i = 0; i < n; ++i) {
		cin >> w >> p;
		v.push_back(II(w, p));
	}
	double low = 0, high = 100.1;
	while ((high - low) > 1e-10) {
		double mid = (high + low) / 2;
		vector<double> w;
		for (auto wp : v) {
			w.push_back(wp.first * (wp.second - mid));
		}
		sort(w.rbegin(), w.rend());
		double sum = accumulate(w.begin(), w.begin() + k, 0.0);
		if (sum >= 0) {
			low = mid;
		} else {
			high = mid;
		}
	}
	cout << low << endl;
	return 0;
}
