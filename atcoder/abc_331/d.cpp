#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int64_t N, Q, a, b, c, d, tot = 0;
	cin >> N >> Q;
	vector<string> pat(N);
	for (int i = 0; i < N; i++) {
		cin >> pat[i];
	}

	vector memo(1002, vector(1002, int64_t(0)));
	for (int i = 0; i < N; ++i) {
		int cnt = 0;
		for (int j = 0; j < N; ++j) {
			cnt += pat[i][j] == 'B';
			memo[i + 1][j + 1] = memo[i][j + 1] + cnt;
		}
		tot += cnt;
	}

	auto calc = [&](int64_t bottom, int64_t right) {
		return (bottom / N) * (right / N) * tot
			+ memo[N][right % N] * (bottom / N)
			+ memo[bottom % N][N] * (right / N)
			+ memo[bottom % N][right % N];
	};
	auto calc_offset = [&](int64_t top, int64_t left, int64_t bottom, int64_t right) {
		return calc(bottom, right)
			- calc(top, right)
			- calc(bottom, left)
			+ calc(top, left);
	};

	for (int i = 0; i < Q; ++i) {
		cin >> a >> b >> c >> d;
		cout << calc_offset(a, b, c + 1, d + 1) << endl;
	}
	return 0;
}
