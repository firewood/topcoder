// BEGIN CUT HERE
/*
SRM 613 Div1 Easy (250)

PROBLEM STATEMENT

Cat Taro likes to play with his cat friends.
Each of his friends currently sits on some coordinate on a straight line that goes from the left to the right.
When Taro gives a signal, each of his friends must move exactly X units to the left or to the right.

You are given an vector <int> coordinates and the int X.
For each i, the element coordinates[i] represents the coordinate of the i-th cat before the movement.
Return the smallest possible difference between the positions of the leftmost cat and the rightmost cat after the movement.


DEFINITION
Class:TaroFriends
Method:getNumber
Parameters:vector <int>, int
Returns:int
Method signature:int getNumber(vector <int> coordinates, int X)


CONSTRAINTS
-coordinates will contain between 1 and 50 elements, inclusive.
-Each element of coordinates will be between -100,000,000 and 100,000,000, inclusive.
-X will be between 0 and 100,000,000, inclusive.


EXAMPLES

0)
{-3, 0, 1}
3

Returns: 3

The difference 3 is obtained if the cats move from {-3,0,1} to {0,-3,-2}.


1)
{4, 7, -7}
5

Returns: 4

The difference 4 is obtained if the cats move from {4,7,-7} to {-1,2,-2}.


2)
{-100000000, 100000000}
100000000

Returns: 0


3)
{3, 7, 4, 6, -10, 7, 10, 9, -5}
7

Returns: 7


4)
{-4, 0, 4, 0}
4

Returns: 4


5)
{7}
0

Returns: 0

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TaroFriends {
public:
	int getNumber(vector <int> coordinates, int X) {
		int ans = 1 << 30;
		sort(coordinates.begin(), coordinates.end());
		for (int i = 0; i < (int)coordinates.size(); ++i) {
			int left = (1 << 30);
			int right = -(1 << 30);
			for (int j = 0; j < (int)coordinates.size(); ++j) {
				int pos = coordinates[j] + (j < i ? X : -X);
				left = min(pos, left);
				right = max(pos, right);
			}
			ans = min(ans, right - left);
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
			int Arr0[] = {-3, 0, 1};
			int Arg1 = 3;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 7, -7};
			int Arg1 = 5;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-100000000, 100000000};
			int Arg1 = 100000000;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3, 7, 4, 6, -10, 7, 10, 9, -5};
			int Arg1 = 7;
			int Arg2 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-4, 0, 4, 0};
			int Arg1 = 4;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7};
			int Arg1 = 0;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TaroFriends ___test;
	___test.run_test(-1);
}
// END CUT HERE
