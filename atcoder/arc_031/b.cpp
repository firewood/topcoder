// B.

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

static const int N = 10;
static const int dx[4] = {-1,1,0,0};
static const int dy[4] = {0,0,-1,1};

void dfs(vector<string> &b, int x, int y) {
	b[y][x] = 'x';
	for (int d = 0; d < 4; ++d) {
		int nx = x + dx[d], ny = y + dy[d];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && b[ny][nx] == 'o') {
			dfs(b, nx, ny);
		}
	}
}

int main(int argc, char *argv[]) {
	vector<string> b(N);
	for (int i = 0; i < N; ++i) {
		cin >> b[i];
	}
	bool ans = false;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (b[i][j] != 'o') {
				vector<string> temp = b;
				dfs(temp, j, i);
				bool ok = true;
				for (int i = 0; i < N; ++i) {
					for (int j = 0; j < N; ++j) {
						if (temp[i][j] == 'o') {
							ok = false;
						}
					}
				}
				if (ok) {
					ans = true;
				}
			}
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
