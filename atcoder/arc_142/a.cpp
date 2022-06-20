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

int64_t solve(int64_t N, int64_t K) {
	int64_t ans = 0;
	string ks = to_string(K);
	string rks = ks;
	reverse(rks.begin(), rks.end());
	int64_t RK = stoll(rks);
	if ((K % 10) == 0 || RK < K) {
		return 0;
	}
	set<int64_t> s({ K, RK });
	for (auto x : s) {
		for (int64_t a = x; a <= N; a *= 10) {
			++ans;
		}
	}
	return ans;
}

int main() {
	int64_t N, K;
	std::cin >> N >> K;
	cout << solve(N, K) << endl;
	return 0;
}
