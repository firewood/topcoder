#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

bool solve(string S) {
	if (S.length() <= 2) {
		sort(S.begin(), S.end());
		for (int i = 8; i < 100; i += 8) {
			string x = to_string(i);
			sort(x.begin(), x.end());
			if (S == x) {
				return true;
			}
		}
	} else {
		vector<int> cnt(10);
		for (char c : S) {
			cnt[c - '0'] += 1;
		}
		for (int i = 104; i < 1000; i += 8) {
			vector<int> r = cnt;
			for (int k = i; k > 0; k /= 10) {
				r[k % 10] -= 1;
			}
			if (all_of(r.begin(), r.end(), [](int x) { return x >= 0; })) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	string S;
	std::cin >> S;
	bool ans = solve(S);
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
