// BEGIN CUT HERE
/*
SRM 710 Div1 Easy (250)
SRM 710 Div1 Medium (500)

PROBLEM STATEMENT

A lord owned a piece of land with area N.
He wanted to give parts of this land as rewards to his subjects, so he decided that he will split the piece of land into one or more pieces in such a way that the size of each piece will be between A and B, inclusive.
But splitting pieces of land is regulated by the king of this country, as follows:


Each piece of land must always have a positive integer area.
For all X, Y: The owner of a piece of land of size X+Y may split it into two pieces of size X and Y, but if they do, they have to pay the king X*Y in taxes.
For all X, Y, Z: The owner of a piece of land of size X+Y+Z may split it into three pieces of size X, Y, and Z, but if they do, they have to pay the king X*Y + Y*Z + Z*X in taxes.


Return -1 if the lord cannot reach his goal. Otherwise, return the smallest total amount of taxes with which the lord can reach his goal.


DEFINITION
Class:LandSplitter
Method:cheapest
Parameters:int, int, int
Returns:long long
Method signature:long long cheapest(int N, int A, int B)


NOTES
-For the chosen constraints the answer always fits into a 64-bit signed integer.


CONSTRAINTS
-1 <= A <= B <= N <= 100,000,000.


EXAMPLES

0)
12
3
3

Returns: 54

One optimal solution is to split the land into two halves (cost 36) and then separately each half into halves (cost 9 twice).

1)
10
3
4

Returns: 33

One optimal solution is to directly split the land into pieces of size 3, 3, and 4.

2)
47
1
47

Returns: 0

Clearly, the optimal solution is to do nothing.

3)
70
40
50

Returns: -1

A land of size 70 cannot be split into pieces of size between 40 and 50, inclusive.

4)
47
4
7

Returns: 945



*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> LLLL;

class LandSplitter {

public:
	long long cheapest(int N, int A, int B) {
		LL n = N, a = A, b = B, l = (n + b - 1) / b, r = n / a, rem = n;
		if (r < l) return -1;
		priority_queue<LLLL, vector<LLLL>, greater<LLLL>> q;
		for (LL i = 0; i < l; ++i) {
			LL next = max(a, rem - (l - i - 1) * b);
			q.push(LLLL(0, next));
			rem -= next;
		}
		while (q.size() >= 2) {
			LLLL x1 = q.top();
			q.pop();
			LLLL x2 = q.top();
			q.pop();
			LL cost = x1.second * x2.second;
			q.push(LLLL(x1.first + x2.first + cost, x1.second + x2.second));
		}
		return q.top().first;
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
			int Arg0 = 12;
			int Arg1 = 3;
			int Arg2 = 3;
			long long Arg3 = 54LL;

			verify_case(n, Arg3, cheapest(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 3;
			int Arg2 = 4;
			long long Arg3 = 33LL;

			verify_case(n, Arg3, cheapest(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 47;
			int Arg1 = 1;
			int Arg2 = 47;
			long long Arg3 = 0LL;

			verify_case(n, Arg3, cheapest(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 70;
			int Arg1 = 40;
			int Arg2 = 50;
			long long Arg3 = -1LL;

			verify_case(n, Arg3, cheapest(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 47;
			int Arg1 = 4;
			int Arg2 = 7;
			long long Arg3 = 945LL;

			verify_case(n, Arg3, cheapest(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 99999987;
			int Arg1 = 5;
			int Arg2 = 7;
			long long Arg3 = 4999998350000140LL;

			verify_case(n, Arg3, cheapest(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LandSplitter ___test;
	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
