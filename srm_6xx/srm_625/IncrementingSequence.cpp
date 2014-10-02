// BEGIN CUT HERE
/*
SRM 625 Div2 Medium (500)

PROBLEM STATEMENT
You have a vector <int> A with N elements.

Your goal is to change it into a vector <int> that contains each number from 1 to N exactly once. The change will consist of zero or more steps. In each step, you may pick an arbitrary element of A and increment its value by k. You may pick the same element multiple times. Note that you are not allowed to decrement the value of any element.

You are given the int k and the vector <int> A.
Return "POSSIBLE" if it is possible to achieve your goal. Return "IMPOSSIBLE" otherwise.


DEFINITION
Class:IncrementingSequence
Method:canItBeDone
Parameters:int, vector <int>
Returns:string
Method signature:string canItBeDone(int k, vector <int> A)


NOTES
-Return value is case-sensitive. For example, you can't return "Possible" or "possible" instead of "POSSIBLE".


CONSTRAINTS
-k will be between 1 and 10, inclusive.
-A will contain between 1 and 50 elements, inclusive.
-Each element of A will be between 1 and 50, inclusive.


EXAMPLES

0)
3
{1,2,4,3}

Returns: "POSSIBLE"

This sequence of length 4 already contains all numbers from 1 to 4 exactly once. Note that their order does not matter.


1)
5
{2,2}

Returns: "IMPOSSIBLE"


2)
1
{1,1,1,1,1,1,1,1}

Returns: "POSSIBLE"

There are many ways to achieve the goal. For example, it is possible to obtain the sequence {1,2,3,4,5,6,7,8}. To do this, just increment the element at each position one by one until it reaches the required value.


3)
2
{5,3,3,2,1}

Returns: "IMPOSSIBLE"

We want to have the values {1,2,3,4,5}, in any order. Currently, we are missing the 4. As k=2, the only way to produce a 4 is by incrementing a 2. But if we increment our only 2, we will have no way of producing another 2.


4)
9
{1,2,3,1,4,5,6,7,9,8}

Returns: "POSSIBLE"


5)
2
{1,1,1,1,1,1,2,2,2,2,2,2}

Returns: "POSSIBLE"


6)
1
{1}

Returns: "POSSIBLE"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class IncrementingSequence {
public:
	string canItBeDone(int k, vector <int> A) {
		int cnt[64] = {};
		for (int i = 0; i < (int)A.size(); ++i) {
			cnt[A[i]] += 1;
		}
		for (int i = (int)A.size(); i > 0; --i) {
			int j;
			for (j = i; j > 0; j -= k) {
				if (cnt[j] > 0) {
					break;
				}
			}
			if (j <= 0) {
				return "IMPOSSIBLE";
			}
			cnt[j] -= 1;
		}
		return "POSSIBLE";
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
			int Arg0 = 3;
			int Arr1[] = {1,2,4,3};
			string Arg2 = "POSSIBLE";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {2,2};
			string Arg2 = "IMPOSSIBLE";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {1,1,1,1,1,1,1,1};
			string Arg2 = "POSSIBLE";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {5,3,3,2,1};
			string Arg2 = "IMPOSSIBLE";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arr1[] = {1,2,3,1,4,5,6,7,9,8};
			string Arg2 = "POSSIBLE";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {1,1,1,1,1,1,2,2,2,2,2,2};
			string Arg2 = "POSSIBLE";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {1};
			string Arg2 = "POSSIBLE";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, canItBeDone(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	IncrementingSequence ___test;
	___test.run_test(-1);
}
// END CUT HERE
