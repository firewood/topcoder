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

int64_t solve(int64_t N, int64_t A, int64_t B, std::vector<int64_t> X) {
	int64_t ans = 0, pos = X.front();
	for (int i = 1; i < N; ++i) {
		ans += min((X[i] - X[i - 1]) * A, B);
	}
	return ans;
}

int main() {
	int64_t N, A, B;
	std::cin >> N >> A >> B;
	std::vector<int64_t> X(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i];
	}
	cout << solve(N, A, B, X) << endl;
	return 0;
}
