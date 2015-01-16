// BEGIN CUT HERE
/*
SRM 646 Div1 Easy (250)

PROBLEM STATEMENT
John and Brus have some integers.
You are given these integers in a vector <int> numbers.
In one operation they can pick a number and increase/decrease it by 1.
They want to have at least k consecutive integers.
The order in which those integers appear in numbers does not matter.
Return the minimal number of operations required to achieve the goal.


DEFINITION
Class:TheConsecutiveIntegersDivOne
Method:find
Parameters:vector <int>, int
Returns:int
Method signature:int find(vector <int> numbers, int k)


CONSTRAINTS
-numbers will contain between 2 and 47 elements, inclusive.
-Each element of numbers will be between -10,000,000 and 10,000,000, inclusive.
-All elements of numbers will be distinct.
-k will be between 1 and the number of elements in numbers, inclusive.


EXAMPLES

0)
{4, 7, 47}
2

Returns: 2

There are three optimal strategies:

Increase 4 two times to obtain {6,7,47}.
Decrease 7 two times to obtain {4,5,47}.
Increase 4 and decrease 7 to obtain {5,6,47}.


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


4)
{-96, -53, 82, -24, 6, -75}
4

Returns: 90

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TheConsecutiveIntegersDivOne {
public:
	int find(vector <int> numbers, int k) {
		int ans = 1 << 30;
		int N = (int)numbers.size();
		sort(numbers.begin(), numbers.end());
		for (int i = 0; i <= N - k; ++i) {
			for (int b = 0; b < k; ++b) {
				int sum = 0;
				for (int j = 0; j < k; ++j) {
					sum += abs(numbers[i + b] - b + j - numbers[i + j]);
				}
				ans = min(ans, sum);
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
			int Arr0[] = {4, 7, 47};
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

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-96, -53, 82, -24, 6, -75};
			int Arg1 = 4;
			int Arg2 = 90;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = { -4845232, -5077278, -1696332, 9685053, -8008906, -2041580, -2825611, 7330935, -1994531, -5206896, -202206, -1506777, 8005773 };
			int Arg1 = 9;
			int Arg2 = 12555151;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheConsecutiveIntegersDivOne ___test;
	___test.run_test(-1);
}
// END CUT HERE
