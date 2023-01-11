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

bool solve(int T, int N, std::vector<int> A, int M, std::vector<int> B) {
	deque<int> q;
	int ai = 0, bi = 0;
	for (int t = 0; ai < N || bi < M ; ++t) {
		while (!q.empty() && q.front() + T < t) {
			q.pop_front();
		}
		while (ai < N && t == A[ai]) {
			q.push_back(A[ai++]);
		}
		while (bi < M && t == B[bi]) {
			if (q.empty()) {
				return false;
			}
			q.pop_front();
			++bi;
		}
	}
	return true;
}

int main() {
	int T, N, M;
	std::cin >> T >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::cin >> M;
	std::vector<int> B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> B[i];
	}
	cout << (solve(T, N, A, M, B) ? "yes" : "no") << endl;
	return 0;
}
