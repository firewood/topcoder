// BEGIN CUT HERE
/*
SRM 653 Div1 Easy (250)

PROBLEM STATEMENT

Some people are sitting in a row.
Each person came here from some country.
People from the same country are all sitting together.

A reporter has already approached some of the people and asked each of them the same question:
"How many people from your country (including you) are here?"
All the people who were asked the question gave her correct answers.

You are given a vector <int> a.
The elements of a correspond to the people in the row, in order.
For each i, element i of a is either 0 if the corresponding person was not asked the question, or a positive integer: the answer given by that person.

The reporter just realized that she might be able to reconstruct all the missing answers from the answers she already knows.
Return "Sufficient" if she can do that, or "Insufficient" if she cannot.


DEFINITION
Class:CountryGroupHard
Method:solve
Parameters:vector <int>
Returns:string
Method signature:string solve(vector <int> a)


CONSTRAINTS
-The number of elements in a will be between 1 and 100, inclusive.
-All numbers of a will be between 0 and 100, inclusive.
-There exist valid country assignment of people for input.


EXAMPLES

0)
{0,2,3,0,0}

Returns: "Sufficient"

The first two people must be from the same country. The last three people must also be from the same country. Thus, the only possible sequence of answers is {2,2,3,3,3}.


1)
{0,2,0}

Returns: "Insufficient"

There are still two different sequences of answers that are consistent with the reporter's information: the answers can be either {1,2,2} or {2,2,1}.


2)
{0,3,0,0,3,0}

Returns: "Sufficient"


3)
{0,0,3,3,0,0}

Returns: "Insufficient"


4)
{2,2,0,2,2}

Returns: "Sufficient"

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

class CountryGroupHard {

	int N;
	vector<int> x;
	int memo[256];

	int check(int pos) {
		int &r = memo[pos];
		if (r >= 0) {
			return r;
		}
		if (pos >= N) {
			return r = 1;
		}
		int i, j, k;
		for (i = pos; i < N; ++i) {
			if (x[i]) {
				break;
			}
		}
		if (i >= N) {
			return r = N - pos;
		}
		int cnt = 0;
		for (j = max(pos, i - x[i] + 1); j <= i; ++j) {
			int c = 0;
			for (k = j; k < (j + x[i]) && k < N; ++k) {
				c += (x[k] == 0 || x[k] == x[i]);
			}
			if (c == x[i]) {
				int t = check(j + x[i]);
				cnt += t;
				if (t > 0 && j >= (pos + 2)) {
					return 2;
				}
			}
		}
		return r = cnt;
	}

public:
	string solve(vector <int> a) {
		memset(memo, -1, sizeof(memo));
		N = (int)a.size();
		x = a;
		return check(0) == 1 ? "Sufficient" : "Insufficient";
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
			int Arr0[] = {0,2,3,0,0};
			string Arg1 = "Sufficient";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,2,0};
			string Arg1 = "Insufficient";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,3,0,0,3,0};
			string Arg1 = "Sufficient";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,3,3,0,0};
			string Arg1 = "Insufficient";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,0,2,2};
			string Arg1 = "Sufficient";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CountryGroupHard ___test;
	___test.run_test(-1);
}
// END CUT HERE
