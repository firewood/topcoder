// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> LLLL;

int main(int argc, char *argv[])
{
	int n;
	LL C;
	cin >> n >> C;
	vector<LLLL> cd, dc;
	vector<LL> b1(n+1), b2(n+1);
	for (int i = 0; i < n; ++i) {
		LL x, v;
		cin >> x >> v;
		cd.push_back(LLLL(x, v));
	}
	sort(cd.begin(), cd.end());
	dc = cd;
	for (int i = 0; i < n; ++i) {
		dc[i].first = C - cd[i].first;
	}
	sort(dc.begin(), dc.end());

	LL ans = 0, tot = 0;
	for (int i = 0; i < n; ++i) {
		tot += cd[i].second;
		ans = max(ans, tot - cd[i].first);
		b1[i+1] = ans;
	}
	ans = 0;
	tot = 0;
	for (int i = 0; i < n; ++i) {
		tot += dc[i].second;
		ans = max(ans, tot - dc[i].first);
		b2[i+1] = ans;
	}

	tot = 0;
	for (int i = 0; i < n; ++i) {
		LL r = max(0LL, b2[n - (i + 1)] - cd[i].first);
		tot += cd[i].second;
		ans = max(ans, tot - cd[i].first + r);
	}
	tot = 0;
	for (int i = 0; i < n; ++i) {
		LL r = max(0LL, b1[n - (i + 1)] - dc[i].first);
		tot += dc[i].second;
		ans = max(ans, tot - dc[i].first + r);
	}

	cout << ans << endl;
	return 0;
}
