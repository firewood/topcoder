// BEGIN CUT HERE
/*
SRM 617 Div2 Easy (250)

PROBLEM STATEMENT
In this problem, some test cases have more than one correct output. We are using a special checker to verify that the output of your program is correct.

A positive integer x is called composite if there are positive integers y > 1 and z > 1 such that x = yz.
In other words, a composite positive integer has a positive integer divisor other than 1 and itself.
For example, 48 is composite because 48 = 4*12.
The smallest few composite integers are 4, 6, 8, 9, and 10.

You are given an int n.
Return a vector <int> with two elements.
Both elements of the returned vector <int> must be positive composite integers, and their sum must be n.

For the given constraints on n at least one such pair always exists.
Note that if there are many such pairs, your solution can return any one of them.

DEFINITION
Class:SilverbachConjecture
Method:solve
Parameters:int
Returns:vector <int>
Method signature:vector <int> solve(int n)


CONSTRAINTS
-n will be between 20 and 2000, inclusive.


EXAMPLES

0)
20

Returns: {8, 12 }

For n=20 there are seven correct answers: {4,16}, {6,14}, {8,12}, {10,10}, {12,8}, {14,6}, and {16,4}. Your program must return one of these seven answers.


1)
30

Returns: {15, 15 }

You may return two identical numbers.


2)
999

Returns: {699, 300 }


3)
45

Returns: {15, 30 }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SilverbachConjecture {
public:
	vector <int> solve(int n) {
		int p[2000] = {};
		p[2] = 1;
		for (int i = 3; i < 2000; ++i) {
			p[i] = 1;
			for (int j = 2; j < i; ++j) {
				if ((i % j) == 0) {
					p[i] = 0;
					break;
				}
			}
		}
		vector <int> ans(2);
		for (int i = 4; !ans[0] && i < 2000; ++i) {
			if (!p[i]) {
				for (int j = 4; j < 2000; ++j) {
					if (!p[j]) {
						if (i + j == n) {
							ans[0] = i;
							ans[1] = j;
							break;
						}
					}
				}
			}
		}
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
			int Arg0 = 20;
			int Arr1[] = {8, 12 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 30;
			int Arr1[] = {15, 15 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 999;
			int Arr1[] = {699, 300 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 45;
			int Arr1[] = {15, 30 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SilverbachConjecture ___test;
	___test.run_test(-1);
}
// END CUT HERE
