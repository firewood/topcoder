// BEGIN CUT HERE
/*
SRM 611 Div1 Easy (250)

PROBLEM STATEMENT
For any non-empty sequence of positive integers s1, s2, ..., sK their least common multiple is the smallest positive integer that is divisible by each of the given numbers.
We will use "lcm" to denote the least common multiple.
For example, lcm(3) = 3, lcm(4,6) = 12, and lcm(2,5,7) = 70.


Given a sequence S, we now define the set LCM(S) as follows:
LCM(S) = { lcm(s1, s2, ..., sk) | s1, s2, ..., sk belong to S, k > 0}.
In words: LCM(S) is the set of all values that can be obtained by selecting some elements of S and computing their least common multiple.
For example, for S={2,3,4} we have LCM(S)={2,3,4,6,12}.


You are given two vector <int>s A and B.
Return "Equal" if LCM(A) = LCM(B), and "Not equal" otherwise.

DEFINITION
Class:LCMSet
Method:equal
Parameters:vector <int>, vector <int>
Returns:string
Method signature:string equal(vector <int> A, vector <int> B)


CONSTRAINTS
-A will contain between 1 and 50 elements, inclusive.
-B will contain between 1 and 50 elements, inclusive.
-Each element in A will be between 2 and 1,000,000,000, inclusive.
-Each element in B will be between 2 and 1,000,000,000, inclusive.
-Elements in A will be distinct.
-Elements in B will be distinct.


EXAMPLES

0)
{2,3,4,12}
{2,3,4,6}

Returns: "Equal"

LCM(A) = LCM(B) = {2,3,4,6,12}


1)
{4,9}
{6,36}

Returns: "Not equal"

LCM(A) = {4,9,36}, LCM(B) = {6,36}


2)
{2,3,5,7,14,105}
{2,3,5,6,7,30,35}

Returns: "Equal"


3)
{2,3,5,7,14,105}
{2,3,5,6,7,30,36}

Returns: "Not equal"


4)
{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}
{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}

Returns: "Equal"

Note that some of the numbers in the sets LCM(A) and LCM(B) can be huge.
In this case, the largest number in LCM(A) is 2305567963945518424753102147331756070.


5)
{999999999,1953125,512,1000000000}
{999999999,1953125,512}

Returns: "Equal"


6)
{999999998,999999999,1000000000}
{999999999,1000000000}

Returns: "Not equal"

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

class LCMSet {

	bool check(int a, const IntVec &v) {
		int x = 1;
		for (int y : v){
			if ((a % y) == 0) {
				x = lcm(x, y);
			}
		}
		return a == x;
	}

public:
	string equal(vector <int> A, vector <int> B) {
		for (int a : A) {
			if (!check(a, B)) {
				return "Not equal";
			}
		}
		for (int b : B) {
			if (!check(b, A)) {
				return "Not equal";
			}
		}
		return "Equal";
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
			int Arr0[] = {2,3,4,12};
			int Arr1[] = {2,3,4,6};
			string Arg2 = "Equal";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, equal(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,9};
			int Arr1[] = {6,36};
			string Arg2 = "Not equal";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, equal(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,3,5,7,14,105};
			int Arr1[] = {2,3,5,6,7,30,35};
			string Arg2 = "Equal";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, equal(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,3,5,7,14,105};
			int Arr1[] = {2,3,5,6,7,30,36};
			string Arg2 = "Not equal";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, equal(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
			int Arr1[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
			string Arg2 = "Equal";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, equal(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {999999999,1953125,512,1000000000};
			int Arr1[] = {999999999,1953125,512};
			string Arg2 = "Equal";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, equal(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {999999998,999999999,1000000000};
			int Arr1[] = {999999999,1000000000};
			string Arg2 = "Not equal";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, equal(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LCMSet ___test;
	___test.run_test(-1);
}
// END CUT HERE
