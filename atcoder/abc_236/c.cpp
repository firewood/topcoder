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

void solve(int64_t N, int64_t M, std::vector<std::string> S, std::vector<std::string> T) {
	set<string> s;
	for (int i = 0; i < M; ++i) {
		s.insert(T[i]);
	}
	for (int i = 0; i < N; ++i) {
		cout << (s.find(S[i]) != s.end() ? "Yes" : "No") << endl;
	}
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	std::vector<std::string> T(M);
	for (int i = 0; i < M; i++) {
		std::cin >> T[i];
	}
	solve(N, M, S, T);
	return 0;
}
