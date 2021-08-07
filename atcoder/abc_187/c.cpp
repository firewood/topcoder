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

typedef long double LD;
typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;

string solve(int64_t N, std::vector<std::string> S) {
	set<string> a, b;
	for (string s : S) {
		if (s[0] == '!') {
			a.insert(s.substr(1));
		} else {
			b.insert(s);
		}
	}
	for (string s : a) {
		if (b.find(s) != b.end()) {
			return s;
		}
	}
	return "satisfiable";
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	cout << solve(N, S) << endl;
	return 0;
}
