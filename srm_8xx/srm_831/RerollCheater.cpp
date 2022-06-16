// BEGIN CUT HERE
/*
SRM 831 Div1 Easy (250)

PROBLEM STATEMENT

You are playing a computer game in which you roll some 20-sided dice.

You have just started one round of the game by taking some dice and rolling them.
The numbers you got are given in the vector <int> currentDice.

Your ultimate goal is to maximize the sum of the numbers on your dice.

You are now allowed to make between zero and N consecutive rerolls.
For each reroll, you choose one of the dice you have and you roll it again to get a new "randomly selected" value.

For each reroll you can select any one of the dice currently in front of you.
You may reroll each die multiple times. 

However, there's one big catch.
As we said above, these are not real dice, this is just a computer simulation.
You have discovered that the game uses a deterministic pseudorandom generator to simulate the dice rolls, and you can predict the values it's going to generate with 100 percent accuracy.
The vector <int> futureRolls has exactly N elements: the values that will come up the next N times you'll roll a die. 
(The values are given in the correct order. I.e., the first die you'll reroll will give you the new value futureRolls[0], the one after that will give futureRolls[1], and so on.)

Find one way to maximize the final sum of the dice in front of you.
If your solution has K rerolls, return a vector <int> with K elements:
for each step, in order, the 0-based index of the element of currentDice you want to reroll in that step.


DEFINITION
Class:RerollCheater
Method:reroll
Parameters:vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> reroll(vector <int> currentDice, vector <int> futureRolls)


NOTES
-Any valid solution will be accepted.
-It is not required to minimize the number of rerolls.


CONSTRAINTS
-currentDice will have between 1 and 100 elements, inclusive.
-futureRolls will have between 1 and 1000 elements, inclusive.
-Each number in the input will be between 1 and 20, inclusive.


EXAMPLES

0)
{1, 2, 1, 1, 1, 1}
{20, 20, 20}

Returns: {3, 4, 5 }


Your initial roll was really unlucky: you rolled five ones and a two. You can now make up to three rerolls. You know that each of those will give you a 20. The best strategy is to reroll any three distinct dice that show ones.


The return value {3, 4, 5} corresponds to the following sequence of rerolls:


currentDice[3] := futureRolls[0]
currentDice[4] := futureRolls[1]
currentDice[5] := futureRolls[2]


In the end, we will have dice with the following values: {1, 2, 1, 20, 20, 20}.


1)
{4, 7, 13, 19}
{1, 1, 2, 3, 1, 4, 1, 3}

Returns: { }

The upcoming rolls are all quite low, so we cannot improve the dice we initially rolled. Thus, one of the optimal solutions for this test case is to do nothing.

2)
{18, 11, 15, 12}
{3, 14, 9}

Returns: {1, 1 }

Remember that you may reroll the same die in multiple (not necessarily consecutive) rounds. Here we reroll the 11 to get a 3, and then we reroll the 3 again to get a 14 instead.

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

class RerollCheater {
public:
	vector <int> reroll(vector <int> currentDice, vector <int> futureRolls) {
		vector<int> ans, a = currentDice;
		for (auto x : futureRolls) {
			a.emplace_back(x);
		}
		sort(a.rbegin(), a.rend());
		int current_sum = accumulate(currentDice.begin(), currentDice.end(), 0);
		int target_sum = accumulate(a.begin(), a.begin() + currentDice.size(), 0);
		for (auto x : futureRolls) {
			if (current_sum >= target_sum) {
				break;
			}
			int pos = min_element(currentDice.begin(), currentDice.end()) - currentDice.begin();
			ans.emplace_back(pos);
			current_sum += x - currentDice[pos];
			currentDice[pos] = x;
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
			int Arr0[] = {1, 2, 1, 1, 1, 1};
			int Arr1[] = {20, 20, 20};
			int Arr2[] = {3, 4, 5 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, reroll(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 7, 13, 19};
			int Arr1[] = {1, 1, 2, 3, 1, 4, 1, 3};
//			int Arr2[] = { };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
//			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg2;
			verify_case(n, Arg2, reroll(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {18, 11, 15, 12};
			int Arr1[] = {3, 14, 9};
			int Arr2[] = {1, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, reroll(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RerollCheater ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
