// BEGIN CUT HERE
/*
SRM 670 Div1 Easy (250)

PROBLEM STATEMENT
Correct bracket sequences are strings in which each character is a '(' or a ')',
the total number of opening brackets is the same as the total number of closing brackets,
and each prefix contains at least as many opening as closing brackets.
For example, the shortest few correct bracket sequences are "", "()", "(())", and "()()".

The subsequence of a string S is any string that can be obtained by erasing zero or more characters of S.
For example, each of the strings "", "ace", and "abcde" is a subsequence of "abcde".

We will use LCS(S,T) to denote the length of a longest common subsequence of strings S and T.
In other words, LCS(S,T) is the largest k such that there is a string U of length k that is both a subsequence of S and a subsequence of T.
For example, LCS("abcde","bad") = 2.

You are given a string s that contains a correct bracket sequence.
You are looking for a string t with the following properties:

t will have the same length as s,
t will be a correct bracket sequence,
t will not be equal to s,
LCS(s,t) will be as large as possible.

Compute and return the number of strings with these properties.


DEFINITION
Class:Bracket107
Method:yetanother
Parameters:string
Returns:int
Method signature:int yetanother(string s)


NOTES
-You may assume that the answer for each valid test case fits into a signed 32-bit integer variable.


CONSTRAINTS
-s will contain between 4 and 50 characters, inclusive.
-Each character in s will be either '(' or ')'.
-s will be a correct bracket sequence.


EXAMPLES

0)
"(())"

Returns: 1

There is only one other correct bracket sequence of the same length.


1)
"(())()"

Returns: 3

There are four other correct bracket sequences of the same length: "((()))", "()(())", "()()()", and "(()())".
However, only in three of those four cases the length of the longest common subsequence is 5.
LCS( "(())()", "()(())" ) is only 4, therefore "()(())" is not a valid choice of the string t.


2)
"()()()"

Returns: 3


3)
"(((())))"

Returns: 5


4)
"((())())"

Returns: 9

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Bracket107 {

	bool check(string s) {
		int cnt = 0;
		for (char c : s) {
			if (c == '(') {
				++cnt;
			} else if (--cnt < 0) {
				return false;
			}
		}
		return true;
	}

public:
	int yetanother(string s) {
		set<string> m;
		int len = s.length();
		for (int i = 1; i < len - 1; ++i) {
			string a = s.substr(0, i) + s.substr(i + 1);
			for (int j = 1; j < len - 1; ++j) {
				string b = a.substr(0, j) + s[i] + a.substr(j);
				if (check(b)) {
					m.insert(b);
				}
			}
		}
		return m.size() - 1;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) {
		cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "(())";
			int Arg1 = 1;

			verify_case(n, Arg1, yetanother(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "(())()";
			int Arg1 = 3;

			verify_case(n, Arg1, yetanother(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "()()()";
			int Arg1 = 3;

			verify_case(n, Arg1, yetanother(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "(((())))";
			int Arg1 = 5;

			verify_case(n, Arg1, yetanother(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "((())())";
			int Arg1 = 9;

			verify_case(n, Arg1, yetanother(Arg0));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Bracket107 ___test;
	___test.run_test(-1);
}
// END CUT HERE
