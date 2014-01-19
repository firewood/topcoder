// BEGIN CUT HERE
/*
SRM 593 Div2 Easy (250)

PROBLEM STATEMENT
The pony Applejack is going to raise a new barn.
The barn will consist of N sections in a row.
Some of the sections will be empty, others will contain a single cow each.
You are given a string str with N characters.
This string describes the desired layout of the barn:
the character 'c' represents a section with a cow, and the character '.' represents an empty section.

After she raises the barn, Applejack will build a wall that will divide the barn into two separate parts:
one containing the first k sections and the other containing the last N-k sections, for some integer k.
Each part must contain at least one section. (I.e., k must be between 1 and N-1, inclusive.)
Additionally, Applejack wants both parts to contain exactly the same number of cows.

Return the number of possible positions for the wall.
In other words, return the number of choices for the integer k such that all the conditions above are satisfied.

DEFINITION
Class:RaiseThisBarn
Method:calc
Parameters:string
Returns:int
Method signature:int calc(string str)


CONSTRAINTS
-str will contain between 2 and 50 characters, inclusive.
-Each character in str will be 'c' or '.'.


EXAMPLES

0)
"cc..c.c"

Returns: 3

Applejack can choose k=2, k=3, or k=4.
The three corresponding solutions are shown below, with '|' representing the wall between the two parts.

cc|..c.c
cc.|.c.c
cc..|c.c


1)
"c....c....c"

Returns: 0

There is an odd number of cows. It is impossible to divide them into two equal halves.


2)
"............"

Returns: 11

This is a barn with 12 empty sections. It can be divided in 11 different ways: into 1+11 sections, 2+10 sections, ..., or 11+1 sections.


3)
".c.c...c..ccc.c..c.c.cc..ccc"

Returns: 3

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class RaiseThisBarn {

	int count(string s)
	{
		int cow = 0;
		for (int i = 0; i < (int)s.length(); ++i) {
			if (s[i] == 'c') {
				++cow;
			}
		}
		return cow;
	}

public:
	int calc(string str) {
		int ans = 0;
		for (int i = 1; i < (int)str.length(); ++i) {
			int cl = count(str.substr(0, i));
			int cr = count(str.substr(i));
			if (cl == cr) {
				++ans;
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
			string Arg0 = "cc..c.c";
			int Arg1 = 3;

			verify_case(n, Arg1, calc(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "c....c....c";
			int Arg1 = 0;

			verify_case(n, Arg1, calc(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "............";
			int Arg1 = 11;

			verify_case(n, Arg1, calc(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = ".c.c...c..ccc.c..c.c.cc..ccc";
			int Arg1 = 3;

			verify_case(n, Arg1, calc(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RaiseThisBarn ___test;
	___test.run_test(-1);
}
// END CUT HERE
