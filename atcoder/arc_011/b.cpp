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

vector<string> solve(int64_t N, std::vector<std::string> w) {
	vector<string> ans;
	map<int, int> m;
	m['b'] = m['c'] = 1;
	m['d'] = m['w'] = 2;
	m['t'] = m['j'] = 3;
	m['f'] = m['q'] = 4;
	m['l'] = m['v'] = 5;
	m['s'] = m['x'] = 6;
	m['p'] = m['m'] = 7;
	m['h'] = m['k'] = 8;
	m['n'] = m['g'] = 9;
	m['z'] = m['r'] = 0;
	for (auto word : w) {
		string s;
		for (auto c : word) {
			c = tolower(c);
			if (m.find(c) != m.end()) {
				s += char('0' + m[c]);
			}
		}
		if (!s.empty()) {
			ans.emplace_back(s);
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<std::string> w(N);
	for (int i = 0; i < N; i++) {
		std::cin >> w[i];
	}
	vector<string> ans = solve(N, w);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
