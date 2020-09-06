#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

typedef pair<int, int> II;

int main() {
	int n;
	cin >> n;
	vector<II> t;
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d-%d", &a, &b);
		a = (a / 5) * 5;
		b = ((b + 4) / 5) * 5;
		if ((b % 100) == 60) {
			b += 40;
		}
		t.emplace_back(II(a, b));
	}
	sort(t.begin(), t.end());
	for (int i = 0; i < n; ++i) {
		int s = t[i].first, e = t[i].second;
		if (i < n - 1 && e >= t[i + 1].first) {
			t[i + 1].first = s;
			t[i + 1].second = max(t[i + 1].second, e);
		} else {
			printf("%04d-%04d\n", t[i].first, t[i].second);
		}
	}
	return 0;
}
