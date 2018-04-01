// BEGIN CUT HERE
/*
SRM 732 Div1 Easy (250)

PROBLEM STATEMENT

You just designed a single-player game called the Flipping Game.

The game is played on a rectangular board that is divided into n rows by m columns. 
The game is played using square tiles. 
The tiles have the same size as the unit square cells on the board. 
Each tile has one side white and the other side black.

You are given n, m, and a vector <string> X that represents the initial state of the board. 
More precisely, the character X[r][c] represents the cell in row r, column c of the board: 
'w' means that this cell contains a tile that is white (i.e., white on top, black on bottom), 'b' is a black tile, and 'e' is an empty cell without a tile.

The game is played in turns. 
Each turn looks as follows: 
Choose any tile T, note its color C, and flip the tile T to show the opposite color. 
Then, the flip cascades: whenever you flip some tile X and there is a tile Y adjacent to X such that the color of Y is also C, you have to flip Y as well. 
Two tiles are considered adjacent if they share a side. 
The turn ends when the cascade ends and there are no more tiles you have to flip.

You win the game when all tiles on the board show the same color. 
Determine and return the smallest number of turns needed to win the game. 
Note that it is always possible to win the game.


DEFINITION
Class:TileFlippingGame
Method:HowManyMoves
Parameters:int, int, vector <string>
Returns:int
Method signature:int HowManyMoves(int n, int m, vector <string> X)


CONSTRAINTS
-n will be between 2 and 20, inclusive.
-m will be between 2 and 20, inclusive.
-X will contain exactly n elements.
-Each element of X will contain exactly m elements.
-Each element of each element of X will be one of 'e', 'b', and 'w'.
-If we concatenate all elements of X, it will contain at least one 'e', at least one 'b', and at least one 'w'.


EXAMPLES

0)
3
3
{"bbb","eee","www"}

Returns: 1

Regardless of which tile you choose to flip, the game ends after the first turn.


1)
3
3
{"bwe","wbw","ewb"}

Returns: 2

First, flip the black tile at the center of the board to white.
Then flip any of the five white tiles to turn all seven tiles to black side up.


2)
4
4
{"beww","beww","beww","wewe"}

Returns: 1


3)
2
8
{"ewewbbbb","bwebewww"}

Returns: 3


4)
5
5
{"bwebw","wbebb","eeeee","bbebb","bbebb"}

Returns: 3

Initially the board looks as follows:

bwebw
wbebb
eeeee
bbebb
bbebb

There are three white tiles. 
One optimal solution is to flip these three tiles from white to black (one tile per turn).
There are also other optimal solutions.
For example, you can start by flipping the top left tile from black to white.

The best way to make all the tiles white requires five flips, which is stricty worse.


5)
6
7
{"bwbbbbb","bwbwwwb","bwbwewb","bwbbbwb","bwwwwwb","bbbbbbb"}

Returns: 1

Initially, the game board looks like the following:

bwbbbbb
bwbwwwb
bwbwewb
bwbbbwb
bwwwwwb
bbbbbbb

As soon as we flip any tile (whether black or white), the game ends.


6)
6
7
{"bwbbbbb","bwbwwwb","eeeeeee","bwbbbwb","bwwwwwb","bbbbbbb"}

Returns: 3

The game board looks similar to the one in Example 5, except row 3 is now completely empty (the entire row's tiles are missing).

bwbbbbb
bwbwwwb
eeeeeee
bwbbbwb
bwwwwwb
bbbbbbb

In two turns, we can turn the first two rows of tiles to either black or white side up.

For the bottom three rows, in one turn we can flip one of the white tiles to have all of them black side up.

Overall in three turns we can flip all tiles to their black side up.

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

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] >= _size[rb]) { _parent[rb] = ra, _size[ra] += _size[rb]; } else { _parent[ra] = rb, _size[rb] += _size[ra]; }
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

class TileFlippingGame {
	set<int> g[400];

public:
	int HowManyMoves(int n, int m, vector <string> X) {
		UnionFind common(n*m), neighbor(n*m);
		const int dx[4] = { -1,1,0,0 };
		const int dy[4] = { 0,0,-1,1 };
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				g[i * m + j].clear();
				if (X[i][j] != 'e') {
					for (int d = 0; d < 4; ++d) {
						int r = i + dy[d], c = j + dx[d];
						if (r >= 0 && r < n && c >= 0 && c < m && X[r][c] == X[i][j]) {
							common.unite(i * m + j, r * m + c);
						}
					}
				}
			}
		}
		vector<int> nodes;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (X[i][j] != 'e') {
					int p = common.root(i * m + j);
					if (p == i * m + j) {
						nodes.push_back(p);
						for (int d = 0; d < 4; ++d) {
							int r = i + dy[d], c = j + dx[d];
							if (r >= 0 && r < n && c >= 0 && c < m && X[r][c] != 'e' && X[i][j] != X[r][c]) {
								int q = common.root(r * m + c);
								neighbor.unite(p, q);
								g[p].insert(q);
								g[q].insert(p);
							}
						}
					}
				}
			}
		}
		int gdist[2][400] = {};
		for (int node : nodes) {
			int vis[400] = {};
			vis[node] = 1;
			vector<int> q;
			for (int next : g[node]) {
				vis[next] = 1;
				q.push_back(next);
			}
			int dist = 0;
			while (q.size()) {
				++dist;
				vector<int> nq;
				for (int v : q) {
					for (int next : g[v]) {
						if (!vis[next]) {
							vis[next] = 1;
							nq.push_back(next);
						}
					}
				}
				q = nq;
			}
			bool white = X[node / m][node % m] == 'w';
			int nr = neighbor.root(node);
			gdist[white][nr] = max(gdist[white][nr], (dist + 1) / 2);
			gdist[!white][nr] = max(gdist[!white][nr], 1 + dist / 2);

			// b  0    bw   1 bwb 1 bwbw 2
			// b  1  bw  1   bwb  2
		}
		int cost[2] = {};
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < n * m; ++j) {
				if (neighbor.root(j) == j) {
					cost[i] += gdist[i][j];
				}
			}
		}
		return min(cost[0], cost[1]);
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
			int Arg0 = 3;
			int Arg1 = 3;
			string Arr2[] = {"bbb","eee","www"};
			int Arg3 = 1;

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, HowManyMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			string Arr2[] = {"bwe","wbw","ewb"};
			int Arg3 = 2;

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, HowManyMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			string Arr2[] = {"beww","beww","beww","wewe"};
			int Arg3 = 1;

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, HowManyMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 8;
			string Arr2[] = {"ewewbbbb","bwebewww"};
			int Arg3 = 3;

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, HowManyMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 5;
			string Arr2[] = {"bwebw","wbebb","eeeee","bbebb","bbebb"};
			int Arg3 = 3;

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, HowManyMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 7;
			string Arr2[] = {"bwbbbbb","bwbwwwb","bwbwewb","bwbbbwb","bwwwwwb","bbbbbbb"};
			int Arg3 = 1;

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, HowManyMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 7;
			string Arr2[] = {"bwbbbbb","bwbwwwb","eeeeeee","bwbbbwb","bwwwwwb","bbbbbbb"};
			int Arg3 = 3;

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, HowManyMoves(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TileFlippingGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
