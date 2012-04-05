// BEGIN CUT HERE
/*
// SRM 539 Div1 Easy (250)

// PROBLEM STATEMENT
// You used to have only 30 rocks, but now you have plenty of them. In fact,
we will assume that you have a potentially infinite supply of rocks. You would
like to show that you own over 9000 rocks.
You have a set of boxes. You will choose a subset of those boxes and fill them
with rocks so that the total number of rocks will be over 9000. Each box has
a lower and an upper bound on the number of rocks it may contain.

You are given the vector <int>s lowerBound and upperBound. For each i,
the values lowerBound[i] and upperBound[i] have the following meaning:
If you decide to use box i, the number of rocks you may put inside the box
must be between lowerBound[i] and upperBound[i], inclusive.

X is a positive integer that has two properties:

X is over 9000.
It is possible to select some of the boxes and fill them with appropriate
numbers of rocks in such a way that the total number of rocks used is exactly X.

Compute and return the number of possible values of X.

DEFINITION
Class:Over9000Rocks
Method:countPossibilities
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int countPossibilities(vector <int> lowerBound, vector <int> upperBound)


CONSTRAINTS
-lowerBound will contain between 1 and 15, elements, inclusive.
-upperBound will contain the same number of elements as lowerBound.
-Each element of lowerBound will be between 1 and 1,000,000 (10^6), inclusive.
-Each element i of upperBound will be between lowerBound[i] and 1,000,000 (10^6), inclusive.


EXAMPLES

0)
{9000}
{9001}

Returns: 1

You can place 9000 or 9001 rocks in the single box. Of the allowed values, only 9001 is over 9000.


1)
{9000, 1, 10}
{9000, 2, 20}

Returns: 15

You have to choose box 0 and at least one other box, otherwise you have no chance of placing over 9000 rocks.
If you only choose boxes 0 and 1, you can place 9001 or 9002 rocks.
If you only choose boxes 0 and 2, you can place between 9010 and 9020 rocks, inclusive.
If you choose all three boxes, you can place between 9011 and 9022 rocks, inclusive.
Hence all possible values of X are 9001, 9002, and everything from 9010 to 9022, inclusive.


2)
{1001, 2001, 3001, 3001}
{1003, 2003, 3003, 3003}

Returns: 9


3)
{9000,90000,1,10}
{9000,90000,3,15}

Returns: 38


4)
{1,1,1,1,1,1}
{3,4,5,6,7,8}

Returns: 0

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

typedef pair<int, int> II;
typedef vector<II> IIVec;

class Over9000Rocks {

public:
	int countPossibilities(vector <int> lowerBound, vector <int> upperBound) {
		int N = lowerBound.size();
		int i, j, k = 0, sz = (1<<N)-1;
		IIVec v(sz);
		for (i = 0; i < N; ++i) {
			for (j = 0; j < k; ++j) {
				v[j+k].first = v[j].first + lowerBound[i];
				v[j+k].second = v[j].second + upperBound[i];
			}
			v[j+k].first = lowerBound[i];
			v[j+k].second = upperBound[i];
			k = k*2+1;
		}
		sort(v.begin(), v.end());

		int res = 0;
		int x = 9001;
		for (i = 0; i < sz; ++i) {
			int l = v[i].first;
			int u = v[i].second;
			if (l > x) {
				x = l;
			}
			if (u >= x) {
				res += (u - x) + 1;
				x = u + 1;
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
			int Arr0[] = {9000};
			int Arr1[] = {9001};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countPossibilities(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9000, 1, 10};
			int Arr1[] = {9000, 2, 20};
			int Arg2 = 15;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countPossibilities(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1001, 2001, 3001, 3001};
			int Arr1[] = {1003, 2003, 3003, 3003};
			int Arg2 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countPossibilities(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9000,90000,1,10};
			int Arr1[] = {9000,90000,3,15};
			int Arg2 = 38;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countPossibilities(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1};
			int Arr1[] = {3,4,5,6,7,8};
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countPossibilities(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9002};
			int Arr1[] = {9002};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countPossibilities(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
			int Arr1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countPossibilities(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Over9000Rocks ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
