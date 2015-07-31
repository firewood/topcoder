// BEGIN CUT HERE
/*
SRM 663 Div2 Easy (250)

PROBLEM STATEMENT
Samantha is renovating a square room.
The floor of the room is an N times N grid of unit square tiles.
Each tile has some color.
You are given the current colors of all tiles in a vector <string> floor with N elements, each containing N characters.
Each character represents one tile.
Identical characters represent tiles of the same color.

Samantha wants to be able to play chess or checkers on the floor.
Hence, she wants to change the entire floor into a checkerboard pattern.
A checkerboard pattern has two properties:

there are exactly two distinct colors of tiles
no two tiles of the same color share a common side

For example, this is a checkerboard pattern:

afa
faf
afa

This is not a checkerboard pattern because there are more than two distinct colors:

aba
bcb
aba

This is not a checkerboard pattern because there are two tiles that share a side and have the same color:

aaa
bab
aba

Samantha wants to change her floor into a checkerboard pattern by changing the colors of as few tiles as possible.
Compute and return the number of tiles she needs to change.


DEFINITION
Class:ChessFloor
Method:minimumChanges
Parameters:vector <string>
Returns:int
Method signature:int minimumChanges(vector <string> floor)


CONSTRAINTS
-N will be between 2 and 20, inclusive.
-floor will contain exactly N elements.
-Each element of floor will consist of exactly N characters.
-Each character in floor will be a lowercase English letter ('a'-'z').


EXAMPLES

0)
{"aba",
 "bbb",
 "aba"}

Returns: 1

This is not a checkerboard pattern, but Samantha can change it into a checkerboard pattern easily.
All she needs to do is to change the color of the middle tile from 'b' to 'a'.
The smallest possible number of changes is therefore 1.


1)
{"wbwbwbwb",
 "bwbwbwbw",
 "wbwbwbwb",
 "bwbwbwbw",
 "wbwbwbwb",
 "bwbwbwbw",
 "wbwbwbwb",
 "bwbwbwbw"}
 
Returns: 0

This floor already has a checkerboard pattern, so no changes are necessary.


2)
{"zz",
 "zz"}

Returns: 2

A checkerboard pattern must contain tiles of two distinct colors.


3)
{"helloand",
 "welcomet",
 "osingler",
 "oundmatc",
 "hsixhund",
 "redandsi",
 "xtythree",
 "goodluck"}

Returns: 56


4)
{"jecjxsengslsmeijrmcx",
 "tcfyhumjcvgkafhhffed",
 "icmgxrlalmhnwwdhqerc",
 "xzrhzbgjgabanfxgabed",
 "fpcooilmwqixfagfojjq",
 "xzrzztidmchxrvrsszii",
 "swnwnrchxujxsknuqdkg",
 "rnvzvcxrukeidojlakcy",
 "kbagitjdrxawtnykrivw",
 "towgkjctgelhpomvywyb",
 "ucgqrhqntqvncargnhhv",
 "mhvwsgvfqgfxktzobetn",
 "fabxcmzbbyblxxmjcaib",
 "wpiwnrdqdixharhjeqwt",
 "xfgulejzvfgvkkuyngdn",
 "kedsalkounuaudmyqggb",
 "gvleogefcsxfkyiraabn",
 "tssjsmhzozbcsqqbebqw",
 "ksbfjoirwlmnoyyqpbvm",
 "phzsdodppzfjjmzocnge"}

Returns: 376

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ChessFloor {
	public:
	int minimumChanges(vector <string> floor) {
		int N = (int)floor.size();
		int ans = N * N;
		for (int a = 'a'; a <= 'z'; ++a) {
			for (int b = 'a'; b <= 'z'; ++b) {
				if (a != b) {
					int c = 0;
					for (int i = 0; i < N; ++i) {
						for (int j = 0; j < N; ++j) {
							c += floor[i][j] != (((i + j) % 2) ? a : b);
						}
					}
					ans = min(ans, c);
				}
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
			string Arr0[] = {"aba",
 "bbb",
 "aba"}
;
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumChanges(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"wbwbwbwb",
 "bwbwbwbw",
 "wbwbwbwb",
 "bwbwbwbw",
 "wbwbwbwb",
 "bwbwbwbw",
 "wbwbwbwb",
 "bwbwbwbw"}
 ;
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumChanges(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"zz",
 "zz"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumChanges(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"helloand",
 "welcomet",
 "osingler",
 "oundmatc",
 "hsixhund",
 "redandsi",
 "xtythree",
 "goodluck"};
			int Arg1 = 56;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumChanges(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"jecjxsengslsmeijrmcx",
 "tcfyhumjcvgkafhhffed",
 "icmgxrlalmhnwwdhqerc",
 "xzrhzbgjgabanfxgabed",
 "fpcooilmwqixfagfojjq",
 "xzrzztidmchxrvrsszii",
 "swnwnrchxujxsknuqdkg",
 "rnvzvcxrukeidojlakcy",
 "kbagitjdrxawtnykrivw",
 "towgkjctgelhpomvywyb",
 "ucgqrhqntqvncargnhhv",
 "mhvwsgvfqgfxktzobetn",
 "fabxcmzbbyblxxmjcaib",
 "wpiwnrdqdixharhjeqwt",
 "xfgulejzvfgvkkuyngdn",
 "kedsalkounuaudmyqggb",
 "gvleogefcsxfkyiraabn",
 "tssjsmhzozbcsqqbebqw",
 "ksbfjoirwlmnoyyqpbvm",
 "phzsdodppzfjjmzocnge"};
			int Arg1 = 376;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumChanges(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ChessFloor ___test;
	___test.run_test(-1);
}
// END CUT HERE
