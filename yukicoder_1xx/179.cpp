#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	stringstream ss(s);
	int H, W;
	ss >> H >> W;
	int M[64][64] = {};
	int sum = 0;
	for (int i = 0; i < H; ++i) {
		getline(cin, s);
		for (int j = 0; j < (int)s.length(); ++j) {
			M[i][j] = s[j] != '.';
			sum += s[j] != '.';
		}
	}
	if (sum == 0) {
		sum = -1;
	}
	bool ans = false;
	int c = 1;
	for (int a = 0; !ans && (a < H); ++a) {
		for (int b = -W + 1; b < W; ++b) {
			++c;
			if (!(a == 0 && b == 0)) {
				int cnt = 0;
				bool f = true;
				for (int i = 0; f && (i + a < H); ++i) {
					for (int j = 0; j + b < W; ++j) {
						if (j + b < 0) {
							continue;
						}
						int x = M[i][j], y = M[i + a][j + b];
						if (x > 0 && x < c) {
							cnt += 2;
							if (y <= 0) {
								f = false;
							} else {
								M[i + a][j + b] = c;
							}
						}
					}
				}
				if (f && cnt == sum) {
					ans = true;
				}
			}
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
