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

typedef long double LD;

LD solve(long long N, long long K, std::vector<long long> &R) {
    sort(R.begin(), R.end());
    LD ans = 0;
    for (int i = N - K; i < N; i++) {
        ans = (ans + R[i]) / 2;
    }
	return ans;
}

int main() {
#if DEBUG
	freopen("in_1.txt", "r", stdin);
#endif
    cout.precision(20);
    long long N, K;
	std::cin >> N >> K;
	std::vector<long long> R(N);
	for (int i = 0; i < N; i++) {
		std::cin >> R[i];
	}
	cout << solve(N, K, R) << endl;
	return 0;
}
