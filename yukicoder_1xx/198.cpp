#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long LL;

int N;
LL B;
LL C[10];

LL cost(LL t) {
	LL cost = 0;
	for (int i = 0; i < N; ++i) {
		cost += abs(t - C[i]);
	}
	return cost;
}

int main(int argc, char *argv[]) {
	cin >> B;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> C[i];
	}
	LL m = accumulate(C, C + N, B) / N;
	LL left = *min_element(C, C + N);
	LL right = min(m, *max_element(C, C + N));
	for (LL a = 0; a < 100; ++a) {
		if (cost((left * 2 + right) / 3) <= cost((left + right * 2) / 3)) {
			right = (left + right * 2) / 3;
		} else {
			left = (left * 2 + right) / 3;
		}
	}
	LL ans = 1LL << 60;
	for (LL a = left; a <= min(m, right + 2); ++a) {
		ans = min(ans, cost(a));
	}
	cout << ans << endl;
	return 0;
}
