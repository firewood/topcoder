// BEGIN CUT HERE
/*
SRM 762 Div1 Easy (250)

PROBLEM STATEMENT

An array A is called positive partitionable if we can divide A into one or more contiguous subarrays such that each element belongs to exactly one of the subarrays and the sum of each subarray is positive.

For example, the array {3,-7,8} is positive partitionable. One valid way of splitting this array is to split it into {3} and {-7,8}. The array {0,1,0,1,2} is also positive partitionable. The array {-1,2,-3,4,-5} and the array {0} are not positively partitionable.

A partition of an array can be described by listing the lengths of the partitions, in order. For example, {3} has length 1 and {-7,8} has length 2, hence the partition of {3,-7,8} into {3} and {-7,8} can be described by the sequence {1,2}. The sequences {2,3}, {2,2,1}, and {4,1} describe different three valid ways of partitioning the sequence {0,1,0,1,2}.

You are given the int n, the vector <int> Aprefix, and the ints seed and Arange.
Use the following pseudocode to generate an array A with n elements:

for i = 0 .. len(Aprefix)-1:
    A[i] = Aprefix[i]

state = seed
for i = len(Aprefix) .. n-1:
    state = (1103515245 * state + 12345)
    A[i] = state modulo (2*Arange+1)
    A[i] = A[i] - Arange
    state = state modulo 2^31

If this array A isn't positive partitionable, return {-1}.
Otherwise, find an array B that describes a valid partition of A.
If there are multiple possibilities for B, pick the lexicographically smallest one.
Return an array that contains the value length(B) and then the first min(len(B),200) elements of B, in order.


DEFINITION
Class:LexicographicPartition
Method:positiveSum
Parameters:int, vector <int>, int, int
Returns:vector <int>
Method signature:vector <int> positiveSum(int n, vector <int> Aprefix, int seed, int Arange)


NOTES
-Given two different sequences A[0..a-1] and B[0..b-1] such that neither is a prefix of the other, the lexicographically smaller sequence is the one that has a smaller value at the first index at which they differ. For example, {3, 7, 100} < {3, 10, 12, 45} because 7 < 10.


CONSTRAINTS
-n will be between 1 and 200,000 inclusive.
-All elements of Aprefix will be between -10^6 and 10^6 inclusive.
-Aprefix will contain between 0 and min(n,500) elements inclusive.
-seed will be between 1 and 10^9 inclusive.
-Arange will be between 0 and 10^6 inclusive. 


EXAMPLES

0)
3
{3,-7,8}
1
1

Returns: {2, 1, 2 }

A = {3,-7,8}. The lexicographically smallest sequence that describes a valid partition is indeed the sequence B={1,2} mentioned in the statement. Thus, we return the array {length(B),1,2} = {2,1,2}.


1)
5
{0,1,0,1,2}
42
47

Returns: {3, 2, 2, 1 }

The optimal B is {2,2,1}.


2)
5
{-1,2,-3,4,-5}
777
4747

Returns: {-1 }


3)
1
{0}
12
34

Returns: {-1 }


4)
10
{4,-7,4,-7}
123456789
5447

Returns: {6, 1, 5, 1, 1, 1, 1 }

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

class LexicographicPartition {
public:
	vector <int> positiveSum(int n, vector <int> Aprefix, int seed, int Arange) {
		vector<int> a = Aprefix;
		a.resize(n);
		LL st = seed;
		LL mod = 2 * Arange + 1;
		for (int i = Aprefix.size(); i < n; ++i) {
			st = (1103515245 * st + 12345);
			a[i] = st % mod;
			a[i] -= Arange;
			st %= 1LL << 31;
		}
		LL sum = accumulate(a.begin(), a.end(), 0LL);
		if (sum <= 0) {
			return { -1 };
		}
		vector<int> ans(1, 1);
		LL x = 0;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			++cnt;
			x += a[i];
			sum -= a[i];
			if (x > 0 && sum > 0) {
				ans.push_back(cnt);
				cnt = 0;
				x = 0;
			}
		}
		if (x > 0) {
			ans.push_back(cnt);
		}
		ans[0] = ans.size() - 1;
		if (ans.size() > 200) {
			ans.resize(201);
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
			int Arg0 = 3;
			int Arr1[] = {3,-7,8};
			int Arg2 = 1;
			int Arg3 = 1;
			int Arr4[] = {2, 1, 2 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, positiveSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {0,1,0,1,2};
			int Arg2 = 42;
			int Arg3 = 47;
			int Arr4[] = {3, 2, 2, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, positiveSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {-1,2,-3,4,-5};
			int Arg2 = 777;
			int Arg3 = 4747;
			int Arr4[] = {-1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, positiveSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {0};
			int Arg2 = 12;
			int Arg3 = 34;
			int Arr4[] = {-1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, positiveSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arr1[] = {4,-7,4,-7};
			int Arg2 = 123456789;
			int Arg3 = 5447;
			int Arr4[] = {6, 1, 5, 1, 1, 1, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, positiveSum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LexicographicPartition ___test;
	___test.run_test(-1);
}
// END CUT HERE
