// BEGIN CUT HERE
/*
// SRM 557 Div2 Medium (550)

// PROBLEM STATEMENT
// You are the Incubator.
You have the ability to turn normal girls into magical girls.

There are n girls in the city.
The girls are conveniently numbered 0 through n-1.
Some girls love some other girls.
Love is not necessarily symmetric.
It is also possible for a girl to love herself.

You are given a vector <string> love.
Character j of element i of love is 'Y' if girl i loves girl j.
Otherwise, that character is 'N'.
In the rest of the problem statement, we will use love[i][j] to denote the truth value of the statement "girl i loves girl j".

Each girl has two boolean properties: isMagical (is she a magical girl?) and isProtected (is she protected by some girl?).
Initially, for each girl i we have isMagical[i] = False and isProtected[i] = False.

At any moment, you can choose an ordinary girl and turn her into a magical girl.
That is, you can take a girl i such that isMagical[i] = False, and change isMagical[i] to True.

Each such change will trigger a series of events:

Each magical girl will protect all girls she loves: if isMagical[i] and love[i][j], then isProtected[j] is set to True.
Each protected girl will also protect all girls she loves: if isProtected[i] and love[i][j], then isProtected[j] is set to True.

Note that some of these changes may in turn trigger other changes, as more and more girls become protected.

Once there are no more changes, you can again change another ordinary girl into a magical one, and so on.
Your goal is to reach a situation with many girls that are magical, but not protected.
That is, you are interested in girls such that isMagical[i] = True and isProtected[i] = False.
Return the maximum number of such girls in a situation that can be reached using the above process.


DEFINITION
Class:IncubatorEasy
Method:maxMagicalGirls
Parameters:vector <string>
Returns:int
Method signature:int maxMagicalGirls(vector <string> love)


CONSTRAINTS
-n will be between 1 and 10, inclusive.
-love will contain exactly n elements.
-Each element of love will contain exactly n characters.
-Each character in each element of love will be either 'Y' or 'N'.


EXAMPLES

0)
{"NY","NN"}

Returns: 1

One optimal solution is to change girl 0 to a magical girl.
Girl 0 will be magical and she will not be protected.
It is not possible to have two girls that are both magical and not protected:
if you change both girls to magical girls (in any order), you will get a situation in which girl 1 is protected.


1)
{"NYN", "NNY", "NNN"}

Returns: 1

Again, there is no way to create more than one unprotected magical girl.
For example, if we start by making girl 2 magical, and then make girl 0 magical, magical girl 0 will protect girl 1, and protected girl 1 will protect girl 2.
Thus, in this case girl 0 will be magical and unprotected, girl 1 will be ordinary and protected, and girl 2 will be magical and protected.


2)
{"NNYNN","NNYNN","NNNYY","NNNNN","NNNNN"}

Returns: 2


3)
{"NNNNN","NYNNN","NYNYN","YNYNN","NNNNN"}

Returns: 2


4)
{"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"}

Returns: 5


5)
{"Y"}

Returns: 0

Note that a girl may love herself.

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;

static int popcount(LL bits) {
	bits = (bits & 0x5555555555555555LL) + (bits >>  1 & 0x5555555555555555LL);
	bits = (bits & 0x3333333333333333LL) + (bits >>  2 & 0x3333333333333333LL);
	bits = (bits & 0x0f0f0f0f0f0f0f0fLL) + (bits >>  4 & 0x0f0f0f0f0f0f0f0fLL);
	bits = (bits & 0x00ff00ff00ff00ffLL) + (bits >>  8 & 0x00ff00ff00ff00ffLL);
	bits = (bits & 0x0000ffff0000ffffLL) + (bits >> 16 & 0x0000ffff0000ffffLL);
	bits = (bits & 0x00000000ffffffffLL) + (bits >> 32 & 0x00000000ffffffffLL);
	return (int)bits;
}

class IncubatorEasy {

public:
	int maxMagicalGirls(vector <string> love) {
		int res = 0;
		int sz = (int)love.size();
		int Max = 1 << sz;
		int pm[10] = {};
		int i, j, k;
		for (i = 0; i < sz; ++i) {
			int b = 0;
			for (j = 0; j < sz; ++j) {
				if (love[i][j] == 'Y') {
					b |= 1<<j;
				}
			}
			pm[i] = b;
		}
		for (i = 0; i < sz; ++i) {
			int b = pm[i];
			for (j = 0; j < sz; ++j) {
				for (k = 0; k < sz; ++k) {
					if (b & (1<<k)) {
						b |= pm[k];
					}
				}
			}
			pm[i] = b;
		}
		for (i = 1; i < Max; ++i) {
			int p = 0;
			for (j = 0; j < sz; ++j) {
				if (i & (1<<j)) {
					p |= pm[j];
				}
			}
			int m = i & ~p;
			res = max(res, (int)popcount(m));
		}
		return res;
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
			string Arr0[] = {"NY","NN"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYN", "NNY", "NNN"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNYNN","NNYNN","NNNYY","NNNNN","NNNNN"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNNNN","NYNNN","NYNYN","YNYNN","NNNNN"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"};
			int Arg1 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"Y"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	IncubatorEasy ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
