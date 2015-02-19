#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

int primes = 0;
int p[10001];
int memo[10001];

static int solve(int n) {
	int &r = memo[n];
	if (r >= 0) {
		return r;
	}
	r = 0;
	for (int i = 2; i+2 <= n; ++i) {
		if (!p[i]) {
			if (!solve(n - i)) {
				r = 1;
				break;
			}
		}
	}
	return r;
}

int main(int argc, char *argv[])
{
	for (int i = 2; i <= 10000; ++i) {
		if (!p[i]) {
			for (int j = i * 2; j <= 10000; j += i) {
				p[j] = 1;
			}
		}
	}
	memset(memo, -1, sizeof(memo));
	memo[0] = memo[1] = memo[2] = 0;

	string s;
	while (getline(cin, s)) {
		int N = atoi(s.c_str());
		string ans = solve(N) ? "Win" : "Lose";
		cout << ans << endl;
	}
	return 0;
}
