// BEGIN CUT HERE
/*
SRM 649 Div2 Easy (250)

PROBLEM STATEMENT
Filip the Frog lives on a number line. There are islands at some points on the number line. You are given the positions of these islands in the vector <int> positions.

Filip starts on the island located at positions[0]. His maximal jump length is L, which means that he can jump to any island that is within a distance of L (inclusive) from his current location. Filip can't jump to a point on the number line that doesn't contain an island. He can make an unlimited number of jumps.

An island is reachable if Filip can get to it through some sequence of jumps. Please find and return the number of reachable islands.


DEFINITION
Class:FilipTheFrog
Method:countReachableIslands
Parameters:vector <int>, int
Returns:int
Method signature:int countReachableIslands(vector <int> positions, int L)


NOTES
-If two islands are located at points A and B on the number line, then the distance between them is |A - B|.


CONSTRAINTS
-positions will contain between 1 and 50 elements, inclusive.
-Each element of positions will be between 0 and 1000, inclusive.
-The elements of positions will be distinct.
-L will be between 1 and 1000, inclusive.


EXAMPLES

0)
{4, 7, 1, 3, 5}
1

Returns: 3

Filip starts at position 4 and his maximal jump length is 1. He can reach the islands at positions 3, 4, and 5.


1)
{100, 101, 103, 105, 107}
2

Returns: 5

Here he can reach all 5 islands.


2)
{17, 10, 22, 14, 6, 1, 2, 3}
4

Returns: 7


3)
{0}
1000

Returns: 1

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
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

class FilipTheFrog {
public:
	int countReachableIslands(vector <int> positions, int L) {
		UnionFind uf(50);
		int N = (int)positions.size();
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				if (abs(positions[i] - positions[j]) <= L) {
					uf.unite(i, j);
				}
			}
		}
		return uf.size(0);
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
			int Arr0[] = {4, 7, 1, 3, 5};
			int Arg1 = 1;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, countReachableIslands(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, 101, 103, 105, 107};
			int Arg1 = 2;
			int Arg2 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, countReachableIslands(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {17, 10, 22, 14, 6, 1, 2, 3};
			int Arg1 = 4;
			int Arg2 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, countReachableIslands(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arg1 = 1000;
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, countReachableIslands(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FilipTheFrog ___test;
	___test.run_test(-1);
}
// END CUT HERE
