#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

void solve(long long A, long long B, long long C, long long D) {
	bool ans = false;
	vector<LL> x = { A, B, C, D };
	int seq[4] = { 0,1,2,3 };
	do {
		if (x[seq[0]] == x[seq[1]] + x[seq[2]] + x[seq[3]]) {
			ans = true;
		}
		if (x[seq[0]] + x[seq[1]] == x[seq[2]] + x[seq[3]]) {
			ans = true;
		}
	} while (next_permutation(seq, seq + 4));
	cout << (ans ? "Yes" : "No") << endl;
}

int main() {
    long long A;
	std::cin >> A;
	long long B;
	std::cin >> B;
	long long C;
	std::cin >> C;
	long long D;
	std::cin >> D;
	solve(A, B, C, D);
	return 0;
}
