#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> II;
typedef pair<int, II> III;
typedef pair<int, III> IIII;
typedef priority_queue<IIII> Queue;

int N, V, Sx, Sy, Gx, Gy;
int L[256][256];
int R[256][256];

int solve() {
	Queue q;
	q.push(IIII(0, III(V, II(Sx, Sy))));
	while (q.size() > 0) {
		IIII top = q.top();
		q.pop();
		int x = top.second.second.first, y = top.second.second.second;
		int r = top.second.first;
		int t = -top.first;
		int dx[] = { -1, 1, 0, 0 };
		int dy[] = { 0, 0, -1, 1 };
		for (int d = 0; d < 4; ++d) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N && r > L[ny][nx] && r > R[ny][nx]) {
				R[ny][nx] = r;
				if (nx == Gx && ny == Gy) {
					return t + 1;
				}
				q.push(IIII(-t - 1, III(r - L[ny][nx], II(nx, ny))));
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	stringstream ss(s);
	ss >> N >> V >> Sx >> Sy >> Gx >> Gy;
	--Sx, --Sy, --Gx, --Gy;
	for (int i = 0; i < N; ++i) {
		getline(cin, s);
		stringstream ss(s);
		for (int j = 0; j < N; ++j) {
			ss >> L[i][j];
		}
	}
	int ans = solve();
	cout << ans << endl;
	return 0;
}
