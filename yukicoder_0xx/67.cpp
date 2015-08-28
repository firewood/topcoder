#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	cout.precision(12);
	int N;
	cin >> N;
	long double L[200000];
	for (int i = 0; i < N; ++i) {
		cin >> L[i];
	}
	long double K;
	cin >> K;
	long double eps = 1.0e-10;
	long double low = 0, high = 1e15;
	while (high - low > eps) {
		long double mid = (low + high) / 2;
		long double cnt = 0;
		for (int i = 0; i < N; ++i) {
			cnt += floor(L[i] / mid);
		}
		if (cnt < K) {
			high = mid;
		} else {
			low = mid;
		}
	}
	cout << high << endl;
	return 0;
}
