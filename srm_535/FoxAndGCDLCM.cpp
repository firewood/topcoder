// BEGIN CUT HERE
/*
// SRM 535 Div2 Medium (500)

// PROBLEM STATEMENT
// Fox Jiro and Eel Saburo are good friends. One day Saburo found
two interesting positive integers: A and B.

On the next day, Saburo met Jiro and wanted to tell him the two integers.
However, he managed to forget their values. All Saburo could remember was
their greatest common divisor G and their least common multiple L.

You are given two long longs: G and L. Find the original integers A and B,
and return the value of A+B. If there are multiple pairs of A and B that
correspond to G and L, pick the one that minimizes A+B. If it is impossible
to find such A and B (i.e., Saburo made a mistake somewhere), return -1.

DEFINITION
Class:FoxAndGCDLCM
Method:get
Parameters:long long, long long
Returns:long long
Method signature:long long get(long long G, long long L)


NOTES
-The greatest common divisor of two integers a and b is the largest
 positive integer that divides both a and b without any remainder.
-The least common multiple of two integers a and b is the smallest
 positive integer that is a multiple of both a and b.


CONSTRAINTS
-G will be between 1 and 1,000,000,000,000 (10^12), inclusive.
-L will be between 1 and 1,000,000,000,000 (10^12), inclusive.


EXAMPLES

0)
2
20

Returns: 14

The possible pairs of A and B are {2, 20} and {4, 10}. We need to pick
{4, 10} since 4+10 is the smallest sum of A and B.

1)
5
8

Returns: -1

There are no pairs of A and B such that their greatest common divisor is 5
and their least common multiple is 8.

2)
1000
100

Returns: -1



3)
100
1000

Returns: 700



4)
10
950863963000

Returns: 6298430

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;
typedef set<string> StrSet;
typedef set<int, int> IntMap;
typedef set<LL, LL> LLMap;
typedef set<string, string> StrMap;

class FoxAndGCDLCM {

	static LL gcd(LL a, LL b) {
		while (true) {
			a = a % b;
			if (a == 0) return b;
			b = b % a;
			if (b == 0) return a;
		}
    }

public:
	long long get(long long G, long long L) {
		if (G < 1 || L < 1 || (L < G) || (L % G)) {
			return -1;
		}
		LL M = L / G;
		LL Max = (LL)sqrt((double)M) + 1;
		bool f = false;
		LL res = M+1;
		LL i;
		for (i = 1; i <= Max; ++i) {
			if ((M % i) == 0) {
				LL j = M / i;
				if (gcd(i, j) == 1) {
					f = true;
					res = min(res, i + j);
				}
			}
		}
		res *= G;
		return f ? res : -1;
	}

	
// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 2LL;
			long long Arg1 = 20LL;
			long long Arg2 = 14LL;

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 5LL;
			long long Arg1 = 8LL;
			long long Arg2 = -1LL;

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1000LL;
			long long Arg1 = 100LL;
			long long Arg2 = -1LL;

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 100LL;
			long long Arg1 = 1000LL;
			long long Arg2 = 700LL;

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 10LL;
			long long Arg1 = 950863963000LL;
			long long Arg2 = 6298430LL;

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndGCDLCM ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
