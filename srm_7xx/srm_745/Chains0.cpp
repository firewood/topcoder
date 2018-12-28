// BEGIN CUT HERE
/*
SRM 745 Level 1 (200)

PROBLEM STATEMENT
All problems in this problem set are about "chains": collections of nested ranges of integers. All problems are independent, but use the same definitions. Each problem statement contains the definitions it needs. If a term appears in multiple problems, the definition is always identical.

Definitions follow. The defined term is always in uppercase.

An INTERVAL [x,y) with x <= y is the set of integers that are greater than or equal to x, and strictly less than y.

There is only one EMPTY INTERVAL but it has multiple equivalent notations. For example, [0,0) and [3,3) both denote the empty interval. Note that [3,0) is not a valid interval, because an interval [x,y) must have x <= y.

An interval I1 is called a PROPER SUBSET of an interval I2 if I2 contains all elements of I1 and at least one other element.

You are given the ints x and y.
These represent a interval [x,y) that contains at least two numbers.
Find any nonempty interval [a,b) that is a proper subset of [x,y).

Return the vector <int> {a, b}.
That is, return a vector <int> with two elements, the first of which is your a and the second is your b.
Any valid solution will be accepted.


DEFINITION
Class:Chains0
Method:getProperSubset
Parameters:int, int
Returns:vector <int>
Method signature:vector <int> getProperSubset(int x, int y)


CONSTRAINTS
-x will be between 0 and 50, inclusive.
-y will be between x+2 and 50, inclusive.


EXAMPLES

0)
10
47

Returns: {23, 29 }


1)
12
15

Returns: {13, 14 }


2)
0
50

Returns: {23, 29 }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Chains0 {
public:
	vector <int> getProperSubset(int x, int y) {
		return { x, x + 1 };
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
			int Arg0 = 10;
			int Arg1 = 47;
			int Arr2[] = {23, 29 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, getProperSubset(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 12;
			int Arg1 = 15;
			int Arr2[] = {13, 14 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, getProperSubset(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 50;
			int Arr2[] = {23, 29 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, getProperSubset(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Chains0 ___test;
	___test.run_test(-1);
}
// END CUT HERE
