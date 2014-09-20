// BEGIN CUT HERE
/*
SRM 633 Div2 Medium (500)

PROBLEM STATEMENT
Frog Suwako lives on a two-dimensional plane.
She likes to jump.
Currently, she is located in the point (0, 0).
She would like to reach the point (x, y).
You are given the ints x and y.

Suwako wants to reach the desired destination in a specific way: using a series of jumps with pre-determined lengths.
You are given these lengths in a vector <int> jumpLenghts.
For example, if jumpLengths = { 2, 5 }, Suwako must make a jump of length exactly 2, followed by a jump of length exactly 5.

Note that Suwako can jump onto arbitrary points in the plane, they are not required to have integer coordinates.
Return "Able" (quotes for clarity) if Suwako is able to reach her desired destination from (0, 0) using the desired sequence of jump lengths.
Otherwise, return "Not able".


DEFINITION
Class:Jumping
Method:ableToGet
Parameters:int, int, vector <int>
Returns:string
Method signature:string ableToGet(int x, int y, vector <int> jumpLengths)


CONSTRAINTS
-x will be between -1,000 and 1,000, inclusive.
-y will be between -1,000 and 1,000, inclusive.
-len will contain between 1 and 50 elements, inclusive.
-Each element in len will be between 1 and 1,000, inclusive.


EXAMPLES

0)
5
4
{2, 5}

Returns: "Able"

One possibility is to jump from (0, 0) to (2, 0), and then from (2, 0) to (5, 4).


1)
3
4
{4}

Returns: "Not able"

The distance from (0, 0) to (3, 4) is 5. You cannot get there using a single jump of length 4 - it is too short.


2)
3
4
{6}

Returns: "Not able"

The distance from (0, 0) to (3, 4) is 5. You cannot get there using a single jump of length 6 - it is too long.


3)
0
1
{100, 100}

Returns: "Able"

Here, one possible solution looks as follows: Let t = sqrt(100*100 - 0.5*0.5). Suwoko will make her first jump from (0, 0) to (t, 0.5), and her second jump from (t, 0.5) to (0, 1).


4)
300
400
{500}

Returns: "Able"


5)
11
12
{1,2,3,4,5,6,7,8,9,10}

Returns: "Able"


6)
11
12
{1,2,3,4,5,6,7,8,9,100}

Returns: "Not able"

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

using namespace std;

class Jumping {

	bool can(double d, vector <int> jumpLengths) {
		int sum = accumulate(jumpLengths.begin(), jumpLengths.end(), 0);
		int m = *max_element(jumpLengths.begin(), jumpLengths.end());
		return sum >= d && m <= (d + sum - m);
	}

public:
	string ableToGet(int x, int y, vector <int> jumpLengths) {
		return can(sqrt(x*x + y*y), jumpLengths) ? "Able" : "Not able";
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
			int Arg0 = 5;
			int Arg1 = 4;
			int Arr2[] = {2, 5};
			string Arg3 = "Able";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, ableToGet(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 4;
			int Arr2[] = {4};
			string Arg3 = "Not able";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, ableToGet(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 4;
			int Arr2[] = {6};
			string Arg3 = "Not able";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, ableToGet(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 1;
			int Arr2[] = {100, 100};
			string Arg3 = "Able";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, ableToGet(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 300;
			int Arg1 = 400;
			int Arr2[] = {500};
			string Arg3 = "Able";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, ableToGet(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 11;
			int Arg1 = 12;
			int Arr2[] = {1,2,3,4,5,6,7,8,9,10};
			string Arg3 = "Able";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, ableToGet(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 11;
			int Arg1 = 12;
			int Arr2[] = {1,2,3,4,5,6,7,8,9,100};
			string Arg3 = "Not able";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, ableToGet(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Jumping ___test;
	___test.run_test(-1);
}
// END CUT HERE
