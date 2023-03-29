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

int solve(std::string s, int k) {
	int ans = 0;
	set<string> ss;
	for (int i = 0; i + k <= s.length(); ++i) {
		ss.insert(s.substr(i, k));
	}
	return ss.size();
}

int main() {
	std::string s;
	int k;
	std::cin >> s >> k;
	cout << solve(s, k) << endl;
	return 0;
}
