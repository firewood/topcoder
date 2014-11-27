// BEGIN CUT HERE
/*
SRM 598 Div2 Medium (500)

PROBLEM STATEMENT
Fox Ciel has some items. The weight of the i-th (0-based) item is item[i]. She wants to put all items into bins.

The capacity of each bin is 300. She can put an arbitrary number of items into a single bin, but the total weight of items in a bin must be less than or equal to 300.

You are given the vector <int> item. It is known that the weight of each item is between 101 and 300, inclusive. Return the minimal number of bins required to store all items.


DEFINITION
Class:BinPackingEasy
Method:minBins
Parameters:vector <int>
Returns:int
Method signature:int minBins(vector <int> item)


CONSTRAINTS
-item will contain between 1 and 50 elements, inclusive.
-Each element of item will be between 101 and 300, inclusive.


EXAMPLES

0)
{150, 150, 150, 150, 150}

Returns: 3

You have five items and each bin can hold at most two of them. You need at least three bins.

1)
{130, 140, 150, 160}

Returns: 2

For example, you can distribute the items in the following way:

Bin 1: 130, 150
Bin 2: 140, 160


2)
{101, 101, 101, 101, 101, 101, 101, 101, 101}

Returns: 5


3)
{101, 200, 101, 101, 101, 101, 200, 101, 200}

Returns: 6


4)
{123, 145, 167, 213, 245, 267, 289, 132, 154, 176, 198}

Returns: 8

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class BinPackingEasy {
public:
	int minBins(vector <int> item) {
		int ans = 0;
		sort(item.begin(), item.end());
		int used[64] = {};
		for (int i = 0; i < (int)item.size(); ++i) {
			if (!used[i]) {
				++ans;
				for (int j = (int)item.size() - 1; j > i; --j) {
					if (!used[j] && (item[i] + item[j]) <= 300) {
						used[j] = 1;
						break;
					}
				}
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {150, 150, 150, 150, 150};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minBins(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {130, 140, 150, 160};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minBins(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {101, 101, 101, 101, 101, 101, 101, 101, 101};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minBins(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {101, 200, 101, 101, 101, 101, 200, 101, 200};
			int Arg1 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minBins(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {123, 145, 167, 213, 245, 267, 289, 132, 154, 176, 198};
			int Arg1 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minBins(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BinPackingEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
