// BEGIN CUT HERE
/*
SRM 585 Div2 Easy (250)

PROBLEM STATEMENT
Let A be a sequence of integers. We want to create this sequence as a concatenation of some (one or more) strictly increasing sequences. The LISNumber of A is the smallest number of strictly increasing sequences we need.

For example, the LISNumber of the sequence A = {1, 4, 4, 2, 6, 3} is 4, since A can be created as {1, 4} + {4} + {2, 6} + {3}, and there is no way to create A by concatenating 3 (or fewer) strictly increasing sequences.

Another example: The LISNumber of the sequence B = {10, 20, 30} is 1, since B is already a strictly increasing sequence.

Note that the optimal way of writing a sequence as a concatenation of some strictly increasing sequences is always unique.

You are given a vector <int> seq. Return the LISNumber of the sequence seq.


DEFINITION
Class:LISNumberDivTwo
Method:calculate
Parameters:vector <int>
Returns:int
Method signature:int calculate(vector <int> seq)


CONSTRAINTS
-seq will contain between 1 and 50 elements, inclusive.
-Each element of seq will be between 1 and 50, inclusive.


EXAMPLES

0)
{1, 4, 4, 2, 6, 3}

Returns: 4

This is the example from the problem statement.


1)
{5, 8, 9, 12, 16, 32, 50}

Returns: 1

In this case, seq itself is already strictly increasing. Thus, the LISNumber of this sequence is 1.


2)
{1, 1, 9, 9, 2, 2, 3, 3}

Returns: 6

{1, 1, 9, 9, 2, 2, 3, 3} = {1} + {1, 9} + {9} + {2} + {2, 3} + {3}


3)
{50, 40, 30, 20, 10}

Returns: 5


4)
{42}

Returns: 1

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class LISNumberDivTwo {
public:
	int calculate(vector <int> seq) {
		int ans = 0, prev = 9999;
		int sz = (int)seq.size();
		int i;
		for (i = 0; i < sz; ++i) {
			if (prev >= seq[i]) {
				++ans;
			}
			prev = seq[i];
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
			int Arr0[] = {1, 4, 4, 2, 6, 3};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, calculate(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 8, 9, 12, 16, 32, 50};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, calculate(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 9, 9, 2, 2, 3, 3};
			int Arg1 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, calculate(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50, 40, 30, 20, 10};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, calculate(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {42};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, calculate(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, calculate(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LISNumberDivTwo ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
