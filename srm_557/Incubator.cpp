// BEGIN CUT HERE
/*
// SRM 557 Div1 Medium (550)

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
Class:Incubator
Method:maxMagicalGirls
Parameters:vector <string>
Returns:int
Method signature:int maxMagicalGirls(vector <string> love)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
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
{"NNYNNNNN","NNNYNNNN","NNNNYNNN","NNYNNNNN","NNNNNYYN","NNNYNNNY","NNNNNNNN","NNNNNNNN"}

Returns: 2


6)
{"Y"}

Returns: 0

Note that a girl may love herself.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;

class Incubator {

	// From The Programming Contest Challendge Book
	IntVec G[100];
	int match[100];
	bool used[100];

	void add_edge(int u, int v) {
		G[u].push_back(v);
		G[v].push_back(u);
	}

	bool dfs(int v) {
		used[v] = true;
		int i;
		for (i = 0; i < (int)G[v].size(); ++i) {
			int u = G[v][i];
			int w = match[u];
			if (w < 0 || !used[w] && dfs(w)) {
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
		return false;
	}

public:
	int maxMagicalGirls(vector <string> love) {
		int sz = (int)love.size();

		// Warshall-Floyd Algorithm
		int p[50][50] = {};
		int i, j, k;
		for (i = 0; i < sz; ++i) {
			for (j = 0; j < sz; ++j) {
				p[i][j] = love[i][j] == 'Y';
			}
		}
		for (k = 0; k < sz; ++k) {
			for (i = 0; i < sz; ++i) {
				for (j = 0; j < sz; ++j) {
					p[i][j] |= p[i][k] & p[k][j];
				}
			}
		}

		// Bipartite Matching
		for (i = 0; i < 100; ++i) {
			G[i].clear();
		}
		memset(match, -1, sizeof(match));
		for (i = 0; i < sz; ++i) {
			for (j = 0; j < sz; ++j) {
				if (p[i][j]) {
					add_edge(i, 50+j);
				}
			}
		}
		int cnt = 0;
		for (i = 0; i < sz; ++i) {
			if (match[i] < 0) {
				memset(used, 0, sizeof(used));
				cnt += dfs(i);
			}
		}

		return sz - cnt;
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
			string Arr0[] = {"NNYNNNNN","NNNYNNNN","NNNNYNNN","NNYNNNNN","NNNNNYYN","NNNYNNNY","NNNNNNNN","NNNNNNNN"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

		// test_case_6
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
	Incubator ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
