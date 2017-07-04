// BEGIN CUT HERE
/*
SRM 716 Div2 Easy (250)

PROBLEM STATEMENT
You are given a positive integer x.
Please check whether we can rearrange the digits of x (in base 10, without leading zeros) to produce a different number that is a multiple of x.

Return "Possible" if this can be done and "Impossible" otherwise.
Note that the return value is case-sensitive.


DEFINITION
Class:Permutiple
Method:isPossible
Parameters:int
Returns:string
Method signature:string isPossible(int x)


CONSTRAINTS
-x will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
142857

Returns: "Possible"

One valid way of rearranging the digits of 142857 is to form the number 285714. This new number is a multiple of x: we have 285714 = 2 * 142857.


Another valid way is to form the number 857142 (which is equal to 6 * 142857).


1)
14

Returns: "Impossible"

The only other number we can get by rearranging the digits of the number 14 is the number 41.
As 41 is not a multiple of 14, there is no solution.


2)
1035

Returns: "Possible"

We can get 3105 = 3 * 1035.


3)
1000000

Returns: "Impossible"


4)
100035

Returns: "Possible"


5)
4

Returns: "Impossible"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Permutiple {
public:
	string isPossible(int x) {
		stringstream a;
		a << x;
		string p;
		a >> p;
		sort(p.begin(), p.end());
		for (int n = x * 2; n <= 999999; n += x) {
			stringstream b;
			b << n;
			string q;
			b >> q;
			sort(q.begin(), q.end());
			if (p == q) {
				return "Possible";
			}
			if (q.length() > p.length()) {
				break;
			}
		}
		return "Impossible";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 142857;
			string Arg1 = "Possible";

			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 14;
			string Arg1 = "Impossible";

			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1035;
			string Arg1 = "Possible";

			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000;
			string Arg1 = "Impossible";

			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100035;
			string Arg1 = "Possible";

			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			string Arg1 = "Impossible";

			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Permutiple ___test;
	___test.run_test(-1);
}
// END CUT HERE
