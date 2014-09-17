// BEGIN CUT HERE
/*
SRM 633 Div1 Easy (250)

PROBLEM STATEMENT
Frog Suwako lives on a two-dimensional plane.
Currently, she is located in the point (0, 0).
She would like to reach the point (x, 0).

Suwako jumps in a peculiar way: her jump lengths repeat in a periodic fashion.
The vector <int> jumpLengths contains one period of her jump lengths, starting with the length of the first jump she will make.
For example, if jumpLengths = { 2, 5 }, Suwako's jump lengths will be 2, 5, 2, 5, 2, 5, ...
Note that Suwako can jump onto arbitrary points in the plane, they are not required to have integer coordinates.

You are given the int x and the vector <int> jumpLengths.
Return the smallest non-negative integer j such that Suwako can reach the desired destination after j jumps.
If there is no such j, return -1 instead.


DEFINITION
Class:PeriodicJumping
Method:minimalTime
Parameters:int, vector <int>
Returns:int
Method signature:int minimalTime(int x, vector <int> jumpLengths)


CONSTRAINTS
-x will be between -1,000,000,000 and 1,000,000,000, inclusive.
-len will contain between 1 and 50 elements, inclusive.
-Each element in len will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
15
{1,2,3,4,5,6,7,8,9,10}

Returns: 5

In 4 jumps Suwako cannot get far enough. In 5 jumps she can reach the destination as follows: (0,0) -> (1,0) -> (3,0) -> (6,0) -> (10,0) -> (15,0).


1)
5
{5}

Returns: 1

One jump is enough, since the distance between (0,0) and (5,0) is exactly 5.


2)
1
{10}

Returns: 2

Here Suwako needs two jumps. One possible solution is to land at (0.5, sqrt(10*10-0.5*0.5)) after the first jump.


3)
-10
{2,3,4,500,6,7,8}

Returns: 11


4)
-1000000000
{1}

Returns: 1000000000


5)
0
{19911120}

Returns: 0

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class PeriodicJumping {
public:
	int minimalTime(int x, vector <int> jumpLengths) {
		if (x == 0) {
			return 0;
		}

		int ans = 0;
		LL X = abs(x);
		LL N = jumpLengths.size();

		LL sum = 0;
		for (int a : jumpLengths) {
			sum += a;
		}

		if (X >= sum * 2) {
			LL loops = X / sum - 1;		// for X==sum*2
			ans += (int)(loops * N);
			sum *= loops;
			for (LL i = 0;; ++i) {
				++ans;
				sum += jumpLengths[i % N];
				if (sum >= X) {
					return ans;
				}
			}
		}

		sum = 0;
		LL m = 0;
		for (LL i = 0; ; ++i) {
			++ans;
			LL j = jumpLengths[i % N];
			sum += j;
			m = max(m, j);
			if (sum >= X && m <= (X + sum - m)) {
				break;
			}
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
			int Arg0 = 15;
			int Arr1[] = {1,2,3,4,5,6,7,8,9,10};
			int Arg2 = 5;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {5};
			int Arg2 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {10};
			int Arg2 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = -10;
			int Arr1[] = {2,3,4,500,6,7,8};
			int Arg2 = 11;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = -1000000000;
			int Arr1[] = {1};
			int Arg2 = 1000000000;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arr1[] = {19911120};
			int Arg2 = 0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;




		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = { 1,10 };
			int Arg2 = 4;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = { 1, 3 };
			int Arg2 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = { 1, 5, 2 };
			int Arg2 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = { 1, 8, 2, 2 };
			int Arg2 = 4;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = { 1, 8, 2, 1 };
			int Arg2 = 5;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = { 8, 2, 2, 1 };
			int Arg2 = 4;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = { 4, 8 };
			int Arg2 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = { 4, 8, 1 };
			int Arg2 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = { 8, 16, 32 };
			int Arg2 = 4;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = { 8, 16, 24 };
			int Arg2 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 290;
			int Arr1[] = { 1,100 };
			int Arg2 = 6;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arr1[] = { 1, 1, 536870912, 536870912, 536870912, 536870912, 536870912, 536870912, 536870912, 536870912 };
			int Arg2 = 4;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PeriodicJumping ___test;
	___test.run_test(-1);
}
// END CUT HERE
