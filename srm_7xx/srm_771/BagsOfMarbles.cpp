// BEGIN CUT HERE
/*
SRM 771 Div2 Easy (250)

PROBLEM STATEMENT

You want to have desired white marbles.
Currently you have none.
All the marbles are in bags owned by your friend.
Each of your friend's bags contains exactly bagSize marbles.
Each of those marbles is either white (you want those) or black (you don't care about those).

Your friends has bags of four types:

Red bags are guaranteed to have no white marbles inside. There are noWhiteBags such bags.
Green bags are guaranteed to have no black marbles inside. There are noBlackBags such bags.
Blue bags are guaranteed to have some white marbles inside. There are someWhiteBags such bags.
Fuchsia bags are guaranteed to have some black marbles inside. There are someBlackBags such bags.

You are going to take marbles from your friend's bags, one at a time.
More precisely, in each step you may choose any specific bag owned by your friend and take one random marble from that bag.

Return the smallest X such that you can be sure to reach your goal after taking X marbles (provided that you choose the bags in a smart way).
If it's impossible to give such a guarantee, return -1 instead.


DEFINITION
Class:BagsOfMarbles
Method:removeFewest
Parameters:int, int, int, int, int, int
Returns:int
Method signature:int removeFewest(int desired, int bagSize, int noWhiteBags, int noBlackBags, int someWhiteBags, int someBlackBags)


NOTES
-The statements "a bag contains no white marbles" and "a bag contains some white marbles" are opposites. I.e., a bag contains some white marbles if and only if it is not true that it contains no white marbles.


CONSTRAINTS
-desired will be between 1 and 40,000, inclusive.
-bagSize will be between 1 and 100, inclusive.
-noWhiteBags will be between 0 and 100, inclusive.
-noBlackBags will be between 0 and 100, inclusive.
-someWhiteBags will be between 0 and 100, inclusive.
-someBlackBags will be between 0 and 100, inclusive.


EXAMPLES

0)
5
10
0
1
0
0

Returns: 5

We want 5 white marbles. Each bag contains 10 marbles. Our friend has 1 bag that contains no black marbles. The optimal stragegy is clear: take any five marbles from that bag.


1)
2
10
2
0
1
0

Returns: -1

We want 2 white marbles. Each bag contains 10 marbles. Our friend has three bags: 2 that contain no white marbles, and 1 that contains some white marbles.
We cannot be sure that there is a way to get two white marbles -- given what we know, it is possible that there only one white ball exists.


2)
51
7
7
7
7
7

Returns: 63

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class BagsOfMarbles {
public:
	int removeFewest(int desired, int bagSize, int noWhiteBags, int noBlackBags, int someWhiteBags, int someBlackBags) {
		int ans = 0;
		while (desired > 0 && noBlackBags > 0) {
			--noBlackBags;
			ans += min(desired, bagSize);
			desired -= bagSize;
		}
		while (desired > 0 && someWhiteBags > 0) {
			--someWhiteBags;
			ans += bagSize;
			--desired;
		}
		return desired <= 0 ? ans : -1;
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
			int Arg0 = 5;
			int Arg1 = 10;
			int Arg2 = 0;
			int Arg3 = 1;
			int Arg4 = 0;
			int Arg5 = 0;
			int Arg6 = 5;

			verify_case(n, Arg6, removeFewest(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 10;
			int Arg2 = 2;
			int Arg3 = 0;
			int Arg4 = 1;
			int Arg5 = 0;
			int Arg6 = -1;

			verify_case(n, Arg6, removeFewest(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 51;
			int Arg1 = 7;
			int Arg2 = 7;
			int Arg3 = 7;
			int Arg4 = 7;
			int Arg5 = 7;
			int Arg6 = 63;

			verify_case(n, Arg6, removeFewest(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BagsOfMarbles ___test;
	___test.run_test(-1);
}
// END CUT HERE
