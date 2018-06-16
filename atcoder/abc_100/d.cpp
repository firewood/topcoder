// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	int n, m;
	cin >> n >> m;
	vector<LL> v[8];
	for (int i = 0; i < n; ++i) {
		LL x, y, z;
		cin >> x >> y >> z;
		for (int j = 0; j < 8; ++j) {
			LL w = ((j & 1) ? x : -x) + ((j & 2) ? y : -y) + ((j & 4) ? z : -z);
			v[j].push_back(w);
		}
	}
	LL ans = 0;
	for (int j = 0; j < 8; ++j) {
		sort(v[j].rbegin(), v[j].rend());
		ans = max(ans, accumulate(v[j].begin(), v[j].begin() + m, 0LL));
	}
	cout << ans << endl;
	return 0;
}
