// BEGIN CUT HERE
/*
TCO22 Regional Algo Easy (150)

PROBLEM STATEMENT

The string circle is written around a circle in the clockwise direction.

Now that you have the circle, you can read a new string by starting anywhere on the circle and then walking along the circle and reading all the letters you encounter.
You may terminate the process whenever you want.
You may walk around the circle in either direction (clockwise or counter-clockwise) but you are not allowed to change direction while walking.

Given is a string goal.
Determine whether goal can be read when following the above instructions. 
You get to choose where on the circle you start, in which direction you walk and when to stop reading.

Return 1 if goal can be read, or 0 if it does not.


DEFINITION
Class:OnACircle
Method:canRead
Parameters:string, string
Returns:int
Method signature:int canRead(string circle, string goal)


CONSTRAINTS
-circle will contain between 3 and 2500 characters, inclusive.
-Each character in circle will be a lowercase English letter ('a'-'z').
-goal will contain between 1 and 2500 characters, inclusive.
-Each character in goal will be a lowercase English letter ('a'-'z').


EXAMPLES

0)
"abcdef"
"bcd"

Returns: 1

The circle can look roughly as follows:


   a--b
  /    \
 f      c
  \    /
   e--d


We can read "bcd" by starting at the only 'b', going clockwise and stopping after the third read letter.


1)
"abcdef"
"dcb"

Returns: 1

The same circle as in the previous example. We can read "dcb" by essentially doing the same thing we did in the previous example, only in reverse: we start at the 'd', walk counter-clockwise, and stop after reading 'b'.


2)
"abcdef"
"bde"

Returns: 0

We are not allowed to skip letters. It is not possible to read "bde" anywhere on this cycle.


3)
"abcdef"
"efabc"

Returns: 1

Here's the circle again.

   a--b
  /    \
 f      c
  \    /
   e--d

We can read "efabc" by starting at the only 'e', going around the circle clockwise and stopping after the 'c'.


4)
"abcdef"
"cbafedcb"

Returns: 1

We can make more than one full loop around the circle.


5)
"abcdef"
"aba"

Returns: 0

Changing direction while reading is not allowed.


6)
"zyzzyzy"
"zyzyzz"

Returns: 1

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

using namespace std;

class OnACircle {
public:
	int canRead(string circle, string goal) {
		string a = circle + circle;
		while (a.length() <= goal.length() * 2) {
			a += circle;
		}
		string rev = a;
		reverse(rev.begin(), rev.end());
		if (strstr(a.c_str(), goal.c_str())) {
			return 1;
		}
		if (strstr(rev.c_str(), goal.c_str())) {
			return 1;
		}
		return 0;
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
			string Arg0 = "abcdef";
			string Arg1 = "bcd";
			int Arg2 = 1;

			verify_case(n, Arg2, canRead(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcdef";
			string Arg1 = "dcb";
			int Arg2 = 1;

			verify_case(n, Arg2, canRead(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcdef";
			string Arg1 = "bde";
			int Arg2 = 0;

			verify_case(n, Arg2, canRead(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcdef";
			string Arg1 = "efabc";
			int Arg2 = 1;

			verify_case(n, Arg2, canRead(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcdef";
			string Arg1 = "cbafedcb";
			int Arg2 = 1;

			verify_case(n, Arg2, canRead(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcdef";
			string Arg1 = "aba";
			int Arg2 = 0;

			verify_case(n, Arg2, canRead(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "zyzzyzy";
			string Arg1 = "zyzyzz";
			int Arg2 = 1;

			verify_case(n, Arg2, canRead(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			string Arg0 = "aaakaahrvrwvkqvrkhvawrqrrwwkakrrqwavwhvhhvkvvqkrvkwrkqrhaav";
			string Arg1 = "aavaaakaa";
			int Arg2 = 1;

			verify_case(n, Arg2, canRead(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OnACircle ___test;
	___test.run_test(-1);
}
// END CUT HERE
