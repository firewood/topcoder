#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef vector<string> StrVec;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool check(int N, int M, StrVec v, int total, int sx, int sy, int dir)
{
	int x = sx, y = sy;
	while (true) {
		int i;
		for (i = 0; i < 2; ++i) {
			int nd = (dir + i) % 4;
			int nx = x + dx[nd], ny = y + dy[nd];
			if (v[ny][nx] == '.') {
				dir = nd, --total;
				x = nx, y = ny;
				v[y][x] = '#';
				break;
			}
		}
		if (i >= 2) {
			break;
		}
	}
	return x == sx && y == sy && total == 0;
}

bool solve(int N, int M, const StrVec &v)
{
	int total = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (v[i][j] == '.') {
				++total;
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (v[i][j] == '.') {
				for (int d = 0; d < 4; ++d) {
					if (check(N, M, v, total, j, i, d)) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

int main(int argc, char *argv[])
{
	int N, M;
	string s;
	{
		getline(cin, s);
		stringstream ss(s);
		ss >> N >> M;
	}
	StrVec v(N+2);
	v[0] = string(102, '#');
	for (int i = 0; i < N; ++i) {
		getline(cin, s);
		v[i + 1] = "#" + s + "#";
	}
	v[N+1] = string(102, '#');

	cout << (solve(N, M, v) ? "YES" : "NO") << endl;
	return 0;
}
