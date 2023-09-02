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

int64_t solve(int64_t N, int64_t D, int64_t P, std::vector<int64_t> F) {
	int64_t sum = accumulate(F.begin(), F.end(), int64_t(0)), ans = sum;
	sort(F.rbegin(), F.rend());
	for (int i = 0; i < N; i += D) {
		int k = min(i + D, N);
		sum += P - accumulate(F.begin() + i, F.begin() + k, int64_t(0));
		ans = min(ans, sum);
	}
	return ans;
}

int main() {
	int64_t N, D, P;
	std::cin >> N >> D >> P;
	std::vector<int64_t> F(N);
	for (int i = 0; i < N; i++) {
		std::cin >> F[i];
	}
	cout << solve(N, D, P, F) << endl;
	return 0;
}
