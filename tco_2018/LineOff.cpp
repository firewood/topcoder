// BEGIN CUT HERE
/*
TCO18 R1B Easy (250)

PROBLEM STATEMENT

You are given a set of colored points on a straight line.

You play a game with these points.
The game is a sequence of moves.
In each move you have to erase two points that are adjacent and share the same color.
(Two points are adjacent if there is no other point between them. Distances don't matter.)

You are given the string points. Each character of points describes the color of one point, in the order in which they are arranged on the line at the beginning of the game.
(Different letters represent different colors.)
Compute and return the maximum number of moves you can make.


DEFINITION
Class:LineOff
Method:movesToDo
Parameters:string
Returns:int
Method signature:int movesToDo(string points)


CONSTRAINTS
-points will contain between 1 and 50 characters, inclusive.
-Each character in points will be a lowercase English letter ('a'-'z').


EXAMPLES

0)
"abba"

Returns: 2

The only valid first move is to erase the two points of color 'b'. After that move the points of color 'a' are now adjacent and they can be removed in our second move.


1)
"zwwwzffw"

Returns: 2

You can remove two 'w' points and two 'f' points with your first two moves. After that the remaining points on the line will be arranged as follows: "zwzw". In this situation you don't have any adjacent points that share the same color, so there are no more moves.


2)
"rrrrrrr"

Returns: 3

With an odd number of points, at least one of them will have no pair.


3)
"dfghj"

Returns: 0

All colors are different so no points can be removed.


4)
"wasitacarooracatisaw"

Returns: 10

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

class LineOff {
public:
	int movesToDo(string points) {
		vector<string> v(26);
		for (int i = 0; i < 26; ++i) {
			v[i] = string(2, (char)(i + 'a'));
		}
		int ans = 0;
		bool f = true;
		while (f) {
			f = false;
			for (int i = 0; i < 26; ++i) {
				int pos = points.find(v[i]);
				if (pos >= 0) {
					points = points.substr(0, pos) + points.substr(pos + 2);
					++ans;
					f = true;
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
			string Arg0 = "abba";
			int Arg1 = 2;

			verify_case(n, Arg1, movesToDo(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "zwwwzffw";
			int Arg1 = 2;

			verify_case(n, Arg1, movesToDo(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "rrrrrrr";
			int Arg1 = 3;

			verify_case(n, Arg1, movesToDo(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "dfghj";
			int Arg1 = 0;

			verify_case(n, Arg1, movesToDo(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "wasitacarooracatisaw";
			int Arg1 = 10;

			verify_case(n, Arg1, movesToDo(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LineOff ___test;
	___test.run_test(-1);
}
// END CUT HERE
