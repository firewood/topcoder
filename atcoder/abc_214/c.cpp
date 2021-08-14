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

vector<int64_t> solve(int64_t N, std::vector<int64_t> S, std::vector<int64_t> T) {
	priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<>> q;
	for (int i = 0; i < N; ++i) {
		q.emplace(make_pair(T[i], i));
	}
	while (!q.empty()) {
		int64_t cost = q.top().first, node = q.top().second;
		q.pop();
		cost += S[node];
		node = (node + 1) % N;
		if (cost < T[node]) {
			T[node] = cost;
			q.emplace(make_pair(cost, node));
		}
	}
	return T;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	std::vector<int64_t> T(N);
	for (int i = 0; i < N; i++) {
		std::cin >> T[i];
	}
	for (auto t : solve(N, S, T)) {
		cout << t << endl;
	}
	return 0;
}
