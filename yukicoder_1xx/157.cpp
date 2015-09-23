#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

int W, H;
string b[32];

void fill(int x, int y) {
	b[y][x] = '-';
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };
	for (int d = 0; d < 4; ++d) {
		int nx = x + dx[d], ny = y + dy[d];
		if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
			if (b[ny][nx] == '.') {
				fill(nx, ny);
			}
		}
	}
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	stringstream ss(s);
	ss >> W >> H;
	for (int i = 0; i < H; ++i) {
		getline(cin, b[i]);
	}
	for (int i = 0; i < H; ++i) {
		int pos = b[i].find('.');
		if (pos >= 0) {
			fill(pos, i);
			break;
		}
	}
	int ans = 1 << 30;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (b[i][j] == '-') {
				for (int y = 0; y < H; ++y) {
					for (int x = 0; x < W; ++x) {
						if (b[y][x] == '.') {
							ans = min(ans, abs(x - j) + abs(y - i) - 1);
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
