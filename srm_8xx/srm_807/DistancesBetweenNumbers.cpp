// BEGIN CUT HERE
/*
SRM 807 700

PROBLEM STATEMENT

Given two non-negative integers X and Y, their distance is defined as the number of base-10 digits in which they differ.

For example:

distance(47, 47) = 0
distance(42, 47) = distance(47, 42) = 1: these numbers have the same tens digit and different ones digits
distance(24, 42) = 2: we are comparing each position separately, not just the sets of digits
distance(1234, 37) = 3: if one number is shorter, the missing digits are zero, so distance(1234, 37) = distance(1234, 0037)

You are given a long sequence A that consists of N non-negative integers.

For each pair of indices i and j (0 <= i < j < N), Lucy calculated the distance between A[i] and A[j].
Then, Lucy computed the sum of all those distances.

Return the final value obtained by Lucy.

In order to keep the input size small, you are only given a prefix of A, the rest is generated pseudorandomly.
Please use the pseudocode or code given below to generate A.

Pseudocode:

A = an empty array of length N
L = length(Aprefix)

for i = 0 to L-1:
    A[i] = Aprefix[i]

for i = L to N-1:
    A[i] = (A[i-1] * 1103515245 + 12345) modulo 2^31

-------------------------------------------------------------------------------------

Java:

int[] A = new int[N];
int L = Aprefix.length;
for (int i=0; i<L; ++i) A[i] = Aprefix[i];
for (int i=L; i<N; ++i) A[i] = (int)((A[i-1] * 1103515245L + 12345L) % (1L << 31));

-------------------------------------------------------------------------------------

C++:

vector<int> A(N);
int L = Aprefix.size();
for (int i=0; i<L; ++i) A[i] = Aprefix[i];
for (int i=L; i<N; ++i) A[i] = (A[i-1] * 1103515245LL + 12345LL) % (1LL << 31);


DEFINITION
Class:DistancesBetweenNumbers
Method:count
Parameters:int, vector <int>
Returns:long long
Method signature:long long count(int N, vector <int> Aprefix)


NOTES
-The reference solution does not depend on A being pseudorandom. It would correctly solve any input of the given size.


CONSTRAINTS
-N will be between 2 and 100,000, inclusive.
-Aprefix will contain between 1 and min(100, N) elements, inclusive.
-Each element of Aprefix will be between 0 and 2^31 - 1, inclusive.


EXAMPLES

0)
4
{47, 47, 47, 47}

Returns: 0

All numbers are the same, all pairwise distances are zero.


1)
4
{47, 47, 42, 47}

Returns: 3

Three pairs have distance 0, three pairs have distance 1.


2)
4
{1, 10, 100, 1000}

Returns: 12

Each pair of elements of this sequence has distance 2.


3)
10
{1234567, 1234890}

Returns: 389

The full array A looks as follows: A = { 1234567, 1234890, 1979817275, 1396317272, 1752240561, 191800982, 48419351, 727754244, 1439963117, 1491506722 }.

If you are writing your own code to generate A, please watch out for integer overflows.

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

typedef long long LL;

class DistancesBetweenNumbers {
public:
	long long count(int N, vector <int> Aprefix) {
		long long ans = 0;

		vector<vector<int>> cnt(10, vector<int>(10));
		vector<LL> A(N);
		LL sz = Aprefix.size();
		for (LL i = 0; i < sz; ++i) A[i] = Aprefix[i];
		for (LL i = sz; i < N; ++i) A[i] = (A[i - 1] * 1103515245LL + 12345LL) % (1LL << 31);
		for (LL i = 0; i < N; ++i) {
			string s = "000000000" + to_string(A[i]);
			s = s.substr(s.length() - 10);
			for (LL j = 0; j < s.length(); ++j) {
				cnt[j][s[j] - '0'] += 1;
			}
		}
		for (LL i = 0; i < N; ++i) {
			string s = "000000000" + to_string(A[i]);
			s = s.substr(s.length() - 10);
			for (LL j = 0; j < s.length(); ++j) {
				LL sum = accumulate(cnt[j].begin(), cnt[j].end(), 0LL) - cnt[j][s[j] - '0'];
				ans += sum;
			}
		}
		return ans / 2;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {47, 47, 47, 47};
			long long Arg2 = 0LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {47, 47, 42, 47};
			long long Arg2 = 3LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {1, 10, 100, 1000};
			long long Arg2 = 12LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arr1[] = {1234567, 1234890};
			long long Arg2 = 389LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DistancesBetweenNumbers ___test;
	___test.run_test(-1);
}
// END CUT HERE
