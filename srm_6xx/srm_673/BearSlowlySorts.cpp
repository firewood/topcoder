// BEGIN CUT HERE
/*
SRM 673 Div2 Medium (500)

PROBLEM STATEMENT
Limak is a little polar bear.
He has a vector <int> w containing a sequence of N distinct numbers.
He wants to sort this sequence into ascending order.

Limak knows some fast sorting algorithms but in the real world such knowledge sometimes isn't enough.
In order to sort the sequence w Limak must physically move the numbers into their correct places.
Such a thing can be hard for a little bear.

In a single move Limak can take all elements he can reach and sort them into ascending order.
The problem is that Limak's arms are too short.
Regardless of where he stands, he can only reach N-1 consecutive elements of w.
Hence, in each move he can either sort all elements except for the last one, or all elements except for the first one.

Limak can make the moves in any order he likes.
Compute and return the smallest number of moves necessary to sort the given sequence w.

DEFINITION
Class:BearSlowlySorts
Method:minMoves
Parameters:vector <int>
Returns:int
Method signature:int minMoves(vector <int> w)


CONSTRAINTS
-w will contain between 3 and 50 elements, inclusive.
-Each element in w will be between 1 and 1000, inclusive.
-w will contain distinct elements.


EXAMPLES

0)
{2,6,8,5}

Returns: 1

Limak can sort this sequence in a single move.
All he needs to do is to sort all elements except for the first one.
In this single move Limak will pick up the elements {6,8,5} and reorder them into {5,6,8}.
This will change the given w into {2,5,6,8}, and that is a sorted sequence.


1)
{4,3,1,6,2,5}

Returns: 2

One of the shortest ways is to sort first N-1 numbers first to get {1,2,3,4,6,5} and then to sort the last N-1 numbers.


2)
{93,155,178,205,213,242,299,307,455,470,514,549,581,617,677}

Returns: 0

This sequence is already sorted, no moves are necessary.


3)
{50,20,30,40,10}

Returns: 3


4)
{234,462,715,596,906,231,278,223,767,925,9,526,369,319,241,354,317,880,5,696}

Returns: 2

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef vector<int> IntVec;

class BearSlowlySorts {
public:
	int minMoves(vector <int> w) {
		IntVec v = w;
		sort(v.begin(), v.end());
		int ans = 0;
		if (v != w) {
			if (v[0] == w[0] || v.back() == w.back()) {
				ans = 1;
			} else {
				ans = 2 + (v[0] == w.back() && v.back() == w[0]);
			}
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
			int Arr0[] = {2,6,8,5};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minMoves(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,3,1,6,2,5};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minMoves(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {93,155,178,205,213,242,299,307,455,470,514,549,581,617,677};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minMoves(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50,20,30,40,10};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minMoves(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {234,462,715,596,906,231,278,223,767,925,9,526,369,319,241,354,317,880,5,696};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minMoves(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearSlowlySorts ___test;
	___test.run_test(-1);
}
// END CUT HERE
