// BEGIN CUT HERE
/*
SRM 703 Div1 Easy (250)

PROBLEM STATEMENT
You are given a vector <int> x with n elements.
Your task is to construct a directed acyclic graph that satisfies all the conditions listed below, or to determine that such a graph does not exist.
The graph must look as follows:

There are n vertices, numbered 0 through n-1.
There are no self-loops, and each pair of vertices is connected by at most one edge.
For each i, the number of vertices reachable from vertex i must be exactly x[i]. Note that each node is reachable from itself.

If there is no such graph exists, return {-1}. (That is, a vector <int> that contains a single element with the value -1.)

If there are multiple such graphs, you may choose any of them.
Suppose that the graph you chose contains the edges a[0] -> b[0], a[1] -> b[1], and so on.
Return the following vector <int>: {a[0], b[0], a[1], b[1], a[2], b[2], ...}.


DEFINITION
Class:DAGConstruction
Method:construct
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> construct(vector <int> x)


NOTES
-Given a directed graph, vertex y is reachable from vertex x if it is possible to travel from x to y by following a sequence of zero or more directed edges.


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-Each element in x will be between 1 and |x|, inclusive.


EXAMPLES

0)
{2, 1}

Returns: {0, 1 }

We are looking for a graph with two vertices.
Additionally, we should be able to reach both vertices from vertex 0 and just a single vertex from vertex 1.
The graph that contains the edge 0 -> 1 has this property.


1)
{1, 1}

Returns: { }

This time the graph should be 2 isolated vertices.


2)
{1, 3, 1}

Returns: {1, 0, 1, 2 }

Note that the directions of edges are unrelated to the vertex numbers.
In this example, the correct answer is the directed acyclic graph that contains the edges 1 -> 0 and 1 -> 2.


3)
{5,5,5,5,5}

Returns: {-1 }

This time we are supposed to return a graph with 5 vertices in which each vertex is reachable from each vertex.
This is only possible if the entire graph is strongly connected.
An acyclic graph on 5 vertices cannot possibly be strongly connected, so we should return {-1}.


4)
{4,2,2,1}

Returns: {0, 1, 0, 2, 1, 3, 2, 3 }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> IIVec;

class DAGConstruction {
public:
	vector <int> construct(vector <int> x) {
		IIVec v;
		for (int i = 0; i != x.size(); ++i) {
			v.push_back(II(x[i], i));
		}
		sort(v.begin(), v.end());
		vector <int> ans;
		for (int i = 0; i != v.size(); ++i) {
			if (v[i].first > (i + 1)) {
				ans.resize(1);
				ans[0] = -1;
				break;
			}
			for (int j = 0; j < (v[i].first - 1); ++j) {
				ans.push_back(v[i].second);
				ans.push_back(v[j].second);
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
			int Arr0[] = {2, 1};
			int Arr1[] = {0, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1};

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1;
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 3, 1};
			int Arr1[] = {1, 0, 1, 2 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,5,5,5,5};
			int Arr1[] = {-1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,2,2,1};
			int Arr1[] = {0, 1, 0, 2, 1, 3, 2, 3 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DAGConstruction ___test;
	___test.run_test(-1);
}
// END CUT HERE
