// BEGIN CUT HERE
/*
SRM 618 Div1 Easy (250)


PROBLEM STATEMENT
A directed acyclic graph is a family graph if the following constraints are all satisfied:

The nodes of the graph are numbered 0 through N-1, for some positive N.
Each node is either male or female.
Each node either has no parents, or it has precisely two parents. (A parent of the node x is a node y such that there is an edge from y to x.)
If a node has parents, their numbers are strictly smaller than the number of the node.
If a node has parents, one of them must be male and the other female.

You are given two vector <int>s parent1 and parent2 with N elements each.
These describe one directed graph that resembles a family graph:
For each i, node i has either two parents (in which case parent1[i] and parent2[i] are their numbers, and both of them are smaller than i), or it has no parents (in which case parent1[i] and parent2[i] are both -1).

Return "Possible" (quotes for clarity) if the given graph can be a family graph, and "Impossible" otherwise.


DEFINITION
Class:Family
Method:isFamily
Parameters:vector <int>, vector <int>
Returns:string
Method signature:string isFamily(vector <int> parent1, vector <int> parent2)


CONSTRAINTS
-parent1 will contain between 1 and 100 elements, inclusive.
-parent1 and parent2 will contain the same number of elements.
-For each i, the i-th element (0-based) of parent1 will be between -1 and i-1, inclusive.
-For each i, the i-th element (0-based) of parent2 will be between -1 and i-1, inclusive.
-For each i, the i-th element of parent1 will be -1 if and only if the i-th element of parent2 is -1.
-For each i, if the i-th element of parent1 is not -1, then the i-th element of parent1 and the i-th element of parent2 will be different.


EXAMPLES

0)
{-1,-1,0}
{-1,-1,1}

Returns: "Possible"

The parents of node 2 are nodes 0 and 1. Nodes 0 and 1 have no parents.


1)
{-1,-1,-1,-1,-1}
{-1,-1,-1,-1,-1}

Returns: "Possible"

Nobody has any parents.


2)
{-1,-1,0,0,1}
{-1,-1,1,2,2}

Returns: "Impossible"

Given that 0 and 1 have a child, their genders must be different. Given that 0 and 2 have a child, their genders must be different, too. Then, 1 and 2 must have the same gender, hence they cannot have a child together. Therefore, this cannot be a valid family graph.


3)
{-1,-1,-1,-1,1,-1,0,5,6,-1,0,3,8,6}

{-1,-1,-1,-1,3,-1,4,6,5,-1,5,4,6,1}


Returns: "Possible"


4)
{-1,-1,-1,2,2,-1,5,6,4,6,2,1,8,0,2,4,6,9,-1,16,-1,11}
{-1,-1,-1,1,0,-1,1,4,2,0,4,8,2,3,0,5,14,14,-1,7,-1,13}

Returns: "Impossible"

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b);
		if (ra == rb)
			return;
		if (_size[ra] >= _size[rb]) {
			_parent[rb] = ra, _size[ra] += _size[rb];
		} else {
			_parent[ra] = rb, _size[rb] += _size[ra];
		}
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0)
			return a;
		while (_parent[p] >= 0)
			p = _parent[p];
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

class Family {
public:
	string isFamily(vector <int> parent1, vector <int> parent2) {
		UnionFind same(100);
		int N = (int)parent1.size();
		for (int i = 0; i < N; ++i) {
			if (parent1[i] >= 0) {
				for (int j = 0; j < N; ++j) {
					if (parent1[i] == parent1[j]) {
						same.unite(parent2[i], parent2[j]);
					}
					if (parent1[i] == parent2[j]) {
						same.unite(parent2[i], parent1[j]);
					}
					if (parent2[i] == parent1[j]) {
						same.unite(parent1[i], parent2[j]);
					}
					if (parent2[i] == parent2[j]) {
						same.unite(parent1[i], parent1[j]);
					}
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			if (parent1[i] >= 0) {
				if (same.root(parent1[i]) == same.root(parent2[i])) {
					return "Impossible";
				}
			}
		}
		return "Possible";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,-1,0};
			int Arr1[] = {-1,-1,1};
			string Arg2 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isFamily(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,-1,-1,-1,-1};
			int Arr1[] = {-1,-1,-1,-1,-1};
			string Arg2 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isFamily(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,-1,0,0,1};
			int Arr1[] = {-1,-1,1,2,2};
			string Arg2 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isFamily(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,-1,-1,-1,1,-1,0,5,6,-1,0,3,8,6}
;
			int Arr1[] = {-1,-1,-1,-1,3,-1,4,6,5,-1,5,4,6,1}
;
			string Arg2 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isFamily(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,-1,-1,2,2,-1,5,6,4,6,2,1,8,0,2,4,6,9,-1,16,-1,11};
			int Arr1[] = {-1,-1,-1,1,0,-1,1,4,2,0,4,8,2,3,0,5,14,14,-1,7,-1,13};
			string Arg2 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, isFamily(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Family ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
