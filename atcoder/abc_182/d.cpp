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

typedef long long LL;

int main() {
	LL N, a, sum = 0, tot = 0, ans = 0, mx = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a;
		sum += a;
		mx = max(mx, sum);
		ans = max(ans, tot + mx);
		tot += sum;
	}
	cout << ans << endl;
	return 0;
}
