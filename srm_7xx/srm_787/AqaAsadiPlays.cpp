// BEGIN CUT HERE
/*
SRM 787 Div2 Medium (500)

PROBLEM STATEMENT

Aqa Asadi is forming a Ninja INOI team from his students.
You are given the power of each student in the vector <int> A.
It is known that the power of a team is equal to the greatest common divisor (GCD) of the team members' powers.

A student is unhappy if they are not on the team but they feel that they are good enough to be selected for the team.
To prevent unhappy students, the power of the Ninja team must be strictly bigger than the power of each individual student who is not included in the team.

The Ninja team cannot be empty and it cannot contain all the students.

Compute and return the size of the largest valid Ninja team. If there is no suitable Ninja team, return -1 instead.


DEFINITION
Class:AqaAsadiPlays
Method:getMin
Parameters:vector <int>
Returns:int
Method signature:int getMin(vector <int> A)


CONSTRAINTS
-The length of A will be between 1 and 100, inclusive.
-Elements of A will be between 1 and 1000000000 (10^9), inclusive.


EXAMPLES

0)
{6, 1, 4}

Returns: 2

Aqa Asadi can select the first and the last student. The power of the team will be GCD(6,4) = 2. The power of the student who was not selected is 1, which is strictly less than the power of the team.
(Selecting only the first student would also be valid, but remember that we are looking for the largest possible team.)


1)
{4, 4, 1, 3, 2}

Returns: 2

The only valid solution is a team with power 4 consisting of the first two students. 


2)
{2, 8, 3, 12, 16}

Returns: 3


3)
{47, 47}

Returns: -1

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
#include <cstring>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

class AqaAsadiPlays {
public:
	int getMin(vector <int> A) {
		int ans = -1;
		for (int i = 0; i < A.size(); ++i) {
			for (int j = i; j < A.size(); ++j) {
				int g = gcd(A[i], A[j]);
				int c = 0, not_selected = 0;
				for (int k = 0; k < A.size(); ++k) {
					if (gcd(g, A[k]) == g) {
						++c;
					} else {
						not_selected += g > A[k];
					}
				}
				if (c < A.size() && (c + not_selected == A.size())) {
					ans = max(ans, c);
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
			int Arr0[] = {6, 1, 4};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 4, 1, 3, 2};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 8, 3, 12, 16};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {47, 47};
			int Arg1 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912 };
			int Arg1 = 29;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AqaAsadiPlays ___test;
	___test.run_test(-1);
}
// END CUT HERE
