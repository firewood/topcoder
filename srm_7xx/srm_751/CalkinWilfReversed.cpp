// BEGIN CUT HERE
/*
SRM 751 Div2 Medium (500)

PROBLEM STATEMENT

The Calkin-Wilf tree is a rooted tree that contains each positive rational number exactly once.
The definition of the tree is really simple: 

The root of the tree contains the value 1/1.
Each node in the tree has one left child and one right child.
If a node contains the fraction a/b, its left child contains the fraction a/(a+b) and its right child contains the fraction (a+b)/b.

Here is an ASCII art drawing of the first few levels of the tree:


                ____________1/1____________
               /                           \
        ____1/2____                     ____2/1____
       /           \                   /           \
    1/3             3/2             2/3             3/1
   /   \           /   \           /   \           /   \
1/4     4/3     3/5     5/2     2/5     5/3     3/4     4/1


The depth of the root is 0. If a node has depth n, its children have depth n+1.


You are given the long longs a and b.
Compute and return the depth of the node that contains the fraction a/b.


DEFINITION
Class:CalkinWilfReversed
Method:getDepth
Parameters:long long, long long
Returns:long long
Method signature:long long getDepth(long long a, long long b)


CONSTRAINTS
-a will be between 1 and 10^18, inclusive.
-b will be between 1 and 10^18, inclusive.
-a and b will be relatively prime. (I.e., their greatest common divisor will be 1.)


EXAMPLES

0)
1
1

Returns: 0

The fraction 1/1 appears in the root of the tree, and by definition the depth of the root is 0.


1)
4
3

Returns: 3

The fraction 4/3 can be found in the bottom level of the figure shown in the problem statement. The depth of its node is 3.


2)
1
1234567890123

Returns: 1234567890122

The fraction 1/1234567890123 is in the leftmost branch of the tree, and its node is quite deep.


3)
1234567
7654321

Returns: 8837

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

class CalkinWilfReversed {
public:
	long long getDepth(long long a, long long b) {
		long long ans = 0;
		while (a > 1 && b > 1) {
			if (a > b) {
				swap(a, b);
			}
			LL c = b / a;
			ans += c;
			b -= a * c;
		}
		ans += a + b - 2;
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 1LL;
			long long Arg2 = 0LL;

			verify_case(n, Arg2, getDepth(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 4LL;
			long long Arg1 = 3LL;
			long long Arg2 = 3LL;

			verify_case(n, Arg2, getDepth(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 1234567890123LL;
			long long Arg2 = 1234567890122LL;

			verify_case(n, Arg2, getDepth(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1234567LL;
			long long Arg1 = 7654321LL;
			long long Arg2 = 8837LL;

			verify_case(n, Arg2, getDepth(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			long long Arg0 = 899;
			long long Arg1 = 270361549640470092LL;
			long long Arg2 = 300735872792668LL;

			verify_case(n, Arg2, getDepth(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CalkinWilfReversed ___test;
	___test.run_test(-1);
}
// END CUT HERE
