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
	string ans;
	bool f = false;
	for (char c : S) {
		if (!f && c == ',') {
			c = '.';
		}
		if (c == '\"') {
			f = !f;
		}
		ans += c;
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
