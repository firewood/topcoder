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

typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> II;
typedef pair<LL, II> III;

static const LL INF = 1LL << 60;

bool is_palindrome(const string& s) {
	int len = (int)s.length();
	for (int i = 0; i < len / 2; ++i) {
		if (s[i] != s[len - i - 1]) return false;
	}
	return true;
}

string solve(string s) {
	string ans = "a" + s;
	if (!is_palindrome(ans)) return ans;
	ans = s + "a";
	if (!is_palindrome(ans)) return ans;
	return "";
}

int main() {
	int t;
	string s;
	cin >> t;
	for (int q = 0; q < t; ++q) {
		cin >> s;
		string ans = solve(s);
		if (ans.empty()) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			cout << ans << endl;
		}
	}
	return 0;
}
