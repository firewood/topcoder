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

int64_t solve(int64_t N, int64_t K, std::vector<int64_t> A) {
	int64_t ans = 0;
	vector<int64_t> hist_index(N, -1), hist_value(N);
	for (int64_t i = 0; i < K; ++i) {
		int64_t x = ans % N;
		if (hist_index[x] >= 0) {
			int64_t cycles = i - hist_index[x], c = max(int64_t(0), (K - i - 1) / cycles);
			ans += (ans - hist_value[x]) * c;
			i += c * cycles;
		}
		hist_index[x] = i;
		hist_value[x] = ans;
		ans += A[x];
	}
	return ans;
}

int main() {
	int64_t N, K;
	std::cin >> N >> K;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, K, A) << endl;
	return 0;
}
