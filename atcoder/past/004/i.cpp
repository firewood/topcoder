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

typedef long long LL;

int main() {
	LL N;
	cin >> N;
	vector<LL> a(N), sum(N * 2 + 2);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < N * 2; ++i) {
		sum[i + 1] = sum[i] + a[i % N];
	}
	LL tot = sum[N];
	LL ans = 1LL << 60;
	for (int i = 0; i < N; ++i) {
		int pos = lower_bound(sum.begin() + i, sum.begin() + i + N, sum[i] + tot / 2) - sum.begin();
		if (pos > i) {
			LL a = sum[pos - 1] - sum[i];
			ans = min(ans, abs(a - (tot - a)));
		}
		LL a = sum[pos] - sum[i];
		ans = min(ans, abs(a - (tot - a)));
	}
	cout << ans << endl;
	return 0;
}
