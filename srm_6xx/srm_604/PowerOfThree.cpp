// BEGIN CUT HERE
/*
SRM 604 Div1 Easy (250)

PROBLEM STATEMENT
Fox Ciel has a robot.
The robot is located on an infinite plane.
At the beginning, the robot starts at the coordinates (0, 0).
The robot can then make several steps.
The steps are numbered starting from 0.

In each step, Ciel must choose one of four directions for the robot: left (x coordinate decreases), right (x coordinate increases), up (y coordinate increases), or down (y coordinate decreases).
In step k, the robot will move 3^k units in the chosen direction.
It is not allowed to skip a step.

You are given ints x and y.
Return "Possible" (quotes for clarity) if it is possible that the robot reaches the point (x,y) after some (possibly zero) steps.
Otherwise, return "Impossible".


DEFINITION
Class:PowerOfThree
Method:ableToGet
Parameters:int, int
Returns:string
Method signature:string ableToGet(int x, int y)


CONSTRAINTS
-x will be between -1,000,000,000 and 1,000,000,000, inclusive.
-y will be between -1,000,000,000 and 1,000,000,000, inclusive.


EXAMPLES

0)
1
3

Returns: "Possible"

In step 0 Ciel will send the robot right to (1,0). In step 1 she will send it up to (1,3).


1)
0
2

Returns: "Possible"

The robot will move from (0,0) down to (0,-1) and then up to (0,2).


2)
1
9

Returns: "Impossible"

Note that it is not allowed to move the robot right in step 0, skip step 1, and then move the robot up in step 2.


3)
3
0

Returns: "Impossible"


4)
1
1

Returns: "Impossible"


5)
-6890
18252

Returns: "Possible"


6)
1000000000
-1000000000

Returns: "Impossible"


7)
0
0

Returns: "Possible"

*/
// END CUT HERE

#include <string> 
#include <vector> 
#include <iostream> 
#include <sstream> 

using namespace std; 

typedef long long LL;

class PowerOfThree {

	bool check(int x, int y) {
		x = abs(x), y = abs(y);
		while (x != 0 || y != 0) {
			int a = x % 3, b = y % 3;
			if (((a == 1 || a == 2) && b == 0) || (a == 0 && (b == 1 || b == 2))) {
				x = (x + 1) / 3;
				y = (y + 1) / 3;
			} else {
				return false;
			}
		}
		return true;
	}

	public:
	string ableToGet(int x, int y) {
		return check(x, y) ? "Possible" : "Impossible";
	}


// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 3;
			string Arg2 = "Possible";

			verify_case(n, Arg2, ableToGet(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 2;
			string Arg2 = "Possible";

			verify_case(n, Arg2, ableToGet(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 9;
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableToGet(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 0;
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableToGet(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableToGet(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = -6890;
			int Arg1 = 18252;
			string Arg2 = "Possible";

			verify_case(n, Arg2, ableToGet(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000000;
			int Arg1 = -1000000000;
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableToGet(Arg0, Arg1));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 0;
			string Arg2 = "Possible";

			verify_case(n, Arg2, ableToGet(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE


};
// BEGIN CUT HERE 
int main() {
	PowerOfThree ___test;
	___test.run_test(-1);

}
// END CUT HERE

