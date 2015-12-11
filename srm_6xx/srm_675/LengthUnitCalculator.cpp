// BEGIN CUT HERE
/*
SRM 675 Div2 Easy (250)

PROBLEM STATEMENT
Your task is to write a calculator that will convert between four different length units: inches (in), feet (ft), yards (yd), and miles (mi).

The conversions between these units:

1 ft = 12 in
1 yd = 3 ft
1 mi = 1760 yd

You are given an int amount and strings fromUnit and toUnit.
Compute and return the amount of toUnits that corresponds to amount fromUnits.
(For example, if amount=41, fromUnit="mi", and toUnit="in", you are supposed to compute the number of inches in 41 miles.)

Note that the result will not necessarily be an integer.

DEFINITION
Class:LengthUnitCalculator
Method:calc
Parameters:int, string, string
Returns:double
Method signature:double calc(int amount, string fromUnit, string toUnit)


NOTES
-Pay attention to the unusual time limit.


CONSTRAINTS
-amount will be between 1 and 1,000, inclusive.
-fromUnit will be one of {"in", "ft", "yd", "mi"}.
-toUnit will be one of {"in", "ft", "yd", "mi"}.


EXAMPLES

0)
1
"mi"
"ft"

Returns: 5280.0

We are asked to convert 1 mile into feet.
From the information in the statement we know that 1 mi = 1760 yd = (1760 * 3) ft = 5280 ft.


1)
1
"ft"
"mi"

Returns: 1.893939393939394E-4

Here we have 1 ft = 1/5280 mi, which is approximately 0.000189394 miles.


2)
123
"ft"
"yd"

Returns: 41.0


3)
1000
"mi"
"in"

Returns: 6.336E7


4)
1
"in"
"mi"

Returns: 1.5782828282828283E-5


5)
47
"mi"
"mi"

Returns: 47.0

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

class LengthUnitCalculator {
public:
	double calc(int amount, string fromUnit, string toUnit) {
		double ans = amount;
		if (fromUnit.compare("in") == 0) {
			ans /= 36;
		}
		if (fromUnit.compare("ft") == 0) {
			ans /= 3;
		}
		if (fromUnit.compare("mi") == 0) {
			ans *= 1760;
		}
		if (toUnit.compare("in") == 0) {
			ans *= 36;
		}
		if (toUnit.compare("ft") == 0) {
			ans *= 3;
		}
		if (toUnit.compare("mi") == 0) {
			ans /= 1760;
		}
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
			int Arg0 = 1;
			string Arg1 = "mi";
			string Arg2 = "ft";
			double Arg3 = 5280.0;

			verify_case(n, Arg3, calc(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			string Arg1 = "ft";
			string Arg2 = "mi";
			double Arg3 = 1.893939393939394E-4;

			verify_case(n, Arg3, calc(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 123;
			string Arg1 = "ft";
			string Arg2 = "yd";
			double Arg3 = 41.0;

			verify_case(n, Arg3, calc(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000;
			string Arg1 = "mi";
			string Arg2 = "in";
			double Arg3 = 6.336E7;

			verify_case(n, Arg3, calc(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			string Arg1 = "in";
			string Arg2 = "mi";
			double Arg3 = 1.5782828282828283E-5;

			verify_case(n, Arg3, calc(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 47;
			string Arg1 = "mi";
			string Arg2 = "mi";
			double Arg3 = 47.0;

			verify_case(n, Arg3, calc(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LengthUnitCalculator ___test;
	___test.run_test(-1);
}
// END CUT HERE
