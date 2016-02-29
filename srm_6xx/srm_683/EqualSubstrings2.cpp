// BEGIN CUT HERE
/*
SRM 683 Div2 Easy (250)

PROBLEM STATEMENT
You are given a string s.
Compute and return the number of ways in which we can choose two identical non-overlapping substrings of s.

(The two substrings must be non-empty.
Each substring must be contiguous.)


DEFINITION
Class:EqualSubstrings2
Method:get
Parameters:string
Returns:int
Method signature:int get(string s)


CONSTRAINTS
-s will consist only of lowercase English letters ('a'-'z').
-The length of s will be between 1 and 50, inclusive.


EXAMPLES

0)
"aa"

Returns: 1

There is exactly one way how to choose two non-empty and non-overlapping substrings.
In this case they happen to be equal (both are "a"), so the correct return value is 1.


1)
"abcd"

Returns: 0

Regardless how we choose two non-overlapping substrings, they will always differ.


2)
"aba"

Returns: 1

One pair: ("a", "a").


3)
"abab"

Returns: 3

Three pairs: ("a", "a"), ("b", "b"), ("ab", "ab").


4)
"aaaab"

Returns: 7

The 7 ways to select the two equal substrings are shown below.
Each row represents one way.
The characters 1 and 2 denote characters selected to form the first and second substring, respectively.


aaaab
-----
12...
1.2..
1..2.
.12..
.1.2.
..12.
1122.

(In the first six ways, the two selected substrings are "a" and "a". In the last way the selected substrings are "aa" and "aa".)


5)
"onetwothreeonetwothree"

Returns: 86

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class EqualSubstrings2 {
public:
	int get(string s) {
		int ans = 0, N = (int)s.length();
		for (int i = 0; i != N; ++i) {
			for (int j = 1; j <= (N - i) / 2; ++j) {
				for (int k = i + j; k + j <= N; ++k) {
					ans += memcmp(s.c_str() + i, s.c_str() + k, j) == 0;
				}
			}
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
			string Arg0 = "aa";
			int Arg1 = 1;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcd";
			int Arg1 = 0;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aba";
			int Arg1 = 1;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abab";
			int Arg1 = 3;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaab";
			int Arg1 = 7;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "onetwothreeonetwothree";
			int Arg1 = 86;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EqualSubstrings2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
