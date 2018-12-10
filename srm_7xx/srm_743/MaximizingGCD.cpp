// BEGIN CUT HERE
/*
SRM 743 Div1 Easy (300)

PROBLEM STATEMENT

If S is a sequence of 2*n integers, its pairing is a sequence of n integers obtained by splitting S into n pairs of consecutive elements and taking the sum of each pair.

For example, the pairing of S = { 4, 7, 0, 3, 1, 1 } is the sequence { 4+7, 0+3, 1+1 } = { 11, 3, 2 }.

You are given a vector <int> A consisting of 2*n positive integers.
You are going to perform the following steps:

Create a new sequence B that is a permutation of A.
Find the sequence C that is the pairing of B.
Compute the greatest common divisor of all elements of C and denote it g.

Find and return the largest possible value of g (over all possible choices of B).


DEFINITION
Class:MaximizingGCD
Method:maximumGCDPairing
Parameters:vector <int>
Returns:int
Method signature:int maximumGCDPairing(vector <int> A)


CONSTRAINTS
-A will containt between 2 and 30 elements, inclusive.
-A will contain an even number of elements.
-Each element of A will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{5, 4, 13, 2}

Returns: 6

A way to obtain output 6 is to set B = { 4, 2, 5, 13 }. Then, the pairing of B is C = { 4+2, 5+13 } = { 6, 18 }. Finally, the GCD of the elements of C is 6.


1)
{26, 23}

Returns: 49

In this case C equals { 49 } for any choice of B.


2)
{100, 200, 300, 500, 1100, 700}

Returns: 100

In this example any choice of B leads to the output of 100.


3)
{46, 78, 133, 92, 1, 23, 29, 67, 43, 111, 3908, 276, 13, 359, 20, 21}

Returns: 4


4)
{16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 
65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608}

Returns: 16400

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

typedef long long LL;

class MaximizingGCD {
public:
	int maximumGCDPairing(vector <int> A) {
		int n = (int)A.size();
		if (n == 2) {
			return A[0] + A[1];
		}
		LL sum = accumulate(A.begin(), A.end(), 0LL);
		LL r = (LL)sqrt(sum);
		auto ok = [&](int f) {
			map<int, int> m;
			for (int i = 0; i < n; ++i) {
				m[A[i] % f] += 1;
			}
			for (auto kv : m) {
				if (kv.first) {
					if (kv.first == f / 2) {
						if (kv.second % 2) {
							return false;
						}
					} else {
						if (kv.second != m[f - kv.first]) {
							return false;
						}
					}
				}
			}
			return true;
		};
		LL ans = 0;
		for (LL a = 1; a <= r; ++a) {
			if ((sum % a) == 0) {
				if (ok(a)) {
					ans = max(ans, a);
				}
				if (ok(sum / a)) {
					ans = max(ans, sum / a);
				}
			}
		}
		return (int)ans;
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
			int Arr0[] = {5, 4, 13, 2};
			int Arg1 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumGCDPairing(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {26, 23};
			int Arg1 = 49;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumGCDPairing(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, 200, 300, 500, 1100, 700};
			int Arg1 = 100;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumGCDPairing(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {46, 78, 133, 92, 1, 23, 29, 67, 43, 111, 3908, 276, 13, 359, 20, 21};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumGCDPairing(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 
65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608};
			int Arg1 = 16400;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumGCDPairing(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MaximizingGCD ___test;
	___test.run_test(-1);
}
// END CUT HERE
