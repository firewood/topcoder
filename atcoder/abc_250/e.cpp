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

static const int INF = 1 << 29;

void solve(int N, std::vector<int> A, std::vector<int> B, int Q, std::vector<int> X, std::vector<int> Y) {
	map<int, int> ma, mb;
	for (int i = N - 1; i >= 0; --i) {
		ma[A[i]] = i;
		mb[B[i]] = i;
	}
	vector<int> pa(N, INF), pb(N, INF);
	auto gen = [&](const vector<int> &A, vector<int>& pos, const map<int, int>& m) {
		int max_pos = -1;
		for (int i = 0; i < N; ++i) {
			auto it = m.find(A[i]);
			if (it == m.end()) {
				break;
			}
			max_pos = max(max_pos, it->second);
			pos[i] = max_pos;
		}
	};
	gen(A, pa, mb);
	gen(B, pb, ma);
	for (int i = 0; i < Q; ++i) {
		int x = X[i], y = Y[i];
		bool ans = pa[x] <= y && pb[y] <= x;
		cout << (ans ? "Yes" : "No") << endl;
	}
}

int main() {
	int N, Q;
	std::cin >> N;
	std::vector<int> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	std::vector<int> b(N);
	for (int i = 0; i < N; i++) {
		std::cin >> b[i];
	}
	std::cin >> Q;
	std::vector<int> x(Q), y(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> x[i] >> y[i];
		--x[i];
		--y[i];
	}
	solve(N, a, b, Q, x, y);
	return 0;
}
