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
#include <random>

using namespace std;

int64_t solve(int N, vector<int> a) {
	set<int> s;
	for (int i = 0; i < N; i++) {
		int x = a[i];
		if (s.find(x) != s.end()) {
			x = -x;
		}
		s.insert(x);
	}
	return s.size();
}

int main() {
	int t, N, X;
	cin >> t;
	for (int q = 0; q < t; ++q) {
		cin >> N;
		std::vector<int> a(N);
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		int64_t ans = solve(N, a);
		cout << ans << endl;
	}
	return 0;
}
