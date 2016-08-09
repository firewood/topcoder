#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> IntVec;

int main(int argc, char *argv[]) {
	int x, y;
	IntVec g[4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0} };
	IntVec a[4];
	for (int i = 0; i < 4; ++i) {
		a[i].resize(4);
		for (int j = 0; j < 4; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 0) {
				y = i, x = j;
			}
		}
	}
	bool ans = false;
	while (true) {
		if (a[0] == g[0] && a[1] == g[1] && a[2] == g[2] && a[3] == g[3]) {
			ans = true;
			break;
		}
		if (x > 0 && a[y][x - 1] == g[y][x]) {
			swap(a[y][x], a[y][x - 1]);
			--x;
		} else if (x < 3 && a[y][x + 1] == g[y][x]) {
			swap(a[y][x], a[y][x + 1]);
			++x;
		} else if (y > 0 && a[y - 1][x] == g[y][x]) {
			swap(a[y][x], a[y - 1][x]);
			--y;
		} else if (y < 3 && a[y + 1][x] == g[y][x]) {
			swap(a[y][x], a[y + 1][x]);
			++y;
		} else {
			break;
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
