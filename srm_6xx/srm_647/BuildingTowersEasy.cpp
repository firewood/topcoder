// BEGIN CUT HERE
/*
SRM 647 Div1 Easy (250)

PROBLEM STATEMENT

The citizens of Byteland want to build N new buildings.
The new buildings will all stand in a line and they will be labeled 1 through N, in order.
The city regulations impose some restrictions on the heights of the new buildings.
You are given the parameters used in these restrictions: two vector <int>s x and t.
The restrictions are described below.

The height of each building must be a nonnegative integer.
The height of building 1 must be 0.
The absolute value of the difference between any two adjacent buildings must be at most 1.
For each valid i, the height of building x[i] must be t[i] or less.

Given these restrictions, the citizens of Byteland want to build a building that will be as tall as possible.
Return the largest possible height some of the N buildings may have.


DEFINITION
Class:BuildingTowersEasy
Method:maxHeight
Parameters:int, vector <int>, vector <int>
Returns:int
Method signature:int maxHeight(int N, vector <int> x, vector <int> t)


CONSTRAINTS
-N will be between 1 and 100,000, inclusive.
-x will contain between 0 and min(N,50) elements, inclusive.
-t will have exactly the same number of elements as x.
-Each element of x will be between 1 and N, inclusive.
-x[i] < x[i+1] for all valid i.
-Each element of t will be between 0 and 100,000, inclusive.


EXAMPLES

0)
10
{3,8}
{1,1}

Returns: 3


In this case we are going to build 10 buildings.
We have two constraints: the height of building 3 can be at most 1, and the height of building 8 can also be at most 1.
The tallest possible new building in this city can have height 3.
One optimal skyline looks as follows: {0,1,1,2,3,3,2,1,1,0}.


1)
100000
{}
{}

Returns: 99999

There are no additional constraints so, for each valid i, the height of building i can be (i-1).


2)
2718
{1,30,400,1300,2500}
{100000,100000,100000,100000,100000}

Returns: 2717


3)
20
{4,7,13,15,18}
{3,8,1,17,16}

Returns: 8


4)
447
{32,35,55,60,61,88,91,97,128,151,181,186,192,196,198,237,259,268,291,314,341,367,389,390,391,428,435}
{81,221,172,641,25,953,330,141,123,440,692,394,200,649,78,726,50,810,501,4,216,407,2,172,0,29,14}

Returns: 120


5)
97638
{8,1749,4550,5388,6752,7089,9737,14891,16671,16821,17691,19753,24589,
25348,30114,32213,34376,36467,37699,41490,44784,44893,57316,58275,58567,
61122,61489,63195,64776,65905,68788,69908,72853,78152,78784,82779,84488,
86277,88611,92793,93214,97583}
{16610,6,497,14,42892,31,79,1203,518,31147,597,7846,1396,8309,12,14,1148,
433,23693,13,1939,244,19,46,27,611,412,10,27023,19141,34,15667,588,10,229,
83,390,14,38441,16021,4,39386}

Returns: 6343

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class BuildingTowersEasy {
public:
	int maxHeight(int N, vector <int> x, vector <int> t) {
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			int h = i;
			for (int j = 0; j < (int)x.size(); ++j) {
				h = min(h, t[j] + abs(x[j] - 1 - i));
			}
			ans = max(ans, h);
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
			int Arg0 = 10;
			int Arr1[] = {3,8};
			int Arr2[] = {1,1};
			int Arg3 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, maxHeight(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100000;
			// int Arr1[] = {};
			// int Arr2[] = {};
			int Arg3 = 99999;

			vector <int> Arg1;
			vector <int> Arg2;
			verify_case(n, Arg3, maxHeight(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2718;
			int Arr1[] = {1,30,400,1300,2500};
			int Arr2[] = {100000,100000,100000,100000,100000};
			int Arg3 = 2717;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, maxHeight(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arr1[] = {4,7,13,15,18};
			int Arr2[] = {3,8,1,17,16};
			int Arg3 = 8;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, maxHeight(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 447;
			int Arr1[] = {32,35,55,60,61,88,91,97,128,151,181,186,192,196,198,237,259,268,291,314,341,367,389,390,391,428,435};
			int Arr2[] = {81,221,172,641,25,953,330,141,123,440,692,394,200,649,78,726,50,810,501,4,216,407,2,172,0,29,14};
			int Arg3 = 120;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, maxHeight(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 97638;
			int Arr1[] = {8,1749,4550,5388,6752,7089,9737,14891,16671,16821,17691,19753,24589,
25348,30114,32213,34376,36467,37699,41490,44784,44893,57316,58275,58567,
61122,61489,63195,64776,65905,68788,69908,72853,78152,78784,82779,84488,
86277,88611,92793,93214,97583};
			int Arr2[] = {16610,6,497,14,42892,31,79,1203,518,31147,597,7846,1396,8309,12,14,1148,
433,23693,13,1939,244,19,46,27,611,412,10,27023,19141,34,15667,588,10,229,
83,390,14,38441,16021,4,39386};
			int Arg3 = 6343;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, maxHeight(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BuildingTowersEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
