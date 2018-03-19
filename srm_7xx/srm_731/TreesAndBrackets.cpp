// BEGIN CUT HERE
/*
SRM 731 Div1 Easy (250)

PROBLEM STATEMENT
This problem is about rooted trees in which the order of children matters.
This type of trees is easily encoded using correct bracket sequences.
The code of a tree rooted at r is constructed as follows:

Write down the opening bracket '('.
For each child c of r, in order, write down the code of the subtree rooted at c.
Write down the closing bracket ')'.

For example, the code of a three-vertex tree in which the root has two children is "(()())".

You are given the strings t1 and t2 that represent two rooted trees using the encoding defined above.
You want to transform t1 into t2.

The only operation you are allowed to perform is to remove a leaf from t1.
(A leaf is a vertex with no children.)
Note that removing the child of a parent does not change the relative order of the other children of that same parent.

Return "Possible" if there is a sequence of zero or more operations that transforms t1 into t2.
Otherwise, return "Impossible".


DEFINITION
Class:TreesAndBrackets
Method:check
Parameters:string, string
Returns:string
Method signature:string check(string t1, string t2)


CONSTRAINTS
-t1 and t2 will contain between 2 and 100 characters, inclusive.
-Each character in t1 and t2 will be either '(' or ')'.
-Both t1 and t2 will represent a correct tree.


EXAMPLES

0)
"(())"
"()"

Returns: "Possible"


1)
"()"
"()"

Returns: "Possible"


2)
"(()()())"
"((()))"

Returns: "Impossible"

Currently t1 is a tree of depth 2 in which the root has three children, while t2 is a tree of depth 3.
Clearly, you cannot increase the depth of a tree by removing some of its vertices.


3)
"((())((())())())"
"(()(())())"

Returns: "Possible"


4)
"((())((())())())"
"((()()()()()))"

Returns: "Impossible"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class TreesAndBrackets {

	vector<string> split(string s) {
		vector<string> r;
		string x;
		int level = 0;
		for (char c : s) {
			x += c;
			level += c == '(' ? 1 : -1;
			if (level == 0) {
				r.push_back(x.substr(1, x.length() - 2));
				x.clear();
			}
		}
		return r;
	}

	bool dfs(string t1, string t2) {
		if (t2.empty()) {
			return true;
		}
		if (t1.empty()) {
			return false;
		}
		vector<string> al = split(t1);
		vector<string> ar = split(t2);
		int left = -1;
		for (int right = 0; right < (int)ar.size(); ++right) {
			while (++left < (int)al.size() && !dfs(al[left], ar[right])) {
				;
			}
			if (left >= (int)al.size()) {
				return false;
			}
		}
		return true;
	}

public:
	string check(string t1, string t2) {
		return dfs(t1, t2) ? "Possible" : "Impossible";
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
			string Arg0 = "(())";
			string Arg1 = "()";
			string Arg2 = "Possible";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "()";
			string Arg1 = "()";
			string Arg2 = "Possible";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "(()()())";
			string Arg1 = "((()))";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "((())((())())())";
			string Arg1 = "(()(())())";
			string Arg2 = "Possible";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "((())((())())())";
			string Arg1 = "((()()()()()))";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TreesAndBrackets ___test;
	___test.run_test(-1);
}
// END CUT HERE
