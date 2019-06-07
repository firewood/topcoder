// BEGIN CUT HERE
/*
TCO19 R2A Easy (250)

PROBLEM STATEMENT

You have a straight stick that is exactly 1,000,000 micrometers long.
You also have n tiny stickers.
Each sticker can be used to mark some point on the stick.
You want to place the stickers in a way that creates a makeshift ruler.
For each distance x between 1 and ceiling(n^2 / 4) there have to be two stickers that are exactly x micrometers apart.

Return a vector <int> with n elements: the positons of stickers (in micrometers, measured from one fixed end of the stick).
A solution always exists. Any valid solution will be accepted.


DEFINITION
Class:RulerMaker
Method:placeStickers
Parameters:int
Returns:vector <int>
Method signature:vector <int> placeStickers(int n)


NOTES
-The value ceiling(x) is the smallest integer greater than or equal to x. For example, ceiling(47) = 47, and ceiling(42.01) = 43.
-The position of each sticker must be an integer between 0 and 1,000,000, inclusive.
-If you don't place a sticker onto the end of the stick, you cannot use that end of the stick for a measurement. E.g., placing a single sticker at coordinate 3 does not allow you to measure the distance 3, only placing two stickers at coordinates 0 and 3 does.


CONSTRAINTS
-n will be between 2 and 1,000, inclusive.


EXAMPLES

0)
3

Returns: {47, 50, 49 }

As ceiling(3^2 / 4) = 3, we have to place three stickers in such a way that we can measure (at least) the distances of 1, 2, and 3 micrometers.
If we place the stickers at coordinates A=47, B=50, and C=49, we see that 1 is the distance between B and C, 2 is the distance between A and C, and 3 is the distance between A and B.


1)
7

Returns: {38, 26, 35, 47, 31, 39, 37 }

Here we need the distances from 1 to 13, inclusive.

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class RulerMaker {
public:
	vector <int> placeStickers(int n) {
		vector <int> ans;
		for (int i = 0; i < n; ++i) {
			if (i < (n + 1) / 2) {
				ans.push_back(i + 1);
			} else {
				ans.push_back(ans.back() + (n + 1) / 2);
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {47, 50, 49 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, placeStickers(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arr1[] = {38, 26, 35, 47, 31, 39, 37 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, placeStickers(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 2;
			int Arr1[] = { 1, 2 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, placeStickers(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RulerMaker ___test;
	___test.run_test(-1);
}
// END CUT HERE
