// BEGIN CUT HERE
/*
TCO18 R1A Hard (1000)

PROBLEM STATEMENT
Deadfish+ is a programming language with only 4 commands. All commands modify a single register. The register is initially set to zero, and during the execution of a program it can store an arbitrarily large integer value. The commands are:

"i" - increment the value,

"d" - decrement the value,

"s" - square the value, and

"p" - sort the digits of the number into non-increasing order (i.e., biggest to smallest).

For example, "p" changes 4070 to 7400, and it changes -4070 to -7400 (the minus sign is preserved).

You are given an int N. Return the minimal number of commands necessary to make the register hold the number N.


DEFINITION
Class:Deadfish
Method:shortestCode
Parameters:int
Returns:int
Method signature:int shortestCode(int N)


CONSTRAINTS
-N will be between 1 and 200,000, inclusive.


EXAMPLES

0)
3

Returns: 3

The fastest way to get to 3 is "iii" - three increments.


1)
5

Returns: 4

One fastest way to get a 5 is "iisi": two increments to get a 2, square to get a 4 and one more increment.
Another optimal way is "ddsi": two decrements change the register to -2, squaring that gives 4, and the final increment changes it to 5.


2)
15

Returns: 5

The fastest way to get 15 is "iissd". The value in the register will change as follows: 0, 1, 2, 4, 16, 15.


3)
61

Returns: 5

The fastest way to get 61 is "iissp". The value in the register will change as follows: 0, 1, 2, 4, 16, 61.


4)
200000

Returns: 207

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

static const int MAX = 400000;

class Deadfish {

	int memo[MAX + 4];

	void init() {
		fill(memo, memo + MAX + 4, -1);
		memo[0] = 0;
		vector<LL> q;
		q.push_back(0);
		for (int c = 1; q.size() > 0; ++c) {
			vector<LL> nx;
			for (LL v : q) {
				LL a = v + 1;
				if (a > 0 && a <= MAX && memo[a] < 0) {
					memo[a] = c;
					nx.push_back(a);
				}
				a = v - 1;
				if (a > 0 && a <= MAX && memo[a] < 0) {
					memo[a] = c;
					nx.push_back(a);
				}
				a = v * v;
				if (a > 0 && a <= MAX && memo[a] < 0) {
					memo[a] = c;
					nx.push_back(a);
				}
				string s = to_string(v);
				sort(s.rbegin(), s.rend());
				a = stoll(s);
				if (a > 0 && a <= MAX && memo[a] < 0) {
					memo[a] = c;
					nx.push_back(a);
				}
			}
			q = nx;
		}
	}

public:
	int shortestCode(int N) {
		if (memo[1] != 1) {
			init();
		}
		return memo[N];
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
			int Arg0 = 3;
			int Arg1 = 3;

			verify_case(n, Arg1, shortestCode(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 4;

			verify_case(n, Arg1, shortestCode(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15;
			int Arg1 = 5;

			verify_case(n, Arg1, shortestCode(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 61;
			int Arg1 = 5;

			verify_case(n, Arg1, shortestCode(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 200000;
			int Arg1 = 207;

			verify_case(n, Arg1, shortestCode(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Deadfish ___test;
	___test.run_test(-1);
}
// END CUT HERE
