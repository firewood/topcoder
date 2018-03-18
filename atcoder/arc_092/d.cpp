// D.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

LL solve1(const vector<int> &a, const vector<int> &b) {
	int n = (int)a.size();
	vector<int> bs[29];
	for (int bi = 0; bi < 29; ++bi) {
		int bm = (1 << bi) - 1;
		for (int i = 0; i < n; ++i) {
			bs[bi].push_back(a[i] & bm);
		}
		sort(bs[bi].begin(), bs[bi].end());
	}
	int as = 0;
	for (int i = 0; i < n; ++i) {
		as ^= a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans ^= as;
		for (int bi = 0; bi < 29; ++bi) {
			int bf = 1 << bi, bm = bf - 1;
			int cnt = (n % 2) && (bf & b[i]);
			int br = bf - (b[i] & bm);
			int ov = (int)(bs[bi].end() - lower_bound(bs[bi].begin(), bs[bi].end(), br));
			cnt += ov;
			if (cnt & 1) {
				ans ^= bf;
			}
		}
	}
	return ans;
}

LL solve2(const vector<int> &a, const vector<int> &b) {
	int n = (int)a.size();
	LL r = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			r ^= (a[i] + b[j]);
		}
	}
	return r;
}

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	LL ans = solve1(a, b);
	cout << ans << endl;

	return 0;
}
