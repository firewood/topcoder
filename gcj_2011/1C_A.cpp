/*

Google Code Jam 2011 Round 1C

Problem A. Square Tiles


問題
グリッドに1x1の正方形のタイルが敷いてある。
全てのタイルが敷いてある場所を2x2のタイルで置き換えたい。
可能かどうか、可能な場合は敷き方を求める。

*/

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef vector<string> StrVec;

bool solve(int R, int C, StrVec &v) {
	int x, y;
	for (y = 0; y < R; ++y) {
		for (x = 0; x < C; ++x) {
			if (v[y][x] == '#') {
				if (x >= C-1 || y >= R-1) {
					return false;
				}
				if (v[y][x+1] != '#' || v[y+1][x] != '#' || v[y+1][x+1] != '#') {
					return false;
				}
				v[y][x] = '/', v[y][x+1] = '\\';
				v[y+1][x] = '\\', v[y+1][x+1] = '/';
			}
		}
	}
	return true;
}

int main()
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	int t, R, C, i;
	for (t = 0; t < T; ++t) {
		StrVec v;
		getline(cin, s);
		stringstream ss(s);
		ss >> R >> C;
		for (i = 0; i < R; ++i) {
			getline(cin, s);
			v.push_back(s);
		}
		cout << "Case #" << (t+1) << ":" << endl;
		if (!solve(R, C, v)) {
			cout << "Impossible" << endl;
		} else {
			for (i = 0; i < R; ++i) {
				cout << v[i] << endl;
			}
		}
	}
	return 0;
}

