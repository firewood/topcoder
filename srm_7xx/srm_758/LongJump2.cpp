// BEGIN CUT HERE
/*
SRM 758 Div2 Easy (250)

PROBLEM STATEMENT

You are watching the finals of a long jump competition.
There are N contestants with bib numbers 1 through N.
There will be three rounds of jumps.
In each round, the contestants jump in the order from 1 to N.

At the beginning, there is no leader.
After each jump, if the jump is strictly longer than each of the previous jumps and the contestant who made the jump isn't the current leader, the contestant becomes the leader.

You are given the int N.
You are also given the vector <int> jumpLengths that contains the lengths of all 3N jumps in the competition, in the order in which they were performed.
Compute how many times some contestant became the leader during the competition.


DEFINITION
Class:LongJump2
Method:countNewLeaders
Parameters:int, vector <int>
Returns:int
Method signature:int countNewLeaders(int N, vector <int> jumpLengths)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-jumpLengths will contain exactly 3*N elements.
-Each element of jumpLengths will be between 0 and 1000, inclusive.


EXAMPLES

0)
1
{812, 780, 815}

Returns: 1

There is a single contestant. When they made their first jump, they became the leader. As there was nobody else to overtake them, the only contestant then remained the leader for the rest of the competition. Note that the last jump did not change the leader, even though it was longer than the first one.


1)
2
{0, 0, 0, 0, 0, 0}

Returns: 1

The first jump of length 0 is enough to become the leader. The subsequent jumps of length 0 are not enough to overtake the leader.


2)
2
{810, 811, 812, 813, 814, 815}

Returns: 6


3)
3
{800, 10, 20, 810, 30, 40, 50, 830, 830}

Returns: 2

Round 1, jump 1: contestant #1 jumps 800 and becomes the leader.
Round 2, jump 1: contestant #1 jumps 810, but she is already the leader, so the leader does not change.
Round 3, jump 2: contestant #2 jumps 830 and overtakes contestant #1 to become the new leader.
Round 3, jump 3: contestant #3 also jumps 830, but contestant #2 remains the leader - you need to jump strictly more than the previous leader in order to overtake them.

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

class LongJump2 {
public:
	int countNewLeaders(int N, vector <int> jumpLengths) {
		int ans = 0, mx = -1, leader = -1;
		for (int i = 0; i < (int)jumpLengths.size(); ++i) {
			if (jumpLengths[i] > mx) {
				mx = jumpLengths[i];
				if (leader != (i % N)) {
					leader = i % N;
					++ans;
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
			int Arg0 = 1;
			int Arr1[] = {812, 780, 815};
			int Arg2 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countNewLeaders(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {0, 0, 0, 0, 0, 0};
			int Arg2 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countNewLeaders(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {810, 811, 812, 813, 814, 815};
			int Arg2 = 6;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countNewLeaders(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {800, 10, 20, 810, 30, 40, 50, 830, 830};
			int Arg2 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countNewLeaders(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LongJump2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
