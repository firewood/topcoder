// BEGIN CUT HERE
/*
SRM 647 Div2 Easy (250)

PROBLEM STATEMENT

A teacher is trying to arrange a group of students into a line.
The teacher knows that whenever she places two students with the same age next to each other, they will talk and disturb everyone.
She wants to avoid that.

You are given a vector <int> x.
Each element of x is the age of one of the students.

Determine whether it is possible for the teacher to arrange the students in a line so that there are no disturbances.
If it can be done, return "possible" (quotes for clarity).
If there will always be some pair of adjacent students with the same age, return "impossible".
Note that the return value is case-sensitive.


DEFINITION
Class:PeacefulLine
Method:makeLine
Parameters:vector <int>
Returns:string
Method signature:string makeLine(vector <int> x)


CONSTRAINTS
-x will have between 1 and 25 elements, inclusive.
-Each element of x will be between 1 and 25, inclusive. 


EXAMPLES

0)
{1,2,3,4}

Returns: "possible"

In this case, no two students have the same age so any order works.


1)
{1,1,1,2}

Returns: "impossible"

Regardless of which order we choose, two of the 1s will always be adjacent.


2)
{1,1,2,2,3,3,4,4}

Returns: "possible"

One example of a peaceful line is {1,2,3,4,1,2,3,4}


3)
{3,3,3,3,13,13,13,13}

Returns: "possible"


4)
{3,7,7,7,3,7,7,7,3}

Returns: "impossible"


5)
{25,12,3,25,25,12,12,12,12,3,25}

Returns: "possible"


6)
{3,3,3,3,13,13,13,13,3}

Returns: "possible"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class PeacefulLine {
public:
	string makeLine(vector <int> x) {
		int cnt[32] = {};
		int m = 0;
		for (int a : x){
			m = max(m, cnt[a] += 1);
		}
		return m <= ((int)x.size() + 1) / 2 ? "possible" : "impossible";
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
			int Arr0[] = {1,2,3,4};
			string Arg1 = "possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, makeLine(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,2};
			string Arg1 = "impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, makeLine(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,2,2,3,3,4,4};
			string Arg1 = "possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, makeLine(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,3,3,3,13,13,13,13};
			string Arg1 = "possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, makeLine(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,7,7,7,3,7,7,7,3};
			string Arg1 = "impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, makeLine(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {25,12,3,25,25,12,12,12,12,3,25};
			string Arg1 = "possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, makeLine(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,3,3,3,13,13,13,13,3};
			string Arg1 = "possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, makeLine(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PeacefulLine ___test;
	___test.run_test(-1);
}
// END CUT HERE
