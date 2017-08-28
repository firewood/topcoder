// BEGIN CUT HERE
/*
SRM 720 Div2 Medium (500)

PROBLEM STATEMENT

You are given an array amount with exactly 10 elements, where the i-th element denotes the number of copies of the digit i you have.

You would like to construct two nonnegative integers A and B.
The base-10 representation of A must have exactly blank1 digits.
The base-10 representation of B must have exactly blank2 digits.
It is allowed for A and B to contain leading zeros.
In addition, the total number of appearances of digit i in the numbers A and B must be at most amount[i].
It's guaranteed that the sum of amount is at least blank1 + blank2.

Among all valid pairs (A, B), find the one for which A * B is minimal.
Return the smallest possible value of the product A * B.


DEFINITION
Class:MinProduct
Method:findMin
Parameters:vector <int>, int, int
Returns:long long
Method signature:long long findMin(vector <int> amount, int blank1, int blank2)


CONSTRAINTS
-amount will have exactly 10 elements.
-Each element of amount will be between 0 and 20.
-blank1, blank2 will be between 1 and 9, inclusive.
-The sum of elements in amount will be at least blank1 + blank2.


EXAMPLES

0)
{0,1,1,2,1,1,0,0,0,0}
2
3

Returns: 3042

In this case, we have the numbers {1,2,3,3,4,5}. A must consist of 2 digits, and B must consist of 3 digits. In this case, one optimal solution is to let A = 13 and B = 234. Then, A * B = 3042. We can show that no other way of assigning digits will give a strictly smaller value A * B.


1)
{1,1,1,1,1,1,1,1,1,1}
1
8

Returns: 0

We can let A = 0, B = 98765432.


2)
{1,3,0,0,0,0,0,0,0,0}
2
2

Returns: 11

It is allowed for A or B to have leading zeros.


3)
{0,20,20,20,20,20,20,20,20,20}
9
9

Returns: 12345678987654321


4)
{1,0,0,0,1,0,0,5,3,2}
9
3

Returns: 36556078253


5)
{0,0,0,0,0,0,0,0,0,18}
9
8

Returns: 99999998900000001

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

class MinProduct {
public:
	long long findMin(vector <int> amount, int blank1, int blank2) {
		if (blank1 > blank2) {
			swap(blank1, blank2);
		}
		LL a = 0, b = 0, d = 0;
		while (blank1 && amount[d]) {
			--amount[d];
			--blank1;
		}
		while (blank1 || blank2) {
			if (blank1) {
				while (!amount[d]) {
					++d;
				}
				a = a * 10 + d;
				amount[d]--;
				--blank1;
			}
			if (blank2) {
				while (!amount[d]) {
					++d;
				}
				b = b * 10 + d;
				amount[d]--;
				--blank2;
			}
		}
		return a * b;
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
			int Arr0[] = {0,1,1,2,1,1,0,0,0,0};
			int Arg1 = 2;
			int Arg2 = 3;
			long long Arg3 = 3042LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, findMin(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1,1,1,1,1};
			int Arg1 = 1;
			int Arg2 = 8;
			long long Arg3 = 0LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, findMin(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,3,0,0,0,0,0,0,0,0};
			int Arg1 = 2;
			int Arg2 = 2;
			long long Arg3 = 11LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, findMin(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,20,20,20,20,20,20,20,20,20};
			int Arg1 = 9;
			int Arg2 = 9;
			long long Arg3 = 12345678987654321LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, findMin(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,0,0,0,1,0,0,5,3,2};
			int Arg1 = 9;
			int Arg2 = 3;
			long long Arg3 = 36556078253LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, findMin(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0,0,0,0,0,0,0,18};
			int Arg1 = 9;
			int Arg2 = 8;
			long long Arg3 = 99999998900000001LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, findMin(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MinProduct ___test;
	___test.run_test(-1);
}
// END CUT HERE
