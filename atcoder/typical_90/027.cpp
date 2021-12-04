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

void solve(int N, vector<string> S) {
	set<string> s;
	for (int i = 0; i < N; ++i) {
		if (s.find(S[i]) == s.end()) {
			cout << i + 1 << endl;
			s.insert(S[i]);
		}
	}
}

int main() {
	int N;
	std::cin >> N;
	std::vector<string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	solve(N, S);
	return 0;
}
