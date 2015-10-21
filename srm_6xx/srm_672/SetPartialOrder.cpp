// BEGIN CUT HERE
/*
SRM 672 Div2 Easy (250)

PROBLEM STATEMENT
In math, we sometimes define a partial order on some objects.
In this problem we will take a look at one possible way how to define a partial order on sets of integers.

Consider two sets of integers: X and Y.
These two sets can be related to each other in four possible ways:

X is equal to Y if each element of X is also an element of Y and vice versa.
X is less than Y if X is not equal to Y (see previous item) and each element of X is also an element of Y.
X is greater than Y if Y is less than X.
In all other cases X and Y are incomparable.

In other words:
X is less than Y if and only if X is a proper subset of Y.
Two sets are incomparable if neither is a subset of the other.

You are given two vector <int>s a and b.
The elements of a form the set X.
The elements of b form the set Y.
Compare X to Y and return the correct one of the following four strings: "EQUAL", "LESS", "GREATER", or "INCOMPARABLE".

(The string "LESS" means that X is less than Y, the string "GREATER" means that X is greater than Y.
Quotes are for clarity only.
Note that the return value is case-sensitive.)


DEFINITION
Class:SetPartialOrder
Method:compareSets
Parameters:vector <int>, vector <int>
Returns:string
Method signature:string compareSets(vector <int> a, vector <int> b)


CONSTRAINTS
-Each of arrays a and b will have length between 1 and 50, inclusive.
-Each element of arrays a and b will be between 1 and 100, inclusive.
-In each of arrays a and b all elements are distinct.


EXAMPLES

0)
{1, 2, 3, 5, 8}
{8, 5, 1, 3, 2}

Returns: "EQUAL"

The order of elements in a and b does not matter. The two sets X and Y are equal.


1)
{2, 3, 5, 7}
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

Returns: "LESS"

Each number that occurs in a does also occur in b.


2)
{2, 4, 6, 8, 10, 12, 14, 16}
{2, 4, 8, 16}

Returns: "GREATER"


3)
{42, 23, 17}
{15, 23, 31}

Returns: "INCOMPARABLE"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class SetPartialOrder {
public:
	string compareSets(vector <int> a, vector <int> b) {
		int cnt[128] = {};
		for (int c : a) {
			cnt[c] += 1;
		}
		for (int c : b) {
			cnt[c] -= 1;
		}
		int f = 0;
		for (int i = 0; i < 128; ++i) {
			if (cnt[i]) {
				if (!f) {
					f = cnt[i];
				} else if ((cnt[i] > 0) != (f > 0)) {
					return "INCOMPARABLE";
				}
			}
		}
		if (f > 0) {
			return "GREATER";
		}
		if (f < 0) {
			return "LESS";
		}
		return "EQUAL";
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
			int Arr0[] = {1, 2, 3, 5, 8};
			int Arr1[] = {8, 5, 1, 3, 2};
			string Arg2 = "EQUAL";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, compareSets(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 3, 5, 7};
			int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			string Arg2 = "LESS";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, compareSets(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 4, 6, 8, 10, 12, 14, 16};
			int Arr1[] = {2, 4, 8, 16};
			string Arg2 = "GREATER";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, compareSets(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {42, 23, 17};
			int Arr1[] = {15, 23, 31};
			string Arg2 = "INCOMPARABLE";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, compareSets(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 1 };
			int Arr1[] = { 2 };
			string Arg2 = "INCOMPARABLE";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, compareSets(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SetPartialOrder ___test;
	___test.run_test(-1);
}
// END CUT HERE
