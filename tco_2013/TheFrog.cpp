// BEGIN CUT HERE
/*
TCO13 Round 1A Medium (500)

// PROBLEM STATEMENT
// Frog Jim is fond of jumping.
Moreover, all his jumps have the same length X.
Currently, he is standing at the point 0 on the real axis.
He needs to jump along the axis until he gets to point D or beyond it.

There are several pits between points 0 and D. 
For each valid i, there is a pit strictly between L[i] and R[i].
This means that Jim cannot step onto any point that is strictly between points L[i] and R[i].
(He is allowed to step onto the points L[i] and R[i]: as all pits are disjoint, the endpoints of each pit are always safe.)

Find the minimum length of jump X such that if Jim performs only jumps of length X, he can avoid every pit and get to point D or any point beyond it. Note that this length can be non-integer.

DEFINITION
Class:TheFrog
Method:getMinimum
Parameters:int, vector <int>, vector <int>
Returns:double
Method signature:double getMinimum(int D, vector <int> L, vector <int> R)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-D will be between 1 and 30,000, inclusive.
-L will contain between 1 and 50 elements, inclusive.
-Each element of L will be between 0 and D-1, inclusive.
-R will contain the same number of elements as L.
-The i-th element of R will be between L[i]+1 and D, inclusive.
-The intervals given by (L[i], R[i]) will not intersect.


EXAMPLES

0)
16
{2}
{7}

Returns: 7.0

Moving by jumps of length 7, Jim goes from point 0 to point 7,
then to point 14 and then to point 21, which is beyond 16.
If Jim chose a shorter jump, he would end up in the pit.


1)
25
{11, 3}
{21, 7}

Returns: 10.5

There are two pits. One of them is between points 11 and 21 and the other between points 3 and 7.
By fixing jump length at 10.5, Jim successfully avoids them.


2)
100
{0}
{100}

Returns: 100.0

Jim has no other choice but to jump right to point 100.


3)
100
{0, 50}
{50, 100}

Returns: 50.0

In this case, point 50 is a suitable place to land, so Jim can choose X = 50.


4)
30000
{17, 25281, 5775, 2825, 14040}
{55, 26000, 5791, 3150, 14092}

Returns: 787.8787878787879

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

static const double eps = 1e-10;

class TheFrog {
public:
	double getMinimum(int D, vector <int> L, vector <int> R) {
		double ans = 30000.0;
		int sz = (int)L.size();
		int i, j, k;
		for (i = 0; i < sz; ++i) {
			for (j = 1; ; ++j) {
				double d = (double)R[i] / (double)j;
				if (d < 1.0) {
					break;
				}
				for (k = 0; k < sz; ++k) {
					double jumps = floor((double)L[k] / d + eps);
					double next_pos = (jumps + 1.0) * d + eps;
					if ((int)next_pos < R[k]) {
						break;
					}
				}
				if (k >= sz) {
					ans = min(ans, d);
				}
			}
		}

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
			int Arg0 = 16;
			int Arr1[] = {2};
			int Arr2[] = {7};
			double Arg3 = 7.0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getMinimum(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 25;
			int Arr1[] = {11, 3};
			int Arr2[] = {21, 7};
			double Arg3 = 10.5;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getMinimum(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arr1[] = {0};
			int Arr2[] = {100};
			double Arg3 = 100.0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getMinimum(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arr1[] = {0, 50};
			int Arr2[] = {50, 100};
			double Arg3 = 50.0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getMinimum(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 30000;
			int Arr1[] = {17, 25281, 5775, 2825, 14040};
			int Arr2[] = {55, 26000, 5791, 3150, 14092};
			double Arg3 = 787.8787878787879;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getMinimum(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 10482;
			int Arr1[] = {122, 312, 909, 1267, 2645, 2832, 3501, 4434, 5018, 5106, 5585, 6171, 6408, 7565, 9555, 10192};
			int Arr2[] = {249, 481, 1176, 2364, 2825, 3329, 4299, 4460, 5087, 5412, 5725, 6269, 7175, 7784, 9943, 10338};
			double Arg3 = 2485.75;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getMinimum(Arg0, Arg1, Arg2));
//			verify_case(n, Arg3, getMinimum_wujianan2007(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 17005;
			int Arr1[] = {2379, 378, 11270, 16798, 6165, 3084, 9563, 14913, 7842, 2910, 2455, 7789, 7279, 3763, 12783, 9605, 8165, 2246, 8945, 3237, 2783, 11812, 4552, 1478, 16703, 7420, 21, 4751, 3828, 1636, 219, 180, 14811};
			int Arr2[] = {2428, 405, 11280, 16844, 6190, 3117, 9602, 14925, 7879, 2939, 2473, 7837, 7285, 3775, 12796, 9645, 8211, 2252, 8979, 3272, 2831, 11858, 4583, 1481, 16745, 7438, 44, 4801, 3857, 1658, 247, 211, 14858};
			double Arg3 = 167.69662921348313;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getMinimum(Arg0, Arg1, Arg2));
//			verify_case(n, Arg3, getMinimum_wujianan2007(Arg0, Arg1, Arg2));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheFrog ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
