// BEGIN CUT HERE
/*
SRM 684 Div1 Easy (250)

PROBLEM STATEMENT
A set of positive integers is called k-smooth if each pair (A,B) of elements of the set satisfies A <= k * B.
For example, the set {3,4,7,9} is 3-smooth but the set {30,60,100} is not: 100 is strictly more than 3 * 30.

Hero likes some sets of integers.
In order to determine whether he likes a set S, Hero uses the following procedure:

Form a new set D of pairwise differences of elements in S. In other words: for each pair of elements A, B in S, put the number |A-B| into D.
Hero likes the original set S if and only if the new set D is k-smooth.


You are given a vector <int> a containing a set of distinct integers.
You are also given the int k Hero uses while determining whether he likes a set of integers.

Select the largest subset of a Hero likes.
Return the number of elements in that subset.


DEFINITION
Class:CliqueParty
Method:maxsize
Parameters:vector <int>, int
Returns:int
Method signature:int maxsize(vector <int> a, int k)


CONSTRAINTS
-Number of elements in a will be between 2 and 50, inclusive.
-Each elements in a will be between 1 and 1,000,000,000, inclusive.
-All elements in a will be distinct.
-k will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{1,2,3}
2

Returns: 3

Hero likes the entire set a.


1)
{1,2,3}
1

Returns: 2

Here, Hero does not like the entire set a, but he does like, for example, the subset {1,3}.


2)
{4,10,5,6}
2

Returns: 3


3)
{1,2,3,4,5,6}
3

Returns: 4


4)
{10,9,25,24,23,30}
7

Returns: 4

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class CliqueParty {
public:
	int maxsize(vector <int> a, int K) {
		int ans = 0;
		sort(a.begin(), a.end());
		int N = (int)a.size();
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				int mx = a[j] - a[i];
				int mn = (mx + K - 1) / K;
				set<int> s;
				s.insert(a[i]);
				s.insert(a[j]);
				for (int k = i + 1; k < j; ++k) {
					int nk = mx;
					for (int x : s) {
						nk = min(nk, abs(x - a[k]));
					}
					if (nk >= mn) {
						s.insert(a[k]);
					}
				}
				ans = max(ans, (int)s.size());
			}
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
			int Arr0[] = {1,2,3};
			int Arg1 = 2;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxsize(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3};
			int Arg1 = 1;
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxsize(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,10,5,6};
			int Arg1 = 2;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxsize(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6};
			int Arg1 = 3;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxsize(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,9,25,24,23,30};
			int Arg1 = 7;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxsize(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50 };
			int Arg1 = 25;
			int Arg2 = 26;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxsize(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CliqueParty ___test;
	___test.run_test(-1);
}
// END CUT HERE
