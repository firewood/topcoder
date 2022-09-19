#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> II;

const int dx[] = { -1,-1,0,0,1,1 };
const int dy[] = { -1,0,-1,1,0,1 };

int64_t solve(int N, std::vector<int> X, std::vector<int> Y) {
	int64_t ans = 0;
	set<II> s, vis;
	for (int i = 0; i < N; ++i) {
		s.insert(II(X[i], Y[i]));
	}
	for (auto kv : s) {
		if (vis.find(kv) != vis.end()) {
			continue;
		}
		++ans;
		deque<II> q;
		q.push_back(kv);
		vis.insert(kv);
		while (!q.empty()) {
			II top = q.front();
			q.pop_front();
			for (int dir = 0; dir < 6; ++dir) {
				II next(top.first + dx[dir], top.second + dy[dir]);
				if (s.find(next) != s.end() && vis.find(next) == vis.end()) {
					q.push_back(next);
					vis.insert(next);
				}
			}
		}
	}
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> X(N), Y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i] >> Y[i];
	}
	cout << solve(N, X, Y) << endl;
	return 0;
}
