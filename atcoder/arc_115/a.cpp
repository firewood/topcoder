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

LL solve(long long N, long long M, std::vector<std::string> &S) {
	LL cnt[2] = {};
	for (string s : S) {
		int sum = 0;
		for (char c : s) {
			sum += c != '0';
		}
		cnt[sum % 2] += 1;
	}
	return cnt[0] * cnt[1];
}

int main() {
    long long N, M;
	std::cin >> N >> M;
	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	cout << solve(N, M, S) << endl;
	return 0;
}
