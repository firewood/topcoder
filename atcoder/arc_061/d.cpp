// D.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

typedef long long LL;
typedef map<int, int> IIMap;
typedef map<int, IIMap> IIIMap;

int main(int argc, char *argv[]) {
	int H, W, N;
	cin >> H >> W >> N;
	IIIMap m;
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		for (int c = -2; c <= 0; ++c) {
			int p = a + c;
			if (p >= 0 && p <= H - 3) {
				IIMap &x = m[p];
				for (int d = -2; d <= 0; ++d) {
					int q = b + d;
					if (q >= 0 && q <= W - 3) {
						x[q] += 1;
					}
				}
			}
		}
	}
	LL cnt[10] = { (LL)(H - 2) * (W - 2) };
	for (auto x : m) {
		for (auto y : x.second) {
			cnt[y.second] += 1;
			--cnt[0];
		}
	}
	for (int i = 0; i <= 9; ++i) {
		cout << cnt[i] << endl;
	}
	return 0;
}
