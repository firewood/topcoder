// BEGIN CUT HERE
/*
SRM 670 Div2 Easy (250)

PROBLEM STATEMENT
Two players are playing a cooperative game.
At the beginning of the game each player has some cards.
There is a positive integer written on each card.
The game is played as follows:

Each player chooses one of their cards.
At the same time, each player gives the chosen card to the other player.
Each player computes the sum of the numbers on the cards they now have.
The final outcome of the game is the product of the two sums the players computed in the previous step.

You are given the vector <int>s a and b.
The elements of a are the numbers on the first player's cards at the beginning of the game.
The elements of b are the numbers on the second player's cards.
Compute and return the number of different outcomes the game may have.


DEFINITION
Class:Cdgame
Method:rescount
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int rescount(vector <int> a, vector <int> b)


CONSTRAINTS
-A and B will contain between 1 and 50 elements, inclusive.
-A and B will contain the same number of elements.
-Each element in A and B will be between 1 and 100, inclusive.


EXAMPLES

0)
{1,2}
{3,4}

Returns: 2

This game can be played in four possible ways.
One of them looks as follows:

The first player chooses the card with the number 1. At the same time, the second player chooses the card with the number 3.
Each player gives the chosen card to the other player. After the exchange the first player has the cards with numbers 2 and 3, and the second player has the cards with numbers 1 and 4.
The first player computes that his sum is 2+3 = 5. The second player computes that her sum is 1+4 = 5.
The final outcome is the value 5*5 = 25.

The other three ways correspond to the following outcomes: (2+4)*(1+3) = 6*4 = 24, (1+3)*(2+4) = 4*6 = 24, and (1+4)*(2+3) = 5*5 = 25.
Hence, only two different outcomes are possible: 24 and 25.
Thus, the correct return value is 2.


1)
{1,2,4}
{8,16,32}

Returns: 9

With three cards in each player's hand there are 9 ways to play the game.
In this case each of those ways leads to a different outcome.


2)
{1,1,1}
{1,1,1}

Returns: 1

Again, there are 9 ways to play the game, but obviously in this case the outcome will always be the same.


3)
{1,2,3}
{5,5,5}

Returns: 3


4)
{3,3,4,1}
{2,2,2,100}

Returns: 4


5)
{31,34,55,56,57}
{1,2,3,4,5}

Returns: 15

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Cdgame {
public:
	int rescount(vector <int> a, vector <int> b) {
		set<int> s;
		for (int i = 0; i != a.size(); ++i) {
			for (int j = 0; j != b.size(); ++j) {
				s.insert((accumulate(a.begin(), a.end(), -a[i]) + b[j]) * (accumulate(b.begin(), b.end(), -b[j]) + a[i]));
			}
		}
		return s.size();
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
			int Arr0[] = {1,2};
			int Arr1[] = {3,4};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, rescount(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,4};
			int Arr1[] = {8,16,32};
			int Arg2 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, rescount(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1};
			int Arr1[] = {1,1,1};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, rescount(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3};
			int Arr1[] = {5,5,5};
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, rescount(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,3,4,1};
			int Arr1[] = {2,2,2,100};
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, rescount(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {31,34,55,56,57};
			int Arr1[] = {1,2,3,4,5};
			int Arg2 = 15;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, rescount(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Cdgame ___test;
	___test.run_test(-1);
}
// END CUT HERE
