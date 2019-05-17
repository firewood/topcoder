// BEGIN CUT HERE
/*
SRM 758 Div1 Easy (300)

PROBLEM STATEMENT

The number 31143310 is self-describing because we can read it as the statement "this number contains three '1's, one '4's, three '3's, and one '0'", and that statement correctly describes the whole number.

More formally, a number is called self-describing if it satisfies the following:

It has an even number of digits. Below, we will label the individual digits a[0], b[0], a[1], b[1], ... from the left to the right.
The digits b[i] are all distinct.
For each valid i, the number contains exactly a[i] copies of the digit b[i].
The number does not contain any other digits, except for those described by the statements mentioned above.

You are given the vector <int> digits.
Find the smallest self-describing number N such that the digits that appear in N are precisely the digits in digits.
If such a number exists, return a string with its decimal representation.
Otherwise, return an empty string


DEFINITION
Class:SelfDescFind
Method:construct
Parameters:vector <int>
Returns:string
Method signature:string construct(vector <int> digits)


NOTES
-Watch out for integer overflow.


CONSTRAINTS
-digits will contain between 1 and 10 elements, inclusive.
-Each element of digits will be between 0 and 9, inclusive.
-The elements of digits will form a strictly increasing sequence.


EXAMPLES

0)
{1}

Returns: ""


1)
{2}

Returns: "22"

The smallest self-describing number is 22. It contains two '2's, and it says about itself that it contains two '2's.


2)
{0,1,3,4}

Returns: "10143133"


3)
{0,1,2,4,5,6,8,9}

Returns: ""


4)
{0,1,2,3,5,6,8,9}

Returns: "1016181923253251"


5)
{4}

Returns: ""

Note that 4444 is not a valid self-describing number.

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class SelfDescFind {
public:
	string construct(vector <int> digits) {
		int mx[10] = { 1,9,9,7,6,6,5,3,2,2 };
		vector<int> rc(10);
		vector<int> u(10);
		int ld = 0, i;
		for (int d : digits) {
			u[d] = 1;
			rc[d] = 1;
			ld = max(ld, d);
		}
		string ans;
		do {
			vector<int> chk = u;
			for (int d : rc) {
				chk[d] += 1;
			}
			for (i = 1; i < 10; ++i) {
				if (chk[i] != rc[i])break;
			}
			if (i >= 10) {
				string s;
				set<string> t;
				for (i = 0; i < 10; ++i) {
					if (u[i]) {
						t.insert(to_string(rc[i]) + to_string(i));
					}
				}
				for (string x : t) {
					s += x;
				}
				if (ans.empty() || s < ans) {
					ans = s;
				}
			}
			for (i = 0; i <= ld; ++i) {
				if (!u[i])continue;
				rc[i] += 1;
				if (rc[i] <= mx[i]) {
					break;
				}
				rc[i] = 1;
			}
		} while (i <= ld);
		return ans;
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
			int Arr0[] = {1};
			string Arg1 = "";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2};
			string Arg1 = "22";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,3,4};
			string Arg1 = "10143133";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,2,4,5,6,8,9};
			string Arg1 = "";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,2,3,5,6,8,9};
			string Arg1 = "1016181923253251";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4};
			string Arg1 = "";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 0 };
			string Arg1 = "";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 1,2,3,4 };
			string Arg1 = "12143133";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SelfDescFind ___test;
	___test.run_test(-1);
}
// END CUT HERE
