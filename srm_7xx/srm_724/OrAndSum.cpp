// BEGIN CUT HERE
/*
SRM 724 Div1 Easy (250)

PROBLEM STATEMENT
You are given two vector<long long>s: pairOr and pairSum.
Each of these arrays will contain n non-negative integers.

Determine whether it is possible to construct a sequence x[0], ..., x[n] of nonnegative integers with the following properties:

for each i between 0 and n-1, inclusive, x[i] or x[i+1] = pairOr[i]
for each i between 0 and n-1, inclusive, x[i] + x[i+1] = pairSum[i]

Note that the sequence x should contain n+1 elements: one more than the length of each of the given arrays.

Return "Possible" if we can find at least one such sequence x, and "Impossible" if not.

 
DEFINITION
Class:OrAndSum
Method:isPossible
Parameters:vector<long long>, vector<long long>
Returns:string
Method signature:string isPossible(vector<long long> pairOr, vector<long long> pairSum)


CONSTRAINTS
-pairOr will contain between 1 and 50 elements, inclusive.
-pairOr and pairSum will contain the same number of elements.
-Each element in pairOr will be between 0 and 1,000,000,000,000,000,000 (10^18), inclusive.
-Each element in pairSum will be between 0 and 1,000,000,000,000,000,000 (10^18), inclusive.


EXAMPLES

0)
{7}
{11}

Returns: "Possible"

One of the solutions is {5,6}.

 
1)
{11}
{7}

Returns: "Impossible"

The sum of two numbers will always be greater than or equal to their bitwise or.

 
2)
{3,3,7,5,7}
{3,5,7,9,11}

Returns: "Possible"

One of the solutions is {1,2,3,4,5,6}.

 
3)
{1,100,1000}
{100,1000,10000}

Returns: "Impossible"

 
4)
{261208776456074191,261208776456074191,261208776456074191}
{333333333333333333,333333333333333333,333333333333333333}

Returns: "Possible"


5)
{0}
{0}

Returns: "Possible"

*/
// END CUT HERE

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class OrAndSum {
    bool possible(vector<LL> &pairOr, vector<LL> &pairSum) {
        int n = (int)pairOr.size();
        for (int i = 0; i <= 60; ++i) {
            bool ok = false;
            int j;
            for (j = 0; j <= 1; ++j) {
                ok = true;
                int prev = j;
                for (int k = 0; k < n; ++k) {
                    int curr = (prev ^ pairSum[k]) & 1;
                    if ((prev | curr) != (pairOr[k] & 1)) {
                        ok = false;
                        break;
                    }
                    prev = curr;
                }
                if (ok) {
                    break;
                }
            }
            if (!ok) {
                return false;
            }
            int prev = j;
            for (int k = 0; k < n; ++k) {
                int curr = (prev ^ pairSum[k]) & 1;
                pairOr[k] >>= 1;
                pairSum[k] -= prev + curr;
                pairSum[k] >>= 1;
                prev = curr;
            }
        }
        return true;
    }

public:
	string isPossible(vector<long long> pairOr, vector<long long> pairSum) {
        return possible(pairOr, pairSum) ? "Possible" : "Impossible";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {7};
			long Arr1[] = {11};
			string Arg2 = "Possible";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {11};
			long Arr1[] = {7};
			string Arg2 = "Impossible";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {3,3,7,5,7};
			long Arr1[] = {3,5,7,9,11};
			string Arg2 = "Possible";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {1,100,1000};
			long Arr1[] = {100,1000,10000};
			string Arg2 = "Impossible";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {261208776456074191,261208776456074191,261208776456074191};
			long Arr1[] = {333333333333333333,333333333333333333,333333333333333333};
			string Arg2 = "Possible";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {0};
			long Arr1[] = {0};
			string Arg2 = "Possible";

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE
};

// BEGIN CUT HERE
int main() {
	OrAndSum ___test;
	___test.run_test(-1);
}
// END CUT HERE
