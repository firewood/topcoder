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

int64_t solve2(int64_t N, std::vector<int64_t> A) {
	int64_t ans = 0;
	for (int len = 1; len <= N; ++len) {
		for (int i = 0; i + len <= N; ++i) {
			for (int j = 0; j < len / 2; ++j) {
				ans += A[i + j] != A[i + len - j - 1];
			}
		}
	}
	return ans;
}

int64_t solve(int64_t N, std::vector<int64_t> A) {
	int64_t ans = 0;
	map<int64_t, int64_t> m;
	for (auto x : A) {
		m[x] += 1;
	}
	for (int i = 0; i < (N + 1) / 2; ++i) {
		int64_t left = A[i], right = A[N - i - 1];
		ans += (N - 2 * i - m[left]) * (i + 1);
		ans += (N - 2 * i - m[right]) * (i + 1);
		if (left != right) {
			ans -= i + 1;
		}
		m[left] -= 1;
		m[right] -= 1;
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
	cout << solve(N, A) << endl;
	return 0;
}
