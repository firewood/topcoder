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

int64_t solve(int64_t N, std::vector<int64_t> A) {
	int64_t ans = 0;
	map<int64_t, int64_t> m;
	for (int i = 0; i < N; i++) {
		int64_t cnt = i - m[A[i]];
		ans += cnt;
		m[A[i]] += 1;
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, std::move(A)) << endl;
	return 0;
}
