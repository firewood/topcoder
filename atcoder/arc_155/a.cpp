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

bool is_palindrome(const string &s) {
	string rev = s;
	reverse(rev.begin(), rev.end());
	return s == rev;
}

bool solve(int64_t N, int64_t K, string s) {
	K %= 2 * N;
	int64_t len = min(N, K);
	string rev = s;
	reverse(rev.begin(), rev.end());
	string x = rev.substr(0, len) + rev.substr(N - (K - len), K - len);
	return is_palindrome(s + x) && is_palindrome(x + s);
}

int main() {
	int64_t T, N, K;
	string s;
	cin >> T;
	for (int tt = 0; tt < T; ++tt) {
		cin >> N >> K;
		cin >> s;
		bool ans = solve(N, K, s);
		cout << (ans ? "Yes" : "No") << endl;
	}
	return 0;
}
