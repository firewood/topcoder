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

vector<int64_t> solve(int64_t N, std::vector<int64_t> L, std::vector<int64_t> R) {
	vector<int64_t> ans(N);
	int64_t left = 0, right = 0;
	for (int i = 1; i < N; ++i) {
		if (R[i] < R[left]) {
			left = i;
		}
		if (L[i] > L[right]) {
			right = i;
		}
		ans[i] = max(int64_t(0), (L[right] - R[left] + 1) / 2);
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> L(N), R(N);
	for (int i = 0; i < N; i++) {
		std::cin >> L[i] >> R[i];
	}
	vector<int64_t> ans = solve(N, L, R);
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}
