// BEGIN CUT HERE
/*
SRM 637 Div2 Easy (250)

PROBLEM STATEMENT
Cat Snuke and wolf Sothe are playing the Greater Game.
The game is played with cards.
Each card has a number written on it.
There are 2N cards.
The numbers on the cards are the integers between 1 and 2N, inclusive.

At the beginning of the game, each player gets N of the cards and chooses the order in which he wants to play them.
The game then consists of N turns.
In each turn, both players play one of their cards simultaneously.
The player who revealed the card with the larger number gets a point.

You are given two vector <int>s: snuke and sothe.
The elements of snuke are the numbers on the cards Snuke is going to play, in order.
Similarly, the elements of sothe are the numbers on the cards Sothe is going to play, in order.
Compute and return the number of points Snuke will have at the end of the game.


DEFINITION
Class:GreaterGameDiv2
Method:calc
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int calc(vector <int> snuke, vector <int> sothe)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-snuke and sothe will contain exactly N elements each.
-Each integer in snuke and sothe will be between 1 and 2N, inclusive.
-The integers in snuke and sothe will be distinct.


EXAMPLES

0)
{1,3}
{4,2}

Returns: 1

Snuke loses the first round because 1 is less than 4. Snuke then wins the second round because 3 is greater than 2.


1)
{1,3,5,7,9}
{2,4,6,8,10}

Returns: 0


2)
{2}
{1}

Returns: 1


3)
{3,5,9,16,14,20,15,17,13,2}
{6,18,1,8,7,10,11,19,12,4}

Returns: 6

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class GreaterGameDiv2 {
public:
	int calc(vector <int> snuke, vector <int> sothe) {
		int ans = 0;
		for (int i = 0; i < (int)snuke.size(); ++i) {
			ans += snuke[i] > sothe[i];
		}
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
			int Arr0[] = {1,3};
			int Arr1[] = {4,2};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, calc(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,3,5,7,9};
			int Arr1[] = {2,4,6,8,10};
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, calc(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2};
			int Arr1[] = {1};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, calc(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,5,9,16,14,20,15,17,13,2};
			int Arr1[] = {6,18,1,8,7,10,11,19,12,4};
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, calc(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GreaterGameDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
