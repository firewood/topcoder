#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int cnt[2] = {};
	for (int i = 0; i < 2; ++i) {
		int br[4] = {};
		for (char c : s) {
			switch (c) {
			case '(':
				if (i) {
					cnt[i] += br[3];
				} else {
					++br[0];
				}
				break;
			case '^':
				br[2] += br[1];
				br[1] = br[0];
				br[0] = 0;
				break;
			case '*':
				br[3] += br[2];
				br[2] = 0;
				break;
			case ')':
				if (i) {
					++br[0];
				} else {
					cnt[i] += br[3];
				}
				break;
			}
		}
		reverse(s.begin(), s.end());
	}
	cout << cnt[0] << " " << cnt[1] << endl;
	return 0;
}
