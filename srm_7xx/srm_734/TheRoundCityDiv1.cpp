// BEGIN CUT HERE
/*
SRM 734 Div1 Easy (300)

PROBLEM STATEMENT
John and Brus have found a nice horizontal plane and they built a round city somewhere on the plane.
The center of the city is at coordinates (0, 0).
This point is left empty.
There is a house at each other lattice point that is at most r units away from the city center.
That is, the lattice point (x, y) other than (0, 0) contains a house if and only if sqrt(x*x + y*y) ? r.

John and Brus are wondering how many houses are visible from the city center.
A house is visible if and only if there are no other houses on the line segment connecting the house and the city center.
(For the purpose of this definition, each house is a single point.)

You are given the int r.
Return the number of houses that are visible from the city center.


DEFINITION
Class:TheRoundCityDiv1
Method:find
Parameters:int
Returns:long long
Method signature:long long find(int r)


CONSTRAINTS
-r will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
1

Returns: 4

There are four houses in the city: at (0, 1), (0, -1), (1, 0), and (-1, 0).
All four of them are visible from the city center.


1)
2

Returns: 8

There are twelve houses in the city: 

(0, 1), (0, -1), (1, 0), (-1, 0), 

(1, 1), (1, -1), (-1, 1), (-1, -1),

(0, 2), (0, -2), (2, 0), (-2, 0), 

The last four are not visible from the city center. For example, (0, 2) is not visible because (0, 1) is on the line segment from (0, 2) to the city center.


2)
3

Returns: 16

There are twenty-eight houses in the city:

(0, 1), (0, -1), (1, 0), (-1, 0), 

(0, 2), (0, -2), (2, 0), (-2, 0), (1, 1), (1, -1), (-1, 1), (-1, -1),

(0, 3), (0, -3), (3, 0), (-3, 0), (1, 2), (1, -2), (-1, 2), (-1, -2),

(2, 1), (2, -1), (-2, 1), (-2, -1), (2, 2), (2, -2), (-2, 2), (-2, -2).


Twelve of them:

(0, 2), (0, -2), (2, 0), (-2, 0),

(0, 3), (0, -3), (3, 0), (-3, 0), (2, 2), (2, -2), (-2, 2), (-2, -2)

are not visible from the city center.


3)
47

Returns: 4176

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

class TheRoundCityDiv1 {
public:
	long long find(int _r) {
		LL r = _r;
		vector<LL> p(1000001);
		for (LL i = 2; i <= r; ++i) {
			if (!p[i]) {
				for (LL j = i; j <= r; j += i) {
					p[j] = i;
				}
			}
		}
		LL ans = 1;
		for (LL i = 1; i < r; ++i) {
			LL factors[16];
			LL fcnt = 0;
			LL m = (LL)sqrt(r * r - i * i);
			LL x = i;
			while (p[x]) {
				LL a = p[x];
				factors[fcnt++] = a;
				while ((x % a) == 0) {
					x /= a;
				}
			}
			LL bm = 1LL << fcnt;
			for (LL b = 1; b < bm; ++b) {
				LL y = 1, bcnt = 0;
				for (LL j = 0; j < fcnt; ++j) {
					if ((1LL << j) & b) {
						y *= factors[j];
						++bcnt;
					}
				}
				ans += (bcnt % 2) ? -m/y : m/y;
			}
			ans += m;
		}
		return ans * 4;
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
			int Arg0 = 1;
			long long Arg1 = 4LL;

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			long long Arg1 = 8LL;

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			long long Arg1 = 16LL;

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 47;
			long long Arg1 = 4176LL;

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1000000;
			long long Arg1 = 1909859313984LL;

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheRoundCityDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
