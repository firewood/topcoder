// BEGIN CUT HERE
/*
SRM 627 Div1 Medium (500)

PROBLEM STATEMENT
You are given a connected undirected graph with N vertices.
The vertices are numbered 0 through N-1.
The graph is special: the number of edges is exactly equal to the number of vertices.
You are given the description of the graph as three vector <int>s: A, B, and V.
Each of these vector <int>s has N elements.
For each valid i, there's an edge between vertices A[i] and B[i].
There are no self-loops and no duplicate edges.
For each valid i, we associate the value V[i] with the vertex i.

We will be interested in some simple paths in this graph.
A simple path is a sequence of vertices such that no vertex is used twice, and each pair of consecutive vertices is connected by an edge.
For any simple path, we can write down a sequence of integers: the values associated with the vertices on the path, in order of appearance.
We will call such a sequence the value list of the given simple path.

An inversion in a sequence S is a pair of valid indices (i,j) into the sequence S such that i < j but S[i] > S[j].
For example, the sequence S = {10, 30, 20, 20} has two inversions: (1,2) and (1,3).
(The indices are 0-based.)

You are given a graph G in the format described above, and an int K.
In the graph G, consider all simple paths with K or more vertices.
If there is no such simple path, return -1.
Otherwise, return the smallest number of inversions in the value list of such path.


DEFINITION
Class:GraphInversions
Method:getMinimumInversions
Parameters:vector <int>, vector <int>, vector <int>, int
Returns:int
Method signature:int getMinimumInversions(vector <int> A, vector <int> B, vector <int> V, int K)


CONSTRAINTS
-N will be between 3 and 1000, inclusive.
-A, B, and V will each have N elements.
-Each element of A and B will be between 0 and N-1, inclusive.
-For all valid i, A[i] will not be equal to B[i]. (I.e., there are no self loops.)
-No two edges will connect the same pair of vertices.
-The graph described by A and B will be connected.
-Each element of V will be between 1 and 1000, inclusive.
-K will be between 1 and N, inclusive.


EXAMPLES

0)
{0,1,2}
{1,2,0}
{40,50,60}
3

Returns: 0

The best path is the path {0, 1, 2}. Its value list is the sequence {40, 50, 60}, and there are 0 inversions in this sequence.


1)
{0,1,2,3}
{1,2,3,0}
{60,40,50,30}
3

Returns: 1

As K=3, we are interested in simple paths of lengths 3 or more.
There are no simple paths of length 4 or more in this graph.
Each simple path of length 3 gives us at least one inversion.
The path {3, 2, 1} is an example of an optimal path.
Its value list is {30, 50, 40}.
There is 1 inversion: the 50 occurring before the 40.


2)
{0,1,2,3,0}
{1,2,3,0,4}
{10,10,10,5,5}
5

Returns: 1

Two or more nodes can have the same associated value.


3)
{0,1,2,3,0,2}
{1,2,3,0,4,5}
{10,2,5,3,7,1}
6

Returns: -1

There are no simple paths with length 6.


4)
{5,7,7,5,5,7,6,4}
{2,0,2,0,1,4,7,3}
{15,10,5,30,22,10,5,2}
6

Returns: 3

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<IntVec> IVV;

class BIT {
	std::vector<int> bit;
	int size;
public:
	BIT() { }
	BIT(int sz) { init(sz); }
	void init(int sz) {
		bit = std::vector<int>((size = sz) + 1);
	}
	int sum(int i) {
		++i;
		int s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int i, int x) {
		++i;
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

class GraphInversions {
	int n;
	IntVec vertex;
	IVV edge;
	int visited[1000];
	BIT bit;

	int dfs(int c, int k) {
		if (k <= 1) {
			return bit.sum(vertex[c]);
		}
		int res = 1e6;
		visited[c] = 1;
		bit.add(vertex[c]+1, 1);
		for (int v : edge[c]) {
			if (!visited[v]) {
				res = min(res, dfs(v, k - 1));
			}
		}
		bit.add(vertex[c]+1, -1);
		visited[c] = 0;
		return res + bit.sum(vertex[c]);
	}

public:
	int getMinimumInversions(vector <int> A, vector <int> B, vector <int> V, int K) {
		n = (int)A.size();
		edge = IVV(n);
		vertex = V;
		for (int i = 0; i < n; ++i) {
			edge[A[i]].push_back(B[i]);
			edge[B[i]].push_back(A[i]);
		}

		int ans = 1e6;
		for (int i = 0; i < n; ++i) {
			memset(visited, 0, sizeof(visited));
			bit.init(1024);
			ans = min(ans, dfs(i, K));
		}
		return (ans < 1e6) ? ans : -1;
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
			int Arr0[] = {0,1,2};
			int Arr1[] = {1,2,0};
			int Arr2[] = {40,50,60};
			int Arg3 = 3;
			int Arg4 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,2,3};
			int Arr1[] = {1,2,3,0};
			int Arr2[] = {60,40,50,30};
			int Arg3 = 3;
			int Arg4 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,2,3,0};
			int Arr1[] = {1,2,3,0,4};
			int Arr2[] = {10,10,10,5,5};
			int Arg3 = 5;
			int Arg4 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,2,3,0,2};
			int Arr1[] = {1,2,3,0,4,5};
			int Arr2[] = {10,2,5,3,7,1};
			int Arg3 = 6;
			int Arg4 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,7,7,5,5,7,6,4};
			int Arr1[] = {2,0,2,0,1,4,7,3};
			int Arr2[] = {15,10,5,30,22,10,5,2};
			int Arg3 = 6;
			int Arg4 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GraphInversions ___test;
	___test.run_test(-1);
}
// END CUT HERE
