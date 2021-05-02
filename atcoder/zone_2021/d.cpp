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

string solve(const std::string &S) {
	string ans;
	bool reversed = false;
	for (char c : S) {
		if (c == 'R') {
			reversed = !reversed;
		} else if (reversed) {
			if (!ans.empty() && ans.front() == c) {
				ans = ans.substr(1);
			} else {
				ans = string(1, c) + ans;
			}
		} else {
			if (!ans.empty() && ans.back() == c) {
				ans.pop_back();
			} else {
				ans += c;
			}
		}
	}
	if (reversed) {
		reverse(ans.begin(), ans.end());
	}
	return ans;
}

int main() {
    std::string S;
	std::cin >> S;
	cout << solve(S) << endl;
	return 0;
}
