// BEGIN CUT HERE
/*
SRM 815 Div1 Easy (250)

PROBLEM STATEMENT

The old-fashioned door lock keys are usually some pattern of cuts into a metal that should fit perfectly into the lock in order to unlock it. The key also has a handle at one of the ends which is used to turn the key after it is inserted into the lock.

The simplest keys have all the cuts at an equal depth.
On such keys, each part of the key is either cut or not.
We can represent such keys using strings of two characters: a period ('.') will represent a cut piece and a caret ('^') will represent an uncut piece (also called a "tooth").

An example key would be ".^^.^.^^^.^.^". This key has length 13 and has five cuts (at zero-indexed positions 0, 3, 5, 9, and 11) and eight teeth.

Elly is designing a new lock mechanism. 
Her lock will be opened by using multiple simple keys (as described above).
The keys will be inserted parallel to each other and aligned so that they all end at the same depth.

The more simple keys the girl uses, the better the security of the lock gets. 
However, due to the specifics of the lock, no two keys can have a tooth at the same position. 

For example if the girl has the following keys:


    { "..^.^^.^", 
      "^.^^...^", 
      "^.....^." }

she can use two of them: if she places "..^.^^.^" and "^.....^." next to each other, at most one of them has a tooth at each position. She cannot use all three keys, because there would be multiple teeth at zero-indexed positions 0, 2, and 7.
Moreover, the girl cannot even use only the keys "^.^^...^" and "^.....^." together, because they have a tooth at the same position.

The girl has a collection of keys she can use for her new locking system.
They are given to you in the vector <string> keys.
Each element of keys represents a single key in the format described above ('.' for a cut and '^' for a tooth).

Help Elly: Determine and return the maximal number of keys she can use for her lock.


DEFINITION
Class:EllysKeys
Method:getMax
Parameters:vector <string>
Returns:int
Method signature:int getMax(vector <string> keys)


NOTES
-The keys all have handles on the same side, so they cannot be used in reverse. E.g., if you are given the key "^^...", you cannot use it as "...^^".


CONSTRAINTS
-keys will contain between 1 and 50 elements, inclusive.
-Each element of keys will have length between 1 and 20, inclusive.
-Each element of keys will contain only the characters '.' and '^'. 
-All elements of keys will have the same length.


EXAMPLES

0)
{"..^.^^.^",
 "^.^^...^",
 "^.....^."}

Returns: 2

The example from the problem statement.


1)
{"^.^"}

Returns: 1

With a single key the best solution is always to use it.


2)
{"^..^...^",
 ".^^.....",
 ".^..^...",
 "..^...^.",
 "...^^.^."}

Returns: 3

Here the optimal configuration is to take keys 0, 2, and 3 (zero-indexed).


3)
{"....................",
 "^^^^^^..^^^^..^^^^^.",
 "..^^...^^..^^.^^..^^",
 "..^^...^^..^^.^^^^^.",
 "..^^...^^..^^.^^....",
 "..^^....^^^^..^^....",
 "....................",
 ".^^^^...^^^^..^^^^..",
 "^^...^.^^..^^.^^..^^",
 "^^.....^^..^^.^^..^^",
 "^^...^.^^..^^.^^..^^",
 ".^^^^...^^^^..^^^^..",
 "....................",
 "...^^^^^^...^^^^^...",
 "...^^.......^^..^^..",
 "...^^^^^....^^^^^...",
 "...^^.......^^.^^...",
 "...^^^^^^...^^..^^..",
 "...................."}

Returns: 5

It is possible that some keys don't have any teeth, in which case all of them can be used.

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

class EllysKeys {
public:
	int getMax(vector <string> keys) {
		int ans = 0, bm = 1 << keys[0].length();
		vector<int> dp(bm);
		for (int i = 0; i < keys.size(); ++i) {
			int f = 0;
			string s = keys[i];
			for (int j = 0; j < s.length(); ++j) {
				f = (f * 2) + (s[j] != '.');
			}
			for (int b = bm - 1; b >= 0; --b) {
				if ((b & f) == f) {
					dp[b] = max(dp[b], dp[b & ~f] + 1);
				}
			}
		}
		for (int b = 0; b < bm; ++b) {
			ans = max(ans, dp[b]);
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
			string Arr0[] = {"..^.^^.^",
 "^.^^...^",
 "^.....^."};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMax(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"^.^"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMax(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"^..^...^",
 ".^^.....",
 ".^..^...",
 "..^...^.",
 "...^^.^."};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMax(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"....................",
 "^^^^^^..^^^^..^^^^^.",
 "..^^...^^..^^.^^..^^",
 "..^^...^^..^^.^^^^^.",
 "..^^...^^..^^.^^....",
 "..^^....^^^^..^^....",
 "....................",
 ".^^^^...^^^^..^^^^..",
 "^^...^.^^..^^.^^..^^",
 "^^.....^^..^^.^^..^^",
 "^^...^.^^..^^.^^..^^",
 ".^^^^...^^^^..^^^^..",
 "....................",
 "...^^^^^^...^^^^^...",
 "...^^.......^^..^^..",
 "...^^^^^....^^^^^...",
 "...^^.......^^.^^...",
 "...^^^^^^...^^..^^..",
 "...................."};
			int Arg1 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMax(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysKeys ___test;
	___test.run_test(-1);
}
// END CUT HERE
