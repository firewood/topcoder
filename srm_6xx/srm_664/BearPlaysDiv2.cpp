// BEGIN CUT HERE
/*
SRM 664 Div2 Medium (550)

PROBLEM STATEMENT
Limak is a little bear who loves to play.
Today he is playing by moving some stones between three piles of stones.
Initially, the piles contain A, B, and C stones, respectively.
Limak's goal is to produce three equal piles.

Limak will try reaching his goal by performing a sequence of zero or more operations.
In each operation he will start by choosing two unequal piles.
Let's label their sizes X and Y in such a way that X < Y.
He will then double the size of the smaller chosen pile by moving some stones between the two chosen piles.
Formally, the new sizes of the two chosen piles will be X+X and Y-X.

You are given the ints A, B, and C.
Return "possible" (quotes for clarity) if there is a sequence of operations that will make all three piles equal.
Otherwise, return "impossible".


DEFINITION
Class:BearPlaysDiv2
Method:equalPiles
Parameters:int, int, int
Returns:string
Method signature:string equalPiles(int A, int B, int C)


CONSTRAINTS
-A, B and C will be between 1 and 500, inclusive.


EXAMPLES

0)
10
15
35

Returns: "possible"

One valid sequence of operations looks as follows:

The initial pile sizes are 10, 15, and 35.
For the first operation Limak will choose the piles with 15 and 35 stones. After doubling the size of the smaller pile the new sizes of these two piles will be 30 and 20.
After the first operation the pile sizes are 10, 30, and 20.
For the second operation Limak will choose the piles with 10 and 30 stones. After doubling the size of the smaller pile the new sizes of these two piles will be 20 and 20.
After the second operation each pile has 20 stones, which means that Limak has reached his goal.


1)
1
1
2

Returns: "impossible"

No matter what Limak does, there will always be two piles with a single stone each and one pile with 2 stones.


2)
4
6
8

Returns: "impossible"


3)
18
18
18

Returns: "possible"

Sometimes Limak can reach his goal without making any operations.


4)
225
500
475

Returns: "possible"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, int> II;

class BearPlaysDiv2 {
	int T;
	set<II> memo;

	bool dfs(int a, int b) {
		int c = T - a - b;
		if (a == b && b == c) {
			return true;
		}
		II key(a, b);
		if (memo.find(key) != memo.end()) {
			return false;
		}
		memo.insert(key);
		int p = min(a, b);
		int q = max(a, b);
		if (dfs(p * 2, q - p)) {
			return true;
		}
		int r = min(p, c);
		int s = max(p, c);
		if (dfs(r * 2, s - r)) {
			return true;
		}
		return false;
	}

public:
	string equalPiles(int A, int B, int C) {
		T = A + B + C;
		memo.clear();
		return dfs(A, B) ? "possible" : "impossible";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 15;
			int Arg2 = 35;
			string Arg3 = "possible";

			verify_case(n, Arg3, equalPiles(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 2;
			string Arg3 = "impossible";

			verify_case(n, Arg3, equalPiles(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 6;
			int Arg2 = 8;
			string Arg3 = "impossible";

			verify_case(n, Arg3, equalPiles(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 18;
			int Arg1 = 18;
			int Arg2 = 18;
			string Arg3 = "possible";

			verify_case(n, Arg3, equalPiles(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 225;
			int Arg1 = 500;
			int Arg2 = 475;
			string Arg3 = "possible";

			verify_case(n, Arg3, equalPiles(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearPlaysDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
