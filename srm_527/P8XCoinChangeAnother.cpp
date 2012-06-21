// BEGIN CUT HERE
/*
// SRM 527 Div2 Hard (950)

// PROBLEM STATEMENT
// The Exponential kingdom has N types of coins. For each i from 0 to N-1,
inclusive, there is a coin type worth 2^i (two to the power of i).
For example, if N=3  then the coin values would be 2^0, 2^1, and 2^2.

You are given the int N and two long longs coins_sum and coins_count.
Your task is to find a set of coins with two properties: First, it must
contain exactly coins_count coins. Second, the sum of coins it contains
must be exactly equal to coins_sum. Your method must return the solution
as a vector<long long> containing exactly N elements. The i-th element of
the return value must be the number of coins worth 2^i in your set.
If there are multiple solutions, return the lexicographically smallest one.
If there is no set that satisfies both properties, return an empty
vector<long long> instead.


DEFINITION
Class:P8XCoinChangeAnother
Method:solve
Parameters:int, long long, long long
Returns:vector<long long>
Method signature:vector<long long> solve(int N, long long coins_sum, long long coins_count)


NOTES
-Given two different vector<long long>s A and B of equal length, let i be
 the smallest index such that A[i] and B[i] differ. If A[i] &lt B[i],
 we say that A is lexicographically smaller than B, and vice versa.


CONSTRAINTS
-N will be between 1 and 60, inclusive.
-coins_sum and coins_count will each be between 1 and 10^18, inclusive.


EXAMPLES

0)
2
4
3

Returns: {2, 1 }

We have N=2, which means that we can use coins worth 2^0 and coins worth 2^1.
We are looking for a set of 3 coins worth 4 in total. There is a unique solution:
use 2 coins worth 2^0 and 1 coin worth 2^1.


1)
3
6
3

Returns: {0, 3, 0 }

We have N=3, which means that we can use coins worth 2^0, 2^1, and 2^2.
We are looking for a set of 3 coins worth 6 in total. There are two possible
solutions: 2 coins of type 0 and 1 coin of type 2, or 3 coins of type 1.
Since the latter is lexicographically smaller than the former, your method
should return the latter.


2)
2
8
1

Returns: { }


3)
1
10000000000
10000000000

Returns: {10000000000 }

*/
// END CUT HERE
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

class P8XCoinChangeAnother {

public:
	vector<long long> solve(int N, long long coins_sum, long long coins_count) {
		LLVec v(N);
		v[0] = coins_sum;
		LL c = coins_sum;
		LL diff = c - coins_count;
		int i;
		for (i = 0; i < (N-1); ++i) {
			LL a = min(v[i] / 2, diff);
			if (a > 0) {
				v[i] -= a*2;
				v[i+1] += a;
				diff -= a;
			}
		}
		LLVec result;
		if (diff == 0) {
			result = v;
		}
		return result;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			long long Arg1 = 4LL;
			long long Arg2 = 3LL;
			long long Arr3[] = {2, 1 };

			vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			long long Arg1 = 6LL;
			long long Arg2 = 3LL;
			long long Arr3[] = {0, 3, 0 };

			vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			long long Arg1 = 8LL;
			long long Arg2 = 1LL;
//			long long Arr3[] = { };

			vector<long long> Arg3;
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			long long Arg1 = 10000000000LL;
			long long Arg2 = 10000000000LL;
			long long Arr3[] = {10000000000 };

			vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	P8XCoinChangeAnother ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
