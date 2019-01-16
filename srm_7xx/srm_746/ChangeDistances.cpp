// BEGIN CUT HERE
/*
SRM 746 Div1 Easy (250)

PROBLEM STATEMENT

You are given an undirected graph G on n vertices, labeled 0 through n-1.
Find any undirected graph H on those n vertices such that such that for all pairs of vertices u != v, the distance between u and v in G is different from the distance between u and v in H.

More precisely, you are given the adjacency matrix of G in the vector <string> g: g[i][j] is '1' if there is an edge between vertices i and j, and it is '0' otherwise.
Return the adjacency matrix of your H in the same format.
It can be shown that there is always a solution. If there are multiple answers, you may return any of them.


DEFINITION
Class:ChangeDistances
Method:findGraph
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> findGraph(vector <string> g)


NOTES
-The distance between two vertices in a graph is the smallest number of edges one needs to traverse in order to get from one of them to the other. If there is no path between the two vertices, the distance is considered to be infinity.
-The returned vector <string> must be symmetric according to the main diagonal, and it must have '0's on the main diagonal.


CONSTRAINTS
-n will be between 1 and 50 elements, inclusive.
-g will have exactly n elements.
-Each element of g will have exactly n characters.
-Each character of each element of g will be either '0' or '1'. 
-For all u and v, g[u][v] = g[v][u].
-For all u, g[u][u] = 0.


EXAMPLES

0)
{"011","100","100"}

Returns: {"000", "001", "010" }

The graph G contains the edges 0-1 and 0-2. Thus, distG(0,1) = distG(0,2) = 1, and distG(1,2) = 2.

The graph H that corresponds to the return value shown above contains only the edge 1-2.
Thus, distH(0,1) = distH(0,2) = infinity and distH(1,2) = 1.


1)
{"000","000","000"}

Returns: {"011", "100", "100" }

The given graph G consists of three isolated vertices. All distances are infinite.

The return value describes the graph H that contains edges 0-1 and 0-2. In this graph all distances are finite, and therefore different from the corresponding distances in G.


2)
{"0100","1000","0001","0010"}

Returns: {"0011", "0010", "1100", "1000" }

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ChangeDistances {
public:
	vector <string> findGraph(vector <string> g) {
		vector <string> ans = g;
		int n = (int)g.size();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i != j) {
					ans[i][j] ^= 1;
				}
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"011","100","100"};
			string Arr1[] = {"000", "001", "010" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findGraph(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"000","000","000"};
			string Arr1[] = {"011", "100", "100" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findGraph(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0100","1000","0001","0010"};
			string Arr1[] = {"0011", "0010", "1100", "1000" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findGraph(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ChangeDistances ___test;
	___test.run_test(-1);
}
// END CUT HERE
