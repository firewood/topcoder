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

bool solve(int64_t N, int64_t P, int64_t Q, int64_t R, std::vector<int64_t> A) {
	int64_t sum = 0;
	set<int64_t> s;
	for (auto a : A) {
		sum += a;
		s.insert(sum);
	}
	sum = 0;
	for (auto a : A) {
		if (s.find(sum + P) != s.end() && s.find(sum + P + Q) != s.end() && s.find(sum + P + Q + R) != s.end()) {
			return true;
		}
		sum += a;
	}
	return false;
}

int main() {
	int64_t N, P, Q, R;
	std::cin >> N >> P >> Q >> R;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << (solve(N, P, Q, R, A) ? "Yes" : "No") << endl;
	return 0;
}
