// BEGIN CUT HERE
/*
SRM 596 Div1 Easy (250)

PROBLEM STATEMENT

You have an array with N elements.
Initially, each element is 0.
You can perform the following operations:

Increment operation: Choose one element of the array and increment the value by one.
Doubling operation: Double the value of each element.

You are given a vector <int> desiredArray containing N elements.
Compute and return the smallest possible number of operations needed to change the array from all zeros to desiredArray.


DEFINITION
Class:IncrementAndDoubling
Method:getMin
Parameters:vector <int>
Returns:int
Method signature:int getMin(vector <int> desiredArray)


CONSTRAINTS
-desiredArray will contain between 1 and 50 elements, inclusive.
-Each element of desiredArray will be between 0 and 1,000, inclusive.


EXAMPLES

0)
{2, 1}

Returns: 3

One of the optimal solutions is to apply increment operations to element 0 twice and then to element 1 once.
Total number of operations is 3.


1)
{16, 16, 16}

Returns: 7

The optimum solution looks as follows.
First, apply an increment operation to each element.
Then apply the doubling operation four times.
Total number of operations is 3+4=7.


2)
{100}

Returns: 9


3)
{0, 0, 1, 0, 1}

Returns: 2

Some elements in desiredArray may be zeros.


4)
{123, 234, 345, 456, 567, 789}

Returns: 40


5)
{7,5,8,1,8,6,6,5,3,5,5,2,8,9,9,4,6,9,4,4,1,9,9,2,8,4,7,4,8,8,6,3,9,4,3,4,5,1,9,8,3,8,3,7,9,3,8,4,4,7}

Returns: 84

*/
// END CUT HERE
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class IncrementAndDoubling {
public:
	int getMin(vector <int> desiredArray) {
		int ans = 1000000000;
		int c = 0;
		while (true) {
			int sum = accumulate(desiredArray.begin(), desiredArray.end(), 0);
			ans = min(ans, c + sum);
			if (sum <= 0) {
				break;
			}
			for (int i = 0; i < (int)desiredArray.size(); ++i) {
				c += desiredArray[i] % 2;
				desiredArray[i] /= 2;
			}
			++c;
		}
		return ans;
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
			int Arr0[] = {2, 1};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {16, 16, 16};
			int Arg1 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100};
			int Arg1 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 1, 0, 1};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {123, 234, 345, 456, 567, 789};
			int Arg1 = 40;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7,5,8,1,8,6,6,5,3,5,5,2,8,9,9,4,6,9,4,4,1,9,9,2,8,4,7,4,8,8,6,3,9,4,3,4,5,1,9,8,3,8,3,7,9,3,8,4,4,7};
			int Arg1 = 84;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	IncrementAndDoubling ___test;
	___test.run_test(-1);
}
// END CUT HERE
