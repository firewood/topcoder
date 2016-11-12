// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int H, W;
	string b[16];
	cin >> H >> W;
	for (int i = 0; i < H; ++i) {
		cin >> b[i];
	}
	bool ans = true;
	int r = 0, c = 0;
	while (true) {
		b[r][c] = '.';
		if (r == H - 1 && c == W - 1) {
			break;
		}
		if (c < W - 1 && b[r][c + 1] == '#') {
			++c;
		} else if (r < H - 1 && b[r + 1][c] == '#') {
			++r;
		} else {
			ans = false;
			break;
		}
	}
	for (int i = 0; i < H; ++i) {
		if ((int)b[i].find('#') >= 0) {
			ans = false;
		}
	}
	cout << (ans ? "Possible" : "Impossible") << endl;
	return 0;
}
