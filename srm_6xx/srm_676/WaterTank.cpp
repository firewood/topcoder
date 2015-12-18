// BEGIN CUT HERE
/*
SRM 676 Div1 Easy (250)

PROBLEM STATEMENT

You are given the int C and the vector <int>s x and t.
You have a water tank with capacity C liters.
The tank is initially empty.

At time 0 water will start flowing into the tank through an input pipe.
This process will consist of n consecutive intervals, numbered 0 to n-1 in order.
Interval i lasts for t[i] seconds.
During each second of interval i exactly x[i] liters of water will enter the tank.

The tank also has an output pipe.
The water will always leave the tank through the output pipe as quickly as it can.
The output pipe has a valve.
You can use the valve to set the output pipe to any maximum output rate R (in liters per second).
This maximum output rate must remain constant during the entire process.
The rate must be nonnegative but it doesn't have to be an integer.

Determine and return the smallest output rate limit R such that the amount of water in the tank will never exceed C liters.


DEFINITION
Class:WaterTank
Method:minOutputRate
Parameters:vector <int>, vector <int>, int
Returns:double
Method signature:double minOutputRate(vector <int> t, vector <int> x, int C)


NOTES
-Your return value must have an absolute or relative error smaller than 1e-6.


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-t,x will have exactly n elements.
-Each element of t will be between 1 and 1,000,000, inclusive.
-Each element of x will be between 1 and 1,000,000, inclusive.
-C will be between 1 and 10^9, inclusive.


EXAMPLES

0)
{3,3}
{1,2}
3

Returns: 0.9999999999999999

In this case, we have two time intervals, the first one lasts 3 seconds and water flows at 1 liter per second. The second one lasts 3 seconds and water flows in at 2 liters per second.

The answer in this case is 1. During the first interval, water flows in and out at the same rate, while in the second interval, water flows in at a net rate of 1 liter per second. Any lower output rate would cause the tank to overflow 3 liters.


1)
{1,2,3,4,5}
{5,4,3,2,1}
10

Returns: 1.9999999999999996


2)
{5949,3198,376,3592,4019,3481,5609,3840,6092,4059}
{29,38,96,84,10,2,39,27,76,94}
1000000000

Returns: 0.0


3)
{9,3,4,8,1,2,5,7,6}
{123,456,789,1011,1213,1415,1617,1819,2021}
11

Returns: 2019.1666666666665


4)
{100}
{1000}
12345

Returns: 876.55

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class WaterTank {

public:
	double minOutputRate(vector <int> t, vector <int> x, int C) {
		long double low = 0;
		long double high = 1.0e+10;
		for (int i = 0; i < 1000; ++i) {
			long double mid = (low + high) / 2;
			bool f = [&]() -> bool {
				long double tot = 0;
				for (int j = 0; j != t.size(); ++j) {
					tot += 1.0 * t[j] * x[j];
					tot = max((long double)0.0, tot - mid * t[j]);
					if (tot > C) {
						return false;
					}
				}
				return true;
			} ();

			if (f) {
				high = mid;
			} else {
				low = mid;
			}
		}
		return low;
	}


// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (fabs(Expected - Received) < 1e-6) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,3};
			int Arr1[] = {1,2};
			int Arg2 = 3;
			double Arg3 = 0.9999999999999999;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minOutputRate(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5};
			int Arr1[] = {5,4,3,2,1};
			int Arg2 = 10;
			double Arg3 = 1.9999999999999996;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minOutputRate(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5949,3198,376,3592,4019,3481,5609,3840,6092,4059};
			int Arr1[] = {29,38,96,84,10,2,39,27,76,94};
			int Arg2 = 1000000000;
			double Arg3 = 0.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minOutputRate(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9,3,4,8,1,2,5,7,6};
			int Arr1[] = {123,456,789,1011,1213,1415,1617,1819,2021};
			int Arg2 = 11;
			double Arg3 = 2019.1666666666665;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minOutputRate(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100};
			int Arr1[] = {1000};
			int Arg2 = 12345;
			double Arg3 = 876.55;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minOutputRate(Arg0, Arg1, Arg2));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 2, 2 };
			int Arr1[] = { 2, 2 };
			int Arg2 = 3;
			double Arg3 = 1.25;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minOutputRate(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WaterTank ___test;
	___test.run_test(-1);
}
// END CUT HERE
