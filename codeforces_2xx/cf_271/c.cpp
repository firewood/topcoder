
// C. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

typedef pair<int, int> II;

int main(int argc, char *argv[])
{
	int N;
	string s;
	{
		getline(cin, s);
		stringstream ss(s);
		ss >> N;
	}
	for (int i = 0; i < N; ++i) {
		II xy[4][4];
		int x[4][4], y[4][4], a[4], b[4];
		for (int j = 0; j < 4; ++j) {
			getline(cin, s);
			stringstream ss(s);
			ss >> xy[j][0].first >> xy[j][0].second >> a[j] >> b[j];
			xy[j][0].first *= 4, xy[j][0].second *= 4, a[j] *= 4, b[j] *= 4;
			for (int k = 1; k < 4; ++k) {
				int p = xy[j][k - 1].first - a[j], q = xy[j][k - 1].second - b[j];
				xy[j][k].first = a[j] - q, xy[j][k].second = b[j] + p;
			}
		}

		int ans = 1 << 30;
		int d[4] = {};
		for (int j = 0; j < 256; ++j) {
			II xy1[4], xy2[4];
			int cx = 0, cy = 0;
			for (int k = 0; k < 4; ++k) {
				xy1[k] = xy[k][d[k]];
				cx += xy1[k].first, cy += xy1[k].second;
			}
			sort(xy1, xy1 + 4);
			cx /= 4, cy /= 4;

			if (xy1[0] != xy1[1] && xy1[2] != xy1[3]) {
				xy2[0] = xy1[0];
				for (int k = 1; k < 4; ++k) {
					int p = xy2[k - 1].first - cx, q = xy2[k - 1].second - cy;
					xy2[k].first = cx - q, xy2[k].second = cy + p;
				}
				sort(xy2, xy2 + 4);

				if (memcmp(xy1, xy2, sizeof(xy1)) == 0) {
					int c = d[0] + d[1] + d[2] + d[3];
					ans = min(ans, c);
				}
			}

			for (int k = 0; k < 4; ++k) {
				if (++d[k] < 4) {
					break;
				}
				d[k] = 0;
			}
		}

		cout << ((ans < (1 << 30)) ? ans : -1) << endl;
	}

	return 0;
}

