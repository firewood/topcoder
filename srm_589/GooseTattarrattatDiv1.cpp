// BEGIN CUT HERE
/*
SRM 589 Div1 Easy (250)

PROBLEM STATEMENT
Goose Tattarrattat has a string S of lowercase letters.
Tattarrattat wants to change her string into a palindrome: a string that reads the same forwards and backwards.
(For example, "racecar" is a palindrome.)

She will do this in a series of steps.
In each step, Tattarrattat will choose two letters of the alphabet: X and Y.
She will then change each X in her string into a Y.
Changing each single character takes 1 second.

For example, if S="goose" and Tattarrattat chooses X='o' and Y='e' in the next step, the step will take 2 seconds (because there are two 'o's in S) and after the step she would have S="geese".

You are given the string S.
Return the smallest number of seconds in which Tattarrattat can change S into a palindrome.


DEFINITION
Class:GooseTattarrattatDiv1
Method:getmin
Parameters:string
Returns:int
Method signature:int getmin(string S)


NOTES
-Tattarrattat must always change all occurrences of the chosen letter into the other one; she is not allowed to change only some of the occurrences.


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-Each character in S will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"geese"

Returns: 2

There are many ways how Tattarrattat can change this S into a palindrome.
For example, she could do it in two steps as follows:

Change all 'g's to 'e's: this takes 1 second and produces the string "eeese".
Change all 'e's to 's's: this takes 4 seconds and produces the string "sssss".

This way took her 1+4 = 5 seconds.
However, there are faster ways.
The best one only takes 2 seconds.
For example, she can first change all 'g's to 'e's (1 second), and then change all 's's to 'e's (1 second), obtaining the palindrome "eeeee".


1)
"tattarrattat"

Returns: 0

This string is already a palindrome so no changes are needed.


2)
"xyyzzzxxx"

Returns: 2


3)
"xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag"

Returns: 11


4)
"abaabb"

Returns: 3

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] >= _size[rb]) { _parent[rb] = ra, _size[ra] += _size[rb]; }
		else { _parent[ra] = rb, _size[rb] += _size[ra]; }
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

class GooseTattarrattatDiv1 {

public:
	int getmin(string S) {
		int ans = 0;
		int len = (int)S.length();
		UnionFind u(len);
		for (int i = 0; i < len; ++i) {
			u.unite(i, len-i-1);
			for (int j = i+1; j < len; ++j) {
				if (S[i] == S[j]) {
					u.unite(i, j);
				}
			}
		}
		for (int i = 0; i < len; ++i) {
			if (u.root(i) == i) {
				int m = 0;
				int cnt[256] = {};
				for (int j = 0; j < len; ++j) {
					if (u.root(j) == i) {
						m = max(m, ++cnt[S[j]]);
					}
				}
				ans += u.size(i) - m;
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
			string Arg0 = "geese";
			int Arg1 = 2;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "tattarrattat";
			int Arg1 = 0;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "xyyzzzxxx";
			int Arg1 = 2;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag";
			int Arg1 = 11;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abaabb";
			int Arg1 = 3;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;


		// 5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcdefghijklmnopqrstuvwxy zyxwvutsrqponmlkjihgfedcb";
			int Arg1 = 48;
			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GooseTattarrattatDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
