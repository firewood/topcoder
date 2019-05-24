// BEGIN CUT HERE
/*
TCO19 R1B Easy (250)

PROBLEM STATEMENT

Elly hates the cold, but for some weird reason she likes skiing. Now she has started organizing a new ski adventure on a mountain ridge she hasn't visited before.

Elly has a map of the mountain ridge: the vector <int> height.
The mountain (when viewed from a side) has the shape of a polyline that goes through the points (0, height[0]), (1, height[1]), (2, height[2]), and so on.
For example, suppose height = {3, 4, 11, 6, 2, 2, 2, 5, 7, 7, 10, 8, 5, 8, 1, 4}.
If you walk along this mountain from the left to the right, you start at altitude 3, go up to altitude 4, then up some more to altitude 11. From there it goes down the hill to altitudes 6, 2, and so on.

Elly can hire a helicopter to bring her up to any point on the mountain. 
She can then pick a direction (either left or right) and start skiing.
There are only two restrictions:

She cannot ski uphill.
While skiing, she cannot change direction. (If she started skiing left, she cannot turn around and ski right, or vice versa.)

For example, suppose Elly starts at index 2 (altitude 11) and chooses to go right. In this case the longest possible ski run consists of five points: {11, 6, 2, 2, 2}. She cannot continue farther because the next segment of the mountain goes uphill.
Should she start at the same place and go left instead, she would only visit three points (altitudes 11, 4, and 3, in this order).

Find the longest section of the mountain Elly can ski in a single run, and return the number of points that form the section.


DEFINITION
Class:EllysSki
Method:getMax
Parameters:vector <int>
Returns:int
Method signature:int getMax(vector <int> height)


CONSTRAINTS
-height will contain between 1 and 50 elements, inclusive.
-Each element of height will be between 1 and 1000, inclusive.


EXAMPLES

0)
{3, 4, 11, 6, 2, 2, 2, 5, 7, 7, 10, 8, 5, 8, 1, 4}

Returns: 7

The example from the problem statement.
The optimal solution is to start at index 10 (altitude 10) and ski left. The points visited, in order in which Elly skis through them, have altitudes {10, 7, 7, 5, 2, 2, 2}.


1)
{42, 42, 42}

Returns: 3

This mountain is quite flat, but okay for skiing, according to Elly. She should start at either end and ski towards the other end.


2)
{543, 230, 421, 415, 271, 962, 677, 373, 951, 114, 379, 15, 211, 955, 66, 573, 982, 296, 730, 591}

Returns: 3


3)
{50, 77, 24, 86, 98, 84, 42, 70, 88, 78, 73, 17, 76, 68, 64, 65, 40, 77, 33, 87, 11, 23, 78, 20, 8, 74, 44, 95, 94, 78, 27, 88, 71, 40, 11, 98, 82, 85, 79, 89, 31, 67, 41, 61, 71, 62, 74, 77, 86, 36}

Returns: 4

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class EllysSki {
	int count(vector <int> height) {
		int prev = 1 << 30, cnt = 0, m = 0;
		for (int h : height) {
			if (h > prev) {
				cnt = 0;
			}
			++cnt;
			prev = h;
			m = max(m, cnt);
		}
		return m;
	}

public:
	int getMax(vector <int> height) {
		int ans = count(height);
		reverse(height.begin(), height.end());
		ans = max(ans, count(height));
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
			int Arr0[] = {3, 4, 11, 6, 2, 2, 2, 5, 7, 7, 10, 8, 5, 8, 1, 4};
			int Arg1 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMax(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {42, 42, 42};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMax(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {543, 230, 421, 415, 271, 962, 677, 373, 951, 114, 379, 15, 211, 955, 66, 573, 982, 296, 730, 591};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMax(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50, 77, 24, 86, 98, 84, 42, 70, 88, 78, 73, 17, 76, 68, 64, 65, 40, 77, 33, 87, 11, 23, 78, 20, 8, 74, 44, 95, 94, 78, 27, 88, 71, 40, 11, 98, 82, 85, 79, 89, 31, 67, 41, 61, 71, 62, 74, 77, 86, 36};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMax(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysSki ___test;
	___test.run_test(-1);
}
// END CUT HERE
