// BEGIN CUT HERE
/*
TCO19 R1A Hard (1000)

PROBLEM STATEMENT

An airline is selling tickets for one of its flights. 
The ticket can be purchased during N consecutive days.
On each day the price of the ticket is a constant, but it may change between days.

You are given the int N and the vector <int> C that describes how the prices change between days.
Suppose the price on day 1 is P1.
Between day 1 and day 2 the price will change by C[0] percent, between day 2 and day 3 it will change by C[1] percent, and so on.
Formally, if Pi denotes the price on day i, we have that for each i > 1 the price Pi is computed as Pi-1 * (100 + C[i-2]) / 100.

Of course, since we are talking about real money, all prices are immediately rounded to two decimal places (i.e., cents). The usual rounding "to the nearest cent" is applied, with half a cent always being rounded up. Thus, X.424999 is rounded to X.42, while X.425 becomes X.43.
Note that the rounding is applied after computing each price. For example, the price P3 is computed from the rounded value of the price P2.

The company wants to estimate the amount of money they will get for one ticket.
For simplicity, they made the assumption that the ticket will sell on one of the N days, chosen uniformly at random.
Thus, the expected price it will be sold for is (P1 + P2 + ... + PN) / N.
Note that the calculated expected price is also rounded to cents.

Let's take a look at the following example. The airline is selling a ticket for 5 days with the changes in price between days being -10%, +15%, +5%, -20%. If the airline sets the initial price P1 to 200 euro, then the prices in each of the 5 days will be (200.00, 180.00, 207.00, 217.35, 173.88). The expected selling price will then be (200.00 + 180.00 + 207.00 + 217.35 + 173.88) / 5 = 195.65 euro. (Note that the actual expected price is 195.646, but it is also rounded to cents.)

In order to be profitable, the airline wants the expected price of the ticket to be target euro. (That is, exactly target.00 euro after the last rounding.) Now they wonder what initial price P1 they should set in order to achieve this goal. In the example above, if target is 180 euro, then the initial price P1 must be 184.01 euro. This way the price of the ticket in each of the days would be (184.01, 165.61, 190.45, 199.97, 159.98), whose average is 180.004 which rounds to the desired 180.00.

Elly recently started working at the airline. Now her task is to determine the initial price of the ticket P1 given N, C, and target. Return a floating point number rounded to exactly two decimal places - the initial price P1, that the company must use.


DEFINITION
Class:EllysTicketPrices
Method:getPrice
Parameters:int, vector <int>, int
Returns:double
Method signature:double getPrice(int N, vector <int> C, int target)


NOTES
-Even though the return value is exact, due to the way floating point numbers work return values with an absolute or a relative error up to 10^(-9) will be accepted.


CONSTRAINTS
-N will be between 2 and 100, inclusive.
-C will contain exactly N - 1 elements.
-Each element of C will be between -99 and +99, inclusive.
-target will be between 10 and 10,000, inclusive.
-It is guaranteed that the input will be such that there will exist a unique price P1 which gives the expected selling price target.


EXAMPLES

0)
5
{-10, 15, 5, -20}
180

Returns: 184.01

The example from the problem statement.


1)
11
{5, 16, 17, -3, -10, 20, 20, 14, 2, 0}
1337

Returns: 874.77


2)
2
{0}
42

Returns: 42.0

With no change in the price, the answer should be obvious.


3)
20
{30, -26, 87, 47, -39, 25, -67, 62, -38, 68, -84, 5, 28, -20, 50, -61, 10, 63, -71}
392

Returns: 476.28


4)
50
{-60, 61, 17, 86, 56, 27, 9, 41, -27, -36, 57, -16, 1, 50, -55, -36, 14, 13, -93, 14, 18, 25, 62, -18, 40,
 79, 56, 19, 10, -55, -43, 45, -43, -84, 61, -64, 41, -55, 38, 18, 36, -43, 79, 33, 87, 19, -47, 38, -56}
8887

Returns: 9451.93

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

class EllysTicketPrices {
	int _n;
	vector <int> _c;
	long double _t;

	long double calc(double x) {
		long double sum = x;
		for (int i = 0; i < _n-1; ++i) {
			long double next = round(x * (100 + _c[i]) / 100);
			sum += next;
			x = next;
		}
		return sum / _n;
	}

public:
	double getPrice(int N, vector <int> C, int target) {
		_n = N;
		_c = C;
		_t = target * 100;
		long double left = 0.0001, right = 1e9;
		while (right - left > 1e-3) {
			long double mid = (left + right) / 2;
			long double e = calc(mid);
			if (e > _t) {
				right = mid;
			} else {
				left = mid;
			}
		}
		long double ans = floor(left), me = calc(ans);
		for (long double x = max((long double)1.0, ans - 3); x <= ans + 3; x += 1.0) {
			long double y = floor(x);
			long double e = calc(y);
			if (fabs(e - _t) < fabs(me - _t)) {
				ans = y;
				me = e;
			}
		}
		return ans * 0.01;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (fabs(Expected - Received) < 1e-9 ) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {-10, 15, 5, -20};
			int Arg2 = 180;
			double Arg3 = 184.01;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getPrice(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 11;
			int Arr1[] = {5, 16, 17, -3, -10, 20, 20, 14, 2, 0};
			int Arg2 = 1337;
			double Arg3 = 874.77;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getPrice(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {0};
			int Arg2 = 42;
			double Arg3 = 42.0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getPrice(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arr1[] = {30, -26, 87, 47, -39, 25, -67, 62, -38, 68, -84, 5, 28, -20, 50, -61, 10, 63, -71};
			int Arg2 = 392;
			double Arg3 = 476.28;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getPrice(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arr1[] = {-60, 61, 17, 86, 56, 27, 9, 41, -27, -36, 57, -16, 1, 50, -55, -36, 14, 13, -93, 14, 18, 25, 62, -18, 40,
 79, 56, 19, 10, -55, -43, 45, -43, -84, 61, -64, 41, -55, 38, 18, 36, -43, 79, 33, 87, 19, -47, 38, -56};
			int Arg2 = 8887;
			double Arg3 = 9451.93;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getPrice(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 3;
			int Arr1[] = { -99, -99 };
			int Arg2 = 10000;
			double Arg3 = 29700.03;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getPrice(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	cerr.precision(10);
	EllysTicketPrices ___test;
	___test.run_test(-1);
}
// END CUT HERE
