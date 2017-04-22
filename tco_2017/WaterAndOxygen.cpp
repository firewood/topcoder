// BEGIN CUT HERE
/*
TCO 2017 R1B Easy (250)

PROBLEM STATEMENT
You are in a spaceship that is far away from the Earth.
Your crew needs costH2O moles of water (H2O) and costO2 moles of oxygen (O2) per day.
The spaceship currently has remainH2O moles of water and remainO2 moles of oxygen left in the tanks.
This ship is old so you don't have any equipment to recycle used water and oxygen: once you use them, they are gone.
The only thing you can do is electrolysis of water.
For any positive real x, you can electrolyze x moles of water.
You will lose those x moles of water but you will produce x/2 moles of oxygen.
(You will also produce x moles of hydrogen but those don't matter in this task.)

Compute and return the longest amount of time (in days) your crew can survive.
Note that the answer is not necessarily an integer.


DEFINITION
Class:WaterAndOxygen
Method:maxDays
Parameters:int, int, int, int
Returns:double
Method signature:double maxDays(int remainH20, int remainO2, int costH2O, int costO2)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-costH2O will be between 1 and 1,000,000,000, inclusive.
-costO2 will be between 1 and 1,000,000,000, inclusive.
-remainH2O will be between 0 and 1,000,000,000, inclusive.
-remainO2 will be between 0 and 1,000,000,000, inclusive.


EXAMPLES

0)
64
70
3
7

Returns: 12.0

If you don't do anything, after 70 / 7 = 10 days you will run out of oxygen.
At that time you will have 64 - 10 * 3 = 34 moles of water left.
In order to survive longer you will need to electrolyze some of your remaining water to produce the oxygen you need.
To get enough oxygen for a day, you need to electrolyze 2 * 7 = 14 moles of water.
Don't forget that you also need 3 moles of actual water per day.
Thus, on each of the following days you will consume 17 moles of water, which means that you can survive for 34 / 2 = 2 extra days.
In total you will survive for 10 + 2 = 12 days.


1)
99
102
1
1

Returns: 99.0

You will run out of water after 99/1 = 99 days, while the oxygen will last for 102/1 = 102 days.
Electrolysis won't help you live longer than 99 days.


2)
101
99
1
1

Returns: 99.66666666666667

This time you should use 4/3 of a mole of water to produce 2/3 of a mole of oxygen.


3)
123456789
987654321
123
456

Returns: 1003713.731707317


4)
987654321
123456789
456
123

Returns: 1758643.7307692308


5)
0
0
13
27

Returns: 0.0

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class WaterAndOxygen {
public:
	double maxDays(int remainH20, int remainO2, int costH2O, int costO2) {
		double ans = min(1.0 * remainH20 / costH2O, 1.0 * remainO2 / costO2);
		ans += (remainH20 - ans * costH2O) / (costH2O + costO2 * 2.0);
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 64;
			int Arg1 = 70;
			int Arg2 = 3;
			int Arg3 = 7;
			double Arg4 = 12.0;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 99;
			int Arg1 = 102;
			int Arg2 = 1;
			int Arg3 = 1;
			double Arg4 = 99.0;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 101;
			int Arg1 = 99;
			int Arg2 = 1;
			int Arg3 = 1;
			double Arg4 = 99.66666666666667;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 123456789;
			int Arg1 = 987654321;
			int Arg2 = 123;
			int Arg3 = 456;
			double Arg4 = 1003713.731707317;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 987654321;
			int Arg1 = 123456789;
			int Arg2 = 456;
			int Arg3 = 123;
			double Arg4 = 1758643.7307692308;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 0;
			int Arg2 = 13;
			int Arg3 = 27;
			double Arg4 = 0.0;

			verify_case(n, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WaterAndOxygen ___test;
	___test.run_test(-1);
}
// END CUT HERE
