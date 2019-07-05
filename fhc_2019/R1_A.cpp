//
// Facebook Hacker Cup 2019 Round 1
// A. Graphs as a Service
//

/*
Constraints

1 <= T <= 350
1 <= N <= 50
1 <= M <= 1000

*/

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
#include <cstring>

using namespace std;

typedef pair<int, int> II;
typedef pair<II, int> III;

bool solve(int n, vector<III> &e) {
	int dist[64][64];
	memset(dist, 0x3f, sizeof(dist));
	for (int i = 0; i < n; ++i) {
		dist[i][i] = 0;
	}
	for (int i = 0; i < (int)e.size(); ++i) {
		dist[e[i].first.first - 1][e[i].first.second - 1] = e[i].second;
		dist[e[i].first.second - 1][e[i].first.first - 1] = e[i].second;
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 0; i < (int)e.size(); ++i) {
		if (dist[e[i].first.first - 1][e[i].first.second - 1] != e[i].second) {
			return false;
		}
	}
	return true;
}

int main(int argc, char* argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n, m;
		cin >> n >> m;
		vector<III> e(m);
		for (int i = 0; i < m; ++i) {
			cin >> e[i].first.first >> e[i].first.second >> e[i].second;
		}
		bool ans = solve(n, e);
		cout << "Case #" << t << ": ";
		if (ans) {
			cout << m << endl;
			for (int i = 0; i < m; ++i) {
				cout << e[i].first.first << " " << e[i].first.second << " " << e[i].second << endl;
			}
		} else {
			cout << "Impossible" << endl;
		}
	}
	return 0;
}
