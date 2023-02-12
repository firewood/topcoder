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

int solve(int C, std::vector<int> N, std::vector<int> M, std::vector<int> L) {
	vector<vector<int>> v;
	vector<int> mx(3);
	for (int i = 0; i < C; ++i) {
		vector<int> a;
		a.emplace_back(N[i]);
		a.emplace_back(M[i]);
		a.emplace_back(L[i]);
		sort(a.begin(), a.end());
		for (int j = 0; j < 3; ++j) {
			mx[j] = max(mx[j], a[j]);
		}
	}
	return mx[0] * mx[1] * mx[2];
}

int main() {
	int64_t C;
	std::cin >> C;
	std::vector<int> N(C), M(C), L(C);
	for (int i = 0; i < C; i++) {
		std::cin >> N[i] >> M[i] >> L[i];
	}
	cout << solve(C, N, M, L) << endl;
	return 0;
}
