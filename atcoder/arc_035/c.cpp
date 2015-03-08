// C.

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	stringstream ss(s);
	LL N, M;
	ss >> N >> M;
	LL dist[400][400];
	memset(dist, 0x3f, sizeof(dist));
	for (LL i = 0; i < N; ++i) {
		dist[i][i] = 0;
	}
	for (LL i = 0; i < M; ++i) {
		getline(cin, s);
		stringstream ss(s);
		LL a, b, c;
		ss >> a >> b >> c;
		--a, --b;
		dist[a][b] = c;
		dist[b][a] = c;
	}
	for (LL k = 0; k < N; ++k) {
		for (LL i = 0; i < N; ++i) {
			for (LL j = 0; j < N; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	getline(cin, s);
	LL K = atoi(s.c_str());
	for (LL i = 0; i < K; ++i) {
		getline(cin, s);
		stringstream ss(s);
		LL x, y, z;
		ss >> x >> y >> z;
		--x, --y;
		if (dist[x][y] > z) {
			dist[x][y] = z;
			dist[y][x] = z;
			for (LL i = 0; i < N; ++i) {
				for (LL j = 0; j < N; ++j) {
					dist[i][j] = min(dist[i][j], dist[i][x] + dist[x][y] + dist[y][j]);
					dist[i][j] = min(dist[i][j], dist[i][y] + dist[y][x] + dist[x][j]);
				}
			}
		}
		LL sum = 0;
		for (LL i = 0; i < N; ++i) {
			for (LL j = i + 1; j < N; ++j) {
				sum += dist[i][j];
			}
		}
		cout << sum << endl;
	}
	return 0;
}
