// BEGIN CUT HERE
/*

TCO 2016 Round 2A Easy (400)

Problem Statement

You are given the int[] x: a list containing n integers.
Each element of x is a positive integer of the form 2^a * 3^b, where a and b are some nonnegative integers.
The elements of x are not necessarily distinct.

You are going to perform n-1 operations. Each operation will consist of the following steps:

Choose two distinct indices into your list. Let X and Y be the numbers at those indices.
Remove both of them from the list. (Note that X and Y are allowed to have the same value.)
Compute one of two possible values: either the greatest common divisor (gcd) of X and Y,
or the least common multiple (lcm) of X and Y.
Append the computed value to your list.
Obviously, after n-1 operations you will be left with a single integer.
In addition to x you are given the int t.
You would like to know whether it is possible to perform the sequence of operations on x
in such a way that the final integer will be t.
If it is possible, return "Possible", otherwise return "Impossible".


Definition

Class:	LCMGCD
Method:	isPossible
Parameters:	int[], int
Returns:	String
Method signature:	String isPossible(int[] x, int t)
(be sure your method is public)


Constraints
-	x will contain between 1 and 50 elements, inclusive.
-	Each element of x will be between 1 and 10^9, inclusive.
-	t will be between 1 and 10^9, inclusive.
-	t and each element of x will be of the form 2^i*3^j for some nonnegative i,j.

Examples
0)

{2,3}
6
Returns: "Possible"
We can take the lcm to reach the goal.


1)

{4,9}
6
Returns: "Impossible"
We have lcm(4,9) = 36 and gcd(4,9) = 1. It's impossible to get 6.


2)

{6,12,24,18,36,72,54,108,216}
36
Returns: "Possible"


3)

{6,27,81,729}
6
Returns: "Impossible"


4)

{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
1
Returns: "Possible"


5)

{72,16,16,16,16,16,27,27,27,27,27,27,27,27,27}
72
Returns: "Possible"


6)

{100663296, 544195584, 229582512, 59049}
60466176
Returns: "Possible"
Watch out for integer overflow. The intermediate results won't always fit into a 32-bit integer variable.


7)

{2,4,8,16,32,64}
256
Returns: "Impossible"

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;
typedef vector<LL> LLVec;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

class LCMGCD {
public:
	string isPossible(vector <int> x, int t) {
		LL tt = t;
		bool ans = false;
		LLVec xx(x.begin(), x.end());
		for (int i = 0; !ans && i < 100000; ++i) {
			random_shuffle(xx.begin(), xx.end());
			ans = possible(xx, tt);
		}
		return ans ? "Possible" : "Impossible";
	}

	bool possible(LLVec x, LL t) {
		for (size_t i = x.size(); i > 1; --i) {
			if (rand() % 2) {
				x[i - 2] = gcd(x[i - 2], x[i - 1]);
			} else {
				x[i - 2] = lcm(x[i - 2], x[i - 1]);
			}
			swap(x[i - 2], x[rand() % (i - 1)]);
		}
		return x[0] == t;
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
			int Arr0[] = { 2,3 };
			int Arg1 = 6;
			string Arg2 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 4,9 };
			int Arg1 = 6;
			string Arg2 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 36, 54, 216 };
			int Arg1 = 36;
			string Arg2 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 2187, 54, 18, 2187, 54, 59049, 2, 729, 19683, 6, 18, 729, 2, 59049, 2, 6, 2, 177147, 54, 6561, 18, 2, 2187, 6561, 18, 2, 729, 19683, 177147, 729, 54, 54, 54, 6, 19683, 2187, 729, 6561, 54, 2, 243, 2187, 2, 177147, 54, 54, 59049, 2187, 59049, 6 };
			int Arg1 = 162;
			string Arg2 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LCMGCD ___test;
	___test.run_test(-1);
}
// END CUT HERE
