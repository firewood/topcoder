// BEGIN CUT HERE
/*
SRM 834 Div1 Easy (300)

PROBLEM STATEMENT

There are N variables, numbered from 0 to N-1.
These variables are also labeled using the first N uppercase English letters ('A', 'B', 'C', ...).

Each variable represents a string of lowercase English letters ('a'-'z').
Additionally, each variable has a known fixed length: variable i represents a string of length L[i].

A word is a string of lowercase letters.

A pattern is a string that contains variables and lowercase letters.

An assignment is a sequence of N words that represent the values of our variables. (For each i, word i in this sequence must have length L[i].)

Given an assignment, the evaluation of a pattern is the word obtained by replacing each occurrence of each variable by its assigned value.

You are given N, L and the vector <string> patterns.


Determine whether there is an assignment such that all the given patterns evaluate to the same word W.
If yes, return any word W that can be obtained this way.
If no, return an empty string.


DEFINITION
Class:MatchingPatterns
Method:solve
Parameters:int, vector <int>, vector <string>
Returns:string
Method signature:string solve(int N, vector <int> L, vector <string> patterns)


CONSTRAINTS
-N will be between 1 and 26, inclusive.
-L will have exactly N elements.
-Each element of L will be between 1 and 10, inclusive.
-patterns will have between 1 and 5 elements, inclusive.
-Each element of patterns will have between 1 and 50 characters, inclusive.
-Each character in patterns will be either a lowercase English letter ('a'-'z') or one of the first N uppercase English letters.


EXAMPLES

0)
1
{2}
{"AAA"}

Returns: "hehehe"

The valid answers are precisely all strings of the form "xyxyxy" where x and y are any two (not necessarily distinct) lowercase letters.


1)
2
{2, 3}
{"ABxA", "BxxB"}

Returns: "xxxxxxxx"

The returned string is the only correct return value for this test case.


2)
3
{2, 3, 2}
{"ABxA", "yCCB"}

Returns: ""

There is no assignment for which these two patterns evaluate to the same word.


3)
3
{4, 5, 6}
{"A", "B", "C"}

Returns: ""

These three patterns will never evaluate to words of the same length, so they clearly cannot evaluate to the same word.


4)
4
{1, 2, 3, 4}
{"ABCD", "DxAyzB"}

Returns: "yzzzxyyzzz"

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

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] < _size[rb]) swap(ra, rb);
		_parent[rb] = ra, _size[ra] += _size[rb];
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

class MatchingPatterns {
public:
	string solve(int N, vector <int> L, vector <string> patterns) {
		UnionFind uf(2000);
		int pats = (int)patterns.size(), length = -1;
		for (auto pattern : patterns) {
			int len = 0;
			for (char c : pattern) {
				if (c <= 'Z') {
					int i = c - 'A';
					for (int k = 0; k < L[i]; ++k) {
						uf.unite(500 + len++, 1000 + i * 10 + k);
					}
				} else {
					uf.unite(500 + len++, c - 'a');
				}
			}
			if (length >= 0 && length != len) {
				return "";
			}
			length = len;
		}

		for (int i = 0; i < 26; ++i) {
			for (int j = i + 1; j < 26; ++j) {
				if (uf.root(i) == uf.root(j)) {
					return "";
				}
			}
		}

		string ans(length, '-');
		for (int i = 0; i < length; ++i) {
			int ch = -1;
			for (int k = 0; k < 26; ++k) {
				if (uf.root(k) == uf.root(500 + i)) {
					ch = k;
					break;
				}
			}
			if (ch == -1) {
				ch = 0;
				uf.unite(0, 500 + i);
			}
			ans[i] = char('a' + ch);
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {2};
			string Arr2[] = {"AAA"};
			string Arg3 = "hehehe";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {2, 3};
			string Arr2[] = {"ABxA", "BxxB"};
			string Arg3 = "xxxxxxxx";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {2, 3, 2};
			string Arr2[] = {"ABxA", "yCCB"};
			string Arg3 = "";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {4, 5, 6};
			string Arr2[] = {"A", "B", "C"};
			string Arg3 = "";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {1, 2, 3, 4};
			string Arr2[] = {"ABCD", "DxAyzB"};
			string Arg3 = "yzzzxyyzzz";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MatchingPatterns ___test;
	___test.run_test(-1);
}
// END CUT HERE
