// BEGIN CUT HERE
/*
SRM 704 Div2 Easy (250)

PROBLEM STATEMENT
A sequence S is called an arithmetic sequence if there is a number d (called the difference) such that for each i, S[i+1] = S[i] + d.
Note that d may be zero or negative.
Examples of arithmetic sequences: {1,2,3}, {3,2,1}, {10,10,10,10}, {47}.


You are given a vector <int> x.
You want to change x into an arithmetic sequence.
In order to do that, you are allowed to swap any two elements of x.
You may perform arbitrarily many such swaps, one after another.
For example, you can change {2,1,5,4,3} to {2,1,3,4,5} and then change that sequence to {1,2,3,4,5}.


Return "Possible" if x can be changed into an arithmetic sequence.
Otherwise, return "Impossible".
Note that the return value is case-sensitive.


DEFINITION
Class:SwapAndArithmetic
Method:able
Parameters:vector <int>
Returns:string
Method signature:string able(vector <int> x)


CONSTRAINTS
-x will contain between 2 and 50 elements, inclusive.
-Each element in x will be between 0 and 1,000, inclusive.


EXAMPLES

0)
{3,1,2}

Returns: "Possible"

We can swap the last two elements to change the given x to {3, 2, 1}, which is an arithmetic sequence.


1)
{1,2,4}

Returns: "Impossible"

We can change x to one of the following 6 sequences:

{1,2,4}
{1,4,2}
{2,1,4}
{2,4,1}
{4,1,2}
{4,2,1}

There is no arithmetic sequence among these six sequences.


2)
{1,1,1,1,1,1}

Returns: "Possible"


3)
{1000,704,1}

Returns: "Impossible"


4)
{7,3,11,5,1,9}

Returns: "Possible"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class SwapAndArithmetic {
public:
	string able(vector <int> x) {
		sort(x.begin(), x.end());
		int d = x[1] - x[0];
		for (int i = 2; i != x.size(); ++i) {
			if ((x[i] - x[i - 1]) != d) {
				return "Impossible";
			}
		}
		return "Possible";
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
			int Arr0[] = {3,1,2};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, able(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,4};
			string Arg1 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, able(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, able(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000,704,1};
			string Arg1 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, able(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7,3,11,5,1,9};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, able(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SwapAndArithmetic ___test;
	___test.run_test(-1);
}
// END CUT HERE
