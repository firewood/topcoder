// BEGIN CUT HERE
/*
SRM 796 Div1 Easy (250)

PROBLEM STATEMENT

Peter is very fond of his niece Emily.
For Christmas, Peter wants to give his niece a collection of various toys.
He has already purchased N toys.
However, at the last moment Peter realized that he probably cannot give Emily all the toys.

The problem is that many of the toys require batteries, and those are not included in the package.
Peter forgot to purchase batteries and now he could only find very few of them: he only has B batteries.
And there's nothing worse than getting a toy that does not work because it lacks batteries.
(Well, there are surely plenty of worse things, but not in Emily's world.)

Hence, Peter came to the following conclusion: he will only give Emily a subset of the toys he has purchased.
The toys given to Emily must require at most B batteries in total.

The toys are numbered from 0 to N-1, inclusive.
Toy i requires (i mod 5) batteries.
The amount of fun from toy i is ((X*i*i + Y*i + Z) mod M).

The amount of fun from a collection of toys is simply the sum of amounts of fun from the individual toys in the collection.
Find the collection of toys Peter should give Emily if he wants her to have as much fun as possible with the toys.
Return the total amount of fun for that collection.


DEFINITION
Class:ChristmasBatteries
Method:mostFun
Parameters:int, int, int, int, int, int
Returns:int
Method signature:int mostFun(int B, int N, int X, int Y, int Z, int M)


NOTES
-Watch out for integer overflow when computing the amount of fun from a toy. In particular, we suggest computing the value X*i*i mod M as follows: (((X*i) mod M) * i) mod M.
-The reference solution does not depend on the properties of the formula used to compute the fun from a toy. The reference solution would find the correct subset for any values of fun from toys.


CONSTRAINTS
-B will be between 0 and 7, inclusive.
-N will be between 1 and 10^6, inclusive.
-X, Y, Z will be between 0 and 999, inclusive.
-M will be between 1 and 1000, inclusive.


EXAMPLES

0)
0
5
1
1
1
1000

Returns: 1

There are five toys. Peter has no batteries at all, so he can only give Emily toy 0 that requires no batteries at all. The fun from this toy is (1*0*0 + 1*0 + 1) mod 1000 = 1.


1)
3
5
1
1
1
1000

Returns: 14


The same scenario as above, but now Peter has three batteries.

Let's look at all the available toys:

toy 0: requires 0 batteries, fun = 1
toy 1: requires 1 battery, fun = 3
toy 2: requires 2 batteries, fun = 7
toy 3: requires 3 batteries, fun = 13
toy 4: requires 4 batteries, fun = 21

Peter has multiple options what to give Emily.
For example, he could give her toys 0, 1, and 2.
However, we can easily verify that the best present are toys 0 and 3.
These require a total of 3 batteries, and the total fun from them is 1 + 13 = 14.


2)
3
5
1
1
1
13

Returns: 11

The same scenario as Example 1, but now the fun from toy 3 is zero and fun from toy 4 is only 8. Here the optimal solution is to give Emily toys 0, 1, and 2.


3)
4
10000
123
456
789
1

Returns: 0

The fun from each toy is 0, so Peter's choice of presents does not matter at all. He can simply give Emily nothing.


4)
7
4
3
5
7
997

Returns: 100

Peter has 7 batteries, his entire collection of toys only requires 6. Thus, he can give Emily all the toys.


5)
2
12345
234
34
5
117

Returns: 143371

Watch out for integer overflow. For example, the fun from the very last toy in Peter's collection (toy 12344) is (234 * 12344 * 12344 + 34 * 12344 + 5) mod 117 = 22.

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

class ChristmasBatteries {
public:
	int mostFun(int B, int N, int X, int Y, int Z, int M) {
		vector<LL> dp(B + 1);
		for (LL i = 0; i < N; ++i) {
			LL cost = i % 5;
			LL fun = (X * i * i + Y * i + Z) % M;
			vector<LL> next = dp;
			for (LL j = 0; j + cost <= B; ++j) {
				next[j + cost] = max(next[j + cost], dp[j] + fun);
			}
			dp = next;
		}
		return *max_element(dp.begin(), dp.end());
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
			int Arg0 = 0;
			int Arg1 = 5;
			int Arg2 = 1;
			int Arg3 = 1;
			int Arg4 = 1;
			int Arg5 = 1000;
			int Arg6 = 1;

			verify_case(n, Arg6, mostFun(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 5;
			int Arg2 = 1;
			int Arg3 = 1;
			int Arg4 = 1;
			int Arg5 = 1000;
			int Arg6 = 14;

			verify_case(n, Arg6, mostFun(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 5;
			int Arg2 = 1;
			int Arg3 = 1;
			int Arg4 = 1;
			int Arg5 = 13;
			int Arg6 = 11;

			verify_case(n, Arg6, mostFun(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 10000;
			int Arg2 = 123;
			int Arg3 = 456;
			int Arg4 = 789;
			int Arg5 = 1;
			int Arg6 = 0;

			verify_case(n, Arg6, mostFun(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 4;
			int Arg2 = 3;
			int Arg3 = 5;
			int Arg4 = 7;
			int Arg5 = 997;
			int Arg6 = 100;

			verify_case(n, Arg6, mostFun(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 12345;
			int Arg2 = 234;
			int Arg3 = 34;
			int Arg4 = 5;
			int Arg5 = 117;
			int Arg6 = 143371;

			verify_case(n, Arg6, mostFun(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ChristmasBatteries ___test;
	___test.run_test(-1);
}
// END CUT HERE
