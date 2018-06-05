/*
TCO18 R2A Easy (250)

PROBLEM STATEMENT
An arithmetic sequence of length n is a sequence y[0], y[1], ..., y[n-1] such that for each i we have y[i] = y[0] + i*d, where d is some constant.
For example, {4,5,6,7}, {1,1,1,1,1}, and {7,5,3} are arithmetic sequences.

You are given a sequence of n positive integers: x[0], x[1], ..., x[n-1].
You are allowed to change this sequence.
More precisely, you may perform arbitrarily many steps.
In each step you may choose any element of the sequence and change it to any integer value.
(Note that the new value is not required to be positive.)
The cost of each change is equal to the absolute difference between the old and the new value.

You are given the vector <int> x.
Compute and return the smallest total cost of changing x into an arithmetic sequence of integers.


DEFINITION
Class:ArithmeticSequenceDiv1
Method:findMinCost
Parameters:vector <int>
Returns:int
Method signature:int findMinCost(vector <int> x)


CONSTRAINTS
-x will contain betwee 1 and 100 elements, inclusive.
-Each element of x will be between 1 and 100, inclusive.


EXAMPLES

0)
{1,3,2}

Returns: 2

One optimal solution is to change this sequence into {1,2,3}.
Changing x[1] from 3 to 2 costs abs(3-2) = 1.
Changing x[2] from 2 to 3 costs abs(2-3) = 1.
Thus, the total cost is 2.


1)
{1,1,1,2,3,4,5}

Returns: 3

Here an optimal solution is to change x[0] from 1 to -1 (cost 2) and then change x[1] from 1 to 0 (cost 1).


2)
{1,2,3,4}

Returns: 0

This is already an arithmetic sequence, so the cheapest solution is to do nothing.


3)
{1,5,2,5}

Returns: 5


4)
{11,33,22}

Returns: 17


5)
{1, 3, 5, 7, 2, 4, 6}

Returns: 12

*/

#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>

using namespace std;

typedef long long LL;

class ArithmeticSequenceDiv1 {
public:
int findMinCost(vector <int> x) {
    LL ans = 1LL<<30;
    for (LL i = -200; i <= 200; ++i) {
        for (LL j = -200; j <= 200; ++j) {
            LL cost = 0;
            for (LL k = 0; k != x.size(); ++k) {
                cost += abs(i + j * k - x[k]);
            }
            ans = min(ans, cost);
        }
    }
    return (int)ans;
}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,3,2};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findMinCost(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,2,3,4,5};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findMinCost(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findMinCost(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,5,2,5};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findMinCost(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {11,33,22};
			int Arg1 = 17;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findMinCost(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 3, 5, 7, 2, 4, 6};
			int Arg1 = 12;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findMinCost(Arg0));
		}
		n++;

	}

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  ArithmeticSequenceDiv1 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
