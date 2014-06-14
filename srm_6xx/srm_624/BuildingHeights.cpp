// BEGIN CUT HERE
/*
SRM 624 Div1 Easy (250)

PROBLEM STATEMENT
Byteland is a city with many skyscrapers, so it's a perfect venue for BASE jumping. Danilo is an enthusiastic BASE jumper. He plans to come to Byteland and to jump off some of its buildings.

Danilo can make arbitrarily many jumps in Byteland. However, he has some rules. First, he never jumps off the same building twice. Second, all buildings he selects for his jumps must have the same number of floors. (This is for safety reasons: It is hard to get the timing right if each jump starts at a different height.)

Philipe is the mayor of Byteland. He welcomes Danilo's visit as he would like to use it as a publicity stunt. Of course, the more jumps Danilo makes, the better the publicity will be. But what if there aren't enough buildings with the same height? To avoid this issue, the mayor is willing to prepare the town for Danilo's visit. Before Danilo arrives, Philipe wants to build additional floors on some of the skyscrapers in Byteland.

You are given a vector <int> heights. Each element of heights is the number of floors in one of Byteland's skyscrapers. Let N be the number of elements in heights. For each M between 1 and N, inclusive, answer the following question: What is the smallest number of additional floors the mayor has to build so that there will be at least M buildings with the same number of floors?

For each i between 1 and N, inclusive, let A[i] be the answer to the above question for M = i+1. Return the value (A[1] XOR A[2] XOR ... XOR A[N]).


DEFINITION
Class:BuildingHeights
Method:minimum
Parameters:vector <int>
Returns:int
Method signature:int minimum(vector <int> heights)


NOTES
-You may assume that the correct return value always fits into a signed 32-bit integer variable.
-Each question should be answered independently of the others. For example, when trying to produce four buildings with the same number of floors, you do not have to start from the optimal solution for three buildings.


CONSTRAINTS
-heights contains between 1 and 4,000 elements, inclusive.
-Each element of heights will be between 1 and 4,000, inclusive.


EXAMPLES

0)
{1, 5, 4, 3, 8}

Returns: 22


Danilo can jump off a building without any changes to the city.
To get two equally tall buildings we need to build one additional floor. For example, we can increase building #2 (0-based index) from 4 to 5 floors.
To get three equally tall buildings we need to build three additional floors: one on building #2 and two on building #3. This way, the buildings #1, #2, and #3 will have 5 floors each.
To get four equally tall buildings we need to build seven additional floors.
Making all five buildings equally tall requires us to build 19 additional floors.


1)
{1, 2, 3}

Returns: 2


2)
{3, 4, 1, 6, 8, 1}

Returns: 21


3)
{990, 20, 2359, 1667, 51, 2455, 1659, 1093, 2015, 205, 656, 752, 1760, 1594, 857,
 2033, 1868, 1932, 2408, 1518, 91, 2220, 1696, 1552, 933, 143, 1888, 1261, 2298, 1975,
 929, 2139, 1994, 2139, 158, 896, 2093, 1816, 841, 459, 2020, 1496, 63, 131, 589, 919,
 1015, 1308, 350, 922, 326, 1792, 641, 2021, 843, 425, 1015, 231, 1685, 2165, 1057,
 1465, 655, 550, 1103, 812, 297, 2048, 1479, 1137, 6, 2350, 1484, 1420, 1332, 925, 2338,
 1198, 2232, 1539, 2119, 57, 830, 1611, 929, 525, 888}

Returns: 56068

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class BuildingHeights {
public:

	int minimum(vector <int> heights) {
		int N = (int)heights.size();
		sort(heights.begin(), heights.end());
		int sum[4000] = {};
		for (int i = 0; i < N; ++i) {
			sum[i + 1] = sum[i] + heights[i];
		}
		int ans = 0;
		for (int M = 2; M <= N; ++M) {
			int c = 1 << 30;
			for (int i = M - 1; i < N; ++i) {
				// s <- sum of i,i-1,...,i-M+1
				int s = sum[i + 1] - sum[i + 1 - M];
				c = min(c, heights[i] * M - s);
			}
			ans ^= c;
		}
		return ans;
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
			int Arr0[] = {1, 5, 4, 3, 8};
			int Arg1 = 22;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimum(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimum(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3, 4, 1, 6, 8, 1};
			int Arg1 = 21;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimum(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {990, 20, 2359, 1667, 51, 2455, 1659, 1093, 2015, 205, 656, 752, 1760, 1594, 857,
 2033, 1868, 1932, 2408, 1518, 91, 2220, 1696, 1552, 933, 143, 1888, 1261, 2298, 1975,
 929, 2139, 1994, 2139, 158, 896, 2093, 1816, 841, 459, 2020, 1496, 63, 131, 589, 919,
 1015, 1308, 350, 922, 326, 1792, 641, 2021, 843, 425, 1015, 231, 1685, 2165, 1057,
 1465, 655, 550, 1103, 812, 297, 2048, 1479, 1137, 6, 2350, 1484, 1420, 1332, 925, 2338,
 1198, 2232, 1539, 2119, 57, 830, 1611, 929, 525, 888};
			int Arg1 = 56068;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimum(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 4000 };
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimum(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 4000,4001 };
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimum(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BuildingHeights ___test;
	___test.run_test(-1);
}
// END CUT HERE
