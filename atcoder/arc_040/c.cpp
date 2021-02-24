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
typedef long double LD;
typedef pair<LL, LL> II;
typedef pair<LL, II> III;

static const LL INF = 1LL << 60;

int solve(long long N, std::vector<std::string> &S) {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int f = S[i].find('.'), r = S[i].rfind('.');
		if (f >= 0) {
			++ans;
			for (int j = f; j <= r; ++j) {
				S[i][j] = 'o';
			}
			if (i < N - 1) {
				for (int j = r; j < (int)S[i].length(); ++j) {
					S[i + 1][j] = 'o';
				}
			}
		}
	}
	return ans;
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	cout << solve(N, S) << endl;
	return 0;
}
