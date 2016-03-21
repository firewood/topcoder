// BEGIN CUT HERE
/*
SRM 685 Div1 Easy (250)

PROBLEM STATEMENT
Fox Ciel is creating a new binary operation.

The operation will be denoted $ and it will be defined on the finite set S = {0, 1, 2, ..., n-1}.
I.e., for each ordered pair (i, j) of elements of S the operation (i $ j) will return some element of S.

For example, we can have S = {0, 1}, and we can define that (0 $ 0) = 0, (0 $ 1) = 1, (1 $ 0) = 0, and (1 $ 1) = 0.

Note that Ciel's operation is not necessarily symmetric.
In other words, it is possible that for some i and j the operations (i $ j) and (j $ i) return two different values.

A nice concise description of the operation $ is its "multiplication table": a square table where in row i and column j we have the value (i $ j).
You are given this "multiplication table" encoded as a vector <int> table with n^2 elements.
For each valid i and j the operation (i $ j) returns the value table[i*n+j].

A subset T of S is called good if it has the following property:
for any two elements i and j in T, (i $ j) is also in T.

Find and return the minimal size of a good subset of S.
Note that the answer is always defined, as there always are some good subsets.
For example, the entire set S is always good.

DEFINITION
Class:MultiplicationTable2
Method:minimalGoodSet
Parameters:vector <int>
Returns:int
Method signature:int minimalGoodSet(vector <int> table)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-table will contain exactly n*n elements.
-Each element in table will be between 0 and n-1, inclusive.


EXAMPLES

0)
{1,1,2,3,
 1,0,3,2,
 2,0,1,3,
 1,2,3,0}

Returns: 2

The smallest Good set is {0,1}, we can verify:

0 $ 0 = 1
0 $ 1 = 1
1 $ 0 = 1
1 $ 1 = 0


1)
{0,1,2,3,
 1,2,3,0,
 2,3,0,1,
 3,0,1,2}

Returns: 1

This time the answer is 1 since {0} is a Good set.


2)
{1,1,1,1,
 2,2,2,2,
 3,3,3,3,
 0,0,0,0}

Returns: 4

Now the only Good set is {0,1,2,3}.


3)
{0}

Returns: 1

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class MultiplicationTable2 {

public:
	int minimalGoodSet(vector <int> table) {
		int N = (int)sqrt(table.size() + 0.1);
		int ans = N;
		for (int i = 0; i < N; ++i) {
			set<int> s, m;
			m.insert(i);
			m.insert(table[N * i + i]);
			while (m.size()) {
				for (int a : m) {
					s.insert(a);
				}
				m.clear();
				for (int a : s) {
					for (int b : s) {
						if (s.find(table[N * a + b]) == s.end()) {
							m.insert(table[N * a + b]);
						}
					}
				}
			}
			ans = min(ans, (int)s.size());
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
			int Arr0[] = {1,1,2,3,
 1,0,3,2,
 2,0,1,3,
 1,2,3,0};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalGoodSet(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,2,3,
 1,2,3,0,
 2,3,0,1,
 3,0,1,2};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalGoodSet(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,
 2,2,2,2,
 3,3,3,3,
 0,0,0,0};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalGoodSet(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimalGoodSet(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MultiplicationTable2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
