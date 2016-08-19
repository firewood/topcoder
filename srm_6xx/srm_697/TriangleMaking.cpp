// BEGIN CUT HERE
/*
SRM 697 Div2 Easy (250)

PROBLEM STATEMENT
You have three sticks.
Their current lengths are a, b, and c.
You can shorten each of those sticks arbitrarily.
Your goal is to produce three sticks with the following properties:

The length of each stick is a positive integer.
The three sticks can be used to build a triangle. The triangle must be non-degenerate. (I.e., it must have a positive area.)
The perimeter of the triangle must be as large as possible.

You are given the ints a, b, and c.
Compute and return the largest possible perimeter of the triangle constructed from your three sticks.


DEFINITION
Class:TriangleMaking
Method:maxPerimeter
Parameters:int, int, int
Returns:int
Method signature:int maxPerimeter(int a, int b, int c)


NOTES
-The return value is always defined. In other words, for any a, b, and c there is at least one way to build a valid triangle.


CONSTRAINTS
-a will be between 1 and 100, inclusive.  
-b will be between 1 and 100, inclusive.  
-c will be between 1 and 100, inclusive.  


EXAMPLES

0)
1
2
3

Returns: 5

Shorten the last stick from 3 to 2. There is a triangle with sides (1,2,2). The perimeter of this triangle is 1+2+2 = 5.


1)
2
2
2

Returns: 6

Here the optimal solution is to use the three sticks you have without shortening any of them.


2)
1
100
1

Returns: 3


3)
41
64
16

Returns: 113

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

// BEGIN CUT HERE
/*
typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<II> IIVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;
typedef set<II> IISet;
typedef set<string> StrSet;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
#define MOD 1000000007LL
#define MOD 1000000009LL
*/
// END CUT HERE

class TriangleMaking {
public:
	int maxPerimeter(int a, int b, int c) {
		int x[3] = { a, b, c };
		sort(x, x + 3);
		x[2] = min(x[2], x[0] + x[1] - 1);
		return x[0] + x[1] + x[2];
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
			int Arg0 = 1;
			int Arg1 = 2;
			int Arg2 = 3;
			int Arg3 = 5;

			verify_case(n, Arg3, maxPerimeter(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 2;
			int Arg3 = 6;

			verify_case(n, Arg3, maxPerimeter(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 100;
			int Arg2 = 1;
			int Arg3 = 3;

			verify_case(n, Arg3, maxPerimeter(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 41;
			int Arg1 = 64;
			int Arg2 = 16;
			int Arg3 = 113;

			verify_case(n, Arg3, maxPerimeter(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TriangleMaking ___test;
	___test.run_test(-1);
}
// END CUT HERE
