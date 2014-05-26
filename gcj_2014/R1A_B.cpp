// Google Code Jam 2014 R1A
// Problem B. Full Binary Tree

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef vector<int> IntVec;

IntVec g[16];
int vis[16];
int valid = 0;

static inline int popcount(unsigned int b)
{
#ifdef __GNUC__
	return __builtin_popcount(b);
#elif _MSC_VER >= 1400
	return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	b += b >> 16;
	return b & 0x3F;
#endif
}

bool dfs(int b, int n, int p) {
	int &r = vis[n];
	if (r >= 0) {
		return r;
	}
	int cnt = 0;
	int c[3];
	for (int i = 0; i < (int)g[n].size(); ++i) {
		int a = g[n][i];
		if (a != p && !((1 << a) & b)) {
			c[cnt++] = a;
			if (cnt > 2) {
				r = 0;
				return r;
			}
		}
	}
	if (cnt == 0) {
		r = 1;
	}
	else if (cnt == 1) {
		r = 0;
	}
	else {
		r = dfs(b, c[0], n) && dfs(b, c[1], n);
	}
	if (r) {
		valid &= ~(1 << n);
	}
	return r;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	if (T <= 0) return 0;

	for (int t = 1; t <= T; ++t) {
		int N = 0;

		getline(cin, s);
		{
			stringstream ss(s);
			ss >> N;
		}

		for (int i = 0; i < N; ++i) {
			g[i].clear();
		}

		for (int n = 0; n < N - 1; ++n) {
			getline(cin, s);
			stringstream ss(s);
			int a = 0, b = 0;
			ss >> a >> b;
			a -= 1, b -= 1;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		int ans = N;
		int m = 1 << N;
		for (int b = 0; b < m; ++b) {
			for (int s = 0; s < N; ++s) {
				memset(vis, -1, sizeof(vis));
				valid = (m-1) & ~b;
				if (dfs(b, s, s) && valid == 0) {
					ans = min(ans, popcount(b));
				}
			}
		}

		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}
