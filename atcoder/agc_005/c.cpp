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

bool solve(int N, std::vector<int> a) {
	vector<int> cnt(101);
	for (auto x : a) {
		cnt[x] += 1;
	}
	int mx = *max_element(a.begin(), a.end());
	if ((mx % 2) == 0) {
		if (cnt[mx / 2] >= 2) return false;
	} else {
		if (cnt[mx / 2 + 1] != 2) return false;
	}
	for (int i = mx; i >= 2; --i) {
		if (i * 2 < mx) {
			if (cnt[i]) return false;
		} else {
			if (cnt[i] == 0) return false;
		}
	}
	return true;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	cout << (solve(N, a) ? "Possible" : "Impossible") << endl;
	return 0;
}
