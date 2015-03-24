// BEGIN CUT HERE
/*
SRM 653 Div2 Easy (250)

PROBLEM STATEMENT

Some people are sitting in a row.
Each person came here from some country.
You have a theory that people from the same country are all sitting together.
You decided to test this theory.
You asked each person the same question: "How many people from your country (including you) are here?"

You are given a vector <int> a containing their answers.
The answers are given in the order in which the people sit in the row.
(Note that some of the answers may be incorrect.
See the examples for clarification.)

If all the answers are consistent with your theory, return the number of different countries that are present.
(Given that all answers are consistent with the theory, the number of countries can always be uniquely determined.)
Otherwise, return -1.


DEFINITION
Class:CountryGroup
Method:solve
Parameters:vector <int>
Returns:int
Method signature:int solve(vector <int> a)


CONSTRAINTS
-The number of elements in a will be between 1 and 100, inclusive.
-All elements of a will be between 1 and 100, inclusive.


EXAMPLES

0)
{2,2,3,3,3}

Returns: 2

These answers are consistent with your theory. The first two people are from one country, the other three are from a different country. Thus, there are two countries and the correct return value is 2.


1)
{1,1,1,1,1}

Returns: 5

Here, each person comes from a different country.


2)
{3,3}

Returns: -1

These answers do not correspond to your theory. In particular, they are not even correct: there are only two people but each of them claims that there are three people from their country.


3)
{4,4,4,4,1,1,2,2,3,3,3}

Returns: 5


4)
{2,1,2,2,1,2}

Returns: -1

These answers do not correspond to your theory. It is possible that these are people from four different countries, but even if that were the case, we can tell that people from some countries are not sitting together. For example, consider the leftmost person. According to her answer, there are two people from her country. However, the person sitting next to her cannot be from the same country.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class CountryGroup {
public:
	int solve(vector <int> a) {
		int ans = 0;
		int x = 0, cnt = 0;
		for (int c : a) {
			if (!x) {
				x = c;
				cnt = 1;
			} else if (x != c) {
				return -1;
			} else {
				++cnt;
			}
			if (cnt == x) {
				++ans;
				x = 0;
				cnt = 0;
			}
		}
		if (x) {
			return -1;
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
			int Arr0[] = {2,2,3,3,3};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,3};
			int Arg1 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,4,4,4,1,1,2,2,3,3,3};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,1,2,2,1,2};
			int Arg1 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CountryGroup ___test;
	___test.run_test(-1);
}
// END CUT HERE
