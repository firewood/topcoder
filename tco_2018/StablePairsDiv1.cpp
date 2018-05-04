// BEGIN CUT HERE
/*
TCO18 R1B Medium (600)

PROBLEM STATEMENT

Consider the set of integers between 1 and n, inclusive, and two positive integers c and k.
You want to build an ordered list of k pairs 
(x1, y1),
(x2, y2),
...
(xk, yk)
such that the following conditions are met.

 1 ? xi < yi ? n for all i between 1 and k, inclusive.
 yi < xi+1 for all i between 1 and k-1, inclusive.
 (xi+1 + yi+1) - (xi + yi) = c for all i between 1 and k-1, inclusive.

If a list of pairs satisfies all of the above conditions, the list is said to be stable.
For any fixed n, c, and k, a stable list of k pairs is said to be maximal
if its sum of elements (the sum of all 2k integers it contains) is the largest among all stable lists 
of k pairs.

For instance, consider n=5, c=4, and k=2.
There are two stable lists of pairs: one is [(1, 2), (3, 4)] and the other is [(2, 3), (4, 5)].
The latter is the only maximal stable list of pairs in this example as its sum is (2+3+4+5) = 14.

Given n, c, and k, find one maximal stable list of pairs, 
and return a vector <int> that describes the list.
Specifically, if 
(x1, y1),
(x2, y2),
...,
(xk, yk)
is your maximal stable list of pairs, you must return 
{
x1, y1,
x2, y2,
...,
xk, yk
}.

If there are many maximal stable lists of pairs, you may return any one of them. 
If no stable list of pairs with the desired properties exists, you must return an empty vector <int>.


DEFINITION
Class:StablePairsDiv1
Method:findMaxStablePairs
Parameters:int, int, int
Returns:vector <int>
Method signature:vector <int> findMaxStablePairs(int n, int c, int k)


CONSTRAINTS
-n will be between 1 and 100, inclusive.
-c will be between 1 and 100, inclusive.
-k will be between 1 and 100, inclusive.


EXAMPLES

0)
5
4
2

Returns: {2, 3, 4, 5 }

This example was described in the problem statement.


1)
4
4
2

Returns: {1, 2, 3, 4 }


2)
1
100
1

Returns: { }

When n=1, regardless of c and k, there is no way to build a pair. 


3)
3
100
1

Returns: {2, 3 }

With k=1 we are looking for stable lists that only contain a single pair of numbers. There are three stable lists: [(1, 2)], [(1, 3)], and [(2, 3)]. Obviously, the last one is the only maximal one in this case.


4)
10
6
3

Returns: {2, 5, 6, 7, 9, 10 }


5)
12
7
3

Returns: {4, 5, 6, 10, 11, 12 }

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

class StablePairsDiv1 {
public:
	vector <int> findMaxStablePairs(int n, int c, int k) {
		vector <int> ans;
		for (int sum = 3; sum <= 200; ++sum) {
			vector <int> temp;
			int prev = 0;
			for (int i = 0; i < k; ++i) {
				int s = sum + c * i;
				int p = -1, q = -1;
				for (int j = prev + 1; j <= s / 2; ++j) {
					int k = s - j;
					if (j < k && k <= n) {
						if (p < 0 || k < q) {
							p = j, q = k;
						}
					}
				}
				if (p < 0) {
					break;
				}
				temp.push_back(p);
				temp.push_back(q);
				prev = q;
			}
			if (temp.size() == k * 2) {
				ans = temp;
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
			int Arg0 = 5;
			int Arg1 = 4;
			int Arg2 = 2;
			int Arr3[] = {2, 3, 4, 5 };

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			int Arg2 = 2;
			int Arr3[] = {1, 2, 3, 4 };

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 100;
			int Arg2 = 1;

			vector <int> Arg3;
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 100;
			int Arg2 = 1;
			int Arr3[] = {2, 3 };

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 6;
			int Arg2 = 3;
			int Arr3[] = {2, 5, 6, 7, 9, 10 };

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 12;
			int Arg1 = 7;
			int Arg2 = 3;
			int Arr3[] = {4, 5, 6, 10, 11, 12 };

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arg0 = 5;
			int Arg1 = 100;
			int Arg2 = 5;

			vector <int> Arg3;
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arg0 = 100;
			int Arg1 = 8;
			int Arg2 = 1;
			int Arr3[] = { 99,100 };

			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 97;
			int Arg1 = 8;
			int Arg2 = 25;

			vector <int> Arg3;
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 100;
			int Arg1 = 3;
			int Arg2 = 3;

			vector <int> Arg3;
			verify_case(n, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StablePairsDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
