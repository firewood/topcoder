// BEGIN CUT HERE
/*
// SRM 530 Div2 Easy (250)

// PROBLEM STATEMENT
// Like all other software engineers, Gogo likes to play with bins and balls.
He has N bins, numbered 0 through N-1. Yesterday, Gogo distributed all his balls
into the bins, placing S[0] balls into bin 0, S[1] balls into bin 1, and so on.
No two bins contained the same number of balls. It is possible that
one of the bins contained zero balls.

This morning, Gogo attended a lecture about sorting. After he got home,
he decided to rearrange the balls in his bins into sorted order. More precisely,
he wanted to reach a state with T[0] balls in bin 0, T[1] balls in bin 1,
and so on, such that the following two conditions are met:

 T is a permutation of S 
 T is sorted in ascending order 

For example, suppose that S = {2, 5, 0}, i.e., there are 2 balls in bin 0,
5 balls in bin 1, and 0 balls in bin 2. Gogo would rearrange the balls
to obtain T = {0, 2, 5}.

When rearranging the balls, Gogo always moves them one ball at a time.
In other words, in each move Gogo takes a single ball from one bin and
places it into another bin. Gogo is very smart, so he always uses
the smallest possible number of moves.

For example, when rearranging S = {2, 5, 0} to T = {0, 2, 5}, Gogo will make
exactly 5 moves. One way of changing S to T in 5 moves: first Gogo will move
3 balls from bin 1 to bin 2, and then he will move 2 balls from bin 0 to bin 2.

You just came to visit Gogo. You see that he already rearranged the balls.
You are given a vector <int> T containing the current number of balls
in each of the bins.

You do not know the original state S. The number of balls Gogo moved depends on S.
For example, we already know that for S = {2, 5, 0} Gogo would move 5 balls.
If he had S = {0, 5, 2} instead, he would also produce T = {0, 2, 5}, but
this time he would only need 3 moves.

Your method must find and return the maximum number of moves Gogo could have
performed. In other words, among all sequences S that produce the given sequence T,
find one that requires the most moves, and return that number of moves.

DEFINITION
Class:GogoXBallsAndBinsEasy
Method:solve
Parameters:vector <int>
Returns:int
Method signature:int solve(vector <int> T)


CONSTRAINTS
-T will contain between 2 and 10 elements, inclusive.
-Each element of T will be between 0 and 10, inclusive.
-T will be given in a strictly ascending manner. Note that this implies that
all the elements of T will be distinct.


EXAMPLES

0)
{0, 2, 5}

Returns: 5

This is the example from the problem statement. No sequence is worse than
S = {2, 5, 0}. There are two other sequences S such that Gogo will make exactly
5 moves when producing T = {0, 2, 5}, namely {5, 0, 2} and {5, 2, 0}.

1)
{5, 6, 7, 8}

Returns: 4



2)
{0, 1, 2, 10}

Returns: 11



3)
{1, 2, 3, 4, 5, 6, 7, 8}

Returns: 16

*/
// END CUT HERE
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class GogoXBallsAndBinsEasy {

public:
	int solve(vector <int> T) {
		sort(T.begin(), T.end());
		int res = 0;
		int i, j = T.size() - 1;
		for (i = 0; i < j; ++i, --j) {
			res += T[j] - T[i];
		}
		return res;
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
			int Arr0[] = {0, 2, 5};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 6, 7, 8};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 1, 2, 10};
			int Arg1 = 11;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8};
			int Arg1 = 16;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GogoXBallsAndBinsEasy ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
