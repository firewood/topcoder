// BEGIN CUT HERE
/*
SRM 786 Div1 Easy (250)

PROBLEM STATEMENT
You are given a string S of length N. You are also given an integer K. In each step, you are allowed to select an index i and swap the characters at indices i and i + K (such that i + K < N) in the string S. After the swap, the new formed string should be lexographically greater than the old string. You keep on performing such steps, as long as possible. You need to find the maximum number of steps that can be performed on the given string.
You are given integers A0, X, Y and N and a string P. Use the pseudocode below to generate the string S.
A[0] = A0
for i = 1 to N-1:
	A[i] = (A[i-1] * X + Y) modulo 1812447359

S = P
for i = size(P) to N-1:
	S[i] = (char)(A[i] % 26 + 'a')


DEFINITION
Class:SwapTheString
Method:findNumberOfSwaps
Parameters:string, int, int, int, int, int
Returns:long long
Method signature:long long findNumberOfSwaps(string P, int A0, int X, int Y, int N, int K)


CONSTRAINTS
-The length of P will be between 0 and min(N, 100) (inclusive)
-A0 will be between 0 and 1812447358 (inclusive)
-X will be between 0 and 1812447358 (inclusive)
-Y will be between 0 and 1812447358 (inclusive)
-N will be between 1 and 200,000 (inclusive)
-K will be between 1 and N (inclusive)
-String P will only contain lowercase English letters ('a'-'z').


EXAMPLES

0)
"cbexa"
0
0
0
5
2

Returns: 2

There are 2 possible swaps in string "cbexa" : "cbexa" -> "cxeba" (swapping characters at index 1 and 3) and then "cxeba" -> "excba" (swapping characters at index 0 and 2). Note that if the k would have been 1, more swaps would have been possible.


1)
""
5
2
3
4
1

Returns: 3

The string here is "fndj". There are 3 swaps possible : "fndj" -> "fnjd", "fnjd" -> "nfjd" and "nfjd" -> "njfd". Note that there can be multiple ways to do these swaps.


2)
"b"
1001
1001
1001
5
2

Returns: 3

The string is "banol". There are 3 swaps possible : "banol" -> "bonal", "bonal" -> "nobal" and "nobal" -> "nolab".


3)
""
9999
50000
4797
6
3

Returns: 2


4)
""
3435
1000000000
1812447358
7
2

Returns: 5

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

template<typename T>
class BIT {
	std::vector<T> bit;
	int size;
public:
	BIT() { }
	BIT(int sz) { init(sz); }
	void init(int sz) {
		bit = std::vector<T>((size_t)(size = sz) + 1);
	}
	T sum(int i) {
		T s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int i, T x) {
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

class SwapTheString {
public:
	long long findNumberOfSwaps(string P, int A0, int X, int Y, int N, int K) {
		LL ans = 0;
		vector<int> a(N);
		a[0] = A0;
		for (int i = 1; i < N; ++i) {
			a[i] = (a[i - 1] * (LL)X + Y) % 1812447359;
		}
		vector<int> s(N);
		for (int i = 0; i < N; ++i) {
			if (i < P.length()) {
				s[i] = P[i] - 'a';
			} else {
				s[i] = a[i] % 26;
			}
		}
		reverse(s.begin(), s.end());

		for (int t = 0; t < K; ++t) {
			// 転倒数 inversion number
			BIT<LL> bit(32);
			for (int k = 0; k < N; ++k) {
				int i = t + k * K;
				if (i >= N) {
					break;
				}
				ans += k - bit.sum(1 + s[i]);
				bit.add(1 + s[i], 1);
			}
		}

		return ans;
	}

	// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T>& V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long& Expected, const long long& Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) {
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)) {
			string Arg0 = "cbexa";
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 0;
			int Arg4 = 5;
			int Arg5 = 2;
			long long Arg6 = 2LL;

			verify_case(n, Arg6, findNumberOfSwaps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			string Arg0 = "";
			int Arg1 = 5;
			int Arg2 = 2;
			int Arg3 = 3;
			int Arg4 = 4;
			int Arg5 = 1;
			long long Arg6 = 3LL;

			verify_case(n, Arg6, findNumberOfSwaps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)) {
			string Arg0 = "b";
			int Arg1 = 1001;
			int Arg2 = 1001;
			int Arg3 = 1001;
			int Arg4 = 5;
			int Arg5 = 2;
			long long Arg6 = 3LL;

			verify_case(n, Arg6, findNumberOfSwaps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)) {
			string Arg0 = "";
			int Arg1 = 9999;
			int Arg2 = 50000;
			int Arg3 = 4797;
			int Arg4 = 6;
			int Arg5 = 3;
			long long Arg6 = 2LL;

			verify_case(n, Arg6, findNumberOfSwaps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)) {
			string Arg0 = "";
			int Arg1 = 3435;
			int Arg2 = 1000000000;
			int Arg3 = 1812447358;
			int Arg4 = 7;
			int Arg5 = 2;
			long long Arg6 = 5LL;

			verify_case(n, Arg6, findNumberOfSwaps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SwapTheString ___test;
	___test.run_test(1);
}
// END CUT HERE
