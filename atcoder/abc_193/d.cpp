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

LD solve(long long K, std::string S, std::string T) {
	LD ans = 0;
	vector<int> ac(10), bc(10);
	for (int i = 0; i < S.length() - 1; ++i) {
		ac[S[i] - '0'] += 1;
		bc[T[i] - '0'] += 1;
	}
	for (int i = 1; i <= 9; ++i) {
		if (ac[i] + bc[i] >= K) continue;
		LD x = 1.0 * (K - ac[i] - bc[i]) / (K * 9 - S.length() * 2 + 2);
		ac[i] += 1;
		for (int j = 1; j <= 9; ++j) {
			if (ac[j] + bc[j] >= K) continue;
			LD y = 1.0 * (K - ac[j] - bc[j]) / (K * 9 - S.length() * 2 + 1);
			bc[j] += 1;
			LL a = 0, b = 0;
			for (int i = 1; i <= 9; ++i) {
				a += i * round(pow(10, ac[i]));
				b += i * round(pow(10, bc[i]));
			}
			if (a > b) {
				ans += x * y;
			}
			bc[j] -= 1;
		}
		ac[i] -= 1;
	}
	return ans;
}

int main() {
	cout.precision(20);
    long long K;
	std::string S;
	std::string T;
	std::cin >> K >> S >> T;
	cout << solve(K, S, T) << endl;
	return 0;
}
