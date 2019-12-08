// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

typedef bitset<512000> BS;
const int offset = 512000 / 2;

int main(int argc, char* argv[]) {

#ifdef _MSC_VER
	while (true)
#endif
	{
		int h = -1, w = -1;
		cin >> h >> w;
		if (h < 0) return 0;
		int a[80][80] = {}, b[80][80] = {};
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> b[i][j];
			}
		}
		vector<BS> prev(w);
		for (int i = 0; i < h; ++i) {
			vector<BS> curr(w);
			for (int j = 0; j < w; ++j) {
				int diff = abs(b[i][j] - a[i][j]);
				if (i == 0 && j == 0) {
					curr[0][offset + diff] = true;
				}
				if (i > 0) {
					curr[j] |= (prev[j] << diff);
					curr[j] |= (prev[j] >> diff);
				}
				if (j > 0) {
					curr[j] |= (curr[j - 1] << diff);
					curr[j] |= (curr[j - 1] >> diff);
				}
			}
			prev = curr;
		}
		int ans = 1 << 30;
		for (int i = 0; i < offset; ++i) {
			if (prev[w - 1][offset + i] || prev[w - 1][offset - i]) {
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
