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
#include <atcoder/modint>

using namespace std;

using mint = atcoder::modint1000000007;

mint solve(int64_t N, std::vector<int64_t> A) {
	mint ans = 1, x = 1, d = 1;
	int64_t y = 0;
	for (int i = 0; i < N; ++i) {
		x += d * A[i];
		y = (y + A[i]) / 10;
		if (y == 0) {
			ans *= x;
			x = 1;
			d = 1;
		} else {
			d *= 10;
		}
	}
	return ans * x - 1;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A).val() << endl;
	return 0;
}
