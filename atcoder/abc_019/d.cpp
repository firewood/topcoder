#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n, md = -1, mi = -1, ans = 0;
	char w[256];
	fgets(w, 256, stdin);
	n = atoi(w);
	for (int i = 2; i <= n; ++i) {
		printf("? 1 %d\n", i);
		fflush(stdout);
		fgets(w, 256, stdin);
		int d = atoi(w);
		if (d > md) {
			md = d;
			mi = i;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (i == mi) continue;
		printf("? %d %d\n", mi, i);
		fflush(stdout);
		fgets(w, 256, stdin);
		ans = max(ans, atoi(w));
	}
	printf("! %d\n", ans);
	return 0;
}
