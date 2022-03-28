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

bool solve(int N, int K, std::vector<int> A, std::vector<int> B) {
	vector<int> s = { A[0], B[0] };
	for (int i = 1; i < N; ++i) {
		vector<int> ns;
		for (auto x : { A[i], B[i] }) {
			if ([&]() {
				for (auto y : s) {
					if (abs(x - y) <= K) {
						return true;
					}
				}
				return false;
			}()) {
				ns.emplace_back(x);
			}
		}
		s = ns;
	}
	return !s.empty();
}

int main() {
	int N, K;
	std::cin >> N >> K;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int> B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}
	cout << (solve(N, K, A, B) ? "Yes" : "No") << endl;
	return 0;
}
