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
#include <random>

using namespace std;

string solve(int N, string s) {
	string x;
	char prev = 'z' + 1;
	for (char c : s) {
		if (c > prev || c == prev && x.length() == 1) {
			break;
		}
		x += c;
		prev = c;
	}
	string r = x;
	reverse(r.begin(), r.end());
	return x + r;
}

string solve2(int N, string s) {
	string r = s;
	reverse(r.begin(), r.end());
	string ans = s + r;
	for (int i = 1; i <= s.length(); ++i) {
		string x = s.substr(0, i);
		string y = x;
		reverse(y.begin(), y.end());
		string z = x + y;
		if (z < ans) {
			ans = z;
		}
	}
	return ans;
}

int main() {
/*
	{
		string s = "aaabbbcccddd";
		int n = s.length();
		for (int i = 0; i < 10000; ++i) {
			random_shuffle(s.begin(), s.end());
			string a = solve(n, s);
			string b = solve2(n, s);
			if (a != b) {
				i += 0;
			}

		}
	}
*/
	int t, N, X;
	string s;
	cin >> t;
	for (int q = 0; q < t; ++q) {
		cin >> N;
		cin >> s;
		string ans = solve(N, s);
		cout << ans << endl;
	}
	return 0;
}
