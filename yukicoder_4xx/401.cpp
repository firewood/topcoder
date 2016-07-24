#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	int n[32][32] = {};
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int d = 0, x = -1, y = 0;
	cin >> N;
	for (int i = 1; i <= N * N; ++i) {
		int nx = x + dx[d], ny = y + dy[d];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N || n[ny][nx]) {
			d = (d + 1) % 4;
			nx = x + dx[d], ny = y + dy[d];
		}
		x = nx, y = ny;
		n[y][x] = i;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%s%03d", j ? " " : "", n[i][j]);
		}
		printf("\n");
	}
	return 0;
}
