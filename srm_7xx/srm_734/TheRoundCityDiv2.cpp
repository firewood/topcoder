// BEGIN CUT HERE
/*
SRM 734 Div2 Easy (250)

PROBLEM STATEMENT
John and Brus have found a nice horizontal plane and they built a round city somewhere on the plane.
The center of the city is at coordinates (0, 0).
This point is left empty.
There is a house at each other lattice point that is at most r units away from the city center.
That is, the lattice point (x, y) other than (0, 0) contains a house if and only if sqrt(x*x + y*y) ? r.

John and Brus now want to count all houses in the city.
You are given the int r.
Return the number of houses.


DEFINITION
Class:TheRoundCityDiv2
Method:find
Parameters:int
Returns:int
Method signature:int find(int r)


CONSTRAINTS
-r will be between 1 and 100, inclusive.


EXAMPLES

0)
1

Returns: 4

There are four houses in the city:

(0, 1), (0, -1), (1, 0) and (-1, 0).


1)
2

Returns: 12

There are twelve houses in the city: 

(0, 1), (0, -1), (1, 0), (-1, 0), 

(0, 2), (0, -2), (2, 0), (-2, 0), (1, 1), (1, -1), (-1, 1) and (-1, -1).


2)
3

Returns: 28

There are twenty-eight houses in the city:

(0, 1), (0, -1), (1, 0), (-1, 0), 

(0, 2), (0, -2), (2, 0), (-2, 0), (1, 1), (1, -1), (-1, 1), (-1, -1),

(0, 3), (0, -3), (3, 0), (-3, 0), (1, 2), (1, -2), (-1, 2), (-1, -2),

(2, 1), (2, -1), (-2, 1), (-2, -1), (2, 2), (2, -2), (-2, 2) and (-2, -2).


3)
47

Returns: 6920

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

class TheRoundCityDiv2 {
public:
	int find(int r) {
		int ans = 0;
		for (int x = -r; x <= r; ++x) {
			for (int y = -r; y <= r; ++y) {
				ans += x * x + y * y <= r * r;
			}
		}
		return ans - 1;
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
			int Arg0 = 1;
			int Arg1 = 4;

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 12;

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 28;

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 47;
			int Arg1 = 6920;

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheRoundCityDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
