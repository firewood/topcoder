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

typedef long long LL;

LL solve(long long N, long long X, std::vector<long long> &V, std::vector<long long> &P) {
	LL sum = 0;
	for (int i = 0; i < N; i++) {
		sum += V[i] * P[i];
		if (sum > X * 100) {
			return i + 1;
		}
	}
	return -1;
}

int main() {
	long long N, X;
	std::cin >> N >> X;
	std::vector<long long> V(N), P(N);
	for (int i = 0; i < N; i++) {
		std::cin >> V[i] >> P[i];
	}
	cout << solve(N, X, V, P) << endl;
	return 0;
}
