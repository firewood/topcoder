#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

void solve(int L, std::vector<int> &B) {
	vector<int> ans(L);
	int prev = 0;
	for (int i = 1; i < L; ++i) {
		ans[i] = ans[i - 1] ^ B[i - 1];
	}
	if (ans[0] ^ ans[L - 1] != B[L - 1]) {
		cout << -1 << endl;
	} else {
		for (int a : ans) {
			cout << a << endl;
		}
	}
}

int main() {
	int L;
	std::cin >> L;
	std::vector<int> B(L);
	for (int i = 0; i < L; i++) {
		std::cin >> B[i];
	}
	solve(L, B);
	return 0;
}
