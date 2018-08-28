// B.

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int h, w;
	cin >> h >> w;
	vector<string> b(h);
	for (int i = 0; i < h; ++i) {
		cin >> b[i];
	}
	vector<int> cnt(w);
	for (int j = 0; j < w; ++j) {
		for (int i = 0; i < h; ++i) {
			cnt[j] += b[i][j] == '.';
		}
	}
	string e(w, '.');
	for (int i = 0; i < h; ++i) {
		if (b[i] != e) {
			for (int j = 0; j < w; ++j) {
				if (cnt[j] < h) {
					cout << b[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}
