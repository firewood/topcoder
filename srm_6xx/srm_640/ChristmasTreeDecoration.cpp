// BEGIN CUT HERE
/*
SRM 640 Div1 Easy (250)

PROBLEM STATEMENT
Christmas is just around the corner, and Alice just decorated her Christmas tree.
There are N stars on the tree.
The stars are numbered 1 through N.
Additionally, each star has some color.
You are given the colors of stars as a vector <int> col with N elements.
For each i, col[i] is the color of star i+1.
(Different integers represent different colors.)

Alice has prepared N-1 ribbons and she is now going to attach them to the tree.
Each ribbon will connect two of the stars.
The ribbons have to be placed in such a way that all stars and ribbons will hold together.
(In other words, in the resulting arrangement the stars and ribbons will correspond to vertices and edges of a tree.)

Only some pairs of stars can be connected by a ribbon.
You are given a list of all such pairs of stars in two vector <int>s: x and y.
For each valid i, it is possible to add a ribbon that connects the stars with numbers x[i] and y[i].

According to Alice, a ribbon that connects two stars that share the same color is less beautiful than a ribbon that connects two stars with different colors.
Therefore, she would like to minimize the number of ribbons that connect two same-colored stars.
Compute and return the smallest possible number of such ribbons.


DEFINITION
Class:ChristmasTreeDecoration
Method:solve
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int solve(vector <int> col, vector <int> x, vector <int> y)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-The number of elements in col will be N exactly.
-The number of elements in x will be between 1 and 200, inclusive.
-The number of elements in y will be the same as the number of elements in x.
-All elements of x and y will be between 1 and N, inclusive.
-For each i, the numbers x[i] and y[i] will be different.
-All unordered pairs (x[i], y[i]) will be distinct.
-There will be at least one way to choose N-1 ribbons that form a connected graph.


EXAMPLES

0)
{1,1,2,2}
{1,2,3,4}
{2,3,4,1}

Returns: 1

We have four stars. Stars 1 and 2 have the same color, and stars 3 a 4 have the same color.
There are four pairs of stars we may connect: 1-2, 2-3, 3-4, and 4-1.
One optimal solution is to use the following ribbons: 2-3, 3-4, and 4-1.
Two of these are beautiful (2-3 and 4-1) and only one (3-4) is not beautiful.


1)
{1,1,2,2}
{1,2,3,4,1,2}
{2,3,4,1,3,4}

Returns: 0

Now we can have three beautiful ribbons.


2)
{50,50,50,50}
{1,2,3,1,1,2}
{2,3,4,4,3,4}

Returns: 3

All stars have the same color. Regardless of how we attach the ribbons, none of them will be beautiful.


3)
{1,4,2,3}
{1,2,3}
{2,3,4}

Returns: 0


4)
{1,1,1,2,2,2,3,3,3,4,4,4}
{1,2,3,4,5,6,7,8,9,10,11,12,1,1,1,1,1,1}
{2,3,1,5,6,4,8,9,7,11,12,10,5,7,12,11,6,4}

Returns: 5

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

typedef set<int> IntSet;

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

class ChristmasTreeDecoration {

public:
	int solve(vector <int> col, vector <int> x, vector <int> y) {
		int N = (int)col.size();
		int V = (int)x.size();
		UnionFind uf(N);
		for (int i = 0; i < V; ++i) {
			if (col[x[i] - 1] != col[y[i] - 1]) {
				uf.unite(x[i] - 1, y[i] - 1);
			}
		}
		IntSet s;
		for (int i = 0; i < N; ++i) {
			if (uf.root(i) == i) {
				s.insert(i);
			}
		}
		return (int)s.size() - 1;
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
			int Arr0[] = {1,1,2,2};
			int Arr1[] = {1,2,3,4};
			int Arr2[] = {2,3,4,1};
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,2,2};
			int Arr1[] = {1,2,3,4,1,2};
			int Arr2[] = {2,3,4,1,3,4};
			int Arg3 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50,50,50,50};
			int Arr1[] = {1,2,3,1,1,2};
			int Arr2[] = {2,3,4,4,3,4};
			int Arg3 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,4,2,3};
			int Arr1[] = {1,2,3};
			int Arr2[] = {2,3,4};
			int Arg3 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,2,2,2,3,3,3,4,4,4};
			int Arr1[] = {1,2,3,4,5,6,7,8,9,10,11,12,1,1,1,1,1,1};
			int Arr2[] = {2,3,1,5,6,4,8,9,7,11,12,10,5,7,12,11,6,4};
			int Arg3 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ChristmasTreeDecoration ___test;
	___test.run_test(-1);
}
// END CUT HERE
