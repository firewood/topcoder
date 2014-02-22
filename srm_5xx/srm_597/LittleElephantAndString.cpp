// BEGIN CUT HERE
/*
SRM 597 Div1 Easy (250)

PROBLEM STATEMENT

Little Elephant from the Zoo of Lviv likes strings.

You are given a string A and a string B of the same length.
In one turn Little Elephant can choose any character of A and move it to the beginning of the string (i.e., before the first character of A).
Return the minimal number of turns needed to transform A into B. If it's impossible, return -1 instead.


DEFINITION
Class:LittleElephantAndString
Method:getNumber
Parameters:string, string
Returns:int
Method signature:int getNumber(string A, string B)


CONSTRAINTS
-A will contain between 1 and 50 characters, inclusive.
-B will contain between 1 and 50 characters, inclusive.
-A and B will be of the same length.
-A and B will consist of uppercase letters ('A'-'Z') only.


EXAMPLES

0)
"ABC"
"CBA"

Returns: 2

The optimal solution is to make two turns.
On the first turn, choose character 'B' and obtain string "BAC".
On the second turn, choose character 'C' and obtain "CBA".


1)
"A"
"B"

Returns: -1

In this case, it's impossible to transform A into B.


2)
"AAABBB"
"BBBAAA"

Returns: 3


3)
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"ZYXWVUTSRQPONMLKJIHGFEDCBA"

Returns: 25


4)
"A"
"A"

Returns: 0


5)
"DCABA"
"DACBA"

Returns: 2

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class LittleElephantAndString {
public:
	int getNumber(string A, string B) {
		string a = A, b = B;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		if (a != b) {
			return -1;
		}

		int ans = 0;
		int len = (int)A.length();

		int p = len - 1;
		int q = len - 1;
		while (p >= 0 && q >= 0) {
			char c = A[p--];
			if (c == B[q]) {
				--q;
				continue;
			}
			++ans;
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
			string Arg0 = "ABC";
			string Arg1 = "CBA";
			int Arg2 = 2;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "A";
			string Arg1 = "B";
			int Arg2 = -1;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAABBB";
			string Arg1 = "BBBAAA";
			int Arg2 = 3;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string Arg1 = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
			int Arg2 = 25;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "A";
			string Arg1 = "A";
			int Arg2 = 0;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "DCABA";
			string Arg1 = "DACBA";
			int Arg2 = 2;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "BCDEFA";
			string Arg1 = "ABCDEF";
			int Arg2 = 1;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "BACDEF";
			string Arg1 = "ABCDEF";
			int Arg2 = 1;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "FABDEC";
			string Arg1 = "ABCDEF";
			int Arg2 = 5;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "FAFBCD";
			string Arg1 = "ABCDFF";
			int Arg2 = 4;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LittleElephantAndString ___test;
	___test.run_test(-1);

}
// END CUT HERE
