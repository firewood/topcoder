
// Google Code Jam 2014 Qualification Round
// Problem C. Minesweeper Master

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

static inline int popcount(unsigned int b) {
#ifdef __GNUC__
	return __builtin_popcount(b);
#elif _MSC_VER >= 1400
	return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	return (b + (b >> 16)) & 0x3F;
#endif
}

int r, c;
int bd[8][8] = {};

void make_bd(int b)
{
	memset(bd, 0, sizeof(bd));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			bd[i + 1][j + 1] = (b & (1 << (i * c + j))) != 0;
		}
	}
}

void print_bd(int r, int c, int b, int cx, int cy)
{
	make_bd(b);
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			printf("%c", (i==cy && j==cx) ? 'c' : (bd[i][j] > 0 ? '*' : '.'));
		}
		printf("\n");
	}
}

void fill(int x, int y)
{
	if (x < 1 || x > c || y < 1 || y > r || bd[y][x] != 0){
		return;
	}
	bd[y][x] = -1;

	bool z = true;
	for (int dy = -1; dy <= 1; ++dy) {
		for (int dx = -1; dx <= 1; ++dx) {
			if (bd[y + dy][x + dx] > 0) {
				z = false;
			}
		}
	}

	if (z) {
		for (int dy = -1; dy <= 1; ++dy) {
			for (int dx = -1; dx <= 1; ++dx) {
				fill(x + dx, y + dy);
			}
		}
	}
}

bool check(int b, int &cx, int &cy)
{
	make_bd(b);
	for (int y = r; y >= 1; --y) {
		for (int x = c; x >= 1; --x) {
			if (!bd[y][x]) {
				fill(x, y);
				bool valid = true;
				for (int p = 1; p <= r; ++p) {
					for (int q = 1; q <= c; ++q) {
						if (!bd[p][q]) {
							valid = false;
						}
					}
				}
				if (valid) {
					cx = x;
					cy = y;
					return true;
				}
				make_bd(b);
			}
		}
	}

	return false;
}


int main(int argc, char *argv[])
{
	int f[6][6][32] = {};
	int cx[6][6][32] = {};
	int cy[6][6][32] = {};
	memset(f, -1, sizeof(f));

	for (r = 1; r <= 5; ++r) {
		for (c = 1; c <= 5; ++c) {
			int m = 1 << (r*c);
			for (int b = 0; b < m; ++b) {
				int bits = popcount(b);
				if (f[r][c][bits] >= 0) {
					continue;
				}

				int x, y;
				if (check(b, x, y)) {
					f[r][c][bits] = b;
					cx[r][c][bits] = x;
					cy[r][c][bits] = y;
				}
			}

#if 0
			printf("\n\n(%d,%d)\n", r, c);
			for (int bits = 0; bits < 32; ++bits) {
				if (f[r][c][bits] >= 0) {
					printf("\nbits=%d\n", bits);
					print_bd(r, c, f[r][c][bits], cx[r][c][bits], cy[r][c][bits]);
				}
			}
#endif
		}
	}

	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	if (T <= 0) return 0;

	for (int t = 1; t <= T; ++t) {
		getline(cin, s);
		stringstream ss(s);
		int m = 0;
		ss >> r >> c >> m;
		printf("Case #%d:\n", t);
		if (r>=6 || c>=6 || f[r][c][m] < 0) {
			printf("Impossible\n");
		} else {
			print_bd(r, c, f[r][c][m], cx[r][c][m], cy[r][c][m]);
		}
	}

	return 0;
}

