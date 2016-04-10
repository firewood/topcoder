// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

int memo[100][100][100];
int w[100];

int cost(int lev, int s, int e) {
	int &r = memo[lev][s][e];
	if (r <= 0) {
		if (s == e) {
			r = w[s] * lev;
		} else if (s + 1 == e) {
			r = (w[s] + w[e]) * (lev + 1);
		} else {
			r = 1 << 30;
			for (int i = s + 1; i <= e; ++i) {
				r = min(r, cost(lev + 1, s, i - 1) + cost(lev + 1, i, e));
			}
		}
	}
	return r;
}

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	int ans = 0;
	if (N <= 100) {
		for (int i = 0; i < N; ++i) {
			cin >> w[i];
		}
		ans = cost(0, 0, N - 1);
	}
	cout << ans << endl;
	return 0;
}
