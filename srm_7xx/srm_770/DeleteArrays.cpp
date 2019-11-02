// BEGIN CUT HERE
/*
SRM 770 Div1 Easy (300)

PROBLEM STATEMENT

You are given three numbers: a, b, and c.
You need to generate three arrays A, B, C of lengths a, b, c using the pseudocode given below:

A[0] = 33
A[1] = 42
for i = 2 to a-1:
    A[i] = (5*A[i-1] + 7*A[i-2]) modulo 1000000007 + 1

B[0] = 13
for i = 1 to b-1:
    B[i] = (11*B[i-1]) modulo 1000000007 + 1

C[0] = 7
C[1] = 2
for i = 2 to c-1:
    C[i] = (5*C[i-1] + 7*C[i-2]) modulo 1000000007 + 1

Now that you have 3 arrays A , B and C, you can perform three types of moves:

	Remove one element each from arrays A and B. The cost of this operation is (x + the sum of elements you removed).
	Remove one element each from arrays B and C. The cost of this operation is (y + the sum of elements you removed).
	Remove one element each from arrays A and C. The cost of this operation is (z + the sum of elements you removed).

You need to minimize the sum of elements remaining in these arrays after performing above mentioned operations any number of times.
If there are multiple ways to obtain the minimum sum, you need to minimize the cost of doing so. 

Return an array of two integers containing the minimum sum (at index 0) and minimum cost of obtaining the minimum sum (at index 1).


DEFINITION
Class:DeleteArrays
Method:doDelete
Parameters:int, int, int, long long, long long, long long
Returns:vector<long long>
Method signature:vector<long long> doDelete(int a, int b, int c, long long x, long long y, long long z)


NOTES
-The input format is only chosen to keep the input size small. The reference solution does not depend on any properties of these arrays A, B, C, it would work correctly for any arrays of the given length.
-Watch out for integer overflows, both when generating the input arrays and when calculating the return values.
-The elements of arrays can be removed in any order.


CONSTRAINTS
-Each of a, b and c will be between 2 and 10^5, inclusive.
-Each of x, y and z will be between 1 and 10^9, inclusive.


EXAMPLES

0)
2
2
2
2
3
4

Returns: {0, 250 }

The arrays are: 
A = {33, 42}
B = {13, 144} 
C = {7, 2} 
We can remove first elements from arrays A and B with cost (2 + 33 + 13) = 48. 
Next we remove the remaining element from A and the first element of C with cost (4 + 42 + 7) = 53. 
Finally, we remove the remaining elements from B and C with cost (3 + 144 + 2) = 149. 
Sum of Elements remaining = 0, which is clearly optimal. Cost = 48 + 53 + 149 = 250.


1)
3
2
2
3
2
1

Returns: {2, 688 }

The arrays are: 
A = {33, 42, 442}
B = {13, 144} 
C = {7, 2} 
One optimal solution:

Remove 33 from A and 13 from B, cost = (3 + 33 + 13) = 49.
Remove 442 from A and 144 from B, cost = (3 + 442 + 144) = 589.
Remove 42 from A and 7 from C, cost = (1 + 42 + 7) = 50.

Sum of remaining elements = 2. Total cost = 49 + 589 + 50 = 688.


2)
4
4
4
5
6
7

Returns: {0, 22620 }


3)
100000
5
8
424242
474747
123456789

Returns: {50097960828195, 13989929548 }

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

static const LL MOD = 1000000007LL;

class DeleteArrays {
public:
	vector<long long> doDelete(int a, int b, int c, long long x, long long y, long long z) {
		vector<int> aa(a), bb(b), cc(c);
		aa[0] = 33, aa[1] = 42;
		for (int i = 2; i < a; ++i) {
			aa[i] = ((5LL * aa[i - 1] + 7LL * aa[i - 2]) % MOD) + 1;
		}
		bb[0] = 13;
		for (int i = 1; i < b; ++i) {
			bb[i] = ((11LL * bb[i - 1]) % MOD) + 1;
		}
		cc[0] = 7;
		cc[1] = 2;
		for (int i = 2; i < c; ++i) {
			cc[i] = ((5LL * cc[i - 1] + 7LL * cc[i - 2]) % MOD) + 1;
		}
		sort(aa.begin(), aa.end());
		sort(bb.begin(), bb.end());
		sort(cc.begin(), cc.end());
		vector<LL> ret(2, 1LL << 60);
		for (int rot = 0; rot < 3; ++rot) {
			LL taken = accumulate(aa.begin(), aa.end(), 0LL) + accumulate(bb.begin(), bb.end(), 0LL);
			LL left = accumulate(cc.begin(), cc.end(), 0LL);
			for (int nc = 0; nc <= c; ++nc) {
				if (nc > 0) {
					taken += cc[c - nc];
					left -= cc[c - nc];
				}
				if ((a + b + nc) % 2 == 1) {
					continue;
				}
				int nab = (a + b - nc) / 2, nac = (a + nc - b) / 2, nbc = (b + nc - a) / 2;
				if (nab >= 0 && nac >= 0 && nbc >= 0) {
					ret = min(ret, { left, nab * x + nbc * y + nac * z + taken });
				}
			}
			auto dd = aa;
			aa = bb, bb = cc, cc = dd;
			auto d = a;
			a = b, b = c, c = d;
			auto w = x;
			x = y, y = z, z = w;
		}
		return ret;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 2;
			long long Arg3 = 2LL;
			long long Arg4 = 3LL;
			long long Arg5 = 4LL;
			long Arr6[] = {0, 250 };

			vector<long long> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
			verify_case(n, Arg6, doDelete(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			int Arg2 = 2;
			long long Arg3 = 3LL;
			long long Arg4 = 2LL;
			long long Arg5 = 1LL;
			long Arr6[] = {2, 688 };

			vector<long long> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
			verify_case(n, Arg6, doDelete(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			int Arg2 = 4;
			long long Arg3 = 5LL;
			long long Arg4 = 6LL;
			long long Arg5 = 7LL;
			long Arr6[] = {0, 22620 };

			vector<long long> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
			verify_case(n, Arg6, doDelete(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100000;
			int Arg1 = 5;
			int Arg2 = 8;
			long long Arg3 = 424242LL;
			long long Arg4 = 474747LL;
			long long Arg5 = 123456789LL;
			long long Arr6[] = {50097960828195LL, 13989929548LL };

			vector<long long> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
			verify_case(n, Arg6, doDelete(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DeleteArrays ___test;
	___test.run_test(-1);
}
// END CUT HERE
