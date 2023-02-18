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

int64_t solve2(int64_t N, string s) {
	string goal(N, '0');
	set<string> ss;
	ss.insert(s);
	vector<string> q;
	q.emplace_back(s);
	for (int tt = 0; tt < 10 && !q.empty(); ++tt) {
		vector<string> nq;
		for (auto x : q) {
			if (x == goal) return tt;
			for (int i = 0; i < N - 2; ++i) {
				x[i] ^= 1;
				for (int j = i + 2; j < N; ++j) {
					x[j] ^= 1;
					if (ss.find(x) == ss.end()) {
						ss.insert(x);
						nq.emplace_back(x);
					}
					x[j] ^= 1;
				}
				x[i] ^= 1;
			}
		}
		q = nq;
	}
	return -1;
}

int64_t solve(int64_t N, string s) {
	int64_t cnt = count(s.begin(), s.end(), '1');
	if (cnt % 2) {
		return -1;
	}
	if (s == "0110") return 3;
	if (cnt == 2 && s.find("11") != string::npos) {
		return N <= 3 ? -1 : 2;
	}
	return cnt / 2;
}

int main() {
	int64_t T, N, K;
	string s;
	cin >> T;
	for (int tt = 0; tt < T; ++tt) {
		cin >> N >> s;
		cout << solve(N, s) << endl;
	}
	return 0;
}
