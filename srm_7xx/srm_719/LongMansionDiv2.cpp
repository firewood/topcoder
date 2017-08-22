// BEGIN CUT HERE
/*
SRM 719 Div2 Medium (500)

PROBLEM STATEMENT
LYC is the pet dog of Emperor Zhangzj of Yali Empire. Zhangzj has a huge affluence.
Besides his palace, he has multiple estates. One of them is the Long Mansion,
a famous site in Yali. LYC loves to play.
One day, he accidentally enters the labyrinthine Long Mansion.

The mansion can be seen as a grid of N rows, indexed from 0 to (N - 1) from up to down,
and M columns, indexed from 0 to (M - 1) from left to right.
Initially, LYC is standing on the cell in the top left corner.
The exit is in the bottom right corner.
In other words, LYC wants to travel from row 0 and column 0 to row (N - 1) and column (M - 1).
LYC can walk from one cell directly to another if and only if they share a side.
He wants to reach the exit as soon as possible..

Unfortunately, each cell contains some obstacles that slow LYC down.
For each cell we know the time LYC needs to spend there while passing through the cell.
LYC also needs to spend that amount of time in the initial cell and in the exit cell as well.
There is a pattern to the obstacles: each column of the mansion looks the same.
In other words, all cells within any given row contain the same obstacle type,
and therefore they delay LYC by the same amount of time. For example,
the entire first row are some bushes, the entire second row contains some walls, and so on.
You are given the times in the vector <int> t.
More precisely, LYC will spend t[i] time in each cell he visits in row i.

You are given one int M, and one vector <int> t.
Return the minimal time LYC needs to spend to reach the exit.


 DEFINITION
Class:LongMansionDiv2
Method:minimalTime
Parameters:int, vector <int>
Returns:long long
Method signature:long long minimalTime(int M, vector <int> t)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-M will be between 1 and 1,000,000,000, inclusive.
-t will contain exactly N elements.
-Each element of t will be between 1 and 1,000, inclusive.


EXAMPLES

0)
3
{1, 2, 1}

Returns: 6

LYC's path can be (0, 0) &rarr (0, 1) &rarr (1, 1) &rarr (2, 1) &rarr (2, 2). The time he spends will be 1 + 1 + 2 + 1 + 1 = 6. Note that the first and last cell count as well.


1)
4
{3, 2, 4, 2}

Returns: 17

This time, LYC's path can be (0, 0) &rarr (1, 0) &rarr (1, 1) &rarr (1, 2) &rarr (2, 2) &rarr (3, 2) &rarr (3, 3).


2)
5
{3, 2, 5, 4, 2, 8}

Returns: 32


3)
1000000000
{1000}

Returns: 1000000000000

Watch out for overflow.


4)
1
{1}

Returns: 1

*/
// END CUT HERE

#include <algorithm>
#include <iostream>
#include <sstream>
#include <numeric>
#include <vector>

using namespace std;

class LongMansionDiv2 {
	public:
	long long minimalTime(int M, vector <int> t) {
        long long ans = accumulate(t.begin(), t.end(), 0LL);
        long long m = *min_element(t.begin(), t.end());
        ans += m * (M - 1);
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
			int Arg0 = 3;
			int Arr1[] = {1, 2, 1};
			long long Arg2 = 6LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {3, 2, 4, 2};
			long long Arg2 = 17LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {3, 2, 5, 4, 2, 8};
			long long Arg2 = 32LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000000;
			int Arr1[] = {1000};
			long long Arg2 = 1000000000000LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {1};
			long long Arg2 = 1LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalTime(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE
};

// BEGIN CUT HERE
int main() {
	LongMansionDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
