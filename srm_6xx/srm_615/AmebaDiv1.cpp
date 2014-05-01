// BEGIN CUT HERE
/*
SRM 615 Div1 Easy (250)

PROBLEM STATEMENT
Monte-Carlo is an amoeba. Amoebas can feed on gel: whenever an amoeba encounters a piece of gel that is exactly as big as the amoeba, the amoeba will consume the gel and thus double its size.

Initially, the size of Monte-Carlo was some unknown positive integer. During its lifetime, Monte-Carlo encountered several gels and consumed the ones it could.

You are given a vector <int> X. The elements of X are the sizes of gels Monte-Carlo encountered, in chronological order.

Let S be the set of all possible final sizes of Monte-Carlo. Compute and return the number of positive integers that do not belong into S.


DEFINITION
Class:AmebaDiv1
Method:count
Parameters:vector <int>
Returns:int
Method signature:int count(vector <int> X)


NOTES
-It is possible to prove that the answer for any test case is finite and fits into a 32-bit signed integer type.


CONSTRAINTS
-X will contain between 1 and 200 integers, inclusive.
-Each element of X will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{3,2,1}

Returns: 2

Here are a few possibilities how Monte-Carlo's life could have looked like:

Monte-Carlo started with size 1, ignored gel #0, ignored gel #1, consumed gel #2 and thus reached size 2.
Monte-Carlo started with size 3, consumed gel #0 and thus reached size 6, and then ignored the next two gels (as they were too small).
Monte-Carlo started with size 47 and ignored all three gels.

All final sizes except for 1 and 3 are possible.


1)
{2,2,2,2,2,2,4,2,2,2}

Returns: 2

If Monte-Carlo starts with size 2, its life will look as follows: First, it will consume gel #0 and thus grow to 4. Later, after ignoring a few gels, Monte-Carlo will consume gel #6 (the one with size 4) and thus grow to 8.

It can be shown that for this X Monte-Carlo's final size can never be 2 or 4. 


2)
{1,2,4,8,16,32,64,128,256,1024,2048}

Returns: 11


3)
{854,250,934,1000,281,250,281,467,854,562,934,1000,854,500,562}

Returns: 7

*/
// END CUT HERE
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef set<int> IntSet;

class AmebaDiv1 {
public:
	int count(vector <int> X) {
		IntSet s(X.begin(), X.end());
		IntSet r;
		for (int n : s) {
			for (int x : X) {
				if (x == n) {
					n *= 2;
				}
			}
			r.insert(n);
		}

		int ans = 0;
		for (int n : s) {
			ans += r.find(n) == r.end();
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
			int Arr0[] = {3,2,1};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,2,2,2,2,4,2,2,2};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,4,8,16,32,64,128,256,1024,2048};
			int Arg1 = 11;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {854,250,934,1000,281,250,281,467,854,562,934,1000,854,500,562};
			int Arg1 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AmebaDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
