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
#include <atcoder/maxflow>

using namespace std;
using namespace atcoder;

int solve(long long N, long long G, long long E, std::vector<long long> &p, std::vector<long long> &a, std::vector<long long> &b) {
	mf_graph<int> g(N + 1);
	for (int i = 0; i < G; i++) {
		g.add_edge(p[i], N, 1);
	}
	for (int i = 0; i < E; i++) {
		g.add_edge(a[i], b[i], 1);
		g.add_edge(b[i], a[i], 1);
	}
	return g.flow(0, N);
}

int main() {
    long long N, G, E;
	std::cin >> N >> G >> E;
	std::vector<long long> p(G);
	for (int i = 0; i < G; i++) {
		std::cin >> p[i];
	}
	std::vector<long long> a(E), b(E);
	for (int i = 0; i < E; i++) {
		std::cin >> a[i] >> b[i];
	}
	cout << solve(N, G, E, p, a, b) << endl;
	return 0;
}
