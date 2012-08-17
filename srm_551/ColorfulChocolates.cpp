// BEGIN CUT HERE
/*
// SRM 551 Div1 Easy (250)

// PROBLEM STATEMENT
// Beaver Bindu has some chocolates arranged in a row.
The wrapping of each chocolate has a single color.
Multiple chocolates can share the same color.
In this problem, each of the possible colors is represented by an uppercase letter.
You are given a string chocolates.
For each i, the i-th chocolate (0-based index) in the row has the color chocolates[i].

The spread of a row of chocolates is the maximum number of adjacent chocolates
that all share the same color.
Formally, the spread can be defined as the maximum value of (j-i+1),
where i <= j and all the chocolates in the positions between i and j,
inclusive, have the same color.

You are also given an int maxSwaps.
Bindu can swap any two adjacent chocolates.
She has decided to make at most maxSwaps such swaps.

Return the maximum spread she can obtain.

DEFINITION
Class:ColorfulChocolates
Method:maximumSpread
Parameters:string, int
Returns:int
Method signature:int maximumSpread(string chocolates, int maxSwaps)

CONSTRAINTS
-chocolates will contain between 1 and 50 characters, inclusive.
-Each character in chocolates will be an uppercase letter ('A'-'Z').
-maxSwaps will be between 1 and 2500, inclusive.


EXAMPLES

0)
"ABCDCBC"
1

Returns: 2

One optimal solution is to swap chocolates at positions 2 and 3, obtaining
the row "ABDCCBC", which has spread 2.


1)
"ABCDCBC"
2

Returns: 3

The only optimal solution is to produce the row "ABDCCCB".


2)
"ABBABABBA"
3

Returns: 4

The row "ABBBBAABA" can be produced with 3 swaps.


3)
"ABBABABBA"
4

Returns: 5

An optimal solution is to produce the row "AABBBBBAA".


4)
"QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO"
77

Returns: 5

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

class ColorfulChocolates {

public:
	int maximumSpread(string chocolates, int maxSwaps) {
		int sz = (int)chocolates.length();
		int res = 0;
		int C, i, j, k, p, q, r, s, a, b;
		for (C = 'A'; C <= 'Z'; ++C) {
			int cnt = 0;
			int pos[50];
			for (i = 0; i < sz; ++i) {
				if (chocolates[i] == C) {
					pos[cnt++] = i;
				}
			}
			for (i = 0; i < cnt; ++i) {
				a = pos[i] - 1;
				b = pos[i] + 1;
				r = maxSwaps;
				j = i-1;
				k = i+1;
				s = 1;
				while (true) {
					p = 9999, q = 9999;
					if (j >= 0) {
						p = a - pos[j];
					}
					if (k < cnt) {
						q = pos[k] - b;
					}
					if (p < q) {
						if (r < p) {
							break;
						}
						r -= p;
						++s;
						--a;
						--j;
					} else if (q < 9999) {
						if (r < q) {
							break;
						}
						r -= q;
						++s;
						++b;
						++k;
					} else {
						break;
					}
				}
				res = max(res, s);
			}
		}
		return res;
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
			string Arg0 = "ABCDCBC";
			int Arg1 = 1;
			int Arg2 = 2;

			verify_case(n, Arg2, maximumSpread(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCDCBC";
			int Arg1 = 2;
			int Arg2 = 3;

			verify_case(n, Arg2, maximumSpread(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABBABABBA";
			int Arg1 = 3;
			int Arg2 = 4;

			verify_case(n, Arg2, maximumSpread(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABBABABBA";
			int Arg1 = 4;
			int Arg2 = 5;

			verify_case(n, Arg2, maximumSpread(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO";
			int Arg1 = 77;
			int Arg2 = 5;

			verify_case(n, Arg2, maximumSpread(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ColorfulChocolates ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
