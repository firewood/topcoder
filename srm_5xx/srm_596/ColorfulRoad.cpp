// BEGIN CUT HERE
/*
SRM 596 Div2 Medium (500)

PROBLEM STATEMENT

There is a one-dimensional road.
The road is separated into N consecutive parts.
The parts are numbered 0 through N-1, in order.
Ciel is going to walk from part 0 to part N-1.

Ciel also noticed that each part of the road has a color: either red, green, or blue.
Part 0 is red.

Ciel is going to perform a sequence of steps.
Each step must lead in the positive direction.
That is, if her current part is i, the next step will take her to one of the parts i+1 through N-1, inclusive.
Her steps can be arbitrarily long.
However, longer steps are harder: a step of length j costs j*j energy.

Additionally, Ciel wants to step on colors in a specific order: red, green, blue, red, green, blue, ...
That is, she starts on the red part 0, makes a step to a green part, from there to a blue part, and so on, always repeating red, green, and blue in a cycle.
Note that the final part N-1 also has some color and thus Ciel must reach it in a corresponding step.

You are given a string road containing N elements.
For each i, element i of road is the color of part i: 'R' represents red, 'G' green, and 'B' blue.
If Ciel can reach part N-1 in the way described above, return the smallest possible total cost of doing so.
Otherwise, return -1.


DEFINITION
Class:ColorfulRoad
Method:getMin
Parameters:string
Returns:int
Method signature:int getMin(string road)


CONSTRAINTS
-road will contain between 2 and 15 characters, inclusive.
-Each character of road will be either 'R' or 'G' or 'B'.
-The first character of road will be 'R'.


EXAMPLES

0)
"RGGGB"

Returns: 8

The optimum solution is to step part 0 -> part 2 -> part 4.
The total cost is 2*2 + 2*2 = 8.


1)
"RGBRGBRGB"

Returns: 8

The optimum solution is to make steps of length 1.
It costs 1*1 = 1 per each step, so the total cost is 8.


2)
"RBBGGGRR"

Returns: -1

It is impossible to reach the destination.


3)
"RBRRBGGGBBBBR"

Returns: 50


4)
"RG"

Returns: 1


5)
"RBRGBGBGGBGRGGG"

Returns: 52

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ColorfulRoad {
public:
	int getMin(string road) {
		int cost[20] = {};
		int next[256] = {};
		next['R'] = 'G';
		next['G'] = 'B';
		next['B'] = 'R';
		for (int i = 1; i < (int)road.length(); ++i) {
			cost[i] = 99999999;
		}
		cost[0] = 0;
		for (int i = 1; i < (int)road.length(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (next[road[j]] == road[i]) {
					cost[i] = min(cost[i], cost[j] + (i-j)*(i-j));
				}
			}
		}
		if (cost[road.length()-1] >= 99999999) {
			return -1;
		}
		return cost[road.length()-1];
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
			string Arg0 = "RGGGB";
			int Arg1 = 8;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RGBRGBRGB";
			int Arg1 = 8;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RBBGGGRR";
			int Arg1 = -1;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RBRRBGGGBBBBR";
			int Arg1 = 50;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RG";
			int Arg1 = 1;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RBRGBGBGGBGRGGG";
			int Arg1 = 52;

			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ColorfulRoad ___test;
	___test.run_test(-1);
}
// END CUT HERE
