// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> II;
typedef pair<int, II> III;

int H;
int W;
int K;
int d[4096];
int u[4096];

int main(int argc, char *argv[])
{
	cin >> H >> W >> K;
	for (int i = 4; i < (H + 4); ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < W; ++j) {
			d[i * 64 + j + 4] = s[j] - '0';
		}
	}
	vector<III> v;
	for (int i = 4; i < (H + 4); ++i) {
		for (int j = 4; j < (W + 4); ++j) {
			int a = i * 64 + j;
			int c = d[a] * d[a + 1] * d[a + 64] * d[a + 64 + 1];
			if (c) {
				v.push_back(III(c, II(0, a)));
			}
		}
	}
	sort(v.rbegin(), v.rend());
	vector<int> ans;
	for (auto &x : v) {
		int a = x.second.second;
		if (d[a] && d[a + 1] && d[a + 64] && d[a + 64 + 1]) {
			int dd[] = { -64, -64 + 1, -1, 2, 64 - 1, 64 + 2, 64 * 2, 64 * 2 + 1 };
			vector<II> w;
			for (int i = 0; i < 8; ++i) {
				w.push_back(II(d[a + dd[i]], a + dd[i]));
			}
			sort(w.rbegin(), w.rend());
			if (w[4 - 1].first) {
				vector<int> aa;
				aa.push_back(a);
				aa.push_back(a + 1);
				aa.push_back(a + 64);
				aa.push_back(a + 64 + 1);
				for (int i = 0; i < 4; ++i) {
					aa.push_back(w[i].second);
				}
				for (int i = 0; i < 8; ++i) {
					d[aa[i]] = 0;
					ans.push_back(aa[i]);
				}
			}
		}
	}
	cout << ans.size() / 8 << endl;
	for (auto a : ans) {
		cout << (a / 64 - 4 + 1) << " " << ((a % 64) - 4 + 1) << endl;
	}
	return 0;
}
