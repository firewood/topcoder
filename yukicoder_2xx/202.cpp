#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>
#include <vector>
#include <cstdio>

using namespace std;

typedef pair<int, int> II;
typedef set<II> IISet;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	int ans = 0;
	IISet coins[202][202];
	for (int i = 0; i < N; ++i) {
		getline(cin, s);
		stringstream ss(s);
		int x, y;
		ss >> x >> y;
		int sx = (x - 20 + 50) / 100;
		int ex = (x + 20 + 50) / 100;
		int sy = (y - 20 + 50) / 100;
		int ey = (y + 20 + 50) / 100;
		bool remove = false;
		for (int i = sy; i <= ey; ++i) {
			for (int j = sx; j <= ex; ++j) {
				IISet &a = coins[i][j];
				IISet::const_iterator it;
				for (it = a.begin(); it != a.end(); ++it) {
					int dx = it->first - x;
					int dy = it->second - y;
					if ((dx * dx + dy * dy) < 20 * 20) {
						remove = true;
						break;
					}
				}
			}
		}
		if (!remove) {
			coins[(y + 50) / 100][(x + 50) / 100].insert(II(x, y));
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
