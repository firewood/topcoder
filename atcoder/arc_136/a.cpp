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

string solve(int64_t N, std::string S) {
	string s, ans;
	for (char c : S) {
		if (c == 'A') {
			s += "BB";
		} else {
			s += c;
		}
	}
	for (char c : s) {
		if (c == 'B' && !ans.empty() && ans.back() == c) {
			ans.back() = 'A';
		} else {
			ans += c;
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::string S;
	std::cin >> N >> S;
	cout << solve(N, S) << endl;
	return 0;
}
