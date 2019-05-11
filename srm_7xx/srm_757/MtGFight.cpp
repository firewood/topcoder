// BEGIN CUT HERE
/*
SRM 757 Div2 Easy (250)

PROBLEM STATEMENT

In the card game Magic the Gathering, some cards represent creatures.
Each creature has two parameters: power and toughness.
Whenever two creatures fight, each deals damage equal to its power to the other creature.
Whenever a creature receives damage greater than or equal to its toughness, it dies.

You are given the description of N creatures: the vector <int>s power and toughness, each containing N elements.
For each valid i, there is a creature whose power is power[i] and whose toughness is toughness[i].

Find two distinct indices i and j such that if creature i fights creature j, creature i will survive and creature j will die.
Return {i, j}.
Any valid answer will be accepted.
If there is no valid answer, return an empty vector <int> instead.


DEFINITION
Class:MtGFight
Method:findGoodFight
Parameters:vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> findGoodFight(vector <int> power, vector <int> toughness)


NOTES
-If an answer exists, the correct return value is a vector <int> with two elements. Element 0 should be the number of the creature that survives, and element 1 should be the number of the creature that dies.
-You are not given the value N explicitly. Instead, you can determine it by looking at the number of elements in power (or toughness).


CONSTRAINTS
-power will contain between 2 and 50 elements, inclusive.
-toughness will contain the same number of elements as power.
-Each element of power will be between 0 and 20, inclusive.
-Each element of toughness will be between 1 and 20, inclusive.


EXAMPLES

0)
{0, 2, 1, 4}
{10, 5, 3, 1}

Returns: {1, 3 }

We will use P/T to denote a creature with power P and toughness T.
The input describes four creatures: creature number 0 is 0/10, creature number 1 is 2/5, creature number 2 is 1/3, and creature number 3 is 4/1.
The only pair that is a correct answer is {1, 3}. When creatures 1 and 3 fight, creature 1 kills creature 3 and manages to survive the fight.
(If creatures 0 and 1 fight, they both survive. If creatures 2 and 3 fight, they both die. And so on.)


1)
{0, 1, 2, 3}
{10, 11, 12, 13}

Returns: { }

All these creatures are weak and tough, so in any fight both creatures survive.


2)
{10, 11, 12, 13}
{1, 2, 3, 4}

Returns: { }

Each of these creatures is powerful but frail. In any fight both creatures will die.


3)
{4, 1, 7, 5, 3, 5}
{3, 2, 9, 1, 3, 4}

Returns: {0, 1 }

There are other correct answers as well, for example, {2, 1} would also be accepted.
Note that the order matters: {1, 0} and {1, 2} are not correct answers.

*/
// END CUT HERE

#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>

using namespace std;

class MtGFight {
public:
vector <int> findGoodFight(vector <int> power, vector <int> toughness) {
    int n = (int)power.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (toughness[i] > power[j] && toughness[j] <= power[i]) {
                return {i, j};
            }
        }
    }
    return {};
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
			int Arr0[] = {0, 2, 1, 4};
			int Arr1[] = {10, 5, 3, 1};
			int Arr2[] = {1, 3 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findGoodFight(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 1, 2, 3};
			int Arr1[] = {10, 11, 12, 13};
			int Arr2[] = { };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findGoodFight(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 11, 12, 13};
			int Arr1[] = {1, 2, 3, 4};
			int Arr2[] = { };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findGoodFight(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 1, 7, 5, 3, 5};
			int Arr1[] = {3, 2, 9, 1, 3, 4};
			int Arr2[] = {0, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findGoodFight(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  MtGFight ___test;
  ___test.run_test(-1);
}
// END CUT HERE
