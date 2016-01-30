#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair <int, int> II;
typedef priority_queue<II> Queue;

int main(int argc, char *argv[])
{
	int W, H, N;
	static int road[1000000][4];
	static int dist[1000000];
	memset(road, -1, sizeof(road));
	memset(dist, 0x80, sizeof(dist));
	int def = dist[0];
	cin >> W >> H >> N;
	for (int i = 0; i < N; ++i) {
		int M;
		cin >> M;
		int prev, pos;
		cin >> prev;
		for (int j = 0; j < M; ++j) {
			cin >> pos;
			int left = prev - (prev % W);
			int right = left + W - 1;
			if (pos < left) {
				while (prev > pos) {
					road[prev][0] = prev - W, road[prev - W][1] = prev;
					prev -= W;
				}
			} else if (pos > right) {
				while (prev < pos) {
					road[prev][1] = prev + W, road[prev + W][0] = prev;
					prev += W;
				}
			} else if (pos < prev) {
				while (prev > pos) {
					road[prev][2] = prev - 1, road[prev - 1][3] = prev;
					prev--;
				}
			} else {
				while (prev < pos) {
					road[prev][3] = prev + 1, road[prev + 1][2] = prev;
					prev++;
				}
			}
		}
	}
	Queue q;
	for (int d = 0; d < 4; ++d) {
		int next = road[W * H - 1][d];
		if (next >= 0) {
			q.push(II(-1, next));
		}
	}
	while (q.size() > 0) {
		II top = q.top();
		q.pop();
		int current = top.second;
		int cost = top.first;
		if (cost > dist[current]) {
			dist[current] = cost--;
			for (int d = 0; d < 4; ++d) {
				int next = road[current][d];
				if (next >= 0 && cost > dist[next]) {
					q.push(II(cost, next));
				}
			}
		}
	}
	if (dist[0] != def) {
		cout << -dist[0] << endl;
	} else {
		cout << "Odekakedekinai.." << endl;
	}
	return 0;
}
