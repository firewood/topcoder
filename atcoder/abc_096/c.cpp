// C.

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	for (int i = 0; i < h; ++i) {
		cin >> s[i];
	}
	bool ans = true;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (s[i][j] == '#') {
				bool ok = false;
				for (int d = 0; d < 4; ++d) {
					const int dx[4] = { -1,1,0,0 };
					const int dy[4] = { 0,0,-1,1 };
					int p = i + dy[d], q = j + dx[d];
					if (p >= 0 && p < h && q >= 0 && q < w && s[p][q] == '#') {
						ok = true;
						break;
					}
				}
				if (!ok) {
					ans = false;
				}
			}
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
