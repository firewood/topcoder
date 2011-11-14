// BEGIN CUT HERE
/*
// SRM 500 Div2 Easy (250)
// PROBLEM STATEMENT
// You are given a 2-dimensional matrix of characters represented by the vector <string> letterMaze. The i-th character of the j-th element of letterMaze  represents the character at row i and column j. Each of the 26 letters from 'A' to 'Z' appears exactly once in letterMaze, the remaining characters are periods ('.').

An alphabet path is a sequence of 26 elements of the matrix such that:

The first element contains the letter 'A'.
The first element and the second element are (horizontally or vertically) adjacent.
The second element contains the letter 'B'.
The second element and the third element are (horizontally or vertically) adjacent.
...
The 25-th element and the 26-th element are (horizontally or vertically) adjacent.
The last, 26-th element contains the letter 'Z'.

Given letterMaze return string "YES" if the alphabet path exists in the matrix and "NO" otherwise.

DEFINITION
Class:AlphabetPath
Method:doesItExist
Parameters:vector <string>
Returns:string
Method signature:string doesItExist(vector <string> letterMaze)


NOTES
-Formally, elements (x1,y1) and (x2,y2) are horizontally or vertically adjacent if and only if abs(x1 - x2) + abs(x2 - y2) = 1. 


CONSTRAINTS
-letterMaze will contain between 1 and 50 elements, inclusive.
-Each element of letterMaze will contain between 1 and 50 characters, inclusive.
-All the elements of letterMaze will contain the same number of characters.
-Each element of letterMaze will only contain uppercase letters ('A'-'Z') and periods ('.').
-Each uppercase letter from 'A' to 'Z' will appear exactly once in letterMaze.


EXAMPLES

0)
{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}

Returns: "YES"

Simply go from left to right.

1)
{"ADEHI..Z",
 "BCFGJK.Y",
 ".PONML.X",
 ".QRSTUVW"}


Returns: "YES"



2)
{"ACBDEFGHIJKLMNOPQRSTUVWXYZ"}

Returns: "NO"



3)
{"ABC.......",
 "...DEFGHIJ",
 "TSRQPONMLK",
 "UVWXYZ...."}

Returns: "NO"

The cells marked with C and D are not adjacent, it is impossible to make an alphabet path in this case.

4)
{"..............",
 "..............",
 "..............",
 "...DEFGHIJK...",
 "...C......L...",
 "...B......M...",
 "...A......N...",
 "..........O...",
 "..ZY..TSRQP...",
 "...XWVU.......",
 ".............."}

Returns: "YES"



#line 94 "AlphabetPath.cpp"
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
typedef vector<string> StrVec;

class AlphabetPath {

public:
	string doesItExist(vector <string> letterMaze) {
		char c = 'A';
		int x = 0, y = 0;
		int i, j;
		while (c <= 'Z') {
			for (i = 0; i < letterMaze.size(); ++i) {
				for (j = 0; j < letterMaze[i].length(); ++j) {
					if (c == letterMaze[i][j]) {
						if (c == 'A') {
							++c;
							x = j;
							y = i;
							goto next;
						}
						if ((abs(x - j) + abs(y - i)) <= 1) {
							++c;
							x = j;
							y = i;
							goto next;
						}
						return "NO";
					}
				}
			}
next:
			;
		}
		return "YES";
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, doesItExist(Arg0)); }
	void test_case_1() { string Arr0[] = {"ADEHI..Z",
 "BCFGJK.Y",
 ".PONML.X",
 ".QRSTUVW"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(1, Arg1, doesItExist(Arg0)); }
	void test_case_2() { string Arr0[] = {"ACBDEFGHIJKLMNOPQRSTUVWXYZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(2, Arg1, doesItExist(Arg0)); }
	void test_case_3() { string Arr0[] = {"ABC.......",
 "...DEFGHIJ",
 "TSRQPONMLK",
 "UVWXYZ...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, doesItExist(Arg0)); }
	void test_case_4() { string Arr0[] = {"..............",
 "..............",
 "..............",
 "...DEFGHIJK...",
 "...C......L...",
 "...B......M...",
 "...A......N...",
 "..........O...",
 "..ZY..TSRQP...",
 "...XWVU.......",
 ".............."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(4, Arg1, doesItExist(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AlphabetPath ___test;
	___test.run_test(0);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
