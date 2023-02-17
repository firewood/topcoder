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

vector<int64_t> solve(int64_t N, std::vector<int64_t> A) {
	vector<int64_t> ans;
	vector<int64_t> B(N + 1), y(N);
	for (int i = N - 1; i >= 0; --i) {
		B[i] = B[i + 1] + A[i];
	}
	B.resize(N);
	if (B[0]) {
		int64_t b = abs(B[0]), sum = 0;
		for (int i = 1; i < N; ++i) {
			sum -= b * B[i];
		}
		ans.emplace_back(sum / B[0]);
		for (int i = 1; i < N; ++i) {
			ans.emplace_back(ans.back() + b);
		}
	} else {
		if (count_if(B.begin(), B.end(), [](auto x) { return x >= 0; }) == N) {
			return {};
		}
		if (count_if(B.begin(), B.end(), [](auto x) { return x <= 0; }) == N) {
			return {};
		}
		int64_t x = accumulate(B.begin() + 1, B.end(), int64_t(0));
		int64_t p = find(B.begin() + 1, B.end(), -1) - B.begin();
		int64_t q = find(B.begin() + 1, B.end(), 1) - B.begin();
		ans.emplace_back(1);
		for (int i = 1; i < N; ++i) {
			if (x >= 0) {
				ans.emplace_back(ans.back() + (i == p ? 1 + x : 1));
			} else {
				ans.emplace_back(ans.back() + (i == q ? 1 - x : 1));
			}
		}
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
	vector<int64_t> ans = solve(N, A);
	if (!ans.empty()) {
		cout << "Yes" << endl;
		for (size_t i = 0; i < ans.size(); ++i) {
			if (i) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
