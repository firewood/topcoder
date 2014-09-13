// BEGIN CUT HERE
/*
SRM 621 Div2 Easy (250)

PROBLEM STATEMENT

	Sasha has a vector <string> stringList. No two elements of stringList have the same length.
	So far, Sasha has learned two ways of sorting strings:
		He can sort strings lexicographically. For example, "car" < "carriage" < "cats" < "doggies". (See Notes for a definition of the lexicographic order.)
		He can also sort strings according to their lengths in ascending order. For example, "car" < "cats" < "doggies" < "carriage".
	Sasha now wonders whether stringList is sorted in either of these two ways. Return "lexicographically" (quotes for clarity) if stringList is sorted lexicographically but not according to the string lengths. Return "lengths" if stringList is sorted according to the string lengths but not lexicographically. Return "both" if it is sorted in both ways. Otherwise, return "none".


DEFINITION
Class:TwoWaysSorting
Method:sortingMethod
Parameters:vector <string>
Returns:string
Method signature:string sortingMethod(vector <string> stringList)


NOTES
-String A is lexicographically smaller than string B if A contains a character with a smaller ASCII value in the first position where they differ. In case one of the strings ends before they have a different character, the shorter one is considered smaller.


CONSTRAINTS
-stringList will contain between 1 and 50 elements, inclusive.
-Each element of stringList will contain between 1 and 50 characters, inclusive.
-Each character of each element of stringList will be a lowercase English letter ('a'-'z').
-Every two elements of stringList will have different lengths.


EXAMPLES

0)
{"a", "aa", "bbb"}

Returns: "both"

These strings are sorted both lexicographically and according to their lengths.


1)
{"c", "bb", "aaa"}

Returns: "lengths"

The lengths of these strings are in ascending order. However, they are not sorted lexicographically as, for instance, "aaa" is lexicographically smaller than "c".


2)
{"etdfgfh", "aio"}

Returns: "none"

Here the first string is longer than the second one, so they are not sorted according to length. (Note that we require the lengths to be in ascending order.) Similarly, they are not sorted lexicographically: "aio" should come before "etdfgfh".


3)
{"aaa", "z"}

Returns: "lexicographically"

The input strings are sorted lexicographically only.


4)
{"z"}

Returns: "both"


5)
{"abcdef", "bcdef", "cdef", "def", "ef", "f", "topcoder"}

Returns: "lexicographically"

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TwoWaysSorting {
public:
	string sortingMethod(vector <string> stringList) {
		vector <string> a = stringList;
		sort(a.begin(), a.end());
		int lex = a == stringList;
		vector<pair<int, string> >v;
		for (int i = 0; i < (int)stringList.size(); ++i) {
			v.push_back(make_pair(stringList[i].length(), stringList[i]));
		}
		sort(v.begin(), v.end());
		a.clear();
		for (int i = 0; i < (int)stringList.size(); ++i) {
			a.push_back(v[i].second);
		}
		int len = a == stringList;
		if (lex && len) {
			return "both";
		}
		if (lex) {
			return "lexicographically";
		}
		if (len) {
			return "lengths";
		}
		return "none";
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
			string Arr0[] = {"a", "aa", "bbb"};
			string Arg1 = "both";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, sortingMethod(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"c", "bb", "aaa"};
			string Arg1 = "lengths";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, sortingMethod(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"etdfgfh", "aio"};
			string Arg1 = "none";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, sortingMethod(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"aaa", "z"};
			string Arg1 = "lexicographically";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, sortingMethod(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"z"};
			string Arg1 = "both";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, sortingMethod(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"abcdef", "bcdef", "cdef", "def", "ef", "f", "topcoder"};
			string Arg1 = "lexicographically";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, sortingMethod(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TwoWaysSorting ___test;
	___test.run_test(-1);
}
// END CUT HERE
