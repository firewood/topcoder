// BEGIN CUT HERE
/*
Fun SRM 7/29 Easy (300)

PROBLEM STATEMENT

You have certainly seen many tasks that start with some ridiculous made-up story. 
Well, this one is nothing like that.

Ivan A. is a smart boy.
He just got a sequence of nonnegative integers as a birthday present.
You are given this sequence in the vector <int> X.

Ivan A. adores the number 5.
He thinks that a sequence is pretty if the product of all its elements ends with the digit 5.
He now wants to change X into a pretty sequence.
In each step he can choose an element of X and replace one of its digits by any other digit.
For example, in a single step Ivan A. can change the number 1234 into the number 1734.

Compute and return the minimal number of steps needed to change X into a pretty sequence.


DEFINITION
Class:ILike5
Method:transformTheSequence
Parameters:vector <int>
Returns:int
Method signature:int transformTheSequence(vector <int> X)


NOTES
-It can be shown that any sequence X can be transformed into a pretty sequence in finitely many steps.
-It is allowed to change the leading digit of a number into a zero, but this is never needed in the optimal solution.


CONSTRAINTS
-X will contain between 1 and 50 numbers, inclusive.
-Each element of X will be between 0 and 10^6, inclusive.


EXAMPLES

0)
{5, 2, 8, 12}

Returns: 3

One optimal solution looks as follows:

Ivan A. changes the 2 to a 1.
Ivan A. changes the 8 to a 9.
Ivan A. changes the last digit of the number 12 from 2 to 9.

After these three steps he will have the sequence {5, 1, 9, 19}.
The product of its elements is 5 * 1 * 9 * 19 = 855, so this sequence is pretty.


1)
{1555}

Returns: 0

The number already ends in a 5.


2)
{0, 10, 100, 1000, 10000}

Returns: 5

Clearly, Ivan A. must change the last digit in each of these numbers, otherwise the product would end in a 0.
One optimal solution is to change this sequence into {7, 13, 105, 1005, 10003}.


3)
{1, 2, 2, 3, 3, 3, 4, 4, 4, 4}

Returns: 6


4)
{7890, 4861, 65773, 3769, 4638, 46000, 548254, 36185, 115}

Returns: 4

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ILike5 {
public:
	int transformTheSequence(vector <int> X) {
		int even = 0;
		bool five = false;
		for (int x : X) {
			if ((x % 10) == 5) {
				five = true;
			} else if ((x % 2) == 0) {
				++even;
				five = true;
			}
		}
		return even + !five;
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
			int Arr0[] = {5, 2, 8, 12};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, transformTheSequence(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1555};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, transformTheSequence(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 10, 100, 1000, 10000};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, transformTheSequence(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
			int Arg1 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, transformTheSequence(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7890, 4861, 65773, 3769, 4638, 46000, 548254, 36185, 115};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, transformTheSequence(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ILike5 ___test;
	___test.run_test(-1);
}
// END CUT HERE
