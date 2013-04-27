// BEGIN CUT HERE
/*
TCO 2013 Round 2B Easy (250)

PROBLEM STATEMENT
There is an infinitely long straight road.
Fox Ciel is going to plant trees of three kinds: apple trees, kiwi trees, and grape trees.
There will be infinitely many trees of each kind.
Trees of each kind will be placed along the entire road in regular intervals.

More precisely, you are given ints apple, kiwi, and grape with the following meaning:
The distance between any two consecutive apple trees must be apple, the distance between any two consecutive kiwi trees must be kiwi,
and the distance between any two consecutive grape trees must be grape.

Ciel can only plant the trees at integer coordinates, but she gets to choose those coordinates as long as the above conditions are satisfied.
In other words, Ciel gets to choose three integers x, y, and z such that:

She plants apple trees at coordinates ..., x - 2 * apple, x - apple, x, x + apple, x + 2 * apple, ...
She plants kiwi trees at coordinates ..., y - 2 * kiwi, y - kiwi, y, y + kiwi, y + 2 * kiwi, ...
She plants grape trees at coordinates ..., z - 2 * grape, z - grape, z, z + grape, z + 2 * grape, ...

Ciel wants to maximize the distance between two closest trees (of any kind).
Return this distance.


DEFINITION
Class:FruitTrees
Method:maxDist
Parameters:int, int, int
Returns:int
Method signature:int maxDist(int apple, int kiwi, int grape)


CONSTRAINTS
-apple will be between 1 and 2,000, inclusive.
-kiwi will be between 1 and 2,000, inclusive.
-grape will be between 1 and 2,000, inclusive.


EXAMPLES

0)
1
5
8

Returns: 0

Apple trees will be planted at all integer coordinates, so at least two trees will be planted where a kiwi tree is planted.


1)
3
3
6

Returns: 1

One of the optimal solutions is as follows:

Plant apple trees at ..., -5, -2, 1, 4, ...
Plant kiwi trees at ..., -4, -1, 2, 5, ...
Plant grape trees at ..., -9, -3, 3, 9, ...


2)
40
30
20

Returns: 5


3)
899
1073
1147

Returns: 14


4)
2000
2000
2000

Returns: 666

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

class FruitTrees {
public:
	int maxDist(int apple, int kiwi, int grape) {
		int a = gcd(apple, kiwi);
		int b = gcd(kiwi, grape);
		int c = gcd(grape, apple);
		int ans = min(a, min(b, c)) / 2;
		if (a == b && b == c) {
			ans = a / 3;
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
			int Arg0 = 1;
			int Arg1 = 5;
			int Arg2 = 8;
			int Arg3 = 0;

			verify_case(n, Arg3, maxDist(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 6;
			int Arg3 = 1;

			verify_case(n, Arg3, maxDist(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 40;
			int Arg1 = 30;
			int Arg2 = 20;
			int Arg3 = 5;

			verify_case(n, Arg3, maxDist(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 899;
			int Arg1 = 1073;
			int Arg2 = 1147;
			int Arg3 = 14;

			verify_case(n, Arg3, maxDist(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2000;
			int Arg1 = 2000;
			int Arg2 = 2000;
			int Arg3 = 666;

			verify_case(n, Arg3, maxDist(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 10;
			int Arg2 = 10;
			int Arg3 = 1;

			verify_case(n, Arg3, maxDist(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 77;
			int Arg1 = 42;
			int Arg2 = 21;
			int Arg3 = 3;

			verify_case(n, Arg3, maxDist(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 6;
			int Arg2 = 6;
			int Arg3 = 1;

			verify_case(n, Arg3, maxDist(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 444;
			int Arg1 = 1480;
			int Arg2 = 1110;
			int Arg3 = 74;

			verify_case(n, Arg3, maxDist(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FruitTrees ___test;
	___test.run_test(-1);
}
// END CUT HERE
