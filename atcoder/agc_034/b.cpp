// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	string s, r;
	cin >> s;
	char prev = 0;
	for (char c : s) {
		if (prev == 'B' && c == 'C') {
			r.resize(r.length() - 1);
			c = 'D';
		}
		r += c;
		prev = c;
	}
	LL ans = 0;
	int acnt = 0;
	prev = 0;
	for (char c : r) {
		if (c == 'A') {
			++acnt;
		} else if (c == 'D') {
			ans += acnt;
		} else {
			acnt = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
