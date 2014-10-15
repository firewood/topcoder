// BEGIN CUT HERE
/*
SRM 636 Div2 Easy (250)

PROBLEM STATEMENT
Limak has found a large field with some piles of stones.

Limak likes perfection. It would make him happy if every pile had the same number of stones. He is now going to move some stones between the piles to make them all equal.

However, there is a catch.
Limak's perfectionism does not allow him to carry just one stone at a time.
As he has two hands, he must always carry exactly two stones: one in each hand.
Thus, he can only make one type of an action: pick up two stones from one of the piles and carry both of them to some other pile. He is not allowed to remove a pile completely. Therefore, he cannot pick up stones from a pile that currently contains fewer than 3 stones.

You are given a vector <int> stones.
Each element of stones is the initial number of stones in one of the piles.
Compute and return the smallest number of actions Limak has to perform in order to make all piles equal.
If it is impossible to make all piles equal using the allowed type of actions, return -1 instead.


DEFINITION
Class:GameOfStones
Method:count
Parameters:vector <int>
Returns:int
Method signature:int count(vector <int> stones)


CONSTRAINTS
-stones will contain between 1 and 100 elements, inclusive. 
-Each element in stones will be between 1 and 100, inclusive.


EXAMPLES

0)
{7, 15, 9, 5}

Returns: 3

There are four piles of stones.
There are 7 stones in pile number 0, 15 stones in pile number 1, 9 stones in pile number 2, and 5 stones in pile number 3.
One optimal solution looks as follows:
First, Limak will move a pair of stones from pile 1 to pile 0.
Afterwards, Limak will twice move a pair of stones from pile 1 to pile 3.
After these 3 actions, each pile contains exactly 9 stones.


1)
{10, 16}

Returns: -1

It can be proven that Limak can't make these two piles equal.


2)
{2, 8, 4}

Returns: -1


3)
{17}

Returns: 0

Limak doesn't need to perform any actions. There is only one pile and it means that all piles already have the same size.


4)
{10, 15, 20, 12, 1, 20}

Returns: -1

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class GameOfStones {
public:
	int count(vector <int> stones) {
		int sum = accumulate(stones.begin(), stones.end(), 0);
		int avg = sum / stones.size();
		if (avg * stones.size() != sum) {
			return -1;
		}
		int ans = 0;
		for (int stone : stones) {
			int d = abs(avg - stone);
			if (d % 2) {
				return -1;
			}
			ans += d / 2;
		}
		return ans / 2;
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
			int Arr0[] = {7, 15, 9, 5};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 16};
			int Arg1 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 8, 4};
			int Arg1 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {17};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 15, 20, 12, 1, 20};
			int Arg1 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GameOfStones ___test;
	___test.run_test(-1);
}
// END CUT HERE
