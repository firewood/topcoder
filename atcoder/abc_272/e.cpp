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
#include <bitset>

using namespace std;

vector<int> solve(int N, int M, std::vector<int> A) {
	vector<int> ans;
	vector<vector<int>> v(M);
	for (int i = 0; i < N; ++i) {
		int a = A[i], c = 0;
		if (a < 0) {
			c = abs(a) / (i + 1);
			a += c * (i + 1);
			if (a < 0) {
				a += i + 1;
				++c;
			}
		}
		while (a < N && c <= M) {
			if (c > 0) {
				v[c - 1].emplace_back(a);
			}
			a += i + 1;
			++c;
		}
	}
	vector<int> used(N + 1, -1);
	for (int i = 0; i < M; ++i) {
		for (auto x : v[i]) {
			used[x] = i;
		}
		for (int j = 0; j <= N; ++j) {
			if (used[j] < i) {
				ans.emplace_back(j);
				break;
			}
		}
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	auto ans = solve(N, M, A);
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}
