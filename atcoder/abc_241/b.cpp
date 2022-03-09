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

bool solve(int N, int M, std::vector<int> A, std::vector<int> B) {
	map<int, int> m;
	for (int i = 0; i < N; ++i) {
		m[A[i]] += 1;
	}
	for (int i = 0; i < M; ++i) {
		m[B[i]] -= 1;
		if (m[B[i]] < 0) {
			return false;
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
	std::vector<int> B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> B[i];
	}
	cout << (solve(N, M, A, B) ? "Yes" : "No") << endl;
	return 0;
}
