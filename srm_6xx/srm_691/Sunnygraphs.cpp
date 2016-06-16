// BEGIN CUT HERE
/*
SRM 691 Div1 Easy (250)

PROBLEM STATEMENT
Hero has just constructed a very specific graph.
He started with n isolated vertices, labeled 0 through n-1.
For each vertex i Hero then chose a vertex a[i] (other than i) and he added an edge that connected i and a[i].
This way he created a graph with n vertices and n edges.
Note that if a[x]=y and a[y]=x, the vertices x and y were connected by two different edges.

Hero now wants to perform the following procedure:

Add a new isolated vertex number n.
Choose a subset M of the original vertices.
For each x in M, erase an edge between vertices x and a[x].
For each x in M, add a new edge between vertices x and n.

Hero's goal is to create a final graph in which the vertices 0 and 1 are in the same connected component.
(I.e., there is a path from one of them to the other.)

In step 2 of the above procedure Hero has 2^n possible subsets to choose from.
A choice of M is good if it produces a graph with the desired property.
Count how many of the 2^n possibilities are good choices.
Return that count as a long long.


DEFINITION
Class:Sunnygraphs
Method:count
Parameters:vector <int>
Returns:long long
Method signature:long long count(vector <int> a)


CONSTRAINTS
-a will contain n elements.
-n will be between 2 and 50, inclusive.
-Each element in a will be between 0 and n - 1, inclusive.
-For each i between 0 and n - 1 holds a[i] != i.


EXAMPLES

0)
{1,0}

Returns: 4

The original graph contained the vertices 0 and 1.
This pair of vertices was connected by two edges.

Next, Hero added a new vertex 2.
Then he had to choose one of four possible subsets M:

If he chose M = {}, the resulting graph contained the edges 0-1 and 0-1. The vertices 0 and 1 were connected.
If he chose M = {0}, the resulting graph contained the edges 0-1 and 0-2. The vertices 0 and 1 were connected.
If he chose M = {1}, the resulting graph contained the edges 0-1 and 1-2. The vertices 0 and 1 were connected.
Finally, if he chose M = {0, 1}, the resulting graph contained the edges 0-2 and 1-2. And again, the vertices 0 and 1 were connected: there is a path 0-1-2.

As all four choices of M are good, the correct answer is 4.


1)
{2,2,0}

Returns: 7

Here, the original graph contained the edges 0-2, 0-2, and 1-2.
For this graph M = {1} is not a good choice.
This choice produces a graph with edges 0-2, 0-2, and 1-3.
In this graph the vertices 0 and 1 are not in the same connected component.
The other seven possible choices of M are all good.


2)
{2,3,0,1}

Returns: 9


3)
{2,2,3,4,3}

Returns: 30


4)
{18,18,20,28,7,27,8,13,40,3,7,21,30,17,13,34,29,16,15,11,0,9,39,36,38,23,24,8,4,9,29,22,35,5,13,23,3,27,34,23,8}

Returns: 2198754820096

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;

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

class Sunnygraphs {
public:
	long long count(vector <int> a) {
		int N = (int)a.size();
		IntVec vis(N);
		for (int n = 0; (vis[n] & 1) == 0; n = a[n]) {
			vis[n] |= 1;
		}
		for (int n = 1; (vis[n] & 2) == 0; n = a[n]) {
			vis[n] |= 2;
		}
		LL w = 1LL << std::count(vis.begin(), vis.end(), 0);
		LL x = 1LL << std::count(vis.begin(), vis.end(), 1);
		LL y = 1LL << std::count(vis.begin(), vis.end(), 2);
		LL z = 1LL << std::count(vis.begin(), vis.end(), 3);
		LL ans = (x + y - 2) * (z - 1) + (x - 1) * (y - 1) * z;
		if (z > 1) {
			ans += z;
		}
		return ans * w;
	}

	long long count2(vector <int> a) {
		long long ans = 0;
		int sz = (int)a.size();
		if (sz <= 16) {
			int m = 1 << sz;
			for (int b = 0; b < m; ++b) {
				UnionFind uf(sz+1);
				for (int i = 0; i < sz; ++i) {
					if (b & (1 << i)) {
						uf.unite(i, sz);
					} else {
						uf.unite(i, a[i]);
					}
				}
				ans += uf.root(0) == uf.root(1);
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,0};
			long long Arg1 = 4LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,0};
			long long Arg1 = 7LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,3,0,1};
			long long Arg1 = 9LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,3,4,3};
			long long Arg1 = 30LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {18,18,20,28,7,27,8,13,40,3,7,21,30,17,13,34,29,16,15,11,0,9,39,36,38,23,24,8,4,9,29,22,35,5,13,23,3,27,34,23,8};
			long long Arg1 = 2198754820096LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Sunnygraphs ___test;
	___test.run_test(-1);

	for (int t = 0; t < 100; ++t) {
		int N = 8;
		IntVec v(N);
		for (int i = 0; i < N; ++i) {
			while (true) {
				v[i] = rand() % N;
				if (v[i] != i) {
					break;
				}
			}
		}
		LL p = ___test.count(v);
		LL q = ___test.count2(v);
		if (p != q) {
			printf("%lld, %lld\n", p, q);
			for (int i = 0; i < N; ++i) {
				printf(" %d", v[i]);
			}
			printf("\n");
			break;
		}
	}
}
// END CUT HERE
