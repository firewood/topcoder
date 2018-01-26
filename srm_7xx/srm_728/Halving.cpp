// BEGIN CUT HERE
/*
SRM 728 Div1 Easy (250)

PROBLEM STATEMENT

You have a collection of sticks.
The length of each stick is a positive integer.

You want to have a collection of sticks in which all the sticks have the same length.
You may alter your current collection by performing zero or more steps.
Each step must look as follows:

You choose one of your sticks. The chosen stick must have length at least 2.
Let L be the length of the chosen stick.
If L is even, cut the stick into two sticks of length L/2 each. Otherwise, cut it into sticks of lengths (L-1)/2 and (L+1)/2.
Keep one of the two new sticks and throw away the other one.

It can be proved that any collection of sticks can be turned into a collection of sticks that all have the same length.
You are given the current lengths of your sticks in the vector <int> a.
Compute and return the smallest number of steps needed to reach your goal.


DEFINITION
Class:Halving
Method:minSteps
Parameters:vector <int>
Returns:int
Method signature:int minSteps(vector <int> a)


CONSTRAINTS
-a will contain between 2 and 50 elements, inclusive.
-Each element of a will be between 1 and 10**9, inclusive.


EXAMPLES

0)
{11, 4}

Returns: 3

One optimal solution is:

 Pick the stick of length 11, cut it into sticks of lengths 5 and 6 and keep the part of length 5. 
 Pick the stick of length 4, cut it into two sticks of length 2 and keep the part of length 2. 
 Pick the stick of length 5, cut it into sticks of lengths 2 and 3 and keep the part of length 2. 

In the end, you'll have two sticks of length 2.

1)
{1000000000, 1000000000, 1000000000, 1000000000}

Returns: 0

All your sticks have the same length, no steps are needed.

2)
{1, 2, 3, 4, 5, 6, 7}

Returns: 10


3)
{13, 13, 7, 11, 13, 11}

Returns: 11


4)
{1, 1}

Returns: 0

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Halving {
	map<int, int> memo[50];
	void gen(int i, int x, int y) {
		if (memo[i].find(x) == memo[i].end() || memo[i][x] > y) {
			memo[i][x] = y;
			if (x >= 2) {
				gen(i, (x + 1) / 2, y + 1);
				gen(i, x / 2, y + 1);
			}
		}
	}
public:
	int minSteps(vector <int> a) {
		int n = (int)a.size();
		for (int i = 0; i < n; ++i) {
			memo[i].clear();
			gen(i, a[i], 0);
		}
		int ans = 1 << 30;
		for (auto kv : memo[0]) {
			int cnt = kv.second;
			for (int i = 1; i < n; ++i) {
				if (memo[i].find(kv.first) == memo[i].end()) {
					cnt = 1 << 30;
					break;
				}
				cnt += memo[i][kv.first];
			}
			ans = min(ans, cnt);
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
			int Arr0[] = {11, 4};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSteps(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000000, 1000000000, 1000000000, 1000000000};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSteps(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4, 5, 6, 7};
			int Arg1 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSteps(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {13, 13, 7, 11, 13, 11};
			int Arg1 = 11;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSteps(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSteps(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 4, 7 };
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSteps(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Halving ___test;
	___test.run_test(-1);
}
// END CUT HERE
