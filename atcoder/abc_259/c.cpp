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

vector<pair<int, int>> run_length_encode(const string& s) {
	vector<pair<int, int>> cnt;
	char prev = s[0];
	int r = 0;
	for (char c : s + "*") {
		if (prev != c) {
			cnt.emplace_back(make_pair(prev, r));
			r = 0;
		}
		++r;
		prev = c;
	}
	return cnt;
}

bool solve(std::string S, std::string T) {
	vector<pair<int, int>> a = run_length_encode(S), b = run_length_encode(T);
	if (a.size() != b.size()) {
		return false;
	}
	for (int i = 0; i < a.size(); ++i) {
		if (a[i].first != b[i].first || (a[i].second != b[i].second && (a[i].second == 1 || a[i].second > b[i].second))) {
			return false;
		}
	}
	return true;
}

int main() {
	std::string S, T;
	std::cin >> S >> T;
	cout << (solve(S, T) ? "Yes" : "No") << endl;
	return 0;
}
