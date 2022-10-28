// BEGIN CUT HERE
/*
SRM 840 Div2 Easy (300)

PROBLEM STATEMENT

You have a collection of bags, each containing some marbles.
You are given the vector <int> bags that describes this collection:
each element of bags is the number of marbles in one of the bags.

Consider the following process:

Find the bag that currently contains the most marbles. (If there are several bags tied for having the maximum number of marbles, pick any one of them.)
Remove half of the marbles from that bag. Round the number of removed marbles up if necessary. (E.g., if there are 21 marbles in the bag, you remove 11 and leave 10 in the bag.)
Throw away the removed marbles.

You are going to repeat the above process steps times.


Determine the final numbers of marbles in the bags.
Return a vector <int> containing these numbers sorted in non-descending order.


DEFINITION
Class:RepeatedHalving
Method:simulate
Parameters:vector <int>, int
Returns:vector <int>
Method signature:vector <int> simulate(vector <int> bags, int steps)


CONSTRAINTS
-bags will contain between 1 and 100 elements, inclusive.
-Each element of bags will be between 0 and 10^9, inclusive.
-steps will be between 1 and 10^9, inclusive.


EXAMPLES

0)
{1, 2, 3, 21, 5, 4}
4

Returns: {1, 2, 2, 2, 3, 4 }


We select the bag with 21 marbles and remove 11 of them, leaving 10.
We select the bag with 10 marbles and remove 5 of them, leaving 5.
We select either one of the two bags with 5 marbles and remove 3 of them, leaving 2 in that bag.
We select the other bag with 5 marbles (which is now the only bag with that many marbles) and we remove 3 of them, leaving 2.

Remember that the return value must be sorted. E.g., the array {1, 2, 3, 2, 2, 4} has the correct pile sizes but not in the correct order, and thus it would not be accepted as an answer.


1)
{1, 1, 1, 1, 1}
5

Returns: {0, 0, 0, 0, 0 }

In each step we select a different bag and we remove the one marble it contains.


2)
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
1000000000

Returns: {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

In each step we select an arbitrary bag and we remove half of the marbles it contains. (I.e., we remove zero marbles and keep zero marbles in the bag.)

Keep in mind that a straightforward simulation of 10^9 steps, one at a time, will take quite a lot of time to complete.


3)
{123, 4568, 89123, 45, 678901234}
27

Returns: {45, 123, 1142, 1294, 1392 }

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>
#include <queue>

using namespace std;

class RepeatedHalving {
public:
	vector <int> simulate(vector <int> bags, int steps) {
		vector <int> ans = bags;
		for (int i = 0; i < steps; ++i) {
			sort(ans.begin(), ans.end());
			if (!ans.back()) break;
			ans.back() /= 2;
		}
		sort(ans.begin(), ans.end());
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 21, 5, 4};
			int Arg1 = 4;
			int Arr2[] = {1, 2, 2, 2, 3, 4 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, simulate(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1, 1, 1};
			int Arg1 = 5;
			int Arr2[] = {0, 0, 0, 0, 0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, simulate(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			int Arg1 = 1000000000;
			int Arr2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, simulate(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {123, 4568, 89123, 45, 678901234};
			int Arg1 = 27;
			int Arr2[] = {45, 123, 1142, 1294, 1392 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, simulate(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RepeatedHalving ___test;
	___test.run_test(-1);
}
// END CUT HERE
