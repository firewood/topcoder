// B. 

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char *argv[])
{
	int n, m;
	cin >> n >> m;
	int sx, sy;
	vector<string> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		int pos = b[i].find('S');
		if (pos >= 0 && pos < m) {
			sx = pos, sy = i;
		}
	}
	string cmd;
	cin >> cmd;
	int seq[4] = { 0,1,2,3 };
	int ans = 0;
	do {
		int x = sx, y = sy;
		int dx[4] = { -1,1,0,0 };
		int dy[4] = { 0,0,-1,1 };
		for (char c : cmd) {
			int dir = c - '0';
			int nx = x + dx[seq[dir]];
			int ny = y + dy[seq[dir]];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || b[ny][nx] == '#') {
				break;
			}
			if (b[ny][nx] == 'E') {
				++ans;
				break;
			}
			x = nx, y = ny;
		}
	} while (next_permutation(seq, seq + 4));
	cout << ans << endl;
	return 0;
}
