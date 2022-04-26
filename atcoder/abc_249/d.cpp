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

int64_t solve(int N, std::vector<int> A) {
	int64_t ans = 0;
	vector<int64_t> cnt(200001);
	for (int i = 0; i < N; ++i) {
		cnt[A[i]] += 1;
	}
	for (int i = 1; i <= 200000; ++i) {
		if (cnt[i] > 0) {
			for (int j = 1; j * j <= i; ++j) {
				int k = i / j;
				if (i == j * k) {
					ans += cnt[i] * cnt[j] * cnt[k] * (j == k ? 1 : 2);
				}
			}
		}
	}
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}
