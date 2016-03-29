// BEGIN CUT HERE
/*
SRM 686 Div2 Easy (250)

PROBLEM STATEMENT

A tree is an object that consists of some locations and some connections. 
The locations are called vertices and the connections between vertices are called edges.  
Each edge connects some pair of vertices.  
The number of vertices is always one greater than the number of edges.  
The entire tree is connected: the edges connect the vertices in such a way that one can walk from any vertex to any other vertex by following a sequence of edges.

You are given the description of a tree with n+1 vertices and n edges: a vector <int> tree with n elements.
The vertices of our tree are numbered 0 through n.
For each i between 0 and n-1, inclusive, there is an edge between vertices i+1 and tree[i].
(The constraints guarantee that these edges always form a valid tree.)

You are now going to destroy the tree by removing one of its vertices (and all edges that go from that vertex to some other vertex).
When you do so, the tree may sometimes fall apart: there will be more than one connected component.

Compute and return the largest number of components you can get by removing a single vertex of your tree.


DEFINITION
Class:TreeAndVertex
Method:get
Parameters:vector <int>
Returns:int
Method signature:int get(vector <int> tree)


NOTES
-The number n is not given explicitly. Instead, you can determine it as the number of elements in tree.


CONSTRAINTS
-tree will contain between 1 and 99 elements, inclusive.
-For each valid i tree[i] will be between 0 and i, inclusive.


EXAMPLES

0)
{0,0,0}

Returns: 3

Here are four vertices and three edges 0-1, 0-2, 0-3. One can remove vertex 0 and get three connected components.


1)
{0, 1, 2, 3}

Returns: 2

Here are five vertices and four edges 0-1, 1-2, 2-3, 3-4. One can remove any vertex, except 0 and 4, to get two connected components.


2)
{0, 0, 2, 2}

Returns: 3


3)
{0, 0, 0, 1, 1, 1}

Returns: 4


4)
{0, 1, 2, 0, 1, 5, 6, 1, 7, 4, 2, 5, 5, 8, 6, 2, 14, 12, 18, 10, 0, 6, 18, 2, 20, 11, 0, 11, 7, 12, 17, 3, 18, 31, 14, 34, 30, 11, 9}

Returns: 5

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class TreeAndVertex {
public:
	int get(vector <int> tree) {
		int ans = 1;
		int cnt[100] = {};
		for (int p : tree) {
			cnt[p] += 1;
			ans = max(ans, cnt[p] + (p > 0));
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
			int Arr0[] = {0,0,0};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 1, 2, 3};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 2, 2};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 1, 1, 1};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 1, 2, 0, 1, 5, 6, 1, 7, 4, 2, 5, 5, 8, 6, 2, 14, 12, 18, 10, 0, 6, 18, 2, 20, 11, 0, 11, 7, 12, 17, 3, 18, 31, 14, 34, 30, 11, 9};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TreeAndVertex ___test;
	___test.run_test(-1);
}
// END CUT HERE
