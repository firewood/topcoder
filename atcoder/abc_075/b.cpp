// B.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int h, w;
	cin >> h >> w;
	string b[52];
	b[0] = b[h + 1] = string(w + 2, '.');
	for (int i = 1; i <= h; ++i) {
		string s;
		cin >> s;
		b[i] = "." + s + ".";
	}
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			if (b[i][j] == '.') {
				int d = 0;
				for (int k = -1; k <= 1; ++k) {
					for (int l = -1; l <= 1; ++l) {
						d += b[i + k][j + l] == '#';
					}
				}
				b[i][j] = '0' + d;
			}
		}
		cout << b[i].substr(1, w) << endl;
	}
	return 0;
}
