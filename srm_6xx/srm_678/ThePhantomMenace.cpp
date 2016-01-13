// BEGIN CUT HERE
/*
SRM 667 Div2 Easy (250)

PROBLEM STATEMENT
Obi Wan Kenobi and Qui-Gon Jinn are trying to escape from the Federation to find Queen Amidala.
They are currently trapped inside a building and they have to escape through one of the doors.

All doors are on the same side of the building.
You are given the coordinate of each door in the vector <int> doors.
The doors are protected by some droids.
Currently, all those droids are standing next to the wall with the doors.
You are given the coordinates of the droids in the vector <int> droids.

Our two heroes prefer a door that is as far as possible from all the droids.
For example, suppose that the doors are at positions { 2, 5, 8 } and that there are two droids: one at position 1 and the other at position 10.
The optimal door for the escape would be the door at position 5.
For this door, the two droids are 4 and 5 units of distance away from the door.
Hence, the closest droid is 4 units of distance away from the door.
Each of the other two doors is closer than that to one of the droids.

Formally, the safety level of a door is equal to the distance between the door and the droid that is closest to that door.
Compute the safety levels of all doors and return the maximum of those safety levels.


DEFINITION
Class:ThePhantomMenace
Method:find
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int find(vector <int> doors, vector <int> droids)


NOTES
-The distance between a door at coordinate x and a droid at coordinate y is |x-y|, that is, the absolute value of the difference between x and y.


CONSTRAINTS
-doors will contain between 1 and 10 elements.
-droids will contain between 1 and 10 elements.
-Each element of doors will be between 0 and 100 inclusive.
-Each element of droids will be between 0 and 100 inclusive.
-No number will appear more than once in the concatenation of doors and droids


EXAMPLES

0)
{1,2,3,4}
{5,6,7,8}

Returns: 4

There are four doors located at {1,2,3,4} and four droids located at {5,6,7,8}.
The safety level of the door at position 1 can be computed as follows:

Droid at position 5 is |5-1| = 4 units of distance away from this door.
Droid at position 6 is |6-1| = 5 units of distance away from this door.
Droid at position 7 is |7-1| = 6 units of distance away from this door.
Droid at position 8 is |8-1| = 7 units of distance away from this door.
Thus, the closest droid to our door is the one at position 5, and the safety level of our door is 4.

The other three doors have safety levels equal to 3, 2, and 1, respectively.
Thus, the best choice for the escape is the door at position 1.
The correct return value (i.e., the largest of all safety levels) is 4.


1)
{1}
{10}

Returns: 9

When there's only one candidate, there's only one choice.


2)
{2,3,5,7,11}
{1,8,13}

Returns: 3

If you use door at position 2, then you are at distance 1 from droid 1.

If you use door at position 3, then you are at distance 2 from droid 1.

If you use door at position 5, then you are at distance 3 from droid 2.

If you use door at position 7, then you are at distance 1 from droid 2.

If you use door at position 11, then you are at distance 2 from droid 3.

So all doors have droids at 3 or less units of distance. If you choose door at position 5 you have droids at distances 4, 3 and 8 so that's the best choice.


3)
{1,3,5,7,9,11,13,15,17,19}
{2,4,6,8,10,12,14,16,18,20}

Returns: 1

Every door is a possible choice for this test case.


4)
{2,1}
{4,3}

Returns: 2

Be careful! The input isn't always sorted.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ThePhantomMenace {
public:
	int find(vector <int> doors, vector <int> droids) {
		int ans = 0;
		for (int door : doors) {
			int d = 1 << 30;
			for (int droid : droids) {
				d = min(d, abs(door - droid));
			}
			ans = max(ans, d);
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
			int Arr0[] = {1,2,3,4};
			int Arr1[] = {5,6,7,8};
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			int Arr1[] = {10};
			int Arg2 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,3,5,7,11};
			int Arr1[] = {1,8,13};
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,3,5,7,9,11,13,15,17,19};
			int Arr1[] = {2,4,6,8,10,12,14,16,18,20};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,1};
			int Arr1[] = {4,3};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ThePhantomMenace ___test;
	___test.run_test(-1);
}
// END CUT HERE
