// BEGIN CUT HERE
/*
SRM 566 Div2 Easy (250)

PROBLEM STATEMENT
Percy has just received a new game called Penguin Tiles.
The game is played on a rectangular grid.
Except for one square, each square of the grid contains a tile with a part of an image of a penguin.
The one remaining square is empty, and it is called the open square.
The player is allowed to slide one of the tiles adjacent to the open square onto the open square.
After several moves the tile game is supposed to form a picture with the bottom right corner containing the open square.

Percy's version of Penguin Tiles is a misprint.
Instead of each tile containing a different part of a penguin all tiles contain an image of the same penguin.
In other words each pair of tiles in Percy's Penguin Tiles is indistinguishable.

Percy has decided to play with the game anyway but instead of moving just one tile at a time he has decided to move several tiles at once.
In one move, Percy can either move some consecutive vertical tiles one square vertically,
or some consecutive horizontal tiles one square horizontally.
Of course, one of the tiles has to be moved onto the open square.
(In other words, instead of moving several tiles one at a time,
Percy may move them all at once, if they all lie in the same row or in the same column.)

You are given a vector <string> tiles representing the game.
The j-th character of the i-th element of tiles is 'P' if the square at row i,
column j contains a tile, and it is '.' (a period) for the open square.
Return the minimum number of moves to complete Percy's game.


DEFINITION
Class:PenguinTiles
Method:minMoves
Parameters:vector <string>
Returns:int
Method signature:int minMoves(vector <string> tiles)


CONSTRAINTS
-tiles will contain between 2 and 50 elements, inclusive.
-Each element of tiles will contain between 2 and 50 characters, inclusive.
-Each element of tiles will contain the same number of characters.
-Each character of each element of tiles will be either 'P' or '.'.
-tiles will contain exactly 1 occurrence of the character '.'.


EXAMPLES

0)
{"PP",
 "P."}

Returns: 0

The open tile is already in the bottom right corner.


1)
{"PPPPPPPP",
 ".PPPPPPP"}

Returns: 1


2)
{"PPP",
 "P.P",
 "PPP"}

Returns: 2


3)
{"P.",
 "PP",
 "PP",
 "PP"}

Returns: 1


4)
{".PPP",
 "PPPP",
 "PPPP",
 "PPPP"}

Returns: 2

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class PenguinTiles {
	public:
	int minMoves(vector <string> tiles) {
		int h = (int)tiles.size();
		int w = (int)tiles[0].length();
		int x, y;
		for (y = 0; y < h; ++y) {
			x = (int)tiles[y].find('.');
			if (x >= 0) {
				break;
			}
		}
		if (x == (w-1) && y == (h-1)) {
			return 0;
		}
		if (x == (w-1) || y == (h-1)) {
			return 1;
		}
		return 2;
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
			string Arr0[] = {"PP",
 "P."};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minMoves(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"PPPPPPPP",
 ".PPPPPPP"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minMoves(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"PPP",
 "P.P",
 "PPP"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minMoves(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"P.",
 "PP",
 "PP",
 "PP"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minMoves(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".PPP",
 "PPPP",
 "PPPP",
 "PPPP"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minMoves(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PenguinTiles ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
