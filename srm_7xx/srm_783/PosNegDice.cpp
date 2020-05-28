// BEGIN CUT HERE
/*
SRM 783 Div2 Easy (300)

PROBLEM STATEMENT

This problem is about a specific way of rolling the dice in one franchise of tabletop RPG games.

Whenever the player attempts a non-trivial action, the action is evaluated as follows:

The game master sets the target value T based on the player's skill.
The game master gives the player some 6-sided dice to roll. Each die is either positive or negative.
The player rolls all the dice.
As long as there is a positive and a negative die with the same value, a pair of such dice is removed from the roll.
At this point, if there is a positive die with value less than or equal to the target, the roll is a success, otherwise it is a failure.
Each negative die that was not removed counts as a point of stress for the player.

You are given the target T and two vector <int>s: positiveDice and negativeDice.
Return a vector <int> with two elements {X, Y}:

X should be 1 if the roll was a success and 0 if it was a failure.
Y should be the number of points of stress the roll produced.


DEFINITION
Class:PosNegDice
Method:evaluateRoll
Parameters:int, vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> evaluateRoll(int T, vector <int> positiveDice, vector <int> negativeDice)


CONSTRAINTS
-T will be between 1 and 5, inclusive.
-positiveDice will contain between 0 and 500 elements, inclusive.
-negativeDice will contain between 0 and 500 elements, inclusive.
-Each element of positiveDice will be between 1 and 6, inclusive.
-Each element of negativeDice will be between 1 and 6, inclusive.


EXAMPLES

0)
1
{1, 6, 2}
{6}

Returns: {1, 0 }

The player rolled four dice: three positive dice and one negative die. The positive dice rolled 1, 6, and 2. The negative die rolled a 6.

After the roll, one pair of dice is removed: a positive die with value 6 and a negative die with value 6.

The player is left with two positive dice. These have values 1 and 2. As one of the dice is less than or equal to T = 1, the roll is a success.

As there are no negative dice left, the player does not receive any stress points.


1)
4
{}
{}

Returns: {0, 0 }

There are no dice at all, so the roll is automatically a failure (as there is no positive die with a value that is small enough). On the positive side, there is also no stress.


2)
4
{5, 6, 6, 5, 5}
{}

Returns: {0, 0 }

A failure (all positive dice rolled numbers that are bigger than the target) but with no stress.


3)
5
{3, 6, 3, 6}
{3, 3, 1, 3, 6, 3, 5}

Returns: {0, 4 }

Twice we remove a positive 3 and a negative 3. Once we remove a positive 6 and a negative 6. We are left with positiveDice = {6} and negativeDice = {1, 3, 3, 5}. The roll is a failure (the remaining positive die is too large) and the player receives four points of stress.


4)
4
{4, 5, 6}
{1, 2, 3}

Returns: {1, 3 }

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

class PosNegDice {
public:
	vector <int> evaluateRoll(int T, vector <int> positiveDice, vector <int> negativeDice) {
		vector <int> ans(2);
		map<int, int> m;
		for (int x : positiveDice) {
			m[x] += 1;
		}
		for (int x : negativeDice) {
			m[x] -= 1;
		}
		for (auto kv : m) {
			if (kv.second > 0) {
				if (kv.first <= T) {
					ans[0] = 1;
				}
			} else {
				ans[1] -= kv.second;
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {1, 6, 2};
			int Arr2[] = {6};
			int Arr3[] = {1, 0 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, evaluateRoll(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			// int Arr1[] = {};
			// int Arr2[] = {};
			int Arr3[] = {0, 0 };

			vector <int> Arg1;
			vector <int> Arg2;
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, evaluateRoll(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {5, 6, 6, 5, 5};
			// int Arr2[] = {};
			int Arr3[] = {0, 0 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2;
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, evaluateRoll(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {3, 6, 3, 6};
			int Arr2[] = {3, 3, 1, 3, 6, 3, 5};
			int Arr3[] = {0, 4 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, evaluateRoll(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {4, 5, 6};
			int Arr2[] = {1, 2, 3};
			int Arr3[] = {1, 3 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, evaluateRoll(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PosNegDice ___test;
	___test.run_test(-1);
}
// END CUT HERE
