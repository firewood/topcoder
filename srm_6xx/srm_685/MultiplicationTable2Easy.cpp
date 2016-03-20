// BEGIN CUT HERE
/*
SRM 685 Div2 Easy (250)

PROBLEM STATEMENT
Fox Ciel is creating a new binary operation.

The operation will be denoted $ and it will be defined on the finite set S = {0, 1, 2, ..., n-1}.
I.e., for each ordered pair (i, j) of elements of S the operation (i $ j) will return some element of S.

For example, we can have S = {0, 1}, and we can define that (0 $ 0) = 0, (0 $ 1) = 1, (1 $ 0) = 0, and (1 $ 1) = 0.

Note that Ciel's operation is not necessarily symmetric.
In other words, it is possible that for some i and j the operations (i $ j) and (j $ i) return two different values.

A nice concise description of the operation $ is its "multiplication table": a square table where in row i and column j we have the value (i $ j).
You are given this "multiplication table" encoded as a vector <int> table with n^2 elements.
For each valid i and j the operation (i $ j) returns the value table[i*n+j].

A subset T of S is called good if it has the following property:
for any two elements i and j in T, (i $ j) is also in T.

You are given a vector <int> t.
The elements of t form a subset of the set S.
Return "Good" (quotes for clarity) if this subset is good.
Otherwise, return "Not Good".
Note that the return value is case-sensitive.


DEFINITION
Class:MultiplicationTable2Easy
Method:isGoodSet
Parameters:vector <int>, vector <int>
Returns:string
Method signature:string isGoodSet(vector <int> table, vector <int> t)


NOTES
-You are not given the value of n explicitly. Instead, you can determine it as the square root of the number of elements in table.


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-table will contain exactly n*n elements.
-Each element in table will be between 0 and n-1, inclusive.
-t will contain between 1 and n elements, inclusive.
-Each element in t will be between 0 and n-1, inclusive.
-Elements in t will be distinct.


EXAMPLES

0)
{1, 1, 2, 3,
 1, 0, 2, 3,
 3, 3, 0, 3,
 2, 2, 2, 0}

{1,0}

Returns: "Good"

We can verify:

0 $ 0 = 1
0 $ 1 = 1
1 $ 0 = 1
1 $ 1 = 0


1)
{1, 1, 2, 3,
 1, 0, 2, 3,
 3, 3, 0, 3,
 2, 2, 2, 0}
{2, 3}

Returns: "Not Good"

Note that: 2 $ 2 = 0 but 0 is not in T, so it is not good.


2)
{1, 1, 2, 3,
 1, 0, 2, 3,
 3, 3, 0, 3,
 2, 2, 2, 0}

{0,1,2,3}

Returns: "Good"


3)
{1, 1, 2, 3,
 1, 0, 2, 3,
 3, 3, 0, 3,
 2, 2, 2, 0}

{1}

Returns: "Not Good"


4)
{2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2}
{2,4,5}

Returns: "Good"


5)
{2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2}
{0,1,3,4,5}

Returns: "Not Good"

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class MultiplicationTable2Easy {
public:
	string isGoodSet(vector <int> table, vector <int> t) {
		int N = (int)sqrt(table.size() + 0.1);
		set<int> s(t.begin(), t.end());
		for (int i : t) {
			for (int j : t) {
				if (s.find(table[i * N + j]) == s.end()) {
					return "Not Good";
				}
			}
		}
		return "Good";
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
			int Arr0[] = {1, 1, 2, 3,
 1, 0, 2, 3,
 3, 3, 0, 3,
 2, 2, 2, 0}
;
			int Arr1[] = {1,0};
			string Arg2 = "Good";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isGoodSet(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 2, 3,
 1, 0, 2, 3,
 3, 3, 0, 3,
 2, 2, 2, 0};
			int Arr1[] = {2, 3};
			string Arg2 = "Not Good";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isGoodSet(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 2, 3,
 1, 0, 2, 3,
 3, 3, 0, 3,
 2, 2, 2, 0}
;
			int Arr1[] = {0,1,2,3};
			string Arg2 = "Good";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isGoodSet(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 2, 3,
 1, 0, 2, 3,
 3, 3, 0, 3,
 2, 2, 2, 0}
;
			int Arr1[] = {1};
			string Arg2 = "Not Good";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isGoodSet(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2};
			int Arr1[] = {2,4,5};
			string Arg2 = "Good";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isGoodSet(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2,
 2,2,2,2,2,2};
			int Arr1[] = {0,1,3,4,5};
			string Arg2 = "Not Good";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isGoodSet(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MultiplicationTable2Easy ___test;
	___test.run_test(-1);
}
// END CUT HERE
