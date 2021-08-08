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

void solve(int64_t H, int64_t W, int64_t N, std::vector<int64_t> A, std::vector<int64_t> B) {
	set<int64_t> h, v;
	map<int64_t, int64_t> mh, mv;
	for (int i = 0; i < N; ++i) {
		v.insert(A[i]);
		h.insert(B[i]);
	}
	int pos = 0;
	for (auto y : v) {
		mv[y] = ++pos;
	}
	pos = 0;
	for (auto x : h) {
		mh[x] = ++pos;
	}
	for (int i = 0; i < N; ++i) {
		cout << mv[A[i]] << " " << mh[B[i]] << endl;
	}
}

int main() {
	int64_t H, W, N;
	std::cin >> H >> W >> N;
	std::vector<int64_t> A(N), B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i] >> B[i];
		--A[i]; --B[i];
	}
	solve(H, W, N, A, B);
	return 0;
}
