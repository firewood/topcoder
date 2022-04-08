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

bool solve(int N, int M, std::vector<int> A, std::vector<int> B, std::vector<int> C, std::vector<int> D) {
	int con[8][8] = {};
	for (int i = 0; i < M; ++i) {
		con[A[i]][B[i]] = 1;
	}
	vector<int> seq(N);
	iota(seq.begin(), seq.end(), 0);
	do {
		int cnt = 0;
		for (int i = 0; i < M; ++i) {
			int a = seq[C[i]], b = seq[D[i]];
			cnt += con[min(a, b)][max(a, b)];
		}
		if (cnt >= M) {
			return true;
		}
	} while (next_permutation(seq.begin(), seq.end()));
	return false;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> A(M), B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i];
		--A[i];
		--B[i];
	}
	std::vector<int> C(M), D(M);
	for (int i = 0; i < M; i++) {
		std::cin >> C[i] >> D[i];
		--C[i];
		--D[i];
	}
	cout << (solve(N, M, A, B, C, D) ? "Yes" : "No") << endl;
	return 0;
}
