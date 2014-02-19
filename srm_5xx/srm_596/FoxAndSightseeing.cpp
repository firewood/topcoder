// BEGIN CUT HERE
/*
SRM 596 Div2 Easy (250)

PROBLEM STATEMENT

Fox Ciel is staying in Linear Country for sightseeing.
The country consists of N cities numbered 0 through N-1.
Ciel is currently staying in city 0.

In this problem, we assume that the country is a straight line and that each city is a point on this line.
You are given a vector <int> position with N elements.
The i-th element in position represents the coordinate of the city i.
The cities are numbered arbitrarily, their numbers are not related to their positions.
Thus, distance between city i and city j is |position[i] - position[j]|,
where |z| represents the absolute value of z.

Ciel wanted to visit all the cities, so she planned a tour.
She was going to visit city 0 on day 1, visit city 1 on day 2, and so on.
She wanted to terminate the tour upon arrival to city N-1.

Unfortunately, it turned out that Ciel's holiday has to be one day shorter.
Of course, she must still start in city 0 and end in city N-1, so she decided to skip one of the other N-2 cities (i.e., one of cities 1 through N-2).
She still wants to visit the other cities in the order given by their numbers.
For example, if N=5, Ciel has three possibilities for her holiday: she will visit the cities in one of the orders (0,1,2,4), (0,1,3,4), or (0,2,3,4).

Among these possibilities, Ciel will choose the one where the total distance she will have to travel is minimized.
Compute and return this minimum total distance.


DEFINITION
Class:FoxAndSightseeing
Method:getMin
Parameters:vector <int>
Returns:int
Method signature:int getMin(vector <int> position)


NOTES
-You are not given the value of N, but you can easily determine it: N is equal to the number of elements in position.


CONSTRAINTS
-position will contain between 3 and 50 elements, inclusive.
-Each element of position will be between -100 and 100, inclusive.
-All the elements in position will be distinct.


EXAMPLES

0)
{1, 4, -1, 3}

Returns: 4

There are two strategies for Ciel.

Skip city 1. The total distance is |1-(-1)|+|(-1)-3| = 2+4 = 6.
Skip city 2. The total distance is |1-4|+|4-3| = 3+1 = 4.

The second choice is better. So you should output 4.


1)
{-2, 4, 3}

Returns: 5

There is only one strategy for Ciel: She skips city 1. The total distance is |(-2)-3| = 5.


2)
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

Returns: 9

For any choice she makes, the total distance is 9.


3)
{100, -100, 99, -99}

Returns: 199

The optimum strategy is to skip city 1.


4)
{74,84,92,23,5,-70,-47,-59,24,-86,-39,99,85,-42,54,100,47,-3,42,38}

Returns: 836


5)
{2,-3,5,7,-11,-13,17,-19,23,29,-31,-37,-41,43,-47,-53,-59,61,-67,71}

Returns: 535

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class FoxAndSightseeing {
public:
	int getMin(vector <int> position) {
		int ans = 999999;
		for (int i = 1; i < ((int)position.size()-1); ++i) {
			int pos = position[0];
			int c = 0;
			for (int j = 1; j < (int)position.size(); ++j) {
				if (i != j) {
					c += abs(pos - position[j]);
					pos = position[j];
				}
			}
			ans = min(ans, c);
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
			int Arr0[] = {1, 4, -1, 3};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-2, 4, 3};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			int Arg1 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, -100, 99, -99};
			int Arg1 = 199;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {74,84,92,23,5,-70,-47,-59,24,-86,-39,99,85,-42,54,100,47,-3,42,38};
			int Arg1 = 836;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,-3,5,7,-11,-13,17,-19,23,29,-31,-37,-41,43,-47,-53,-59,61,-67,71};
			int Arg1 = 535;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndSightseeing ___test;
	___test.run_test(-1);
}
// END CUT HERE
