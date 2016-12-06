#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
	int H, W;
	cin >> H >> W;
	string s[100];
	for (int i = 0; i < H; ++i) {
		cin >> s[i];
	}
	bool filled = false;
	for (int c = 1; !filled && c >= 0; --c) {
		for (int i = 0; !filled && i < H; ++i) {
			if (count(s[i].begin(), s[i].end(), '*') == c) {
				s[i][s[i].find('-')] = '*';
				filled = true;
			}
		}
	}
	for (int i = 0; i < H; ++i) {
		cout << s[i] << endl;
	}
	return 0;
}
