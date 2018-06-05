// BEGIN CUT HERE
/*
TCO18 R1A Medium (500)

PROBLEM STATEMENT
A simple graph is an undirected graph in which each edge connects two different vertices and each pair of vertices is connected by at most one edge.
In other words, there are no self-loops and no multiple edges.

A 2-regular graph is a simple graph such that the degree of each vertex is 2.

You are given the int n and two vector <int>s x and y.
These variables describe a simple graph G on n vertices, labeled 0 through n-1.
For each valid i, the graph G contains an edge that connects the vertices x[i] and y[i].
It is guaranteed that each vertex in G has degree 2 or less.

You want to change G into a 2-regular graph by adding some edges.
Determine whether this can be done, and if yes, find the lexicographically smallest way of doing so.
A more precise definition of the task follows.

An encoding of a set of k edges is any vector <int> E of length 2k such that the set of edges is equal to the set { (E[0], E[1]), (E[2], E[3]), ... }.
For example, suppose you have the edges (1,7) and (2,5).
Then {1,7,5,2} and {2,5,1,7} are two of the valid encodings.
On the other hand, {1,2,5,7} is not a valid encoding.

If changing G into a 2-regular graph is impossible, return the vector <int> {-1}, i.e., an array that contains only one integer, -1.
Otherwise, find and return the lexicographically smallest encoding of a set of edges that should be added to G in order to make it 2-regular.


DEFINITION
Class:MakingRegularGraph
Method:addEdges
Parameters:int, vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> addEdges(int n, vector <int> x, vector <int> y)


NOTES
-Given two different vector <int>s S and T with the same number of elements, the lexicographically smaller one is the one that has a smaller element at the first index at which they differ.


CONSTRAINTS
-n will be between 1 and 1,000, inclusive.
-x will contain between 0 and n-1 elements, inclusive.
-y will contain the same number of elements as x.
-Each element of x will be between 0 and n-2, inclusive.
-Each element of y will be between 1 and n-1, inclusive.
-x[i] < y[i] will hold for all i (i.e., no self-loops).
-In a graph described by n, x, and y, every vertex will have degree 2 or less (For every integer v between 0 and n-1, v appears at most twice in x and y combined).
-In a graph described by n, x, and y, there will be at most one edge between a pair of vertices (two equalities (x[i] = x[j] and y[i] = y[j]) will hold only when i = j).


EXAMPLES

0)
6
{0,2}
{2,3}

Returns: {0, 1, 1, 4, 3, 5, 4, 5 }

There are many ways to turn this G into a 2-regular graph. For example, you may:

add the edges (3, 4), (4, 5), (5, 1), (1, 0) to obtain one large cycle of length 6
add the edges (3, 5), (5, 4), (4, 1), (1, 0) to obtain another cycle of length 6
add the edges (0, 3), (1, 4), (4, 5), (1, 5) to obtain two cycles of length 3 each
...

Each of these options has multiple encodings.
The return value shown above is the lexicographically smallest out of all encodings of all options.
It corresponds to the second set of edges listed above.


1)
4
{1,2,1}
{2,3,3}

Returns: {-1 }

The given graph contains a cycle of length 3 and an isolated vertex.
Unfortunately, we cannot turn this into a 2-reguglar graph.


2)
3
{}
{}

Returns: {0, 1, 0, 2, 1, 2 }

x and y can be empty, meaning there are no edges present.
In this example, there is a unique set of edges we can add in order to create a 2-regular graph: (0, 1), (0, 2), and (1, 2).
However, there exist many different ways to describe these three edges. 
For instance, both {0, 1, 2, 0, 2, 1} and {0, 1, 0, 2, 1, 2} describe the same set of edges.
Recall that you must return the one that comes lexicographically first. 


3)
5
{0}
{4}

Returns: {0, 1, 1, 2, 2, 3, 3, 4 }


4)
5
{2}
{3}

Returns: {0, 1, 0, 2, 1, 4, 3, 4 }

*/
// END CUT HERE

#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>

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


class MakingRegularGraph { 
public: 
  vector <int> addEdges(int n, vector <int> x, vector <int> y) { 
    int rv = n; 
    vector<int> e[1000]; 
    int u[1000] = {}; 
    UnionFind uf(n); 
    for (int i = 0; i != x.size(); ++i) { 
      e[x[i]].push_back(y[i]); 
      e[y[i]].push_back(x[i]); 
      bool same = uf.root(x[i]) == uf.root(y[i]); 
      uf.unite(x[i], y[i]); 
      if (same) { 
        int r = uf.root(x[i]); 
        for (int i = 0; i < n; ++i) { 
          if (uf.root(i) == r) { 
            --rv; 
            u[i] = 1; 
          } 
        } 
      } 
    } 
    if (rv == 0) { 
      return vector <int>(); 
    } 
    if (rv < 3) { 
      return { -1 }; 
    } 
    vector <int> ans; 
    while (rv > 0) { 
      bool done = false; 
      for (int i = 0; !done && i < n; ++i) { 
        if (e[i].size() < 2) { 
          for (int j = 0; j < n; ++j) { 
            if (i == j || e[j].size() >= 2 || u[j]) { 
              continue; 
            } 
            bool same = uf.root(i) == uf.root(j); 
            if (same) { 
              int sz = uf.size(i); 
              if (sz == 2 || ((rv - sz) > 0 && (rv - sz) < 3)) { 
                continue; 
              } 
            } 
            uf.unite(i, j); 
            e[i].push_back(j); 
            e[j].push_back(i); 
            ans.push_back(i); 
            ans.push_back(j); 
            if (same) { 
              int r = uf.root(i); 
              for (int k = 0; k < n; ++k) { 
                if (uf.root(k) == r) { 
                  --rv; 
                  u[k] = 1; 
                } 
              } 
            } 
            done = true; 
            break; 
          } 
        } 
      } 
    } 
    return ans; 
  } 

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arr1[] = {0,2};
			int Arr2[] = {2,3};
			int Arr3[] = {0, 1, 1, 4, 3, 5, 4, 5 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addEdges(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {1,2,1};
			int Arr2[] = {2,3,3};
			int Arr3[] = {-1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addEdges(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			// int Arr1[] = {};
			// int Arr2[] = {};
			int Arr3[] = {0, 1, 0, 2, 1, 2 };

			vector <int> Arg1;
			vector <int> Arg2;
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addEdges(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {0};
			int Arr2[] = {4};
			int Arr3[] = {0, 1, 1, 2, 2, 3, 3, 4 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addEdges(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {2};
			int Arr2[] = {3};
			int Arr3[] = {0, 1, 0, 2, 1, 4, 3, 4 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addEdges(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  MakingRegularGraph ___test;
  ___test.run_test(-1);
}
// END CUT HERE
