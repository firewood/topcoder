// BEGIN CUT HERE
/*
SRM 786 Div2 Easy (250)

PROBLEM STATEMENT

There is a cuboid (a rectangular box) of dimensions L x B x H. Vivek and Jeel decided to play the game CUT THE CUBE.

In this game, the players make moves alternately and the player who cannot make a move loses. Vivek starts the game. Below we define a move.

A move consists of cutting a cuboid along the xy plane, the xz plane, or the yz plane (lengthwise, breadthwise or heightwise).
The two new pieces must again have integer dimensions.
Hence, a cut is only possible if the dimension that is being cut is still greater than 1.

Initially, there is only one cuboid, so Vivek must cut that one into two smaller pieces.
Afterwards, Jeel must choose and cut one of those two pieces.
Next, Vivek must cut one of the three cuboids he currently sees, and so on.

Find out who wins if they both play optimally. Return 1 if Vivek wins otherwise return 2.


DEFINITION
Class:CutTheCube
Method:findWinner
Parameters:int, int, int
Returns:int
Method signature:int findWinner(int L, int B, int H)


CONSTRAINTS
-L will be between 1 and 100,000, inclusive.
-B will be between 1 and 100,000, inclusive.
-H will be between 1 and 100,000, inclusive.


EXAMPLES

0)
1
1
1

Returns: 2

Since all dimensions are 1, Vivek cannot make any move and Jeel wins immediately.


1)
2
1
1

Returns: 1

In this case, Vivek can only cut the cuboid lengthwise. After this move Jeel will end up with two 1x1x1 cubes which cannot be cut further. Hence Vivek wins.


2)
2
2
1

Returns: 1


3)
97931
95210
92383

Returns: 1

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
#include <cstring>

using namespace std;

class CutTheCube {
public:
	int findWinner(int L, int B, int H) {
		long long x = (long long)L * B * H;
		return x % 2 ? 2 : 1;
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
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 2;

			verify_case(n, Arg3, findWinner(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 1;

			verify_case(n, Arg3, findWinner(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 1;
			int Arg3 = 1;

			verify_case(n, Arg3, findWinner(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 97931;
			int Arg1 = 95210;
			int Arg2 = 92383;
			int Arg3 = 1;

			verify_case(n, Arg3, findWinner(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CutTheCube ___test;
	___test.run_test(-1);
}
// END CUT HERE
