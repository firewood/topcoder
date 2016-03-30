// BEGIN CUT HERE
/*
SRM 686 Div1 Easy (250)

PROBLEM STATEMENT

Correct bracket sequences can be defined recursively as follows:

The empty string "" is a correct sequence.
If "X" and "Y" are correct sequences, then "XY" (the concatenation of X and Y) is a correct sequence.
If "X" is a correct sequence, then "(X)" and "[X]" are also correct sequences.
Each correct bracket sequence can be derived using the above rules.

Examples of correct bracket sequences include "", "()", "()[][]", "([]())", and "([[()]])".

You are given a string s that only contains the characters '(', ')', '[', and ']'.
We want to erase some subset of characters of s (possibly none of them, but not all of them).
Moreover, we want to do it in such a way that the resulting string will be a correct non-empty bracket sequence.
Compute and return the number of ways in which this can be done.


DEFINITION
Class:BracketSequenceDiv1
Method:count
Parameters:string
Returns:long long
Method signature:long long count(string s)


CONSTRAINTS
-s will contain between 1 and 40 characters, inclusive.
-Each character in s will be one of '(', ')', '[', ']'.


EXAMPLES

0)
"()[]"

Returns: 3

There are 3 valid ways to erase some characters and obtain a correct non-empty bracket sequence:

Erase nothing and obtain "()[]".
Erase the first two characters and obtain "[]".
Erase the last two characters and obtain "()".


1)
"())"

Returns: 2

Here we have 2 solutions: we can either erase the middle character or the last character.
Note that we count each of those ways separately, even though in both cases we get the same string "()".


2)
"()()"

Returns: 4


3)
"([)]"

Returns: 2


4)
"())[]][]([]()]]()]]]"

Returns: 3854

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
typedef map<LL, LL> LLMap;

class BracketSequenceDiv1 {
	LLMap m[2];

	static string reversed(string s) {
		string r;
		for (int i = (int)s.length() - 1; i >= 0; --i) {
			switch (s[i]) {
			case '(': r += ')'; break;
			case ')': r += '('; break;
			case '[': r += ']'; break;
			case ']': r += '['; break;
			}
		}
		return r;
	}

	static void gen(LLMap &m, string s) {
		int len = (int)s.length();
		int mx = 1 << len;
		for (int b = 0; b < mx; ++b) {
			LL t = 0;
			for (int i = 0; i < len; ++i) {
				if ((1 << i) & b) {
					if (s[i] == ')') {
						if (t == 0 || (t & 3) != 2) {
							t = -1;
							break;
						}
						t >>= 2;
					} else if (s[i] == ']') {
						if (t == 0 || (t & 3) != 3) {
							t = -1;
							break;
						}
						t >>= 2;
					} else if (s[i] == '(') {
						t = (t << 2) | 2;
					} else {
						t = (t << 2) | 3;
					}
				}
			}
			if (t >= 0) {
				m[t] += 1;
			}
		}
	}

public:
	long long count(string s) {
		m[0].clear();
		m[1].clear();
		gen(m[0], s.substr(0, s.length() / 2));
		gen(m[1], reversed(s.substr(s.length() / 2)));

		LL ans = -1;
		LLMap::const_iterator p;
		for (p = m[0].begin(); p != m[0].end(); ++p) {
			ans += p->second * m[1][p->first];
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "()[]";
			long long Arg1 = 3LL;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "())";
			long long Arg1 = 2LL;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "()()";
			long long Arg1 = 4LL;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "([)]";
			long long Arg1 = 2LL;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "())[]][]([]()]]()]]]";
			long long Arg1 = 3854LL;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BracketSequenceDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
