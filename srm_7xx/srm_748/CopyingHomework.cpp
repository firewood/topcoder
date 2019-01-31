// BEGIN CUT HERE
/*
SRM 748 Div2 Easy (250)

PROBLEM STATEMENT

"Dude, can I copy your homework?"
"Sure, but change it a little, so it doesn't look like we cheated."

You are given the vector <int> friendsHomework containing the five values your friend measured for their Physics homework.
Construct and return a vector <int> yourHomework with the following properties:

yourHomework must have exactly 5 elements.
For each i, yourHomework[i] must differ from friendsHomework[i] (so it doesn't look like you cheated).
For each i, the difference between yourHomework[i] and friendsHomework[i] must be at most 10 (so that the values are similar).
The sum of yourHomework must be the same as the sum of friendsHomework (so that you both get the same final result).


DEFINITION
Class:CopyingHomework
Method:copy
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> copy(vector <int> friendsHomework)


NOTES
-Any valid solution will be accepted.


CONSTRAINTS
-friendsHomework will contain exactly 5 elements.
-Each element of friendsHomework will be between 0 and 1000, inclusive.


EXAMPLES

0)
{10, 20, 30, 40, 50}

Returns: {9, 19, 29, 39, 54 }


1)
{0, 0, 0, 0, 0}

Returns: {-1, -1, -1, -1, 4 }

Note that the values in yourHomework may lie outside the range [0,1000]. As long as they satisfy the constraints from the problem statement, you have a valid answer.


2)
{400,399,400,399,400}

Returns: {399, 398, 399, 398, 404 }

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class CopyingHomework {
public:
	vector <int> copy(vector <int> friendsHomework) {
		vector <int> ans = friendsHomework;
		for (int i = 1; i < (int)ans.size(); ++i) {
			ans[i] += (i % 2) ? -2 : 1;
		}
		ans[0] += 2;
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
			int Arr0[] = {10, 20, 30, 40, 50};
			int Arr1[] = {9, 19, 29, 39, 54 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, copy(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 0, 0};
			int Arr1[] = {-1, -1, -1, -1, 4 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, copy(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {400,399,400,399,400};
			int Arr1[] = {399, 398, 399, 398, 404 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, copy(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CopyingHomework ___test;
	___test.run_test(-1);
}
// END CUT HERE
