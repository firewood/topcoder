#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

void solve(long long N, std::vector<int> &p) {
	vector<int> seq(200002);
	iota(seq.begin(), seq.end(), 0);
	set<int> s(seq.begin(), seq.end());
	for (int i = 0; i < N; i++) {
		s.erase(p[i]);
		cout << *(s.begin()) << endl;
	}
}

int main() {
	long long N;
	std::cin >> N;
	std::vector<int> p(N);
	for (int i = 0; i < N; i++) {
		std::cin >> p[i]; // p[i]--;
	}
	solve(N, p);
	return 0;
}
