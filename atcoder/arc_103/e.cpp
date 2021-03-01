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

typedef pair<int, int> II;

bool solve(string s) {
	int n = (int)s.length();
	if (s.front() == '0' || s.back() == '1') {
		return false;
	}
	for (int i = 0; i < n / 2; ++i) {
		if (s[i] != s[n - i - 2]) {
			return false;
		}
	}
	vector<II> ans;
	int parent = n - 1;
	for (int i = n - 2; i >= 0; --i) {
		ans.push_back(II(i + 1, parent + 1));
		if (s[i] == '1') {
			parent = i;
		}
	}
	reverse(ans.begin(), ans.end());
	for (auto kv : ans) {
		cout << kv.first << " " << kv.second << endl;
	}
	return true;
}

int main() {
    string s;
	std::cin >> s;
	if (!solve(s)) {
		cout << -1 << endl;
	}
	return 0;
}
