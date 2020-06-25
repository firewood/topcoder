// BEGIN CUT HERE
/*
SRM 787 Div1 Easy (250)

PROBLEM STATEMENT

Aqa Asadi is a kind teacher who puts a lot of effort into helping students grow and make friends.

N students stand in a line.
They are numbered 0 through N-1, in order.
Student i is A[i] seconds old.

Aqa Asadi came up with a formula that measures how difficult it is for two students to become friends: for students i and j, the difficulty is |A[j] - A[i]| / |j - i|.
In the formula, |x| denotes the absolute value of x.

Find the pair of students with the smallest difficulty to form a friendship, and return that difficulty.

Use the following pseudocode for generating the array A[0..N-1]:

for i = 0 to N-1:
    if i < length(P):
        A[i] = P[i]
    if i == length(P):
        A[i] = B0
    if i > length(P):
        A[i] = (A[i-1] * X + Y) modulo 1000000007


DEFINITION
Class:AqaAsadiMinimizes
Method:getMin
Parameters:vector <int>, int, int, int, int
Returns:double
Method signature:double getMin(vector <int> P, int B0, int X, int Y, int N)


NOTES
-The returned value will be accepted if its relative or absolute error does not exceed 1e-9.


CONSTRAINTS
-N will be between 2 and 500,000, inclusive.
-P will have between 0 and N elements, inclusive.
-P will have at most 100 elements.
-B0, X, Y, and all elements of P will be between 0 and 1,000,000,006, inclusive.


EXAMPLES

0)
{11, 0, 30, 20, 1000}
0
0
0
5

Returns: 3.0

The best pair are the students i=0 and j=3, their difficulty of forming a friendship is |20 - 11| / |3 - 0| = 9/3 = 3.


1)
{47, 1, 10, 3, 2}
0
0
0
5

Returns: 0.3333333333333333

Students i=1 and j=4 are the best choice here.


2)
{123456}
234567890
345678
456789
10

Returns: 8333191.571428572

A = {123456, 234567890, 958968621, 353106369, 103025544, 664206330, 514591322, 898217931, 176235549, 752137571}

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

class AqaAsadiMinimizes {
public:
	double getMin(vector <int> P, int B0, int X, int Y, int N) {
		const int MAX = 1 << 30;
		vector<int> mn(N, MAX);
		vector<int> a = P;
		a.resize(N);
		for (int i = P.size(); i < N; ++i) {
			if (i == P.size()) {
				a[i] = B0;
			} else {
				a[i] = ((LL)a[i - 1] * X + Y) % 1000000007;
			}
		}
		map<int, int> m;
		m[a[0]] = 0;
		for (int i = 1; i < N; ++i) {
			auto it = m.lower_bound(a[i]);
			auto prev = it;
			auto next = it;
			if (it != m.begin()) {
				--prev;
			}
			int d = i - prev->second;
			mn[d] = min(mn[d], abs(prev->first - a[i]));
			if (it != m.end()) {
				++next;
				int d = i - it->second;
				mn[d] = min(mn[d], abs(it->first - a[i]));
				if (next != m.end()) {
					d = i - next->second;
					mn[d] = min(mn[d], abs(next->first - a[i]));
				}
			}
			m[a[i]] = i;
		}
		double ans = 1e16;
		for (int i = 1; i < N; ++i) {
			ans = min(ans, (double)mn[i] / i);
		}
/*
		int cnt = 0;
		for (int i = N - 1; i > 0; --i) {
			for (int j = 0; j < N - i; ++j) {
				double diff = abs(a[i + j] - a[j]);
				ans = min(ans, diff / i);
			}
			cnt += N - i;
			if (cnt > 100000000) break;
		}
*/
		return ans;

	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {11, 0, 30, 20, 1000};
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 0;
			int Arg4 = 5;
			double Arg5 = 3.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg5, getMin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {47, 1, 10, 3, 2};
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 0;
			int Arg4 = 5;
			double Arg5 = 0.3333333333333333;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg5, getMin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {123456};
			int Arg1 = 234567890;
			int Arg2 = 345678;
			int Arg3 = 456789;
			int Arg4 = 10;
			double Arg5 = 8333191.571428572;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg5, getMin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AqaAsadiMinimizes ___test;
	___test.run_test(-1);
}
// END CUT HERE
