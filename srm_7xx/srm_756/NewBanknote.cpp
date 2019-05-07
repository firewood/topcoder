// BEGIN CUT HERE
/*
SRM 756 Div1 Easy (250)

PROBLEM STATEMENT

In this problem we use the Euro currency. One euro equals 100 cents. All amounts in this problem will be in cents to avoid dealing with non-integer numbers.

Euro coins have the following denominations: 1, 2, 5, 10, 20, 50, 100, and 200 cents.
Euro banknotes have the following denominations: 500, 1000, 2000, 5000, 10000, 20000, and 50000 cents.

There are rumors that the European Committee will soon introduce a new banknote worth newBanknote cents.

In this new monetary system, what will be the smallest number of coins and banknotes needed to pay exactly X cents?

You are given the vector <int> amountsToPay.
For each X in amountsToPay answer the above question.
Return a vector <int> containing the answers.


DEFINITION
Class:NewBanknote
Method:fewestPieces
Parameters:int, vector <int>
Returns:vector <int>
Method signature:vector <int> fewestPieces(int newBanknote, vector <int> amountsToPay)


CONSTRAINTS
-newBanknote will be between 1 and 2*10^9, inclusive.
-amountsToPay will have between 1 and 50 elements, inclusive.
-Each element of amountsToPay will be between 1 and 2*10^9, inclusive.


EXAMPLES

0)
4700
{53, 9400, 9401, 30000}

Returns: {3, 2, 3, 2 }

The new banknote is worth exactly 47 euro.

When paying 53 cents, the new banknote is useless. The optimal way uses three coins: 50 + 2 + 1.
When paying 94 euro, the optimal solution is to use two new banknotes.
When paying 94 euro and 1 cent, the optimal solution is to use two new banknotes and a 1-cent coin.
When paying 300 euro, the optimal solution is to use one 100-euro and one 200-euro banknote.


1)
1234
{1233, 1234, 1235}

Returns: {6, 1, 2 }


2)
1000
{1233, 100047}

Returns: {6, 6 }

The new banknote is utterly useless: we already have 10-euro banknotes. Thus, the answer for any amount is the same as when paying using regular Euro denominations only.

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

class NewBanknote {
	int calc(int x) {
		int c = x / 50000;
		x %= 50000;
		const int r[] = { 0, 1, 1, 2, 2, 1, 2, 2, 3, 3 };
		while (x) {
			c += r[x % 10];
			x /= 10;
		}
		return c;
	}

public:
	vector <int> fewestPieces(int newBanknote, vector <int> amountsToPay) {
		vector<int> ans;
		for (int x : amountsToPay) {
			int a = calc(x);
			for (int i = 0; i <= a && x >= 0; ++i, x -= newBanknote) {
				a = min(a, i + calc(x));
			}
			ans.push_back(a);
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
			int Arg0 = 4700;
			int Arr1[] = {53, 9400, 9401, 30000};
			int Arr2[] = {3, 2, 3, 2 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, fewestPieces(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1234;
			int Arr1[] = {1233, 1234, 1235};
			int Arr2[] = {6, 1, 2 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, fewestPieces(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000;
			int Arr1[] = {1233, 100047};
			int Arr2[] = {6, 6 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, fewestPieces(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1000000;
			int Arr1[] = { 10000000 };
			int Arr2[] = { 10 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, fewestPieces(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 10000000;
			int Arr1[] = { 50000,100000,80000 };
			int Arr2[] = { 1,2,3 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, fewestPieces(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 50021;
			int Arr1[] = { 50021*300+50000+300};
			int Arr2[] = { 303 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, fewestPieces(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1000000000;
			int Arr1[] = { 1000000 };
			int Arr2[] = { 1000000/50000 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, fewestPieces(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 50021;
			int Arr1[] = { 820301806 };
			int Arr2[] = { 16401 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, fewestPieces(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 50021;
			int Arr1[] = { 1120249967 };
			int Arr2[] = { 22396 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, fewestPieces(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 977;
			int Arr1[] = { 820301806 };
			int Arr2[] = { 16412 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, fewestPieces(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1;
			int Arr1[] = { 2000000000 };
			int Arr2[] = { 40000 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, fewestPieces(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE
	//16034524
};

// BEGIN CUT HERE
int main() {
	NewBanknote ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
