// BEGIN CUT HERE
/*
SRM 617 Div1 Easy (250)

PROBLEM STATEMENT
You have a long thin cake. For simplicity, we can consider the cake to be one-dimensional. The length of the cake is n. 

You are expecting some friends. You are going to cut the cake into multiple pieces before the friends arrive.

When the friends arrive, you will divide the cake among them, using the following procedure: starting at the beginning of the cake, you will first give some consecutive pieces to your first friend, then some consecutive pieces to your second friend, and so on.

Of course, you want to be fair. That is, each of your friends should receive the same total amount of cake. (The number of pieces may be different for different friends, but the sum of their lengths must be the same.)

As we stated above, you want to cut the cake before your friends arrive. However, you don't know how many friends will actually come. You only know that their count will be a divisor of n smaller than n.

You are given the int n. You want to cut the cake in such a way that for each valid number of friends it will be possible to give each of them the same amount of cake when using the above procedure. Return the smallest possible number of pieces after you cut the cake.


DEFINITION
Class:MyLongCake
Method:cut
Parameters:int
Returns:int
Method signature:int cut(int n)


CONSTRAINTS
-n will be between 2 and 100,000, inclusive.


EXAMPLES

0)
6

Returns: 4

The best possible solution is to cut the cake into 4 pieces. Let's call the pieces A, B, C, and D, in order. Their lengths will be 2, 1, 1, and 2.

As n=6, there will be 1, 2, or 3 friends. If there is just one friend, she gets all four pieces. If there are two friends, the first gets A+B and the second gets C+D. If there are three friends, the first gets A, the second gets B+C, and the third gets D.

Note that the order of parts matters. For example, dividing the cake into parts of length 2, 1, 2, and 1 is not a valid solution.


1)
3

Returns: 1


2)
15

Returns: 7

You are expecting 1, 3, or 5 friends.

3)
100000

Returns: 60000

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class MyLongCake {
public:
	int cut(int n) {
		int ans = 0;
		int x = n;
		for (int p = 2; x > 1 && p <= 100000; ++p) {
			if ((x % p) == 0) {
				while ((x % p) == 0) {
					x /= p;
				}
				ans += n / p;
				n -= n / p;
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
			int Arg0 = 6;
			int Arg1 = 4;

			verify_case(n, Arg1, cut(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 1;

			verify_case(n, Arg1, cut(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15;
			int Arg1 = 7;

			verify_case(n, Arg1, cut(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100000;
			int Arg1 = 60000;

			verify_case(n, Arg1, cut(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 3;
			verify_case(n, Arg1, cut(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arg1 = 4;
			verify_case(n, Arg1, cut(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 27;
			int Arg1 = 9;
			verify_case(n, Arg1, cut(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 9973;
			int Arg1 = 1;
			verify_case(n, Arg1, cut(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 12;
			int Arg1 = 8;
			verify_case(n, Arg1, cut(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MyLongCake ___test;
	___test.run_test(-1);
}
// END CUT HERE
