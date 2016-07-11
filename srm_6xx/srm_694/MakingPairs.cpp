// BEGIN CUT HERE
/*
SRM 694 Div2 Easy (250)

PROBLEM STATEMENT
You have a collection of cards.
Each card contains an integer between 0 and N-1, inclusive.

You are given a vector <int> card with N elements.
For each valid i, you have exactly card[i] cards that contain the integer i.

You want to create pairs of cards that have the same number.
Each card can only be used at most once.
Return the largest number of pairs you can create.


DEFINITION
Class:MakingPairs
Method:get
Parameters:vector <int>
Returns:int
Method signature:int get(vector <int> card)


NOTES
-The value of N is not given explicitly. You can determine its value by looking at the number of elements in card.


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-card will have exactly N elements.
-Each element of card will be between 0 and 50, inclusive.


EXAMPLES

0)
{2,2,2}

Returns: 3

You have two cards with the number 0, two cards with the number 1, and two cards with the number 2.
You can use these cards to form three pairs of identical cards: 0 with 0, 1 with 1, and 2 with 2.

1)
{1,1,1}

Returns: 0

Here, you have three cards that have the numbers 0, 1, and 2, respectively.
As these cards are all distinct, you cannot make any pairs.
Thus, the correct return value is 0.

2)
{5}

Returns: 2

You have five cards.
Each of them contains the number 0.
Using these cards, you can form at most two pairs of identical cards.
(Note that you cannot use the same card in multiple pairs.)

3)
{43,23,10,39,39,22,22,0,3,4,3,2}

Returns: 102



4)
{0}

Returns: 0



*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class MakingPairs {
public:
	int get(vector <int> card) {
		int ans = 0;
		for (int c : card) {
			ans += c / 2;
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
			int Arr0[] = {2,2,2};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {43,23,10,39,39,22,22,0,3,4,3,2};
			int Arg1 = 102;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MakingPairs ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
