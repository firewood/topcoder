// BEGIN CUT HERE
/*
SRM 746 Div2 Easy (250)

PROBLEM STATEMENT

Some kids were playing in the yard. You noticed the following:

When they formed groups of two, r2 kids were left without a group.
When they formed groups of three, r3 kids were left without a group.
When they formed groups of five, r5 kids were left without a group.

Find and return the smallest (positive) number of kids that could have played in the yard.


DEFINITION
Class:KidsInAYard
Method:howMany
Parameters:int, int, int
Returns:int
Method signature:int howMany(int r2, int r3, int r5)


NOTES
-A solution always exists.


CONSTRAINTS
-r2 will be between 0 and 1, inclusive.
-r3 will be between 0 and 2, inclusive.
-r5 will be between 0 and 4, inclusive.


EXAMPLES

0)
1
1
1

Returns: 1

There was a single kid. Regardless of the group size, no groups were formed and the kid was the one left over.


1)
1
0
4

Returns: 9

Nine kids can form three groups of three. If they form pairs, one kid will be left over. Finally, they can form one group of five and have four kids left over. 

We can easily verify that nine kids is the smallest solution in this case. (There are other solutions, for example, 519 kids, but you have to return the smallest solution.)


2)
0
0
0

Returns: 30

Note that the number of kids must be positive.

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

typedef long long LL;

// BEGIN CUT HERE
/*
typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<II> IIVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;
typedef set<II> IISet;
typedef set<string> StrSet;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
#define MOD 1000000007LL
#define MOD 1000000009LL
*/
// END CUT HERE

class KidsInAYard {
public:
	int howMany(int r2, int r3, int r5) {
		int ans;
		for (ans = 1; ; ++ans) {
			if (ans % 2 == r2 && ans % 3 == r3 && ans % 5 == r5) {
				break;
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
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 1;

			verify_case(n, Arg3, howMany(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 0;
			int Arg2 = 4;
			int Arg3 = 9;

			verify_case(n, Arg3, howMany(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 30;

			verify_case(n, Arg3, howMany(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	KidsInAYard ___test;
	___test.run_test(-1);
}
// END CUT HERE
