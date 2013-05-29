// Google Code Jam 2013 R1C
// Problem B. Pogo
// large

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <stdio.h>

using namespace std;

typedef long long LL;

string solve(LL x, LL y)
{
	LL d = abs(x) + abs(y);
	LL s = 0;
	while (true) {
		LL sum = s*(s+1)/2;
		if (sum >= d && (sum%2) == (d%2)) {
			break;
		}
		s += 1;
	}

	string ans;
	while (s > 0) {
		if (abs(x) >= abs(y)) {
			if (x > 0) {
				ans += "E";
				x -= s;
			} else {
				ans += "W";
				x += s;
			}
		} else {
			if (y > 0) {
				ans += "N";
				y -= s;
			} else {
				ans += "S";
				y += s;
			}
		}
		--s;
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

static bool test(int x, int y, const string &ans)
{
	int dx[4] = {-1,1,0,0};
	int dy[4] = {0,0,-1,1};
	char c[4] = {'W','E','S','N'};

	int p = 0, q = 0;
	int i, j;
	for (i = 0; i < (int)ans.length(); ++i) {
		for (j = 0; j < 4; ++j) {
			if (c[j] == ans[i]) {
				p += dx[j] * (i+1);
				q += dy[j] * (i+1);
			}
		}
	}

	return p == x && q == y;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	if (T <= 0) return 0;

	for (int t = 0; t < T; ++t) {
		int X = 0, Y = 0;
		getline(cin, s);
		stringstream ss(s);
		ss >> X >> Y;
		string ans = solve(X,Y);
		if (!test(X, Y, ans)) {
			cout << "TEST FAILED" << endl;
			break;
		}
		cout << "Case #" << (t+1) << ": " << ans << endl;
	}

	return 0;
}

