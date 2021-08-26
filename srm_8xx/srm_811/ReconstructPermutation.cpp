// BEGIN CUT HERE
/*
SRM 811 Div2 Hard (800)

PROBLEM STATEMENT

We once had a permutation of the numbers from 0 to N-1, inclusive.

Then, someone erased some of its elements (possibly none or all of them).
The order of the remaining elements was preserved.

You are given the sequence that remained in the vector <int> partial.

Reconstruct and return the original permutation.
If there are multiple options, return the lexicographically smallest one among them.


DEFINITION
Class:ReconstructPermutation
Method:reconstruct
Parameters:int, vector <int>
Returns:vector <int>
Method signature:vector <int> reconstruct(int N, vector <int> partial)


NOTES
-Given two distinct permutations of order N, the one that has a smaller value at the first index at which they differ is lexicographically smaller.


CONSTRAINTS
-N will be between 1 and 500, inclusive.
-Each element of partial will be between 0 and N-1, inclusive.
-All elements of partial will be mutually distinct.


EXAMPLES

0)
8
{1, 3, 5, 7}

Returns: {0, 1, 2, 3, 4, 5, 6, 7 }

The given partial permutation can be obtained from the lexicographically smallest of all permutations, so that is the answer.


1)
5
{3, 1, 4, 0, 2}

Returns: {3, 1, 4, 0, 2 }

Nothing is missing, the input permutation is also the correct output.


2)
5
{0, 3, 1}

Returns: {0, 2, 3, 1, 4 }

There are 20 different permutations from which the given partial permutation could have been obtained. The other 19 are all lexicographically greater than the one shown as correct return value.


3)
8
{}

Returns: {0, 1, 2, 3, 4, 5, 6, 7 }

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
#include <queue>

using namespace std;

class ReconstructPermutation {
public:
	vector <int> reconstruct(int N, vector <int> partial) {
		vector <int> ans;
		set<int> s;
		for (int i = 0; i < N; ++i) {
			s.insert(i);
		}
		for (auto x : partial) {
			s.erase(x);
		}
		int pi = 0;
		for (auto next : s) {
			while (pi < partial.size() && partial[pi] < next) {
				ans.emplace_back(partial[pi++]);
			}
			ans.emplace_back(next);
		}
		while (pi < partial.size()) {
			ans.emplace_back(partial[pi++]);
		}
		return ans;
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
			int Arg0 = 8;
			int Arr1[] = {1, 3, 5, 7};
			int Arr2[] = {0, 1, 2, 3, 4, 5, 6, 7 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, reconstruct(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {3, 1, 4, 0, 2};
			int Arr2[] = {3, 1, 4, 0, 2 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, reconstruct(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {0, 3, 1};
			int Arr2[] = {0, 2, 3, 1, 4 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, reconstruct(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			// int Arr1[] = {};
			int Arr2[] = {0, 1, 2, 3, 4, 5, 6, 7 };

			vector <int> Arg1;
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, reconstruct(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ReconstructPermutation ___test;
	___test.run_test(-1);
}
// END CUT HERE
