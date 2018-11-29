// BEGIN CUT HERE
/*
SRM 742 Div1 Easy (250)

PROBLEM STATEMENT

You have just inherited a resistor factory. The factory is fully robotized but the automated production lines lack programming. Currently the only thing they know how to manufacture is "product zero": a 1 Ohm resistor.

After some research you have discovered that you can define new products by combining previously defined products.
As you don't want to risk anything too complicated, you opted to only use the two simplest ways to combine resistors: either in series or in parallel.

Two resistors in series look as follows:

   +----+   +----+
---| R1 |---| R2 |---
   +----+   +----+

If the two components used have resistance R1 and R2, the resistance of the entire product is R = R1 + R2.

Two resistors in parallel look as follows:

      +----+  
   +--| R1 |--+
   |  +----+  |
 --+          +--
   |  +----+  |
   +--| R2 |--+
      +----+  

If the two components used have resistance R1 and R2, the resistance R of the entire product satisfies the equation 1/R = 1/R1 + 1/R2.

You just got insider information that the new "whyPhone" will require an awful number of resistors whose resistance is (nanoOhms * 10-9) Ohms.
Of course, this being real hardware, there is some tolerance, so any resistors whose resistance is reasonably close to the desired value will be OK.
Now only one thing stands between you and profit: you need to program the assembly line to produce such resistors.

Formally, the program is an ordered sequence of zero or more commands.
The commands are numbered 1, 2, 3, and so on.
Command i defines product i.
Each triple has the form (p1,p2,op) where p1 and p2 are the numbers of two already defined products (i.e., p1 and p2 must be between 0 and i-1, inclusive) and op is either 0 (meaning that the products p1 and p2 should be put in series) or 1 (meaning in parallel).

Return a vector <int> that is the concatenation of all commands in your program.
You may return any valid program with at most 1000 commands.
If you return an empty program, the final product is defined to be product zero.
Otherwise, the final product is the product defined by the last command in your program.
Your program will be accepted if the resistance of the final product is close enough to the required resistance.
More precisely, the resistance of your final product (expressed as a real number in Ohms) must have an absolute or a relative error at most 1e-9.


DEFINITION
Class:ResistorFactory
Method:construct
Parameters:long long
Returns:vector <int>
Method signature:vector <int> construct(long long nanoOhms)


CONSTRAINTS
-nanoOhms will be between 1 and 10^18, inclusive.


EXAMPLES

0)
3000000000

Returns: {0, 0, 0, 0, 1, 0 }

We want a resistor whose resistance is exactly 3 Ohms. This is easy: just take three 1 Ohm resistors in series. 

More precisely, we first define that product 1 consists of two products 0 in series, and then we say that product 2 is a product 0 and a product 1 in series.


1)
1200000000

Returns: {0, 0, 0, 1, 0, 0, 1, 2, 1 }

This time we want a resistor with resistance 1.2 Ohms.
Again, this is easy to achieve precisely.
One possibility is to take a 2 Ohm and a 3 Ohm resistor and connect them in parallel.


2)
1428571428

Returns: {0, 0, 0, 0, 1, 0, 1, 2, 0, 3, 1, 1 }

The resistor we want this time should have 1.428571428 Ohms. Instead of producing it precisely, we will produce a resistor with resistance 10/7 Ohms. As 10/7 = 1.4285714285714285714..., we are well within the required tolerance.


3)
12000000001

Returns: {0, 0, 0, 0, 1, 0, 2, 2, 0, 3, 3, 0 }


4)
333333333

Returns: {0, 0, 1, 0, 1, 1 }

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

class ResistorFactory {
public:
	vector <int> construct(long long nanoOhms) {
		LL upper = nanoOhms / 1000000000LL;
		long double lower = (long double)(nanoOhms - upper * 1000000000LL);
		vector <int> ans;
		for (int i = 0; i < 30; ++i) {
			ans.push_back(i);
			ans.push_back(i);
			ans.push_back(0);
		}
		ans.push_back(0);
		ans.push_back(0);
		ans.push_back(1);
		for (int i = 0; i < 60; ++i) {
			ans.push_back(31 + i);
			ans.push_back(31 + i);
			ans.push_back(1);
		}
		for (int i = 30; i >= 0; --i) {
			LL x = 1LL << i;
			if (x <= upper) {
				ans.push_back((int)ans.size() / 3);
				ans.push_back(i);
				ans.push_back(0);
				upper -= x;
			}
		}
		long double y = 500000000;
		for (int i = 0; i < 60; ++i) {
			if (y <= lower) {
				ans.push_back((int)ans.size() / 3);
				ans.push_back(i + 31);
				ans.push_back(0);
				lower -= y;
			}
			y *= 0.5;
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 3000000000LL;
			int Arr1[] = {0, 0, 0, 0, 1, 0 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1200000000LL;
			int Arr1[] = {0, 0, 0, 1, 0, 0, 1, 2, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1428571428LL;
			int Arr1[] = {0, 0, 0, 0, 1, 0, 1, 2, 0, 3, 1, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 12000000001LL;
			int Arr1[] = {0, 0, 0, 0, 1, 0, 2, 2, 0, 3, 3, 0 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 333333333LL;
			int Arr1[] = {0, 0, 1, 0, 1, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ResistorFactory ___test;
	___test.run_test(-1);
}
// END CUT HERE
