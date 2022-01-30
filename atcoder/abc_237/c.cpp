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

bool solve(std::string S) {
	bool ans = false;
	int left = 0, right = 0, N = S.length();
	while (left < N && S[left] == 'a') {
		++left;
	}
	while (right < N && S[N - 1 - right] == 'a') {
		++right;
	}
	if (left <= right) {
		string s = S.substr(left, N - left - right);
		string r = s;
		reverse(r.begin(), r.end());
		ans = s == r;
	}
	return ans;
}

int main() {
	std::string S;
	std::cin >> S;
	cout << (solve(S) ? "Yes" : "No") << endl;
	return 0;
}
