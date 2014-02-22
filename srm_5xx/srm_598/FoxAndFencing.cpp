// BEGIN CUT HERE
/*
SRM 598 Div1 Medium (550)

PROBLEM STATEMENT
Fox Ciel is playing a board game with her friend Squirrel Liss.
The game is played on an infinite strip of paper.
The strip of paper is divided into consecutive cells.
Each cell has an integer coordinate.
Formally, for each integer i, the left neighbor of cell i is cell (i-1) and the right neighbor of cell i is cell (i+1).

Each of the players has a single token called the fencer.
At the beginning of the game, Ciel's fencer is in cell 0 and Liss's fencer is in cell d.
Each of the fencers has two limits: its maximum move length and its hitting range.
For Ciel's fencer the maximum move length is mov1 and the hitting range is rng1.
Similarly, for Liss's fencer we have the parameters mov2 and rng2.
Note that the parameters of Liss's fencer may differ from the ones of Ciel's fencer.

The players take alternating turns.
Ciel goes first.
In each turn the current player starts by moving her fencer.
The distance between the original cell and the destination cell must be at most equal to the fencer's maximum move length.
(It is also allowed to leave the fencer in the same cell.)
Then, the current player checks whether the other fencer lies within the hitting range - that is, whether the current distance between the fencers is at most equal to the current fencer's hitting range.
If that is the case, the game ends and the current player wins.

You are given the ints mov1, mov2, rng1, rng2, and d.
Return "Ciel" (quotes for clarity) if Fox Ciel has a winning strategy, "Liss" if Squirrel Liss has a winning strategy, and "Draw" otherwise.


DEFINITION
Class:FoxAndFencing
Method:WhoCanWin
Parameters:int, int, int, int, int
Returns:string
Method signature:string WhoCanWin(int mov1, int mov2, int rng1, int rng2, int d)


CONSTRAINTS
-mov1 will be between 1 and 100,000,000, inclusive.
-mov2 will be between 1 and 100,000,000, inclusive.
-rng1 will be between 1 and 100,000,000, inclusive.
-rng2 will be between 1 and 100,000,000, inclusive.
-d will be between 1 and 100,000,000, inclusive.


EXAMPLES

0)
1
58
1
58
2

Returns: "Ciel"

The attributes of Ciel's fencer are much smaller than the attributes of Liss's fencer.
Luckily for Ciel, she can win the game in her first turn:
she should move her fencer to cell 1 and from there she can hit the other fencer.


1)
2
1
1
100
50

Returns: "Liss"

Ciel cannot score a hit in the first turn.
After Ciel's turn, her fencer will be on one of the cells {-2,-1,0,1,2}.
Regardless of its precise location, Liss can always move her fencer one cell to the left and then hit Ciel.


2)
2
1
1
100
150

Returns: "Draw"

Clearly, Ciel has no chance of winning this game.
However, this time the initial distance d is big enough for Ciel to escape.


3)
100
100
100
100
100000000

Returns: "Draw"


4)
100
1
100
1
100000000

Returns: "Ciel"


5)
100
1
100
250
100000000

Returns: "Draw"


6)
100
1
100
150
100000000

Returns: "Ciel"


7)
100
50
100
1
100000000

Returns: "Ciel"


8)
100
150
100
1
100000000

Returns: "Draw"

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class FoxAndFencing {

	int solve(int mov1, int mov2, int rng1, int rng2, int d) {
		if (rng1+mov1 >= d) {
			return 1;
		}
		if (rng2+mov2 >= d+mov1) {
			return 2;
		}
		if (mov1 > mov2) {
			if (mov1 > mov2*2+rng2-rng1) {
				return 1;
			}
		}
		if (mov1 < mov2) {
			if (mov2 > mov1*2+rng1-rng2) {
				return 2;
			}
		}
		return 0;
	}

public:
	string WhoCanWin(int mov1, int mov2, int rng1, int rng2, int d) {
		const char *result[] = {"Draw", "Ciel", "Liss"};
		return result[solve(mov1, mov2, rng1, rng2, d)];
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
			int Arg1 = 58;
			int Arg2 = 1;
			int Arg3 = 58;
			int Arg4 = 2;
			string Arg5 = "Ciel";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 100;
			int Arg4 = 50;
			string Arg5 = "Liss";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 100;
			int Arg4 = 150;
			string Arg5 = "Draw";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 100;
			int Arg3 = 100;
			int Arg4 = 100000000;
			string Arg5 = "Draw";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 1;
			int Arg2 = 100;
			int Arg3 = 1;
			int Arg4 = 100000000;
			string Arg5 = "Ciel";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 1;
			int Arg2 = 100;
			int Arg3 = 250;
			int Arg4 = 100000000;
			string Arg5 = "Draw";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 1;
			int Arg2 = 100;
			int Arg3 = 150;
			int Arg4 = 100000000;
			string Arg5 = "Ciel";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 50;
			int Arg2 = 100;
			int Arg3 = 1;
			int Arg4 = 100000000;
			string Arg5 = "Ciel";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_8
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 150;
			int Arg2 = 100;
			int Arg3 = 1;
			int Arg4 = 100000000;
			string Arg5 = "Draw";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 8162034;
			int Arg1 = 9177151;
			int Arg2 = 906682;
			int Arg3 = 4158573;
			int Arg4 = 9228270;
			string Arg5 = "Draw";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndFencing ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
