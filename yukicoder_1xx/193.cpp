#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int eval(string s) {
	if (s[0] < '0' || s[s.length() - 1] < '0') {
		return -(1 << 30);
	}
	int tot = 0;
	int sign = 1;
	int val = 0;
	for (char c : s) {
		if (c == '+') {
			tot += val * sign;
			sign = 1;
			val = 0;
		} else if (c == '-') {
			tot += val * sign;
			sign = -1;
			val = 0;
		} else {
			val = val * 10 + c - '0';
		}
	}
	return tot + val * sign;
}

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int ans = -(1 << 30);
	for (int i = 0; i != s.length(); ++i) {
		ans = max(ans, eval(s.substr(i) + s.substr(0, i)));
	}
	cout << ans << endl;
	return 0;
}
