// BEGIN CUT HERE
/*
SRM 646 Div2 Easy (250)

PROBLEM STATEMENT
John and Brus have a set of integers.
You are given its elements in a vector <int> numbers.
They can change the integers in numbers by performing some operations.
In each operation John will pick a number and Brus will either increase or decrease it by 1.

You are also given an int k which is either 1 or 2.
John and Brus want to have at least k integers with consecutive values in their set.
Compute and return the smallest number of operations they have to perform.


DEFINITION
Class:TheConsecutiveIntegersDivTwo
Method:find
Parameters:vector <int>, int
Returns:int
Method signature:int find(vector <int> numbers, int k)


CONSTRAINTS
-numbers will contain between 2 and 47 elements, inclusive.
-Each element of numbers will be between -10,000,000 and 10,000,000, inclusive.
-All elements of numbers will be distinct.
-k will be between 1 and 2, inclusive.


EXAMPLES

0)
{4, 47, 7}
2

Returns: 2

There are three optimal strategies:

Increase 4 two times to obtain {6,47,7}.
Decrease 7 two times to obtain {4,47,5}.
Increase 4 and decrease 7 to obtain {5,47,6}.

Note that the consecutive values can appear anywhere in the set, their position in numbers does not matter.


1)
{1, 100}
1

Returns: 0

No operation is needed.


2)
{-96, -53, 82, -24, 6, -75}
2

Returns: 20


3)
{64, -31, -56}
2

Returns: 24

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TheConsecutiveIntegersDivTwo {
public:
	int find(vector <int> numbers, int k) {
		int ans = 0;
		if (k > 1) {
			ans = 1 << 30;
			sort(numbers.begin(), numbers.end());
			int N = (int)numbers.size();
			for (int i = 0; i < N - 1; ++i) {
				ans = min(ans, abs(numbers[i + 1] - numbers[i]) - 1);
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
			int Arr0[] = {4, 47, 7};
			int Arg1 = 2;
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 100};
			int Arg1 = 1;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-96, -53, 82, -24, 6, -75};
			int Arg1 = 2;
			int Arg2 = 20;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {64, -31, -56};
			int Arg1 = 2;
			int Arg2 = 24;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheConsecutiveIntegersDivTwo ___test;
	___test.run_test(-1);
}
// END CUT HERE
