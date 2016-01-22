//
// Facebook Hacker Cup 2016 Round 1
// C. Yachtzee
//

/*
Constraints

1 <= T <= 50
0 <= A < B <= 1,000,000,000
1 <= N <= 100,000
1 <= Ci <= 1,000,000,000

*/

#include <cstdint>
#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef long double LD;
typedef vector<int64_t> LLVec;

long double solve(int64_t N, int64_t X, LLVec &C) {
	int64_t one = accumulate(C.begin(), C.end(), 0LL);
	int64_t loops = X / one, remain = X % one;
	LD total = 0;
	for (int64_t c : C) {
		LD cost = (LD)c;
		total += cost * cost * 0.5 * loops;
		int64_t r = min(remain, c);
		cost = (LD)r;
		total += cost * cost * 0.5;
		remain -= r;
	}
	return total;
}

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int64_t N, A, B;
		cin >> N >> A >> B;
		LLVec C(N);
		for (int i = 0; i < N; ++i) {
			cin >> C[i];
		}
		LD total = solve(N, B, C) - solve(N, A, C);
		LD ans = total / (LD)(B - A);
		printf("Case #%d: %.7Lf\n", t, ans);
	}
	return 0;
}
