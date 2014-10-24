// BEGIN CUT HERE
/*
SRM 637 Div1 Easy (250)

// PROBLEM STATEMENT
Cat Snuke and wolf Sothe are playing the Greater Game.
The game is played with cards.
Each card has a number written on it.
There are 2N cards.
The numbers on the cards are the integers between 1 and 2N, inclusive.

At the beginning of the game, each player gets N of the cards and chooses the order in which he wants to play them.
The game then consists of N turns.
In each turn, both players play one of their cards simultaneously.
The player who revealed the card with the larger number gets a point.

You are given a vector <int> hand.
The elements of hand are the numbers on Snuke's cards.
He can play those cards in any order he chooses.

Obviously, Snuke can determine the numbers on Sothe's cards, but he does not necessarily know the order in which Sothe is going to play his cards.
You are given the information Snuke has about Sothe in a vector <int> sothe.
For each i, element i of sothe is either the number on the card Sothe will play in turn i (0-based index), or -1 if Snuke does not know the card Sothe will play in that turn.

Snuke wants to play according to a strategy that maximizes the expected number of points he'll get.
Find that strategy and return the corresponding expected number of Snuke's points at the end of the game.

As shown in Example 0, the optimal strategy for Snuke may involve some random decisions.
However, note that before the game starts Snuke must choose the order in which he is going to play all his cards.
He is not allowed to change their order after he sees some of the cards played by Sothe.


DEFINITION
Class:GreaterGame
Method:calc
Parameters:vector <int>, vector <int>
Returns:double
Method signature:double calc(vector <int> hand, vector <int> sothe)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-hand and sothe will contain exactly N elements each.
-Each element of hand will be an integer between 1 and 2N, inclusive.
-Each element of sothe will be either -1, or an integer between 1 and 2N, inclusive.
-The positive integers in hand and sothe will be distinct.


EXAMPLES

0)
{4,2}
{-1,-1}

Returns: 1.5

Sothe will play the cards 1 and 3 in some unknown order.
The best strategy for Snuke is to flip a coin and to play his cards either in the order {2,4} or in the order {4,2} with equal probability.
This leads to two equally likely results of the game:

Snuke plays his 2 against Sothe's 1, and his 4 against Sothe's 3. In this case, Snuke wins both turns and thus scores 2 points.
Snuke plays his 2 against Sothe's 3, and his 4 against Sothe's 1. In this case, Snuke scores 1 point.

Therefore, the expected number of Snuke's points is 1.5.


1)
{4,2}
{1,3}

Returns: 2.0

If Snuke plays card 2 first and card 4 next, he is guaranteed to score 2 points.


2)
{2}
{-1}

Returns: 1.0

Sothe's only card has to be 1, and thus Snuke is guaranteed to win the only turn of this game.


3)
{1,3,5,7}
{8,-1,4,-1}

Returns: 2.5


4)
{6,12,17,14,20,8,16,7,2,15}
{-1,-1,4,-1,11,3,13,-1,-1,18}

Returns: 8.0

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef set<int> IntSet;

class GreaterGame {
public:
	double calc(vector <int> hand, vector <int> sothe) {
		IntSet a(hand.begin(), hand.end());
		IntSet b(sothe.begin(), sothe.end());
		IntSet r;
		int N = (int)hand.size();
		for (int i = 1; i <= 2*N; ++i) {
			r.insert(i);
		}
		for (int i = 0; i < N; ++i) {
			r.erase(hand[i]);
			r.erase(sothe[i]);
		}

		double ans = 0;
		while (b.size() > 0) {
			int x = *b.begin();
			b.erase(b.begin());
			if (x >= 1) {
				IntSet::iterator it = a.lower_bound(x);
				if (it == a.end()) {
					a.erase(a.begin());
				} else {
					ans += 1;
					a.erase(it);
				}
			}
		}

		IntSet::const_iterator p, q;
		for (p = r.begin(); p != r.end(); ++p) {
			double sum = 0;
			for (q = a.begin(); q != a.end(); ++q) {
				if (*q > *p) {
					sum += 1;
				}
			}
			ans += sum / r.size();
		}

		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,2};
			int Arr1[] = {-1,-1};
			double Arg2 = 1.5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, calc(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,2};
			int Arr1[] = {1,3};
			double Arg2 = 2.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, calc(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2};
			int Arr1[] = {-1};
			double Arg2 = 1.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, calc(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,3,5,7};
			int Arr1[] = {8,-1,4,-1};
			double Arg2 = 2.5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, calc(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {6,12,17,14,20,8,16,7,2,15};
			int Arr1[] = {-1,-1,4,-1,11,3,13,-1,-1,18};
			double Arg2 = 8.0;

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
	GreaterGame ___test;
	___test.run_test(-1);

}
// END CUT HERE
