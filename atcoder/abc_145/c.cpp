// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1;
		cin >> n;
		if (n <= 0) return 0;
		int seq[] = { 0,1,2,3,4,5,6,7 };
		double sum = 0;
		double cnt = 0;
		vector<double> x(n), y(n);
		for (int i = 0; i < n; ++i) {
			cin >> x[i] >> y[i];
		}
		do {
			cnt += 1.0;
			for (int i = 1; i < n; ++i) {
				double dx = x[seq[i]] - x[seq[i - 1]];
				double dy = y[seq[i]] - y[seq[i - 1]];
				sum += sqrt(dx * dx + dy * dy);
			}
		} while (next_permutation(seq, seq + n));
		double ans = sum / cnt;
		cout << ans << endl;
	}
	return 0;
}
