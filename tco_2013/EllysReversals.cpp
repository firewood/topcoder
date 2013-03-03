// BEGIN CUT HERE
/*
TCO13 Round 1B Hard (1000)

PROBLEM STATEMENT
Elly has a list of several distinct strings given in the vector <string> words.
She can apply the following operation as many times as she wants (including zero times):

Choose one of the words and call it S.
Choose an even number k between 2 and |S|, inclusive,
where |S| is the length of S (thus, chose a prefix with even length).
Reverse the order of the first k characters of S
(thus, reverse the chosen prefix without the rest of the word).

For example, if she has the word "topcoder", she can reverse its first 2, 4, 6, or all 8 characters.
If she chooses to reverse its first 4 characters, the change will be: "topcoder" -> "cpotoder".
If at a later time she decides to chose the same string and reverse all of its characters
(which is also a valid prefix with even length), she would get "cpotoder"->"redotopc".

After performing some operations two strings might become equal.
If that happens, Elly crosses them out and continues playing her game with the remaining strings only,
i.e. they "disappear" from the list.
The girl wonders what is the minimal number of strings she can end up with.

For example, suppose she has the strings {"esprit", "god", "redotopc", "odcpoter", "dog"}.
The word "redotopc" can be converted to "topcoder" by first reversing all 8 characters and then reversing the first 4.
The word "odcpoter" can also be converted to "topcoder" by performing "odcpoter" -> "docpoter" -> "topcoder".
At that point the words become equal and disappear, leaving Elly only with {"esprit", "god", "dog"}.
This is where she gets stuck: The words "god" and "dog" cannot become equal,
because she can only reverse prefixes with even length. Thus, the minimal number of words she can get is 3.

Given her initial strings in vector <string> words,
return an int indicating the minimal number of strings she can be left with.


DEFINITION
Class:EllysReversals
Method:getMin
Parameters:vector <string>
Returns:int
Method signature:int getMin(vector <string> words)


CONSTRAINTS
-words will contain between 1 and 50 elements, inclusive.
-Each element of words will contain between 1 and 50 characters, inclusive.
-Each element of words will consist only of lowercase letters of the English alphabet ('a'-'z').
-All elements of words will be distinct.


EXAMPLES

0)
{"esprit", "god", "redotopc", "odcpoter", "dog"}

Returns: 3

The example from the problem statement.


1)
{"no", "zaphod", "just", "very", "improbable"}

Returns: 5

It is possible that she cannot get rid of any of the words.


2)
{"rats", "live", "stressed", "to", "act", "as", "star", "desserts", "of", "evil", "cat", "sa", "fo", "ot"}

Returns: 0

It is possible that she ends up with zero words.


3)
{"topcoder", "redocpot", "doretopc", "cpotdoer", "harlemshake"}

Returns: 1

Sometimes it is possible to match different words when using a different sequence of operations.


4)
{"iprlzgukfggzg", "bmhxvjbrtkbxy", "khapjiabbny", "nqlwgmcyvdikt",
 "nxromtvtpug", "leealcapovm", "ushnxwjczczbmd", "bwhykzupcux",
 "xrlboyuwlnsp", "bbjoketeheezfs", "dxfztrldomjqkv", "dkbktqdtgfujcut",
 "zfybzyuxgpnt", "ffmsldrdftode", "vopuufksxd", "pqhbsiujwda",
 "yhwbkzupcux", "hkbabnapjiy", "zqsqefrrzehtxn", "yovinyguyudmv"}

Returns: 16

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<string> StrVec;
typedef set<string> StrSet;

class EllysReversals {
public:
	int getMin(vector <string> words) {
		StrSet m;
		int i, j, k, l;
		for (i = 0; i < (int)words.size(); ++i) {
			StrVec v;
			l = (int)words[i].length();
			k = l & ~1;
			for (j = 0; j < k; j += 2) {
				char a = min(words[i][j], words[i][j+1]);
				char b = max(words[i][j], words[i][j+1]);
				string x;
				x += a;
				x += b;
				v.push_back(x);
			}
			string s;
			sort(v.begin(), v.end());
			for (j = 0; j < (int)v.size(); ++j) {
				s += v[j];
			}
			if (l & 1) {
				s += words[i][k];
			}
			if (m.find(s) != m.end()) {
				m.erase(s);
			} else {
				m.insert(s);
			}
		}
		return (int)m.size();
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
			string Arr0[] = {"esprit", "god", "redotopc", "odcpoter", "dog"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"no", "zaphod", "just", "very", "improbable"};
			int Arg1 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"rats", "live", "stressed", "to", "act", "as", "star", "desserts", "of", "evil", "cat", "sa", "fo", "ot"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"topcoder", "redocpot", "doretopc", "cpotdoer", "harlemshake"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"iprlzgukfggzg", "bmhxvjbrtkbxy", "khapjiabbny", "nqlwgmcyvdikt",
 "nxromtvtpug", "leealcapovm", "ushnxwjczczbmd", "bwhykzupcux",
 "xrlboyuwlnsp", "bbjoketeheezfs", "dxfztrldomjqkv", "dkbktqdtgfujcut",
 "zfybzyuxgpnt", "ffmsldrdftode", "vopuufksxd", "pqhbsiujwda",
 "yhwbkzupcux", "hkbabnapjiy", "zqsqefrrzehtxn", "yovinyguyudmv"};
			int Arg1 = 16;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"topcoder", "redocpot", "doretopc", "cpotdoer", "reodtopc"};
			int Arg1 = 1;
			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysReversals ___test;
	___test.run_test(-1);
}
// END CUT HERE
