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

string solve(std::string s) {
	string ans;
	for (auto c : s) {
		ans += char(c ^ 1);
	}
	return ans;
}

int main() {
	std::string s;
	std::cin >> s;
	cout << solve(s) << endl;
	return 0;
}
