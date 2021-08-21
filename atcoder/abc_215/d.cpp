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

vector<int> get_factors(int x) {
	vector<int> f;
	for (int p = 2; p * p <= x; ++p) {
		if (x % p == 0) {
			while (x % p == 0) {
				x /= p;
			}
			f.emplace_back(p);
		}
	}
	if (x > 1) f.emplace_back(x);
	return f;
}

vector<int> solve(int64_t N, int64_t M, std::vector<int> A) {
	vector<int> used(M + 1);
	for (int i = 0; i < N; ++i) {
		for (auto p : get_factors(A[i])) {
			if (p <= M && !used[p]) {
				for (int j = p; j <= M; j += p) {
					used[j] = 1;
				}
			}
		};
	}
	vector<int> ans;
	for (int i = 1; i <= M; ++i) {
		if (!used[i]) {
			ans.emplace_back(i);
		}
	}
	return ans;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	vector<int> ans = solve(N, M, A);
	cout << ans.size() << endl;
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}
