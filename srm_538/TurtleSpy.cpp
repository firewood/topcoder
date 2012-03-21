// BEGIN CUT HERE
/*
// SRM 538 Div1 Medium (450)

// PROBLEM STATEMENT
// The Very Heterogeneous State of Feudalia's army is designing a new spy robot. The robot is disguised as a turtle and takes four different commands:

"right X", where X is a integer between 1 and 359, inclusive. Will add X degrees to the turtle's direction angle. 
"left X", where X is a integer between 1 and 359, inclusive. Will subtract X degrees from the turtle's direction angle. 
"forward X", where X is a integer. Will move X units in the direction given by the turtle's direction angle.
"backward X", where X is a integer. Will move X units in the opposite direction of the turtle's direction angle (The angle minus 180 degrees).

The army created a program that made the robot infiltrate deeply into foreign land by making the robot terminate as far as possible from the original location. Unfortunately, Feudalia is world famous for the ineptitude of its public officials. The program got mixed up and there is no way to tell the original order of the commands. You are given a vector <string> commands. Each element of commands represents a command in the described format. Find the order for all of the commands in the input that will maximize the Euclidean distance between the point where the robot was started and the point it reached after all commands were executed. Return the maximum distance.



DEFINITION
Class:TurtleSpy
Method:maxDistance
Parameters:vector <string>
Returns:double
Method signature:double maxDistance(vector <string> commands)


NOTES
-The Euclidean distance between the points (x1,y1) and (x2,y2) is sqrt( (x2-x1)^2 + (y2-y1)^2 ).


CONSTRAINTS
-commands will contain between 1 and 50 elements, inclusive.
-Each element of commands will be a string in the form "COMM X", where COMM is one of "left", "right", "forward" or "backward" (quotes for clarity) and X is a integer between 1 and 1000, inclusive.
-For each element of commands, if the command is "left" or "right" then X will not exceed 359.


EXAMPLES

0)
{"forward 100", "backward 100", "left 90" }

Returns: 141.4213562373095

That distance is possible if we make sure to run the "left 90" command inbetween the other two commands.

1)
{"left 45", "forward 100", "right 45", "forward 100"}

Returns: 200.0

We can, for example, run the commands in the following order:
 "forward 100", "left 45", "right 45" and "forward 100".



2)
{"left 10", "forward 40",  "right 30", "left 10", "backward 4", "forward 4" }

Returns: 40.58520737741619

*/
// END CUT HERE
#define _USE_MATH_DEFINES
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;

class TurtleSpy {

public:
	double maxDistance(vector <string> commands) {
		double res = 0;
		IntVec angles;

		double back = 0;
		int i, j;
		for (i = 0; i < (int)commands.size(); ++i) {
			stringstream s(commands[i]);
			string c;
			int v;
			s >> c >> v;
			if (c.compare("forward") == 0) {
				res += v;
			}
			if (c.compare("backward") == 0) {
				back += v;
			}
			if (c.compare("left") == 0) {
				angles.push_back(v);
			}
			if (c.compare("right") == 0) {
				angles.push_back(-v);
			}
		}

		IntVec f(360);
		f[0] = 1;
		if (angles.size() > 0) {
			for (i = 0; i < (int)angles.size(); ++i) {
				IntVec next = f;
				for (j = 0; j < 360; ++j) {
					if (f[j]) {
						int a = (j + angles[i] + 360) % 360;
						next[a] = 1;
					}
				}
				f = next;
			}
		}
		int Max = 0;
		for (j = 0; j < 360; ++j) {
			if (f[j]) {
				if (abs(180 - j) < abs(180 - Max)) {
					Max = j;
				}
			}
		}

		if (back > 0) {
				double rad = ((double)Max * M_PI * 2.0) / 360.0;
				double x = res - back * cos(rad);
				double y = back * sin(rad);
				res = sqrt(x*x + y*y);
		}

		return res;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"forward 100", "backward 100", "left 90" };
			double Arg1 = 141.4213562373095;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"left 45", "forward 100", "right 45", "forward 100"};
			double Arg1 = 200.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"left 10", "forward 40",  "right 30", "left 10", "backward 4", "forward 4" };
			double Arg1 = 40.58520737741619;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"forward 1", "backward 1", "left 2", "left 3", "left 5", "left 7"};
			double Arg1 = 0.29561882225922065;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TurtleSpy ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
