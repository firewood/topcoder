// BEGIN CUT HERE
/*
SRM 784 Div1 Easy (250)

PROBLEM STATEMENT

You are given an vector <int> A of positive integers.
In a single turn, you can do the following: Choose any value X that is greater than 1.
Let C be the number of occurrences of X in the array A.
You then subtract 1 from exactly C/2 (rounded down) of those occurrences.

Find the lexicographically smallest array you can obtain after performing any number of turns.


DEFINITION
Class:ValueDivision
Method:getArray
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> getArray(vector <int> A)


CONSTRAINTS
-A will contain between 1 and 1,000 elements, inclusive.
-Each element of A will be between 1 and 109, inclusive.


EXAMPLES

0)
{1, 5, 7, 4, 5, 4, 1}

Returns: {1, 2, 7, 3, 5, 4, 1 }


1)
{7}

Returns: {7 }


2)
{7, 4}

Returns: {7, 4 }


3)
{7, 7, 7, 7}

Returns: {4, 5, 6, 7 }

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

class ValueDivision {
public:
	vector <int> getArray(vector <int> A) {
		map<int, set<int>> m;
		for (size_t i = 0; i < A.size(); ++i) {
			m[A[i]].insert(i);
		}
		while (!m.empty()) {
			auto it = m.rbegin();
			for (int x : it->second) {
				if (it->first > 1 && x != *it->second.rbegin()) {
					m[it->first - 1].insert(x);
				} else {
					A[x] = it->first;
				}
			}
			m.erase(it->first);
		}
		return A;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 5, 7, 4, 5, 4, 1};
			int Arr1[] = {1, 2, 7, 3, 5, 4, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getArray(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7};
			int Arr1[] = {7 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getArray(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7, 4};
			int Arr1[] = {7, 4 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getArray(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7, 7, 7, 7};
			int Arr1[] = {4, 5, 6, 7 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getArray(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ValueDivision ___test;
	___test.run_test(-1);
}
// END CUT HERE
