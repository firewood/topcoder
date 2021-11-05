// BEGIN CUT HERE
/*
SRM 818 Div1 Easy (300)

// PROBLEM STATEMENT
// 
The median of an array with an odd number of elements is the element that would be in the middle if we sorted the array. For example, the array {10, 40, 50, 20, 30} has the median 30.

Given is an array A[0..N-1] of non-negative integers.
Also given is an index K into the array such that the value A[K] has no other occurrence in the array A.

Count all contiguous subarrays of A such that their length is odd and their median is A[K].

In order to keep the input size small, the array A is pseudorandom and should be generated as follows:

L = length(Aprefix)
for i = 0 to L-1:
    A[i] = Aprefix[i]

state = Aprefix[L-1]
for i = L to N-1:
    state = (state * 1103515245 + 12345) modulo 2^31
    A[i] = state modulo M


DEFINITION
Class:MedianSegments
Method:count
Parameters:int, int, vector <int>, int
Returns:long long
Method signature:long long count(int N, int K, vector <int> Aprefix, int M)


NOTES
-The reference solution does not depend on the input being pseudorandom, it would solve the problem for any array of the given length.


CONSTRAINTS
-N will be between 1 and 300,000, inclusive.
-K will be between 0 and N-1, inclusive.
-Aprefix will have between 1 and min(100, N) elements, inclusive.
-M will be between 1 and 1,000,000,007, inclusive.
-Each element of Aprefix will be between 0 and M-1, inclusive.
-The value A[K] will have no other occurrence in A.


EXAMPLES

0)
10
3
{30, 40, 50, 60, 70, 80, 90, 100, 110, 120}
12345

Returns: 4

The whole array A is given. A[3] is 60. There are four subarrays of A with the median 60: {60}, {50, 60, 70}, {40, 50, 60, 70, 80}, and {30, 40, 50, 60, 70, 80, 90}.


1)
9
4
{0, 10, 2, 9, 5, 4, 6, 7, 3}
47

Returns: 11

The entire array A is one of the possibilities.


2)
13
5
{47023}
12345678

Returns: 5

The generated array should look as follows: 
A = { 47023, 11719828, 11657315, 11330458, 6137953, 2037036, 5878707, 33880, 4844967, 1163070, 1778073, 8789540, 2243117 }.

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

class MedianSegments {
public:
	long long count(int N, int K, vector <int> Aprefix, int M) {
        long long ans = 0, state = Aprefix.back();
        int cnt = 0;
        vector<LL> a;
        map<int, int> m[2];
        for (int i = 0; i < N; ++i) {
            LL x;
            if (i < Aprefix.size()) {
                x = Aprefix[i];
            } else {
                state = (state * 1103515245 + 12345) % (1LL << 31);
                x = state % M;
            }
            a.emplace_back(x);
        }
        LL med = a[K];
        for (int i = 0; i < N; ++i) {
            if (i <= K) {
                m[i % 2][cnt] += 1;
            }
            if (a[i] < med) {
                --cnt;
            } else if (a[i] > med) {
                ++cnt;
            }
            if (i >= K) {
                ans += m[i % 2][cnt];
            }
        }
		return ans;
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
			int Arg0 = 10;
			int Arg1 = 3;
			int Arr2[] = {30, 40, 50, 60, 70, 80, 90, 100, 110, 120};
			int Arg3 = 12345;
			long long Arg4 = 4LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, count(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 4;
			int Arr2[] = {0, 10, 2, 9, 5, 4, 6, 7, 3};
			int Arg3 = 47;
			long long Arg4 = 11LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, count(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 13;
			int Arg1 = 5;
			int Arr2[] = {47023};
			int Arg3 = 12345678;
			long long Arg4 = 5LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, count(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MedianSegments ___test;
	___test.run_test(-1);
}
// END CUT HERE
