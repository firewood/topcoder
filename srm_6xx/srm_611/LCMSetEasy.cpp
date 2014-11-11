// BEGIN CUT HERE
/*
SRM 611 Div2 Medium (500)

PROBLEM STATEMENT
For any non-empty sequence of positive integers s1, s2, ..., sK their least common multiple is the smallest positive integer that is divisible by each of the given numbers.
We will use "lcm" to denote the least common multiple.
For example, lcm(3) = 3, lcm(4,6) = 12, and lcm(2,5,7) = 70.

You are given a vector <int> S and an int x.
Find out whether we can select some elements from S in such a way that their least common multiple will be precisely x.
Formally, we are looking for some s1, s2, ..., sK, K >= 1, such that each si belongs to S, and x=lcm(s1, s2, ..., sK).
Return "Possible" if such elements of S exist, and "Impossible" if they don't.


DEFINITION
Class:LCMSetEasy
Method:include
Parameters:vector <int>, int
Returns:string
Method signature:string include(vector <int> S, int x)


CONSTRAINTS
-S will contain between 1 and 50 elements, inclusive.
-Each element in S will be between 1 and 1,000,000,000, inclusive.
-Elements in S will be distinct.
-x will be between 2 and 1,000,000,000, inclusive.


EXAMPLES

0)
{2,3,4,5}
20

Returns: "Possible"

We can obtain 20 in multiple ways. One of them: 20 = lcm(4, 5).


1)
{2,3,4}
611

Returns: "Impossible"

If S={2,3,4}, the only values we can obtain are 2, 3, 4, 6, and 12.


2)
{2,3,4}
12

Returns: "Possible"


3)
{1,2,3,4,5,6,7,8,9,10}
24

Returns: "Possible"


4)
{100,200,300,400,500,600}
2000

Returns: "Possible"


5)
{100,200,300,400,500,600}
8000

Returns: "Impossible"


6)
{1000000000,999999999,999999998}
999999999

Returns: "Possible"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

class LCMSetEasy {

	bool check(vector <int> S, LL x) {
		LL a = 1;
		for (LL b : S) {
			if ((x % b) == 0) {
				a = lcm(a, b);
			}
		}
		return a == x;
	}

public:
	string include(vector <int> S, int x) {
		return check(S, x) ? "Possible" : "Impossible";
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
			int Arr0[] = {2,3,4,5};
			int Arg1 = 20;
			string Arg2 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, include(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,3,4};
			int Arg1 = 611;
			string Arg2 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, include(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,3,4};
			int Arg1 = 12;
			string Arg2 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, include(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6,7,8,9,10};
			int Arg1 = 24;
			string Arg2 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, include(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100,200,300,400,500,600};
			int Arg1 = 2000;
			string Arg2 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, include(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100,200,300,400,500,600};
			int Arg1 = 8000;
			string Arg2 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, include(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000000,999999999,999999998};
			int Arg1 = 999999999;
			string Arg2 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, include(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LCMSetEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
