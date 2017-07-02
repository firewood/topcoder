// BEGIN CUT HERE
/*
SRM 717 Div2 Easy (250)

PROBLEM STATEMENT

You are given a vector <string> t that describes a rectangular table of zeroes and ones.
Each character in t is either '0' or '1'.

We say that a table is nice if there are two sequences x, y of zeroes and ones such that for each valid pair of indices i, j we have t[i][j] = x[i] xor y[j].

Some technical remarks:

The number of elements in x should be equal to the number of rows of the table, i.e., the number of elements in t.
The number of elements in y should be equal to the number of columns of the table, i.e., the length of each string in t.
The operation xor (exclusive or) is defined as follows: 0 xor 0 = 0, 1 xor 1 = 0, 0 xor 1 = 1, and 1 xor 0 = 1.

Verify whether the given table is nice.
Return "Nice" if it is nice and "Not nice" otherwise.
Note that the return value is case-sensitive.


DEFINITION
Class:NiceTable
Method:isNice
Parameters:vector <string>
Returns:string
Method signature:string isNice(vector <string> t)


CONSTRAINTS
-t will contain between 1 and 5 elements, inclusive.
-Each element of t will contain between 1 and 5 characters, inclusive.
-All elements of t will contain the same number of characters.
-Each element of t will consist only of characters '0' and '1'.


EXAMPLES

0)
{"01",
 "10"}

Returns: "Nice"

One valid choice is to choose x = y = {1, 0}.


1)
{"01",
 "11"}

Returns: "Not nice"


Assume that t is nice.
The sequences x and y have to satisfy the following constraints:

x[0] xor y[0] = 0
x[0] xor y[1] = 1
x[1] xor y[0] = 1
x[1] xor y[1] = 1


From the first constraint we see that x[0] = y[0].
From the second and the third constraint we can then derive that we must also have x[1] = y[1].
But then the fourth constraint is not satisfied, which is a contradiction.
Therefore, this t is not nice.


2)
{"0100",
 "1011",
 "0100"}

Returns: "Nice"

Here, one valid choice is x = {1, 0, 1} and y = {1, 0, 1, 1}.


3)
{"11",
 "10",
 "11",
 "11",
 "11"}

Returns: "Not nice"

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

class NiceTable {
	bool nice(vector <string> t) {
		int h = (int)t.size(), w = (int)t[0].length();
		for (int x = 0; x != (1 << h); ++x) {
			for (int y = 0; y != (1 << w); ++y) {
				bool f = true;
				for (int i = 0; i < h; ++i) {
					for (int j = 0; j < w; ++j) {
						if ((((x >> i) ^ (y >> j)) & 1) != (t[i][j] - '0')) {
							f = false;
						}
					}
				}
				if (f) {
					return true;
				}
			}
		}
		return false;
	}

public:
	string isNice(vector <string> t) {
		return nice(t) ? "Nice" : "Not nice";
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
			string Arr0[] = {"01",
 "10"};
			string Arg1 = "Nice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isNice(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"01",
 "11"};
			string Arg1 = "Not nice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isNice(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0100",
 "1011",
 "0100"};
			string Arg1 = "Nice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isNice(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"11",
 "10",
 "11",
 "11",
 "11"};
			string Arg1 = "Not nice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isNice(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NiceTable ___test;
	___test.run_test(-1);
}
// END CUT HERE
