// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> LLLL;

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<LL> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	vector<LLLL> v;
	for (int i = 0; i < m; ++i) {
		LL b, c;
		cin >> b >> c;
		v.push_back(LLLL(c, b));
	}
	sort(v.rbegin(), v.rend());
	LL ans = 0;
	int ap = 0, vp = 0;
	while (n > 0) {
		if (vp < (int)v.size() && v[vp].second == 0) {
			++vp;
		}
		if (vp < (int)v.size() && v[vp].second > 0 && v[vp].first > a[ap]) {
			ans += v[vp].first;
			v[vp].second--;
		} else {
			ans += a[ap++];
		}
		--n;
	}
	cout << ans << endl;
	return 0;
}
