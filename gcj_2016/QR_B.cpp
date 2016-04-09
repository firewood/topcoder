// Google Code Jam 2016 Qualification Round
// Problem B. Revenge of the Pancakes

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long LL;

string rev(string s) {
	char temp[128] = {};
	for (int i = 0; i != s.length(); ++i) {
		temp[s.length() - i - 1] = s[i] == '+' ? '-' : '+';
	}
	return temp;
}

LL solve(string s) {
	int a = s.find('-');
	int b = s.find('+');
	if (a < 0) {
		return 0;
	} else if (b < 0) {
		return 1;
	}
	int m = max(a, b);
	return 1 + solve(rev(s.substr(0, m)) + s.substr(m));
}

int main(int argc, char *argv[]) {
	LL T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		string s;
		cin >> s;
		cout << "Case #" << t << ": " << solve(s) << endl;
	}
	return 0;
}
