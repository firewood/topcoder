// BEGIN CUT HERE
/*
// SRM 557 Div1 Easy (250)

// PROBLEM STATEMENT
// Fox Ciel lives in a beautiful countryside.
She loves climbing mountains.
Yesterday, she went hiking in the mountains.

Her trip can be described as a sequence of (n+1) integers: h[0], h[1], ..., h[n]. 
These values represent altitudes visited by Fox Ciel during the trip, in order.
Fox Ciel does not remember the precise sequence, but she remembers the following:

for each i, h[i] >= 0
h[0] = h0
h[n] = hn
for each i, abs(h[i+1]-h[i]) = 1

The last condition means that in each step the altitude of Fox Ciel either increased by 1, or decreased by 1.
We will call the two types of steps "steps up" and "steps down", respectively.
Steps up will be denoted 'U' and steps down will be denoted 'D'.

You are given the ints n, h0, and hn: the length of the trip, the altitude at the beginning, and the altitude at the end.
In addition to these, Fox Ciel remembers some contiguous segment of her trip.
You are given this segment as a string history.
Each character of history is either 'U' or 'D'.

Check whether there is a valid trip that matches everything Fox Ciel remembers.
Return "YES" (quotes for clarity) if there is at least one such trip, or "NO" if there is none.


DEFINITION
Class:FoxAndMountainEasy
Method:possible
Parameters:int, int, int, string
Returns:string
Method signature:string possible(int n, int h0, int hn, string history)


CONSTRAINTS
-n will be between 1 and 100,000, inclusive.
-history will contain between 1 and min(50,n) characters, inclusive.
-Each character in history will be either 'U' or 'D'.
-h0 will be between 0 and 100,000, inclusive.
-hn will be between 0 and 100,000, inclusive.


EXAMPLES

0)
4
0
4
"UU"

Returns: "YES"

The only solution is: h[] = {0, 1, 2, 3, 4}, the history of the entire trip will be "UUUU".


1)
4
0
4
"D"

Returns: "NO"

Based on n, h0 and hn, the history of the entire trip must be "UUUU". There is no 'D' in this history.


2)
4
100000
100000
"DDU"

Returns: "YES"

We have the following solution: h[] = {100000, 100001, 100000, 99999, 100000}, the history of the entire trip is "UDDU".


3)
4
0
0
"DDU"

Returns: "NO"


4)
20
20
20
"UDUDUDUDUD"

Returns: "YES"


5)
20
0
0
"UUUUUUUUUU"

Returns: "YES"


6)
20
0
0
"UUUUUUUUUUU"

Returns: "NO"

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class FoxAndMountainEasy {

public:
	string possible(int n, int h0, int hn, string history) {
		int cnt = 0;
		int h = h0;
		int sz = (int)history.length();
		int i;
		for (i = 0; i < sz; ++i) {
			if (history[i] == 'U') {
				++h;
			} else {
				--h;
				if (h < 0) {
					h = 0;
					++cnt;
				}
			}
		}
		int rcnt = n - (sz+cnt);
		int rh = abs(hn - h);
		if (rcnt < rh || (rcnt&1) != (rh&1)) {
			return "NO";
		}
		return "YES";
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
			int Arg0 = 4;
			int Arg1 = 0;
			int Arg2 = 4;
			string Arg3 = "UU";
			string Arg4 = "YES";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 0;
			int Arg2 = 4;
			string Arg3 = "D";
			string Arg4 = "NO";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 100000;
			int Arg2 = 100000;
			string Arg3 = "DDU";
			string Arg4 = "YES";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 0;
			int Arg2 = 0;
			string Arg3 = "DDU";
			string Arg4 = "NO";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arg1 = 20;
			int Arg2 = 20;
			string Arg3 = "UDUDUDUDUD";
			string Arg4 = "YES";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arg1 = 0;
			int Arg2 = 0;
			string Arg3 = "UUUUUUUUUU";
			string Arg4 = "YES";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arg1 = 0;
			int Arg2 = 0;
			string Arg3 = "UUUUUUUUUUU";
			string Arg4 = "NO";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 5650;
			int Arg1 = 1397;
			int Arg2 = 969;
			string Arg3 = "UDUUUDUDDDDUDDUUDUUUUDDUUUUDUDUDUDUDDDD";
			string Arg4 = "YES";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndMountainEasy ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
