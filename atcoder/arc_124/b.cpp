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

set<int> solve(int64_t N, std::vector<int> a, std::vector<int> b) {
	set<int> ans;
	map<int, int> ma, mb;
	for (int i = 0; i < N; ++i) {
		ma[a[i]] += 1;
		mb[b[i]] += 1;
	}
	for (int i = 0; i < N; ++i) {
		auto possible = [&](int x) {
			for (int j = 0; j < N; ++j) {
				int y = x ^ a[j];
				if (mb.find(y) == mb.end() || ma[a[j]] != mb[y]) {
					return false;
				}
			}
			return true;
		};
		int x = a[0] ^ b[i];
		if (possible(x)) {
			ans.insert(x);
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	std::vector<int> b(N);
	for (int i = 0; i < N; i++) {
		std::cin >> b[i];
	}
	set<int> ans = solve(N, a, b);
	cout << ans.size() << endl;
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}
