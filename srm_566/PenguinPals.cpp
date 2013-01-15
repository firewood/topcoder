// BEGIN CUT HERE
/*
SRM 566 Div2 Medium (500)

// PROBLEM STATEMENT
// 
Penguin Pals is a match making service that matches penguins to new friends, using the following procedure:

Each penguin is asked a single question: "Do you prefer the color blue, or the color red?"
All penguins are arranged so that they stand on a circle, equally spaced. 
The organizers draw some straight lines, connecting some pairs of penguins. Each penguin may only be connected to at most one other penguin. Two penguins cannot be connected if they prefer a different color.
Each penguin who is connected to some other penguin follows the line to find their match.




The only problem with the above system was that it allowed penguins to collide if two lines crossed each other.
Therefore, a new additional rule was adopted: no two lines may cross.
Penguin Pals now has some penguins arranged on a circle (after step 2 of the above procedure).
They need to know the maximum number of pairs of penguins they can create.



You are given a string colors whose i-th character represents the prefered color of the i-th penguin (0-based index) in the circular arrangement. The i-th character is 'R' if the i-th penguin prefers red and 'B' if the i-th penguin prefers blue. Return the maximum number of matched pairs that can be formed.


DEFINITION
Class:PenguinPals
Method:findMaximumMatching
Parameters:string
Returns:int
Method signature:int findMaximumMatching(string colors)


CONSTRAINTS
-colors will contain between 1 and 50 characters, inclusive.
-Each character of colors will be either 'R' or 'B'.


EXAMPLES

0)
"RRBRBRBB"

Returns: 3

In this picture the penguins have been colored in their preferred color. 



1)
"RRRR"

Returns: 2



2)
"BBBBB"

Returns: 2



3)
"RBRBRBRBR"

Returns: 4



4)
"RRRBRBRBRBRB"

Returns: 5



5)
"R"

Returns: 0



6)
"RBRRBBRB"

Returns: 3



7)
"RBRBBRBRB"

Returns: 4



*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class PenguinPals {
	int _sz;
	string _c;
	int _memo[51][51];

	int rec(int s, int e) {
		if (s >= e) return 0;
		int &r = _memo[s%_sz][e%_sz];
		if (r >= 0) return r;

		r = 0;
		if (_c[s]==_c[e]) {
			r = max(r, 1 + rec(s+1, e-1));
		}
		int i;
		for (i = s+1; i < e; ++i) {
			r = max(r, rec(s, i-1) + rec(i, e));
		}
		return r;
	}

public:
	int findMaximumMatching(string colors) {
		int i;
		_sz = (int)colors.size();
		_c = colors + colors;
		memset(_memo, -1, sizeof(_memo));

		int ans = 0;
		for (i = 0; i < _sz; ++i) {
			ans = max(ans, rec(i, i+_sz-1));
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
			string Arg0 = "RRBRBRBB";
			int Arg1 = 3;

			verify_case(n, Arg1, findMaximumMatching(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RRRR";
			int Arg1 = 2;

			verify_case(n, Arg1, findMaximumMatching(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BBBBB";
			int Arg1 = 2;

			verify_case(n, Arg1, findMaximumMatching(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RBRBRBRBR";
			int Arg1 = 4;

			verify_case(n, Arg1, findMaximumMatching(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RRRBRBRBRBRB";
			int Arg1 = 5;

			verify_case(n, Arg1, findMaximumMatching(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "R";
			int Arg1 = 0;

			verify_case(n, Arg1, findMaximumMatching(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RBRRBBRB";
			int Arg1 = 3;

			verify_case(n, Arg1, findMaximumMatching(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RBRBBRBRB";
			int Arg1 = 4;

			verify_case(n, Arg1, findMaximumMatching(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "RRRBBBRRRBBBRBRBRBRB";
			int Arg1 = 9;

			verify_case(n, Arg1, findMaximumMatching(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "RRBRBRBBRRBRBRBBRRBRBRBBRRBRBRBBRRBRBRBBRRBRBRBB";
			int Arg1 = 23;

			verify_case(n, Arg1, findMaximumMatching(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "BRBRBRBRBRBBRBRBRBRBBRBBBBBRRRRRRBRRBBRBRBR";
			int Arg1 = 21;

			verify_case(n, Arg1, findMaximumMatching(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PenguinPals ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
//	___test.run_test(8);
	___test.run_test(-1);
}
// END CUT HERE
