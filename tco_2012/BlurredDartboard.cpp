// BEGIN CUT HERE
/*
// TCO 2012 R2B Easy (300)

// PROBLEM STATEMENT
Wojtek and Tomek are playing darts. Unfortunately the dartboard is blurred
and Wojtek can't read some of the numbers written on it. On the other hand,
Tomek remembers the numbers written on the dartboard.

The dartboard is divided into N parts. Wojtek knows that for each integer x
between 1 and N, inclusive, there is exactly one part that is worth x points.
You are given a vector <int> points containing N integers. If points[i] is
positive, the i-th part is worth points[i] points. If points[i] is zero,
he can't read the number that indicates the point value of the i-th part.

Wojtek and Tomek will play the following game. First, Wojtek throws K darts.
Wojtek is perfectly skilled at darts, so he will certainly hit the parts he
wants to hit. He is allowed to hit the same part with multiple darts. After
Wojtek throws all the darts, Tomek calculates Wojtek's total score. The total
score is simply the sum of the points hit by each of the darts. (Note that
each part of the dartboard may be counted multiple times if Wojtek hits it
with multiple darts.) If the total score is at least P points, Wojtek wins.
Otherwise, Tomek wins.

You are given the vector <int> points and the int P. Return the smallest K
such that Wojtek is guaranteed to win the game if he follows the optimal
strategy when throwing the darts.

DEFINITION
Class:BlurredDartboard
Method:minThrows
Parameters:vector <int>, int
Returns:int
Method signature:int minThrows(vector <int> points, int P)


CONSTRAINTS
-points will contain between 1 and 50 elements, inclusive.
-Each element of points will be between 0 and N, inclusive, where N is the
 number of elements in points.
-Each of the integers from 1 to N, inclusive, will appear at most once in points.
-P will be between 1 and 1,000,000,000 (109), inclusive.


EXAMPLES

0)
{0, 3, 4, 0, 0}
8

Returns: 2

Wojtek should hit part 2 twice. He will get 8 points.


1)
{0, 0, 0, 0, 0}
15

Returns: 5

Wojtek should hit each part exactly once. He doesn't know the point values, but the total score will be always 15.


2)
{4, 7, 8, 1, 3, 2, 6, 5}
2012

Returns: 252


3)
{0, 0, 5, 0, 0, 0, 1, 3, 0, 0}
2012

Returns: 307


4)
{0, 2, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 6, 0, 0, 0, 4, 0, 0, 0}
1000000000

Returns: 84656087

*/
// END CUT HERE
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

typedef vector<int> IntVec;

class BlurredDartboard {

public:
	int minThrows(vector <int> points, int P) {
		sort(points.begin(), points.end());
		int sz = points.size();
		int Max = points[sz-1];
		IntVec cnt(sz+1);
		int i, sum = 0;
		for (i = 0; i < sz; ++i) {
			++cnt[points[i]];
			sum += points[i];
		}
		int zsum = (sz+1)*sz/2 - sum;
		double zavg = cnt[0] > 0 ? (double)zsum / (double)cnt[0] : 0;
		if ((double)Max > zavg) {
			return (P + Max-1) / Max;
		}
		int zcnt = P / zsum;
		int res = cnt[0] * zcnt;
		P -= zsum * zcnt;
		zcnt = 0, zsum = 0;
		if (P > 0) {
			for (i = 1; i <= sz; ++i) {
				if (cnt[i] == 0) {
					++zcnt;
					zsum += i;
					if (zsum >= P) {
						break;
					}
				}
			}
			if (Max > 0) {
				zcnt = min(zcnt, (P+Max-1)/Max);
			}
		}
		return res + zcnt;
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
			int Arr0[] = {0, 3, 4, 0, 0};
			int Arg1 = 8;
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minThrows(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 0, 0};
			int Arg1 = 15;
			int Arg2 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minThrows(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 7, 8, 1, 3, 2, 6, 5};
			int Arg1 = 2012;
			int Arg2 = 252;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minThrows(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 5, 0, 0, 0, 1, 3, 0, 0};
			int Arg1 = 2012;
			int Arg2 = 307;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minThrows(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 2, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 6, 0, 0, 0, 4, 0, 0, 0};
			int Arg1 = 1000000000;
			int Arg2 = 84656087;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minThrows(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BlurredDartboard ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
