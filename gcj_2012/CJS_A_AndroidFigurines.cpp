/*

Code Jam Sprint
Problem A. Android Figurines


Problem

A new series of Android mini figurines is on sale at the Google Store.
The impulse to collect them and gift them to your friends is too strong to
resist. You want to buy at least K1, K2, ... KM of each of the M new designs.
The friendly store staff reveal that each design has exactly L packages
in stock, with one figurine per package, but all the packages look the same
with no identifiable labels on the outside, and you can't open them before
the purchase. What is the minimum number of packages you need to buy to
achieve your shopping goal in the worst case scenario?


Input

The first line of the input gives the number of test cases, N. N test cases
follow. Each case is a line formatted as

L M K1 K2 ... KM


Output

For each test case, output one line containing "Case #x: y", where x is the
case number (starting from 1) and y is the minimum number of packages you
need to buy in the worst case scenario (or -1 if the goal cannot be achieved).


Limits

1 <= N <= 100.


Small dataset

0 <= L <= 3.
1 <= M <= 3.
0 <= Kj <= 10, for 1 <= j <= M.


Large dataset

0 <= L <= 100.
1 <= M <= 100.
0 <= Kj <= 100, for 1 <= j <= M.


Sample


Input

2
2 3 1 1 1
3 3 2 3 4


Output

Case #1: 5
Case #2: -1

*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;

static int solve(int L, int M, IntVec &v) {
	// descending sort
	sort(v.rbegin(), v.rend());
	if (v[0] > L) {
		// impossible; insufficient stock
		return -1;
	}
	if (v[0] <= 0) {
		// needless to buy any figurines
		return 0;
	}
	// in worst case we have to purchase
	// all of (M-1) types of figurines in stock
	return v[0] + (M - 1) * L;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	int t, L, M, i, x;
	for (t = 0; t < T; ++t) {
		getline(cin, s);
		stringstream ss(s);
		ss >> L >> M;
		IntVec v;
		for (i = 0; i < M; ++i) {
			ss >> x;
			v.push_back(x);
		}
		int res = solve(L, M, v);
		cout << "Case #" << (t+1) << ": " << res << endl;
	}

	return 0;
}

