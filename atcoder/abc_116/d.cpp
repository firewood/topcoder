// D.

#include <sstream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL n, k;
	cin >> n >> k;
	vector< vector<LL> > td(n);
	for (int i = 0; i < n; ++i) {
		LL t, d;
		cin >> t >> d;
		td[t - 1].push_back(d);
	}
	vector<LL> a, b;
	for (int i = 0; i < n; ++i) {
		sort(td[i].rbegin(), td[i].rend());
		if (!td[i].empty()) {
			a.push_back(td[i][0]);
			for (int j = 1; j < (int)td[i].size(); ++j) {
				b.push_back(td[i][j]);
			}
		}
	}
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	LL kinds = a.size();
	if ((LL)a.size() >= k) {
		a.resize(k);
		kinds = k;
	} else {
		LL c = k - a.size();
		a.insert(a.begin(), b.begin(), b.begin() + c);
		b.erase(b.begin(), b.begin() + c);
	}
	LL ans = accumulate(a.begin(), a.end(), kinds * kinds);
	for (LL x : b) {
		LL nk = max(1LL, kinds - 1);
		LL next = ans - kinds * kinds - a.back() + x + nk * nk;
		if (next <= ans) {
			break;
		}
		kinds = nk;
		a.pop_back();
		ans = next;
	}
	cout << ans << endl;
	return 0;
}
