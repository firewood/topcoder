// BEGIN CUT HERE
/*
SRM 709 Div2 Medium (500)

PROBLEM STATEMENT
Hero has a simple undirected graph.
(Simple means that each edge connects two different vertices, and each pair of vertices is connected by at most one edge.)

A graph is considered pretty if it is a simple undirected graph in which each connected component contains an even number of edges.

You are given the adjacency matrix of Hero's graph as a vector <string> graph.
('Y' means that the two vertices are connected by an edge, 'N' means that they aren't.)

Change Hero's graph into a pretty graph by adding as few edges as possible.
Return the minimum number of edges you have to add, or -1 if Hero's graph cannot be changed into a pretty graph.

DEFINITION
Class:Permatchd2
Method:fix
Parameters:vector <string>
Returns:int
Method signature:int fix(vector <string> graph)


NOTES
-Don't forget that the graph you'll obtain after adding the edges must still be simple.


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-graph will contain exactly n elements.
-Each element in graph will contain exactly n characters.
-Each character in graph will be either 'N' or 'Y'.
-For all valid i graph[i][i] will be equal to 'N'.
-For all valid i, j graph[i][j] will be equal to graph[j][i].


EXAMPLES

0)
{"NYN",
 "YNN",
 "NNN"}

Returns: 1

This is the adjacency matrix of a simple graph on three vertices.
Two of the three vertices are connected by an edge.
Here, an optimal solution is to add one edge that will connect the remaining vertex to one of the other two.
The resulting graph is a simple graph with a single connected component.
The connected component contains two edges, which is an even number.


1)
{"NYY",
 "YNN",
 "YNN"}

Returns: 0


2)
{"NYY",
 "YNY",
 "YYN"}

Returns: -1


3)
{"NYYY",
 "YNYY",
 "YYNN",
 "YYNN"}

Returns: 1


4)
{"NYNNNN",
 "YNNNNN",
 "NNNYNN",
 "NNYNNN",
 "NNNNNY",
 "NNNNYN"}

Returns: 3


5)
{"N"}

Returns: 0

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	std::vector<int> _edges;
	UnionFind(int size) : _parent(size, -1), _size(size, 1), _edges(size) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] >= _size[rb]) {
			_parent[rb] = ra, _size[ra] += _size[rb], _edges[ra] += _edges[rb];
		} else {
			_parent[ra] = rb, _size[rb] += _size[ra], _edges[rb] += _edges[ra];
		}
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
	int &edges(int root) { return _edges[root]; }
};

class Permatchd2 {
public:
	int fix(vector <string> graph) {
		int N = (int)graph.size();
		UnionFind uf(N);
		int ans = 0, cnt = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				if (graph[i][j] == 'Y') {
					uf.unite(i, j);
					uf.edges(uf.root(i)) += 1;
					++cnt;
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			int root = uf.root(i);
			if (i == root) {
				ans += uf.edges(root) % 2;
			}
		}
		return (ans + cnt) <= ((N * (N - 1)) / 2) ? ans : -1;
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
			string Arr0[] = {"NYN",
 "YNN",
 "NNN"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, fix(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYY",
 "YNN",
 "YNN"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, fix(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYY",
 "YNY",
 "YYN"};
			int Arg1 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, fix(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYYY",
 "YNYY",
 "YYNN",
 "YYNN"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, fix(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYNNNN",
 "YNNNNN",
 "NNNYNN",
 "NNYNNN",
 "NNNNNY",
 "NNNNYN"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, fix(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"N"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, fix(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Permatchd2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
