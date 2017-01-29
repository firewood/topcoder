// BEGIN CUT HERE
/*
SRM 706 Div2 Easy (250)

PROBLEM STATEMENT

Bear Limak has three boxes arranged in a row.
The first box currently contains a candies, the second one contains b candies, and the third one contains c candies.

Limak thinks that the three boxes would look nice if they had the following two properties:

Each box should contain at least one candy.
The numbers of candies should form a strictly increasing sequence. In other words, the first box should contain fewer candies than the second box, and the second box should contain fewer candies than the third one.

Limak can only modify the current content of the boxes in one way: he can eat some of the candies.

You are given the ints a, b, and c.
Compute and return the smallest possible number of candies Limak should eat in order to make his three boxes look nice.
If he has no way to make his boxes look nice, return -1 instead.


DEFINITION
Class:ThreeIncreasing
Method:minEaten
Parameters:int, int, int
Returns:int
Method signature:int minEaten(int a, int b, int c)


CONSTRAINTS
-a, b and c will each be between 1 and 3000, inclusive.


EXAMPLES

0)
15
40
22

Returns: 19

Limak can eat 19 candies from the second box.
Numbers of candies will form a strictly increasing sequence {15, 21, 22}.
Limak can't achieve a strictly increasing sequence after eating fewer than 19 candies, so the answer is 19.


1)
5
6
6

Returns: 2

Note that in a strictly increasing sequence every number should be strictly lower than the next number (ties are not allowed).
Here, Limak can eat 1 candy from the first box and 1 candy from the second box, which results in a sequence {4, 5, 6}.
The answer is 2 because Limak eats 2 candies.


2)
6
1
3000

Returns: -1

Here, the second box contains only 1 candy.
The first box should contain a smaller number of candies so Limak would have to eat all candies there.
A box can't become empty though, so the answer is -1.


3)
6
4
2

Returns: -1

As in the previous example, Limak cannot produce a strictly increasing sequence of candy counts without emptying one of the boxes.


4)
4
2
6

Returns: 3

Limak can eat 3 candies from the first box.


5)
1
1234
3000

Returns: 0

Limak doesn't have to eat any candies.
Boxes aren't empty and the sequence {1, 1234, 3000} is strictly increasing.


6)
2789
2400
1693

Returns: 1806

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ThreeIncreasing {
public:
	int minEaten(int a, int b, int c) {
		if (b < 2 || c < 3) {
			return -1;
		}
		int ans = max(0, b - c + 1);
		b -= ans;
		ans += max(0, a - b + 1);
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
			int Arg0 = 15;
			int Arg1 = 40;
			int Arg2 = 22;
			int Arg3 = 19;

			verify_case(n, Arg3, minEaten(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 6;
			int Arg2 = 6;
			int Arg3 = 2;

			verify_case(n, Arg3, minEaten(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 1;
			int Arg2 = 3000;
			int Arg3 = -1;

			verify_case(n, Arg3, minEaten(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 4;
			int Arg2 = 2;
			int Arg3 = -1;

			verify_case(n, Arg3, minEaten(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 2;
			int Arg2 = 6;
			int Arg3 = 3;

			verify_case(n, Arg3, minEaten(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1234;
			int Arg2 = 3000;
			int Arg3 = 0;

			verify_case(n, Arg3, minEaten(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2789;
			int Arg1 = 2400;
			int Arg2 = 1693;
			int Arg3 = 1806;

			verify_case(n, Arg3, minEaten(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ThreeIncreasing ___test;
	___test.run_test(-1);
}
// END CUT HERE
