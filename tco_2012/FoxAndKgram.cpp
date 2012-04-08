// BEGIN CUT HERE
/*
// TCO12 Round 1B Easy (250)

// PROBLEM STATEMENT
// Fox Ciel has some pencils.
Before she'll start writing her homework, she wants to place them into
a mystic pattern for fun.
Different pencils she has may have different lengths.
You are given a vector <int> len. For each i, the length of i-th pencil is len[i]

The pattern she wants to create is called a k-gram.
A k-gram is a pattern consisting of k rows, each of length k.
There are only two types of valid rows:

Yang: A row containing a single pencil of length k.
Yin: A row containing two pencils such that the sum of their lengths is (k-1).
The pencils will be separated by a space of length 1.

Compute and return the largest positive integer k such that Fox Ciel
can use some of her pencils to form a k-gram.
If she is unable to form any k-grams, return 0 instead.


DEFINITION
Class:FoxAndKgram
Method:maxK
Parameters:vector <int>
Returns:int
Method signature:int maxK(vector <int> len)


CONSTRAINTS
-len will contain between 1 and 50 elements, inclusive.
-Each element in len will be between 1 and 50, inclusive.


EXAMPLES

0)
{1,1,1,1,3}

Returns: 3

All pencils can be used to form a 3-gram. One valid 3-gram follows:

- -
---
- -


1)
{2,2,1,3,5,5,5}

Returns: 5

One of the valid 5-grams:

-----
-- --
- ---
-----
-----


2)
{1}

Returns: 1


3)
{2,2,2,2,2,2,2,2,2,2}

Returns: 5


4)
{1,2,3,1,2,4,2,3,1}

Returns: 4

Note that it is not necessary to use all of the pencils.


5)
{2,3,5,7,11,13,17,19,23,29}

Returns: 0

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class FoxAndKgram {

public:
	int maxK(vector <int> len) {
		int sz = len.size();
		int k;
		for (k = 50; k > 0; --k) {
			int cnt = 0;
			int f[50] = {};
			int i, j;
			for (i = 0; i < sz; ++i) {
				if (len[i] == k) {
					++cnt;
					if (cnt >= k) {
						return k;
					}
				}
			}
			for (i = 1; i < sz; ++i) {
				for (j = 0; j < i; ++j) {
					if (!f[i] && !f[j] && len[i] + len[j] == (k-1)) {
						f[i] = 1, f[j] = 1;
						++cnt;
						if (cnt >= k) {
							return k;
						}
					}
				}
			}
		}
		return 0;
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
			int Arr0[] = {1,1,1,1,3};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxK(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,1,3,5,5,5};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxK(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxK(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,2,2,2,2,2,2,2,2};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxK(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,1,2,4,2,3,1};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxK(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,3,5,7,11,13,17,19,23,29};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxK(Arg0));
		}
		n++;




		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxK(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndKgram ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
