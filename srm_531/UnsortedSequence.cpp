// BEGIN CUT HERE
/*
// SRM 531 Div2 Easy (250)

// PROBLEM STATEMENT
// We say that the sequence of numbers {s[0], s[1], s[2], ..., s[N-1]}
is sorted in ascending order if we have s[i] <= s[i+1] for each i
between 0 and N-2, inclusive.

For example, the sequences {1,2,3}, {1,1,1}, and {2,2,4,4,6,6} are sorted
in ascending order, but the sequences {1,2,1}, {7,4,6}, and {3,2,1} are not.

You are given the sequence of numbers as a vector <int> s. Your task is
to order the elements of this sequence into a sequence that will NOT be
sorted in ascending order. Find and return the lexicographically smallest
sequence we can obtain. If there is no possibility to get a sequence that is
not sorted in ascending order, return an empty vector <int> instead.

DEFINITION
Class:UnsortedSequence
Method:getUnsorted
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> getUnsorted(vector <int> s)


NOTES
-Sequence of numbers A is lexicographically smaller than B if A contains
 a smaller number on the first position on which they differ.
-The sequence s may contain duplicates.
-Note that the sequence consisting of only one element is always sorted.


CONSTRAINTS
-s will contain between 1 and 50 elements, inclusive.
-Each element of s will be between 1 and 1000, inclusive.


EXAMPLES

0)
{1,2}

Returns: {2, 1 }

There is only one possible sequence that is not in ascending order: {2,1}.

1)
{1,2,3}

Returns: {1, 3, 2 }

Out of all six possible sequences, five are not in ascending order.
Here they are, in lexicographic order:

{1,3,2}
{2,1,3}
{2,3,1}
{3,1,2}
{3,2,1}


2)
{7,2,2}

Returns: {2, 7, 2 }

Remember, that the given sequence may contain duplicates.

3)
{1000}

Returns: { }

As mentioned in the Notes section, the sequence consisting of only one
element is always sorted. So there is no possibility to unsort this sequence.

4)
{1,1}

Returns: { }

There are also some longer sequences that cannot be unsorted.

5)
{1,2,4,3}

Returns: {1, 2, 4, 3 }



6)
{2,8,5,1,10,5,9,9,3,10,5,6,6,2,8,2,10}

Returns: {1, 2, 2, 2, 3, 5, 5, 5, 6, 6, 8, 8, 9, 10, 9, 10, 10 }

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
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

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class UnsortedSequence {

public:
	vector <int> getUnsorted(vector <int> s) {
		IntVec res;

		int len = s.size();
		if (len <= 1) {
			return res;
		}

		sort(s.begin(), s.end());
		int e = *(s.rbegin());
		int i;
		for (i = len - 1; i >= 0; --i) {
			if (s[i] < e) {
				swap(s[i], s[i+1]);
				return s;
			}
		}

		return res;
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
			int Arr0[] = {1,2};
			int Arr1[] = {2, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getUnsorted(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3};
			int Arr1[] = {1, 3, 2 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getUnsorted(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7,2,2};
			int Arr1[] = {2, 7, 2 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getUnsorted(Arg0));
		}
		n++;

/*
		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000};
			int Arr1[] = { };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getUnsorted(Arg0));
		}
		n++;
*/

/*
		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1};
			int Arr1[] = { };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getUnsorted(Arg0));
		}
		n++;
*/

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,4,3};
			int Arr1[] = {1, 2, 4, 3 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getUnsorted(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,8,5,1,10,5,9,9,3,10,5,6,6,2,8,2,10};
			int Arr1[] = {1, 2, 2, 2, 3, 5, 5, 5, 6, 6, 8, 8, 9, 10, 9, 10, 10 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getUnsorted(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	UnsortedSequence ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
