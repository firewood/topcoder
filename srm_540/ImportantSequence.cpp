// BEGIN CUT HERE
/*
// SRM 540 Div1 Easy (250)

// PROBLEM STATEMENT
// 
This problem statement contains superscripts and/or subscripts. It may not
display properly outside the applet.

Little Rudolph had an important sequence of positive integers. The sequence
consisted of N positive integers a0, a1, .., aN-1.

Rudolph wrote the sequence onto the blackboard in the classroom. While Rudolph
had gone out, little Arthur came into the classroom and saw the sequence.
Arthur likes to play with numbers as much as he likes to give his friends
puzzles. So he did the following:

First, he wrote a '+' or a '-' between each pair of consecutive numbers
(possibly using different signs for different pairs of numbers).
	
Next, for each sign he computed the result of the corresponding operation
and wrote it under the sign.
I.e., if he used the '+' sign between ai and ai+1, he would write the sum
ai+ai+1 under this '+' sign.
Similarly, if he used the '-' sign between ai and ai+1, he would write the
difference ai-ai+1. In this way he obtained a new sequence of N-1 numbers
b0, b1, .., bN-2.
Finally, he erased the original sequence. Now there was only the operator
sequence o0, o1, .., oN-2 and the resulting number sequence b0, b2, .., bN-2
left on the blackboard.

For example, if the original sequence was {1, 2, 3, 4}, and Arthur wrote
operators {+, -, +}, then the content of the blackboard changed like this:

1   2   3   4    ->    1 + 2 - 3 + 4    ->    1 + 2 - 3 + 4    ->     +  -  +
                                                3  -1   7             3 -1  7

When Rudolph returned, he was shocked as his important sequence had disappeared.
Arthur quickly told him what operations he had performed and that Rudolph
has to simply reconstruct the orginal sequence.

Unfortunately, little Arthur did not realize that it is not necessarily
possible to determine the original sequence uniquely. For example, both
original sequences {1, 2, 3, 4} and {2, 1, 2, 5} lead to the same sequence
{3, -1, 7} when operator sequence is {+, -, +}.

The only thing Rudolph remembers about his original sequence is that all
the integers were positive. Rudolph now wants to count all sequences of
positive integers that match the blackboard. You are given vector <int> B
and string operators  both containing N-1 elements. The i-th element of B
is the number bi and i-th element of operators will be '+' or '-',
meaning that the i-th operator is + or -, respectively. Return the number of
different positive integer sequences A that lead to sequence B when operators
operators are used in the way described. If there are infinitely many such
sequences, return -1. Note that there may be test cases where no valid
sequence A exists. For such test cases the correct return value is 0.

DEFINITION
Class:ImportantSequence
Method:getCount
Parameters:vector <int>, string
Returns:int
Method signature:int getCount(vector <int> B, string operators)


NOTES
-It is guaranteed that the correct answer will always fit into the 32-bit signed integer type.
-The integer 0 (zero) is not positive. It may not occur in Rudolph's original sequence.


CONSTRAINTS
-B will contain between 1 and 50 elements, inclusive.
-operators will contain the same number of characters as the number of elements in B.
-Each element of B will be between -1000000000 (-109) and 1000000000 (109), inclusive.
-Each character in operators will be either '+' or '-' (quotes for clarity).


EXAMPLES

0)
{3, -1, 7}
"+-+"

Returns: 2

From the problem statement.


1)
{1}
"-"

Returns: -1

There are infinitely many pairs of positive integers that differ by one.


2)
{1}
"+"

Returns: 0

Note that all numbers ai have to be positive integers.


3)
{10}
"+"

Returns: 9


4)
{540, 2012, 540, 2012, 540, 2012, 540}
"-+-+-+-"

Returns: 1471

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> LLLL;
typedef vector<LLLL> LLLLVec;

class ImportantSequence {

public:
	int getCount(vector <int> B, string operators) {
		int sz = B.size();
		LLLLVec v;
		LL op = 1;
		LL x = 0;
		int i;
		for (i = 0; i < sz; ++i) {
			LL n = B[i];
			if (operators[i] == '+') {
				op = -op;
				x = n - x;
			} else {
				x = x - n;
			}
			v.push_back(LLLL(op, x));
		}
		LL Min = 1;
		LL Max = 1LL << 60;
		for (i = 0; i < sz; ++i) {
			if (v[i].first > 0) {
				Min = max(Min, -v[i].second + 1);
			} else {
				Max = min(Max, v[i].second - 1);
			}
		}

		if (Max >= (1LL << 60)) {
			return -1;
		}
		if (Max < Min) {
			return 0;
		}
		return (int)(Max - Min) + 1;
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
			int Arr0[] = {3, -1, 7};
			string Arg1 = "+-+";
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			string Arg1 = "-";
			int Arg2 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			string Arg1 = "+";
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10};
			string Arg1 = "+";
			int Arg2 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {540, 2012, 540, 2012, 540, 2012, 540};
			string Arg1 = "-+-+-+-";
			int Arg2 = 1471;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 999999999, 1234, 4311};
			string Arg1 = "-------+--";
			int Arg2 = 999994453;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = {380363427, 583629335, -681431183, -219398108, 24128364, 933370503, 476023070, -401987717, -625916565, 496045772, 908035426, -895357751, 464638908, -115569799, -905531819, -393481688, 203364448, 48324176, -36670007, -531426289, -460125068, 629279122, -733410707, -159928285, -562938483, -878488131, 560719010, -466275382, -312074009, -445541791, 320972323, -477210673, 514950353, -252233737, -599779031, 819400249, 364282240, 530984231, 981313465, 353217366, 118458547, -491592609, 190379345, 187993123, 299990918, 968081798, 212935226, 448245418};
			string Arg1 = "-++-+----+-++-+--++--+-+---++-------++-+--++-+-+";
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ImportantSequence ___test;
//	___test.run_test(6);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
