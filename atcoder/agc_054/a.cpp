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

int64_t solve(int64_t N, std::string S) {
	if (S.front() != S.back()) {
		return 1;
	}
	for (int pos = 2; pos + 2 <= N; ++pos) {
		if (S.front() != S[pos - 1] && S[pos] != S.back()) {
			return 2;
		}
	}
	return -1;
}

int main() {
	int64_t N;
	std::string S;
	std::cin >> N >> S;
	cout << solve(N, S) << endl;
	return 0;
}
