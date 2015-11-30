// BEGIN CUT HERE
/*
SRM 670 Div2 Medium (450)

PROBLEM STATEMENT
A plus/minus string is a string in which each character is either a '+' or a '-'.
The balance of a plus/minus string is computed as the number of '+' characters minus the number of '-' characters.
For example, the balance of the string "++-+" is 3-1 = 2, and the balance of the string "---" is 0-3 = -3.

The prefix of a string S is any string that can be obtained by removing some (possibly none, possibly all) characters from the end of S.
For example, the prefixes of the string "++-+" are the strings "++-+", "++-", "++", "+", and "".

Given a plus/minus string, its negativity is the number of its prefixes that have a negative balance.
For example, the negativity of the string "++-+" is 0, as none of its prefixes have a negative balance.
The negativity of the string "---" is 3.
Its three prefixes with a negative balance are "-", "--", and "---".

You are given a string s that is a plus/minus string.
You are also given an int k.
Your goal is to change s into a string with negativity at most k.
In other words, you want to change s into a string that has at most k prefixes that have a negative balance.

In order to change s you are going to perform a sequence of zero or more steps.
In each step you can change a single '-' character in s into a '+' or vice versa.
Compute and return the smallest number of steps needed.


DEFINITION
Class:Drbalance
Method:lesscng
Parameters:string, int
Returns:int
Method signature:int lesscng(string s, int k)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-k will be between 0 and the length of s, inclusive.
-Each character in s will be either '+' or '-'.


EXAMPLES

0)
"---"
1

Returns: 1

One step is sufficient.
If we change character 0 of s into a '+', we will obtain the string "+--".
This string has only one prefix with a negative balance - namely, the entire string "+--".
As k=1, we have reached our goal.


1)
"+-+-"
0

Returns: 0


2)
"-+-+---"
2

Returns: 1


3)
"-------++"
3

Returns: 3


4)
"-+--+--+--++++----+"
3

Returns: 2

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Drbalance {

	int check(string s) {
		int cnt[2] = {};
		int neg = 0;
		for (int i = 0; i != s.length(); ++i) {
			cnt[s[i] == '+'] += 1;
			neg += cnt[0] > cnt[1];
		}
		return neg;
	}

public:
	int lesscng(string s, int k) {
		int ans = 0;
		for (int i = 0; check(s) > k && i != s.length(); ++i) {
			if (s[i] == '-') {
				++ans;
				s[i] = '+';
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
			string Arg0 = "---";
			int Arg1 = 1;
			int Arg2 = 1;

			verify_case(n, Arg2, lesscng(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "+-+-";
			int Arg1 = 0;
			int Arg2 = 0;

			verify_case(n, Arg2, lesscng(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "-+-+---";
			int Arg1 = 2;
			int Arg2 = 1;

			verify_case(n, Arg2, lesscng(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "-------++";
			int Arg1 = 3;
			int Arg2 = 3;

			verify_case(n, Arg2, lesscng(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "-+--+--+--++++----+";
			int Arg1 = 3;
			int Arg2 = 2;

			verify_case(n, Arg2, lesscng(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE
};

// BEGIN CUT HERE
int main() {
	Drbalance ___test;
	___test.run_test(-1);
}
// END CUT HERE
