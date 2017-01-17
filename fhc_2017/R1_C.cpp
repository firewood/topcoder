//
// Facebook Hacker Cup 2017 Round 1
// C. Manic Moving
//

/*
Constraints

1 <= T <= 100
1 <= N <= 100
1 <= M <= 5,000
1 <= K <= 5,000
1 <= Ai, Bi <= N, Ai != Bi
1 <= Si, Di <= N, Si != Di
1 <= Gi <= 1,000

*/

#include <cstdint>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<LL, int> LI;

struct Edge {
	int to;
	int cost;
};
typedef vector<Edge> Edges;

struct Query {
	int from;
	int to;
};
typedef vector<Query> Queries;

const LL INF = 1LL << 60;
LL dist[5000][5000];

void dijkstra(vector<Edges> &edges, int s) {
	fill(dist[s], dist[s] + 5000, INF);
	dist[s][s] = 0;
	priority_queue<LI, vector<LI>, greater<LI> > queue;
	queue.push(LI(0, s));
	while (!queue.empty()) {
		LI top = queue.top();
		queue.pop();
		int v = top.second;
		if (top.first <= dist[s][v]) {
			for (const Edge &e : edges[v]) {
				LL cost = dist[s][v] + e.cost;
				if (cost < dist[s][e.to]) {
					dist[s][e.to] = cost;
					queue.push(LI(cost, e.to));
				}
			}
		}
	}
}

LL solve(int N, int M, int K, vector<Edges> &edges, Queries &queries) {
	for (int i = 0; i < N; ++i) {
		dijkstra(edges, i);
	}
	LI state[5001][4];
	for (int i = 0; i <= K; ++i) {
		for (int j = 0; j < 4; ++j) {
			state[i][j].first = INF;
		}
	}
	state[0][0].first = 0;
	state[0][0].second = 0;
	for (int i = 0; i < K; ++i) {
		if (i >= 1) {
			for (int j = 1; j <= 2; ++j) {
				if (state[i - 1][j].first != INF) {
					LL d = dist[state[i - 1][j].second][queries[i].from] + dist[queries[i].from][queries[i - 1].to];
					if (d >= INF) {
						return -1;
					}
					LL cost = state[i - 1][j].first + d;
					if (cost < state[i][2].first) {
						state[i][2].first = cost;
						state[i][2].second = queries[i - 1].to;
					}
				}
			}
		}
		if (state[i][0].first != INF) {
			LL d = dist[state[i][0].second][queries[i].from];
			if (d >= INF) {
				return -1;
			}
			LL cost = state[i][0].first + d;
			if (cost < state[i][1].first) {
				state[i][1].first = cost;
				state[i][1].second = queries[i].from;
			}
		}
		for (int j = 1; j <= 2; ++j) {
			if (state[i][j].first != INF) {
				LL d = dist[state[i][j].second][queries[i].to];
				if (d >= INF) {
					return -1;
				}
				LL cost = state[i][j].first + d;
				if (cost < state[i + 1][0].first) {
					state[i + 1][0].first = cost;
					state[i + 1][0].second = queries[i].to;
				}
			}
		}
	}
	return state[K][0].first;
}

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N, M, K;
		cin >> N >> M >> K;
		vector<Edges> edges(N);
		for (int i = 0; i < M; ++i) {
			int a, b, g;
			cin >> a >> b >> g;
			edges[a - 1].push_back(Edge{ b - 1, g });
			edges[b - 1].push_back(Edge{ a - 1, g });
		}
		Queries queries;
		for (int i = 0; i < K; ++i) {
			int s, d;
			cin >> s >> d;
			queries.push_back(Query{ s - 1, d - 1 });
		}
		printf("Case #%d: %lld\n", t, solve(N, M, K, edges, queries));
	}
	return 0;
}
