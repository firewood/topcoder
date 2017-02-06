// BEGIN CUT HERE
/*
SRM 706 Div2 Medium (500)

PROBLEM STATEMENT

Little Limak wants to show his parents that he's responsible and independent.
He decided to move out and live on his own, at least for some time.
While living alone, he has to eat every day.
Living alone comes with some other expenses as well.
More precisely, Limak will eat 1 fruit and spend x dollars each day he lives on his own.

Currently Limak has f fruits and d dollars.
Limak can buy more pieces of fruit in the local store.
The store sells 1 fruit for p dollars, and Limak can purchase arbitrarily many pieces of fruit there.

You are given the ints x, f, d, and p.
Compute and return the largest possible number of days Limak can live on his own.


DEFINITION
Class:SellingFruits
Method:maxDays
Parameters:int, int, int, int
Returns:int
Method signature:int maxDays(int x, int f, int d, int p)


NOTES
-Note the unusual Time Limit.
-For the provided constraints, it can be proved that the answer will fit into a 32-bit signed integer.


CONSTRAINTS
-x, f, d and p will each be between 1 and 2,000,000,000, inclusive.


EXAMPLES

0)
3
5
100
10

Returns: 11

Limak needs one fruit and 3 dollars for each day.
He starts with 5 fruits and 100 dollars.
The store sells additional fruit at 10 dollars a piece.

Limak should buy 6 additional pieces of fruit from the store.
This will leave him with 5+6 = 11 pieces of fruit and 100-6*10 = 40 dollars.
That will allow Limak to live on his own for 11 days.
After 11 days he will be left with no fruit and 7 dollars.

Limak is unable to live on his own for longer.
If he buys one more piece of fruit (to have a total of 12), he will only be left with 34 dollars, which is not enough for 12 days.


1)
2
17
20
1

Returns: 10

In 10 days Limak will eat 10 fruits and will spend 20 dollars.
He is left with 7 fruits but he has no money.


2)
1
97
98
1

Returns: 97


3)
16
4
8
2

Returns: 0

In this example Limak needs 1 fruit and 16 dollars for a day.
He doesn't have enough money to live one day on his own, so the answer is 0.


4)
17
1
2000000000
4

Returns: 95238095


5)
1
1996245611
1999990159
123

Returns: 1996275808


6)
15000000
100
2000000000
1

Returns: 133


7)
1
1000000000
2000000000
1000000000

Returns: 1000000000

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

class SellingFruits {
public:
	int maxDays(int x, int f, int d, int p) {
		int dd = min(f, d / x);
//		return dd + (d - dd * x) / ((long long)x + p);





		int fc = d / x;
		int m = min(f, fc);
		int days = m;
		d -= (days*x);
		f -= days;
		int y = p + x;
		int b = d / (p + x);
		int tmp = days + b;
		return (tmp > 0) ? tmp : 0;




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
			int Arg0 = 3;
			int Arg1 = 5;
			int Arg2 = 100;
			int Arg3 = 10;
			int Arg4 = 11;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 17;
			int Arg2 = 20;
			int Arg3 = 1;
			int Arg4 = 10;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 97;
			int Arg2 = 98;
			int Arg3 = 1;
			int Arg4 = 97;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 16;
			int Arg1 = 4;
			int Arg2 = 8;
			int Arg3 = 2;
			int Arg4 = 0;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 17;
			int Arg1 = 1;
			int Arg2 = 2000000000;
			int Arg3 = 4;
			int Arg4 = 95238095;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1996245611;
			int Arg2 = 1999990159;
			int Arg3 = 123;
			int Arg4 = 1996275808;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15000000;
			int Arg1 = 100;
			int Arg2 = 2000000000;
			int Arg3 = 1;
			int Arg4 = 133;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1000000000;
			int Arg2 = 2000000000;
			int Arg3 = 1000000000;
			int Arg4 = 1000000000;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SellingFruits ___test;
	___test.run_test(-1);
}
// END CUT HERE
