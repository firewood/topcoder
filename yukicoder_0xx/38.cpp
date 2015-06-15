#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	stringstream ss(s);
	int Kr, Kb;
	ss >> Kr >> Kb;
	getline(cin, s);

	int rb = 0;
	int cnt[256] = {};
	for (char c : s) {
		cnt[c] += 1;
	}
	int m = 1 << (cnt['R'] + cnt['B']);
	int ans = 0;
	for (int b = 0; b < m; ++b) {
		char w[32];
		int bpos = 0, wpos = 0;
		bool f = true;
		for (char c : s) {
			if (c == 'W') {
				w[wpos++] = c;
			} else {
				if ((1 << bpos) & b) {
					if (c == 'R') {
						if (wpos >= Kr && w[wpos - Kr] == 'R') {
							f = false;
							break;
						}
					} else {
						if (wpos >= Kb && w[wpos - Kb] == 'B') {
							f = false;
							break;
						}
					}
					w[wpos++] = c;
				}
				++bpos;
			}
		}
		if (f) {
			ans = max(ans, wpos);
		}
	}
	cout << ans << endl;
	return 0;
}
