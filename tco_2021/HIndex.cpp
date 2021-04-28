// BEGIN CUT HERE
/*
TCO21 R1B Easy (300)

PROBLEM STATEMENT

The h-index is a fairly popular method of evaluating an author's scientific impact.
The h-index of an author is defined as the maximum value h such that the given author has published at least h papers that have each been cited at least h times.

An unscrupulous scientist has decided to cheat and boost their h-index by paying for fake citations.
You are given:

The vector <int> realCitations. Each element of realCitations is the number of citations for one of the author's papers.
The int budget: the maximum amount of money the scientist is willing to spend on the fake citations.
The int citationPrice: the cost of one fake citation (of one paper of the buyer's choice).


Calculate and return the maximum h-index the scientist can have after purchasing some fake citations.


DEFINITION
Class:HIndex
Method:cheat
Parameters:vector <int>, int, int
Returns:int
Method signature:int cheat(vector <int> realCitations, int budget, int citationPrice)


NOTES
-The scientist has no time to make additional publications, he can only purchase citations to already existing papers.
-Sadly, practices like the one described in the problem statement are quite common in modern academia. Awareness of these practices is the first step towards finding a way to get rid of them.


CONSTRAINTS
-realCitations will have between 1 and 300 elements, inclusive.
-Each element of realCitations will be between 0 and 10^6, inclusive.
-budget will be between 1 and 10^9, inclusive.
-citationPrice will be between 1 and 10^9, inclusive.


EXAMPLES

0)
{25, 3, 5, 3, 8, 0}
447
1000

Returns: 3

A fake citation costs 1000 which is something this scientist cannot afford. The citations he already has give him an h-index of 3.


1)
{25, 3, 5, 3, 8, 0}
1447
1000

Returns: 4

A similar situation to Example 0 but now the scientist does have the budget to purchase one fake citation. One optimal choice is to buy a citation for the fourth paper (raising its total number of citations from 3 to 4), as this will make the scientist's new h-index be 4.


2)
{0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}
140000
10000

Returns: 4

This scientist writes extremely poor papers that get almost no real citations. His current h-index is only 1. However, he is quite rich and can afford to buy up to 14 fake citations. If he does so cleverly, he will be able to raise his h-index to 4 (and doesn't even have to spend all the money in his budget to do so).


3)
{0, 0, 0}
999999999
1000000000

Returns: 0

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

class HIndex {
public:
	int cheat(vector <int> realCitations, int budget, int citationPrice) {
		sort(realCitations.rbegin(), realCitations.rend());
		LL c = budget / citationPrice, ans = 0;
		for (LL i = 1; i <= realCitations.size(); ++i) {
			LL need = 0;
			for (LL j = 0; j < i; ++j) {
				LL x = i - min(i, (LL)realCitations[j]);
				need += x;
			}
			if (need > c) {
				break;
			}
			ans = i;
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
			int Arr0[] = {25, 3, 5, 3, 8, 0};
			int Arg1 = 447;
			int Arg2 = 1000;
			int Arg3 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, cheat(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {25, 3, 5, 3, 8, 0};
			int Arg1 = 1447;
			int Arg2 = 1000;
			int Arg3 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, cheat(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
			int Arg1 = 140000;
			int Arg2 = 10000;
			int Arg3 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, cheat(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0};
			int Arg1 = 999999999;
			int Arg2 = 1000000000;
			int Arg3 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, cheat(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	HIndex ___test;
	___test.run_test(-1);
}
// END CUT HERE
