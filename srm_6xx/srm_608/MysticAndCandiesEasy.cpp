// BEGIN CUT HERE
/*
SRM 608 Div2 Medium (500)

PROBLEM STATEMENT
TopCoder admin mystic_tc is sitting in front of a table. He found N sealed boxes of candies on the table.

He is not sure how many candies each box contains. However, he knows the following information:

The total number of candies in the boxes is C.
For each i, box i (0-based index) contains between 0 and high[i] candies, inclusive.

You know that mystic_tc eats candies as follows: first he chooses a subset of the boxes, then he opens them and eats all the candies he found inside.
He wants to eat at least X candies.
And as he is smart, he will always choose a subset of boxes for which he is sure that they must contain at least X candies.

You are given the ints C and X, and the vector <int> high.
Return the smallest number of boxes mystic_tc may choose.


DEFINITION
Class:MysticAndCandiesEasy
Method:minBoxes
Parameters:int, int, vector <int>
Returns:int
Method signature:int minBoxes(int C, int X, vector <int> high)


CONSTRAINTS
-high will contain between 1 and 50 elements, inclusive.
-Each element of high will be between 1 and 50, inclusive.
-C will be between 1 and the sum of all elements of high, inclusive.
-X will be between 1 and C, inclusive.


EXAMPLES

0)
10
10
{20}

Returns: 1

There is only one box. It contains all 10 candies. In order to eat 10 candies mystic_tc must open it.


1)
10
7
{3, 3, 3, 3, 3}

Returns: 4

Now there are many possibilities for the contents of boxes.
For example, there could be three boxes with 3 candies each, one box with 1 candy, and one empty box.
Another possibility is that there could be five boxes with 2 candies each.
Note that in this case mystic_tc could open three boxes and still get only 6 candies, so he needs to open at least four boxes to be sure he gets at least 7 candies.
And it can be proved that if mystic_tc opens any four of these boxes, they will always contain at least 7 candies in total.


2)
100
63
{12, 34, 23, 45, 34}

Returns: 3

Open boxes 1, 3, 4 (0-based). It can be proved that these boxes contain at least 65 candies in total.


3)
19
12
{12, 9, 15, 1, 6, 4, 9, 10, 10, 10, 14, 14, 1, 1, 12, 10, 9, 2, 3, 6, 1, 7, 3, 4, 10, 3, 14}

Returns: 22


4)
326
109
{9, 13, 6, 6, 6, 16, 16, 16, 10, 16, 4, 3, 10, 8, 11, 17, 12, 5, 7, 8, 7, 4, 15, 7, 14, 2, 2, 1, 17, 1, 7, 7, 12, 17, 2, 9, 7, 1, 8, 16, 7, 4, 16, 2, 13, 3, 13, 1, 17, 6}

Returns: 15

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class MysticAndCandiesEasy {
public:
	int minBoxes(int C, int X, vector <int> high) {
		int N = (int)high.size();
		int ans = N;
		sort(high.begin(), high.end());
		int t = C;
		for (int i = 0; i < N; ++i) {
			t -= high[i];
			if (t >= X) {
				ans = min(ans, N - i - 1);
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
			int Arg0 = 10;
			int Arg1 = 10;
			int Arr2[] = {20};
			int Arg3 = 1;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minBoxes(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 7;
			int Arr2[] = {3, 3, 3, 3, 3};
			int Arg3 = 4;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minBoxes(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 63;
			int Arr2[] = {12, 34, 23, 45, 34};
			int Arg3 = 3;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minBoxes(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 19;
			int Arg1 = 12;
			int Arr2[] = {12, 9, 15, 1, 6, 4, 9, 10, 10, 10, 14, 14, 1, 1, 12, 10, 9, 2, 3, 6, 1, 7, 3, 4, 10, 3, 14};
			int Arg3 = 22;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minBoxes(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 326;
			int Arg1 = 109;
			int Arr2[] = {9, 13, 6, 6, 6, 16, 16, 16, 10, 16, 4, 3, 10, 8, 11, 17, 12, 5, 7, 8, 7, 4, 15, 7, 14, 2, 2, 1, 17, 1, 7, 7, 12, 17, 2, 9, 7, 1, 8, 16, 7, 4, 16, 2, 13, 3, 13, 1, 17, 6};
			int Arg3 = 15;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minBoxes(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MysticAndCandiesEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
