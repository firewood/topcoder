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

static const int64_t INF = 1LL << 60;

int main() {
	int N, M;
	cin >> N >> M;
	std::vector<int64_t> A(N + 1, INF), B(M + 1,INF), aord(N), bord(M);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	int ai = 0, bi = 0, c = 0;
	while (c < N + M) {
		if (A[ai] < B[bi]) {
			aord[ai++] = ++c;
		} else {
			bord[bi++] = ++c;
		}
	}
	for (int i = 0; i < N; ++i) {
		if (i) cout << " ";
		cout << aord[i];
	}
	cout << endl;
	for (int i = 0; i < M; ++i) {
		if (i) cout << " ";
		cout << bord[i];
	}
	cout << endl;
	return 0;
}
