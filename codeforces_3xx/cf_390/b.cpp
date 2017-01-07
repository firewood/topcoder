// B. 

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	char b[6][6] = {};
	for (int i = 0; i < 4; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < 4; ++j) {
			b[i + 1][j + 1] = s[j];
		}
	}

	bool ans = false;
	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= 4; ++j) {
			if (b[i][j] == '.') {
				b[i][j] = 'x';
				for (int k = 1; k <= 4; ++k) {
					for (int l = 1; l <= 4; ++l) {
						if (b[k][l] == 'x') {
							for (int dx = -1; dx <= 1; ++dx) {
								for (int dy = -1; dy <= 1; ++dy) {
									if (dx || dy) {
										if (b[k + dy][l + dx] == 'x'&&b[k - dy][l - dx] == 'x') {
											ans = true;
										}
									}
								}
							}
						}
					}
				}
				b[i][j] = '.';
			}
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
