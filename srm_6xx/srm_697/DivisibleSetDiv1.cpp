// BEGIN CUT HERE
/*
SRM 697 Div1 Easy (300)

PROBLEM STATEMENT
You are given a vector <int> b containing a sequence of n positive integers: b[0], ..., b[n-1].
We are now looking for another sequence a = {a[0], ..., a[n-1]}.
This sequence should have the following properties:

The elements of the sequence a should be distinct.
Each a[i] should be an integer greater than 1.
For each i, the value a[i]^b[i] (that is, a[i] to the power b[i]) should be divisible by p[i], where p[i] is the product of all other elements of a. (I.e. p[i] = a[0]*a[1]*...*a[i-1]*a[i+1]*...*a[n-1].)


Determine whether there is at least one sequence with the desired properties.
Return "Possible" (quotes for clarity) if such a sequence exists and "Impossible" otherwise.

DEFINITION
Class:DivisibleSetDiv1
Method:isPossible
Parameters:vector <int>
Returns:string
Method signature:string isPossible(vector <int> b)


CONSTRAINTS
-b will contain between 2 and 50 elements, inclusive.  
-Each element in b will be between 1 and 10, inclusive.  


EXAMPLES

0)
{2,1}

Returns: "Possible"

Here, we have the following requirements:

The values a[0] and a[1] should be distinct positive integers, both greater than 1.
The value a[0]^2 should be divisible by a[1].
The value a[1]^1 should be divisible by a[0].

One sequence with the above properties is the sequence a = {2, 4}.


1)
{1,1}

Returns: "Impossible"

In this test case the requirements imply that a[0] must be divisible by a[1] and vice versa.
This is possible only if a[0] = a[1].
However, the elements of a must be distinct, so there is no valid sequence.


2)
{7, 7, 7}

Returns: "Possible"

For example, a = {12, 54, 18}.


3)
{5,3,5,4,6,1,3,7,9,6,2,5,4,1,1,9,6,10,10,6,10,7,7,8}

Returns: "Impossible"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef vector<int> IntVec;

class DivisibleSetDiv1 {
	bool possible(IntVec v) {
		int N = v.size();
		if (N > 10) {
			return false;
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		for (int t = 0; t < 10000; ++t) {
			int x[16], sum = 0;
			x[0] = (rand() % 10) + 1, sum = x[0];
			for (int i = 1; i < N; ++i) {
				x[i] = x[0] + (rand() % 3) + 1;
				sum += x[i];
			}
			bool f = true;
			for (int i = 0; i < N; ++i) {
				if (x[i] * v[i] < (sum - x[i])) {
					f = false;
					break;
				}
			}
			if (f) {
				return true;
			}
		}
		return false;
	}

public:
	string isPossible(vector <int> b) {
		return possible(b) ? "Possible" : "Impossible";
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
			int Arr0[] = {2,1};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1};
			string Arg1 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7, 7, 7};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,3,5,4,6,1,3,7,9,6,2,5,4,1,1,9,6,10,10,6,10,7,7,8};
			string Arg1 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 2,2,3 };
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 2,3,4,5 };
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 3,1,3 };
			string Arg1 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 1,2,5 };
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DivisibleSetDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
