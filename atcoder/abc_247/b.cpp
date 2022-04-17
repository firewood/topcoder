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

bool solve(int64_t N, std::vector<std::string> s, std::vector<std::string> t) {
	map<string, int> m;
	for (int i = 0; i < N; ++i) {
		m[s[i]] += 1;
		if (s[i] != t[i]) {
			m[t[i]] += 1;
		}
	}
	for (int i = 0; i < N; ++i) {
		if (m[s[i]] > 1 && (s[i] == t[i] || m[t[i]] > 1)) {
			return false;
		}
	}
	return true;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<std::string> s(N);
	std::vector<std::string> t(N);
	for (int i = 0; i < N; i++) {
		std::cin >> s[i] >> t[i];
	}
	cout << (solve(N, s, t) ? "Yes" : "No") << endl;
	return 0;
}
