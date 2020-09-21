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

using namespace std;

void solve(long long D, long long  T, long long  S) {
	bool ans = D <= T * S;
	cout << (ans ? "Yes" : "No") << endl;
}

int main() {
	long long D, T, S;
	cin >> D >> T >> S;
	solve(D, T, S);
	return 0;
}
