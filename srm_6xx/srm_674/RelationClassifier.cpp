// BEGIN CUT HERE
/*
SRM 674 Div2 Easy (250)

PROBLEM STATEMENT
Weiwei is studying math. Unfortunately, math is very hard for him. Today, the teacher asked Weiwei to determine if a relation is a bijection or not.

Formally, a relation is a set of ordered pairs of elements. The teacher gave Weiwei one such relation. You are also given a description of this relation: vector <int>s domain and range. For each valid i, the relation contains the ordered pair (domain[i], range[i]).

Let X be the set of elements that appear at least once in domain. Similarly, let Y be the set of elements that appear at least once in range. We say that an element x of X is paired to an element y of Y if the relation contains the ordered pair (x, y).

We will say that our relation is a bijection if each element of X is paired to exactly one element of Y, and each element of Y is paired to exactly one element of X.

If Weiwei's relation is a bijection, return "Bijection" (quotes for clarity). Otherwise, return "Not". Note that the return value is case-sensitive.


DEFINITION
Class:RelationClassifier
Method:isBijection
Parameters:vector <int>, vector <int>
Returns:string
Method signature:string isBijection(vector <int> domain, vector <int> range)


CONSTRAINTS
-domain will contain between 1 and 10 elements, inclusive.
-range will contain the same number of elements as domain.
-Each element of domain and range will be between 1 and 100, inclusive.
-No two pairs (domain[i], range[i]) will be identical.


EXAMPLES

0)
{1, 1}
{2, 3}

Returns: "Not"

Since 1 in X is paired with both 2 and 3 in Y, the given relation is not a bijection.


1)
{4, 5}
{2, 2}

Returns: "Not"

Since both 4 and 5 in X are paired with 2 in Y, the given relation is not a bijection.


2)
{1}
{2}

Returns: "Bijection"

A single ordered pair is always a bijection.


3)
{1, 2, 3, 4, 5}
{1, 2, 3, 4, 5}

Returns: "Bijection"


4)
{14, 12, 10, 13, 20, 18, 9, 17, 14, 9}
{18, 6, 8, 15, 2, 14, 10, 13, 13, 15}

Returns: "Not"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class RelationClassifier {
public:
	string isBijection(vector <int> domain, vector <int> range) {
		set<int> a(domain.begin(), domain.end());
		set<int> b(range.begin(), range.end());
		bool ans = domain.size() == a.size() && range.size() == b.size();
		return ans ? "Bijection" : "Not";
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
			int Arr0[] = {1, 1};
			int Arr1[] = {2, 3};
			string Arg2 = "Not";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isBijection(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 5};
			int Arr1[] = {2, 2};
			string Arg2 = "Not";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isBijection(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			int Arr1[] = {2};
			string Arg2 = "Bijection";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isBijection(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4, 5};
			int Arr1[] = {1, 2, 3, 4, 5};
			string Arg2 = "Bijection";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isBijection(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {14, 12, 10, 13, 20, 18, 9, 17, 14, 9};
			int Arr1[] = {18, 6, 8, 15, 2, 14, 10, 13, 13, 15};
			string Arg2 = "Not";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isBijection(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RelationClassifier ___test;
	___test.run_test(-1);
}
// END CUT HERE
