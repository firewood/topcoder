// BEGIN CUT HERE
/*
SRM 764 Level 4 (500)

PROBLEM STATEMENT
You are given four non-negative integers a, b, c, d, and are given that 2n = a2 + b2 + c2 + d2.

You have to find four non-negative integers s, x, y, z such that n = s2 + x2 + y2 + z2.

(It may be proven that such a quadruple always exists.)

Return a vector <int> containing the values {s, x, y, z}.


DEFINITION
Class:FourSquareSum
Method:DivideByTwo
Parameters:int, int, int, int
Returns:vector <int>
Method signature:vector <int> DivideByTwo(int a, int b, int c, int d)


NOTES
-The order of the four elements in your return does not matter.


CONSTRAINTS
-0 ? a,b,c,d ? 106,
-a2+b2+c2+d2 is even.


EXAMPLES

0)
1
2
3
4

Returns: {1, 1, 2, 3 }

12+22+32+42=30, so 12+12+22+32=15 will do.


1)
5
7
1
3

Returns: {1, 1, 2, 6 }

52+72+12+32=84, so 12+12+22+62=42 will do.


2)
0
0
0
0

Returns: {0, 0, 0, 0 }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class FourSquareSum {
public:
	vector <int> DivideByTwo(int a, int b, int c, int d) {
		vector<int> v({ a, b, c, d });
		// sort by parity
		sort(v.begin(), v.end(), [&](int a, int b) -> int {
			if ((a % 2) != (b % 2)) {
				return (a % 2) < (b % 2);
			}
			return a < b;
		});
		return { (v[1] - v[0]) / 2, (v[1] + v[0]) / 2, (v[3] - v[2]) / 2, (v[3] + v[2]) / 2 };
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
			int Arg0 = 1;
			int Arg1 = 2;
			int Arg2 = 3;
			int Arg3 = 4;
			int Arr4[] = {1, 1, 2, 3 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, DivideByTwo(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 7;
			int Arg2 = 1;
			int Arg3 = 3;
			int Arr4[] = {1, 1, 2, 6 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, DivideByTwo(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 0;
			int Arr4[] = {0, 0, 0, 0 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, DivideByTwo(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1000000;
			int Arg1 = 1000000;
			int Arg2 = 1000000;
			int Arg3 = 1000000;
			int Arr4[] = { 0, 1000000, 0, 1000000 };

			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			verify_case(n, Arg4, DivideByTwo(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FourSquareSum ___test;
	___test.run_test(-1);
}
// END CUT HERE
