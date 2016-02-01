// BEGIN CUT HERE
/*
SRM 680 Div2 Medium (500)

PROBLEM STATEMENT
I guess you have never seen a bear eating at a table.
The reason is simple: bears don't use tables.
However, they may sometimes decide to sit on a chair while eating.

Bear Limak is a waiter in a huge restaurant for bears.
The restaurant has infinitely many chairs.
The chairs are arranged in a single long row.
In order, they are numbered using all positive integers: 1, 2, 3, ...
Chair number 1 is closest to the entrance to the restaurant.

A bear takes a lot of space while eating, and all bears value their personal space.
Limak knows that there is a universal constant d with the following meaning:
Whenever two bears sit on chairs, their chair numbers must differ by d or more.
For example, if d=10, you can have two bears in chairs 47 and 57, but you cannot have bears in chairs 47 and 56.

The restaurant just opened for the day and all chairs are empty.
During the day exactly N guests arrived, one at a time.
Whenever a guest arrived, Limak assigned them a chair.
Each guest stayed in the restaurant in their assigned chair until the end of the day.

Generally, guests don't like to be seated close to the entrance because of the noise from the street.
You are given a vector <int> atLeast with N elements: one for each guest, in order.
For each i from 0 to N-1, guest i came with a request: "My chair number must be greater than or equal to atLeast[i]."

When seating a guest, Limak always assigns them the smallest available chair number.
(That is, the smallest chair number that matches the guest's request and is at least d away from each of the bears who are already in the restaurant.)
Return a vector <int> with N elements: for each guest, in the order in which they arrived, the number of the chair where they will be seated.


DEFINITION
Class:BearChairs
Method:findPositions
Parameters:vector <int>, int
Returns:vector <int>
Method signature:vector <int> findPositions(vector <int> atLeast, int d)


CONSTRAINTS
-N will be between 1 and 1000, inclusive.
-atLeast will have exactly N elements.
-Each element in atLeast will be between 1 and 10^6, inclusive.
-d will be between 1 and 10^6, inclusive.


EXAMPLES

0)
{1,21,11,7}
10

Returns: {1, 21, 11, 31 }

Here is what will happen:

Guest 0 wants a chair with a number greater or equal to 1. He gets the chair 1.
Guest 1 wants a chair with a number greater or equal to 21. She gets the chair 21.
Guest 2 wants a chair with a number greater or equal to 11. He gets the chair 11. Note that this chair is still far enough from each of the two bears who are already sitting in the restaurant.
Guest 3 wants a chair with a number greater or equal to 7. The smallest available chair is chair number 31. All free chairs with smaller numbers are too close to some of the previous guests.


1)
{1,21,11,7}
11

Returns: {1, 21, 32, 43 }

The guests have the same requests as in Example 0 but d is larger. Thus, guest 2 doesn't fit between guests 0 and 1 and must be seated in a chair with a larger number.


2)
{1000000,1000000,1000000,1}
1000000

Returns: {1000000, 2000000, 3000000, 4000000 }


3)
{1000000,1000000,1000000,1}
999999

Returns: {1000000, 1999999, 2999998, 1 }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class BearChairs {
public:
	vector <int> findPositions(vector <int> atLeast, int d) {
		vector <int> ans;
		vector <int> sorted;
		for (int a : atLeast) {
			for (int i = 0; i != sorted.size(); ++i) {
				if (sorted[i] + d < a) {
					;
				} else if ((sorted[i] <= a && a <= sorted[i] + d) || (a < sorted[i] && sorted[i] < a + d)) {
					a = sorted[i] + d;
				}
			}
			sorted.push_back(a);
			sort(sorted.begin(), sorted.end());
			ans.push_back(a);
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
			int Arr0[] = {1,21,11,7};
			int Arg1 = 10;
			int Arr2[] = {1, 21, 11, 31 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findPositions(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,21,11,7};
			int Arg1 = 11;
			int Arr2[] = {1, 21, 32, 43 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findPositions(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000,1000000,1000000,1};
			int Arg1 = 1000000;
			int Arr2[] = {1000000, 2000000, 3000000, 4000000 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findPositions(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000,1000000,1000000,1};
			int Arg1 = 999999;
			int Arr2[] = {1000000, 1999999, 2999998, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findPositions(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearChairs ___test;
	___test.run_test(-1);
}
// END CUT HERE
