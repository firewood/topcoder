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

bool solve(int N, int M, std::vector<int> A, std::vector<int> B, std::vector<int> C, std::vector<int> D) {
	vector<II> a, b;
	for (int i = 0; i < N; ++i) {
		a.emplace_back(II(A[i], B[i]));
	}
	for (int i = 0; i < M; ++i) {
		b.emplace_back(II(C[i], D[i]));
	}
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	int h, ai = 0, bi = 0;
	map<int, int> m;
	for (int ai = 0; ai < N; ++ai) {
		while (bi < M && b[bi].first >= a[ai].first) {
			m[b[bi++].second] += 1;
		}
		auto kv = m.lower_bound(a[ai].second);
		if (kv == m.end()) {
			return false;
		}
		kv->second -= 1;
		if (kv->second == 0) {
			m.erase(kv);
		}
	}
	return true;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int> B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}
	std::vector<int> C(M);
	for (int i = 0; i < M; i++) {
		std::cin >> C[i];
	}
	std::vector<int> D(M);
	for (int i = 0; i < M; i++) {
		std::cin >> D[i];
	}
	cout << (solve(N, M, A, B, C, D) ? "Yes" : "No") << endl;
	return 0;
}
