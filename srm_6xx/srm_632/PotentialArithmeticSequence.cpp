// BEGIN CUT HERE
/*
SRM 632 Div1 Easy (250)

PROBLEM STATEMENT

We have a sequence of N positive integers: a[0] through a[N-1].
You do not know these integers.
All you know is the number of trailing zeros in their binary representations.
You are given a vector <int> d with N elements.
For each i, d[i] is the number of trailing zeros in the binary representation of a[i].

For example, suppose that a[0]=40.
In binary, 40 is 101000 which ends in three zeros.
Therefore, d[0] will be 3.

You like arithmetic sequences with difference 1.
(That is, sequences in which each element is 1 greater than the previous one. For example, {4,5,6,7}.)
For simplicity, we will call these sequences "incrementing sequences".

You would like to count all non-empty contiguous subsequences of the sequence a[0], a[1], ..., a[N-1] that can be incrementing sequences (given the information you have in d).

More precisely:
For each pair (i,j) such that 0 <= i <= j <= N-1, we ask the following question: "Given the values d[i] through d[j], is it possible that the values a[i] through a[j] form an incrementing sequence?"

For example, suppose that d = {0,1,0,2,1}.
For i=0 and j=3 the answer is positive: it is possible that the values a[0] through a[3] are {1,2,3,4} which is an incrementing sequence.
For i=1 and j=4 the answer is negative: there is no incrementing sequence with these numbers of trailing zeros in binary.

Compute and return the number of contiguous subsequences of a[0], a[1], ..., a[N-1] that can be incrementing sequences.


DEFINITION
Class:PotentialArithmeticSequence
Method:numberOfSubsequences
Parameters:vector <int>
Returns:int
Method signature:int numberOfSubsequences(vector <int> d)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-d will contain exactly N elements.
-Each element of d will be between 0 and 1,000,000,000 (10^9), inclusive.


EXAMPLES

0)
{0,1,0,2,0,1,0}

Returns: 28

It is possible that the sequence a[0] through a[6] is {1,2,3,4,5,6,7}. All contiguous subsequences of this sequence are incrementing sequences.


1)
{0,0,0,0,0,0,0}

Returns: 7


2)
{0,0,0,0,1,1,1}

Returns: 8


3)
{0,100,0,2,0}

Returns: 11


4)
{1,11,3,0,1,0,1,0,1,0,1,0,3,0,2,0,0,0,0,1,2,3,20}

Returns: 49

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class PotentialArithmeticSequence {
public:
	int numberOfSubsequences(vector <int> d) {
		int N = (int)d.size();
		int a[257];
		for (int i = 0; i <= 8; ++i){
			a[1 << i] = i;
		}
		char b[384];
		for (int i = 0; i < 384; ++i) {
			b[i] = a[i&-i];
		}
		char c[256];
		for (int i = 0; i < N; ++i) {
			c[i] = min(d[i], 7);
		}
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			for (int len = 1; len <= N - i; ++len) {
				for (int j = 1; j <= 256; ++j) {
					if (memcmp(c + i, b + j, len) == 0) {
						++ans;
						break;
					}
				}
			}
		}
		return ans;
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
			int Arr0[] = {0,1,0,2,0,1,0};
			int Arg1 = 28;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, numberOfSubsequences(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0,0,0,0,0};
			int Arg1 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, numberOfSubsequences(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0,0,1,1,1};
			int Arg1 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, numberOfSubsequences(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,100,0,2,0};
			int Arg1 = 11;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, numberOfSubsequences(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,11,3,0,1,0,1,0,1,0,1,0,3,0,2,0,0,0,0,1,2,3,20};
			int Arg1 = 49;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, numberOfSubsequences(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PotentialArithmeticSequence ___test;
	___test.run_test(-1);
}
// END CUT HERE
