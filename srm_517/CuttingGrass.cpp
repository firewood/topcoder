// BEGIN CUT HERE
/*
// SRM 517 Div2 Hard (1000)
// PROBLEM STATEMENT
// There are N blades of grass in Fox Ciel's garden numbered 0 to N-1. Since she doesn't like tall grass,
she wants to make it so that the sum of heights of all grass blades is at most H.


At time 0, the height of the i-th grass blade is init[i]. At each positive integer time t,
the following activities happen (in the specified relative order):


1. First, for each i, 0 <= i < N, the i-th grass blade becomes higher by grow[i].

2. Then, Ciel chooses a single grass blade and cuts it. The height of this grass blade becomes zero.

3. Finally, Ciel calculates the sum of heights of all grass blades.
If it is at most H, then she considers her goal achieved.


Return the earliest possible time she can achieve her goal.
If the sum of heights of all grass blades doesn't exceed H at time 0, return 0.
If it's impossible to achieve the goal, return -1.


DEFINITION
Class:CuttingGrass
Method:theMin
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int theMin(vector <int> init, vector <int> grow, int H)


CONSTRAINTS
-init will contain between 1 and 50 elements, inclusive.
-init and grow will contain the same number of elements.
-Each element of init will be between 0 and 100,000, inclusive.
-Each element of grow will be between 1 and 100,000, inclusive.
-H will be between 0 and 1,000,000, inclusive.


EXAMPLES

0)
{5, 8, 58}
{2, 1, 1}
16

Returns: 1

At time 1:

The heights of grass blades 0, 1, 2 become 7, 9, 59, respectively.
Suppose that Ciel cuts grass blade 2. The height of grass blade 2 becomes zero.
The sum of heights of all grass blades is 7 + 9 + 0 = 16, so she achieves her goal.


1)
{5, 8}
{2, 1}
58

Returns: 0

At time 0, the sum of heights of all grass blades is 13 and doesn't exceed H.

2)
{5, 8}
{2, 1}
0

Returns: -1

It's impossible to achieve the goal.

3)
{5, 1, 6, 5, 8, 4, 7}
{2, 1, 1, 1, 4, 3, 2}
33

Returns: 5

One of the optimal strategies is to cut grass blade 2, 0, 6, 5, 4 (0-indexed) at time 1, 2, 3, 4, 5 respectively.

4)
{49, 13, 62, 95, 69, 75, 62, 96, 97, 22, 69, 69, 52}
{7, 2, 4, 3, 6, 5, 7, 6, 5, 4, 7, 7, 4}
517

Returns: 8



5)
{1231, 1536, 1519, 1940, 1539, 1385, 1599, 1613, 1394, 1803,
 1763, 1706, 1863, 1452, 1818, 1914, 1386, 1954, 1496, 1722,
 1616, 1862, 1755, 1215, 1233, 1078, 1448, 1241, 1732, 1561,
 1633, 1307, 1844, 1911, 1371, 1338, 1989, 1789, 1656, 1413,
 1929, 1182, 1815, 1474, 1540, 1797, 1586, 1427, 1996, 1202}
{86, 55, 2, 86, 96, 71, 81, 53, 79, 22,
 23, 8, 69, 32, 35, 39, 30, 18, 92, 64,
 88, 1, 48, 81, 91, 75, 44, 77, 3, 33,
 9, 52, 56, 4, 19, 73, 52, 18, 8, 77,
 91, 59, 50, 62, 42, 87, 89, 24, 71, 67}
63601

Returns: 36



#line 107 "CuttingGrass.cpp"
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

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;
typedef pair<int, int> IntPair;
typedef vector<IntPair> IntPairVec;

class CuttingGrass {

public:
	int theMin(vector <int> init, vector <int> grow, int H) {
#define INIT(i) v[i].second
#define GROW(i) v[i].first
		int N = init.size();
		LL dp[52][52] = {0};
		int i, j;
		IntPairVec v;
		for (i = 0; i < N; ++i) {
			v.push_back(IntPair(grow[i], init[i]));
		}
		sort(v.begin(), v.end());
		int gsum = 0;
		for (i = 0; i < N; ++i) {
			// 切らない場合の合計値
			dp[i + 1][0] = dp[i][0] + INIT(i);
			for (j = 1; j <= i; ++j) {
				// (i-1)まででj本切ってi番目が成長するのと
				// (i-1)までで(j-1)本切ってi番目を切るのの最小値
				dp[i+1][j] = min(dp[i][j]+INIT(i)+GROW(i)*j, dp[i][j-1]+gsum);
			}
			// used for dp[N][N]
			dp[i+1][j] = dp[i][j-1] + gsum;
			gsum += GROW(i);
		}

		for (j = 0; j <= N; ++j) {
			// j本切った合計がH以下ならOK
			if (dp[N][j] <= H) {
				return j;
			}
		}
		return -1;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 8, 58}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16; int Arg3 = 1; verify_case(0, Arg3, theMin(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 58; int Arg3 = 0; verify_case(1, Arg3, theMin(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = -1; verify_case(2, Arg3, theMin(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {5, 1, 6, 5, 8, 4, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 1, 1, 4, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 33; int Arg3 = 5; verify_case(3, Arg3, theMin(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {49, 13, 62, 95, 69, 75, 62, 96, 97, 22, 69, 69, 52}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 2, 4, 3, 6, 5, 7, 6, 5, 4, 7, 7, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 517; int Arg3 = 8; verify_case(4, Arg3, theMin(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {1231, 1536, 1519, 1940, 1539, 1385, 1599, 1613, 1394, 1803,
 1763, 1706, 1863, 1452, 1818, 1914, 1386, 1954, 1496, 1722,
 1616, 1862, 1755, 1215, 1233, 1078, 1448, 1241, 1732, 1561,
 1633, 1307, 1844, 1911, 1371, 1338, 1989, 1789, 1656, 1413,
 1929, 1182, 1815, 1474, 1540, 1797, 1586, 1427, 1996, 1202}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {86, 55, 2, 86, 96, 71, 81, 53, 79, 22,
 23, 8, 69, 32, 35, 39, 30, 18, 92, 64,
 88, 1, 48, 81, 91, 75, 44, 77, 3, 33,
 9, 52, 56, 4, 19, 73, 52, 18, 8, 77,
 91, 59, 50, 62, 42, 87, 89, 24, 71, 67}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 63601; int Arg3 = 36; verify_case(5, Arg3, theMin(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CuttingGrass ___test;
//	___test.run_test(2);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
