// BEGIN CUT HERE
/*
// SRM 552 Div1 Easy (250)

// PROBLEM STATEMENT
// A Ball Triangle is a set of identical balls placed in a triangular shape.
A Ball Triangle has N rows, numbered 1 to N from top to bottom. For all i,
1 <= i <= N, the i-th row contains i balls. For example, the following image
shows a Ball Triangle with N=3.

Fox Jiro has infinitely many Ball Triangles. He can paint a Ball Triangle
according to the following conditions:

Each of the balls has to be painted either red, green, or blue.
No two adjacent balls may share the same color.

The following image shows one valid coloring of a Ball Triangle for N=3.

Jiro wants to paint as many Ball Triangles as he can.
As long as he follows the rules above, he may color the Ball Triangles
in any way he likes.
Some of the colored Ball Triangles may look exactly the same, but they don't
have to.
The only other constraint is the total amount of paint available to Jiro:
In all the triangles together, he can paint at most R balls red, G balls green,
and B balls blue.

You are given the long longs R, G, and B.
You are also given the int N.
Return the maximum possible number of Ball Triangles Jiro can paint.


DEFINITION
Class:FoxPaintingBalls
Method:theMax
Parameters:long long, long long, long long, int
Returns:long long
Method signature:long long theMax(long long R, long long G, long long B, int N)


CONSTRAINTS
-R, G and B will each be between 0 and 1,000,000,000,000,000,000 (10^18), inclusive.
-N will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
2
2
2
3

Returns: 1

Jiro can paint one Ball Triangle in the same way as in the image in the statement.


1)
1
2
3
3

Returns: 0

This time Jiro can paint no Ball Triangles.


2)
8
6
6
4

Returns: 2


3)
7
6
7
4

Returns: 2


4)
100
100
100
4

Returns: 30


5)
19330428391852493
48815737582834113
11451481019198930
3456

Returns: 5750952686


6)
1
1
1
1

Returns: 3

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class FoxPaintingBalls {

public:
	long long theMax(long long R, long long G, long long B, int N) {
		LL sum = (R+G+B);
		LL n = N;
		if (N <= 1) {
			return sum * N;
		}
		LL need = ((n+1)*n)/2;
		LL a = need / 3;
		LL b = min(R, min(G, B));
		return min(b / a, (sum / need));
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 2LL;
			long long Arg1 = 2LL;
			long long Arg2 = 2LL;
			int Arg3 = 3;
			long long Arg4 = 1LL;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 2LL;
			long long Arg2 = 3LL;
			int Arg3 = 3;
			long long Arg4 = 0LL;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 8LL;
			long long Arg1 = 6LL;
			long long Arg2 = 6LL;
			int Arg3 = 4;
			long long Arg4 = 2LL;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 7LL;
			long long Arg1 = 6LL;
			long long Arg2 = 7LL;
			int Arg3 = 4;
			long long Arg4 = 2LL;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 100LL;
			long long Arg1 = 100LL;
			long long Arg2 = 100LL;
			int Arg3 = 4;
			long long Arg4 = 30LL;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 19330428391852493LL;
			long long Arg1 = 48815737582834113LL;
			long long Arg2 = 11451481019198930LL;
			int Arg3 = 3456;
			long long Arg4 = 5750952686LL;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 1LL;
			long long Arg2 = 1LL;
			int Arg3 = 1;
			long long Arg4 = 3LL;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxPaintingBalls ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
