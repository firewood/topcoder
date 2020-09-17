#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef long long LL;

void solve(long long N, long long C, std::vector<long long> &a) {
	vector<LL> count(C + 1), last(C + 1, -1);
	for (LL i = 0; i < N; ++i) {
		count[a[i]] += (i - last[a[i]]) * (N - i);
		last[a[i]] = i;
	}
	for (LL i = 1; i <= C; ++i) {
		cout << count[i] << endl;
	}
}

int main() {
    long long N;
	std::cin >> N;
	long long C;
	std::cin >> C;
	std::vector<long long> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i]; // a[i]--;
	}
	solve(N, C, a);
	return 0;
}
