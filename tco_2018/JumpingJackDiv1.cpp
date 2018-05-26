// BEGIN CUT HERE
/*
TCO18 Fun Round Beijing Easy (250)

PROBLEM STATEMENT

Jack, your pet frog, is quite a special frog.
He usually makes exactly one jump per day.
The only exception: once every k days he takes a rest and on that day he does not jump at all.

It is now the morning of day 0.
Jack the frog is currently sitting immediately next to your house.
Each day at noon Jack makes a decision:
If the day number is divisible by k, Jack remains where he is.
Otherwise, he jumps dist meters away from your house.

For instance, suppose we have dist=2 and k=2.
Jack's journey will look as follows:

on day 0 Jack stays at your house.
on day 1 at noon Jack jumps 2 meters away from your house.
on day 2 Jack remains 2 meters from your house.
on day 3 at noon Jack jumps another 2 meters away from your house. Thus, he is now 4 meters away from the house.
on day 4 Jack remains 4 meters from your house,
on day 5 at noon Jack jumps again and now he is 6 meters away from the house.
... and so on.

You are given three positive integers: dist, k, and n.
Compute and return the distance between Jack and your house in the evening of day n.


DEFINITION
Class:JumpingJackDiv1
Method:getLocationOfJack
Parameters:int, int, int
Returns:int
Method signature:int getLocationOfJack(int dist, int k, int x)


CONSTRAINTS
-dist will be between 1 and 100, inclusive.
-k will be between 2 and 100, inclusive.
-n will be between 0 and 1,000, inclusive. 


EXAMPLES

0)
2
2
0

Returns: 0

Jack jumps 2 meters and takes a break once every 2 days. In the evening of day 0 he will still be at your house, so the distance between Jack and the house is 0.


1)
2
2
1

Returns: 2

At noon of day 1 Jack jumps 2 meters away from your house. Thus, in the evening of day 1 Jack will be 2 meters away from your house.


2)
2
2
2

Returns: 2


3)
2
2
3

Returns: 4

In this scenario Jack will make two jumps: on day 1 and then on day 3.


4)
2
2
4

Returns: 4


5)
3
7
10

Returns: 27


6)
5
2
10

Returns: 25

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

class JumpingJackDiv1 {
public:
	int getLocationOfJack(int dist, int k, int x) {
		int ans = 0;
		for (int i = 0; i <= x; ++i) {
			if (i % k) {
				ans += dist;
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
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 0;
			int Arg3 = 0;

			verify_case(n, Arg3, getLocationOfJack(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 1;
			int Arg3 = 2;

			verify_case(n, Arg3, getLocationOfJack(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 2;
			int Arg3 = 2;

			verify_case(n, Arg3, getLocationOfJack(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 3;
			int Arg3 = 4;

			verify_case(n, Arg3, getLocationOfJack(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 4;
			int Arg3 = 4;

			verify_case(n, Arg3, getLocationOfJack(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 7;
			int Arg2 = 10;
			int Arg3 = 27;

			verify_case(n, Arg3, getLocationOfJack(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 2;
			int Arg2 = 10;
			int Arg3 = 25;

			verify_case(n, Arg3, getLocationOfJack(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	JumpingJackDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
