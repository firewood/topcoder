// BEGIN CUT HERE
/*
TCO18 Fun Round Poland Medium (500)

PROBLEM STATEMENT

You are given the ints a <= b.
Consider the set of integers between a and b, inclusive.
You want to use some of these integers to construct a set of pairs of integers.
A set that consists of k pairs is said to be diverse if all of the following conditions are met.

All 2k integers used in the pairs are distinct.
The sum of each pair is strictly smaller than a + b.
The sums of the k pairs are k distinct integers.

For instance, suppose that a=2 and b=4, which means that we are allowed to use the integers from the set {2, 3, 4}. Then:

{(2, 2)} is a set that contains one pair of numbers, but it is not a diverse set because it violates condition #1.
{(3, 3)} does also violate condition #1
{(2, 4)} violates condition #2, as 2 + 4 is not strictly smaller than a + b.
{(3, 4)} does also violate condition #2.
{(2, 4), (3, 3)} is a set that contains two pairs of numbers; this set violates conditions #1 and #3.
{(2, 3)} is a diverse set.
{(3, 2)} is another diverse set.

In the above example it is obvious that there is no diverse set with two or more pairs of integers, hence {(2, 3)} and {(3, 2)} are the largest diverse sets.

You are interested in finding the largest possible diverse set of pairs for the given a and b.
That is, among all diverse sets of pairs you can construct, you want to find one that contains the maximum number of pairs.

Return a vector <int> that describes a maximum diverse set of pairs as follows:

If {(x1, y1), (x2, y2), ..., (xk, yk)} is the set of pairs you found, 
return 
{
x1, y1, 
x2, y2, 
..., 
xk, yk
}.

If multiple answers exist, you may return any one of them.
If the maximum set of pairs is an empty set, then you must return an empty vector <int>.


DEFINITION
Class:DiversePairsDiv1
Method:findMaxDiversePairs
Parameters:int, int
Returns:vector <int>
Method signature:vector <int> findMaxDiversePairs(int a, int b)


CONSTRAINTS
-a will be between 1 and 10^9, inclusive.
-b will be between 1 and 10^9, inclusive.
-b-a will be between 0 and 2,000, inclusive.


EXAMPLES

0)
1
1

Returns: { }


1)
1
2

Returns: { }

The only pairs of distinct integers we can construct are (1, 2) and (2, 1), but both sets {(1, 2)} and {(2, 1)} violate condition #2.


2)
2
4

Returns: {2, 3 }

This example was discussed in the problem statement.
{3, 2} is another correct return value.


3)
5
9

Returns: {5, 6 }

There is no diverse set with two pairs of integers. In particular, the set {(5, 8), (6, 7)} does satisfy conditions #1 and #2 (all integers are distinct and all pairwise sums are small enough) but 5+8 = 6+7, so this set violates condition #3.

4)
15
21

Returns: {15, 20, 16, 18 }


5)
20
27

Returns: {21, 25, 22, 23, 20, 24 }

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

class DiversePairsDiv1 {
	vector <int> t(int a, int b, int s) {
		vector <int> ans;
		set<int> up;
		set<int> us;
		for (int i = s; i < b; ++i) {
			if (up.find(i) != up.end()) {
				continue;
			}
			for (int j = b; j >= a; --j) {
				if (i == j || i + j >= a + b || up.find(j) != up.end()) {
					continue;
				}
				int y = i + j;
				if (us.find(y) == us.end()) {
					ans.push_back(i);
					ans.push_back(j);
					up.insert(i);
					up.insert(j);
					us.insert(y);
					break;
				}
			}
		}
		return ans;
	}

public:
	vector <int> findMaxDiversePairs(int a, int b) {
		vector <int> ans;
		int n = a + max(0, (b - a) / 5 - 1);
		int m = min(b, a + (b - a) / 5 + 1);
		for (int s = n; s <= m; s += 1) {
			vector <int> r = t(a, b, s);
			if (r.size() > ans.size()) {
				ans = r;
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
//			int Arr2[] = { };

			vector <int> Arg2;
			verify_case(n, Arg2, findMaxDiversePairs(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 2;
//			int Arr2[] = { };

			vector <int> Arg2;
			verify_case(n, Arg2, findMaxDiversePairs(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 4;
			int Arr2[] = {2, 3 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMaxDiversePairs(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 9;
			int Arr2[] = {5, 6 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMaxDiversePairs(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15;
			int Arg1 = 21;
			int Arr2[] = {15, 20, 16, 18 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMaxDiversePairs(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arg1 = 27;
			int Arr2[] = {21, 25, 22, 23, 20, 24 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMaxDiversePairs(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DiversePairsDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
