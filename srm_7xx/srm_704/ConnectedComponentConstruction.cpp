// BEGIN CUT HERE
/*
SRM 704 Div2 Medium (500)

PROBLEM STATEMENT
Any undirected graph can be decomposed into connected components.
Two vertices u and v belong to the same connected component if we can travel from u to v by following a sequence of zero or more consecutive edges.
The size of a connected component is the number of vertices it contains.

You are given a vector <int> s.
Construct a simple undirected graph with the following properties:

The number of vertices is n, where n is the number of elements in s.
The vertices are numbered 0 through n-1.
For each i, the size of the connected component that contains vertex i is exactly s[i].

If there is no such graph, return an empty vector <string>.
Otherwise, return a vector <string> ret with n elements, each containing n characters.
For each i and j, ret[i][j] should be 'Y' if there is an edge between i and j in your graph.
Otherwise, ret[i][j] should be 'N'.
If there are multiple solutions, you may return any of them.


DEFINITION
Class:ConnectedComponentConstruction
Method:construct
Parameters:vector <int>
Returns:vector <string>
Method signature:vector <string> construct(vector <int> s)


CONSTRAINTS
-s will contain between 1 and 50 elements, inclusive.
-Each element in s will be between 1 and |s|, inclusive.


EXAMPLES

0)
{2,1,1,2,1}

Returns: {"NNNYN", "NNNNN", "NNNNN", "YNNNN", "NNNNN" }

The answer is a graph that contains only one edge.
This edge connects the vertices 0 and 3.
This graph has four connected components: {0, 3}, {1}, {2}, and {4}.


1)
{1,1,1,1}

Returns: {"NNNN", "NNNN", "NNNN", "NNNN" }

Here the only correct answer is a graph with four vertices and no edges.


2)
{3,3,3}

Returns: {"NYY", "YNY", "YYN" }

This time one correct answer could be the complete graph on three vertices.


3)
{4,4,4,4,4}

Returns: { }

There is no solution.


4)
{1}

Returns: {"N" }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ConnectedComponentConstruction {
public:
	vector <string> construct(vector <int> s) {
		int N = (int)s.size();
		vector <string> ans(N);
		for (int i = 0; i < N; ++i) {
			ans[i] = string(N, 'N');
		}
		vector<int> group[64];
		int root[64];
		for (int i = 0; i < N; ++i) {
			root[i] = i;
			for (int j = 0; j <= i; ++j) {
				int r = root[j];
				if (s[r] == s[i] && group[r].size() < s[r]) {
					for (int n : group[r]) {
						ans[n][i] = 'Y';
						ans[i][n] = 'Y';
					}
					group[r].push_back(i);
					root[i] = r;
					break;
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			if (group[root[i]].size() != s[i]) {
				return vector<string>();
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
			int Arr0[] = {2,1,1,2,1};
			string Arr1[] = {"NNNYN", "NNNNN", "NNNNN", "YNNNN", "NNNNN" };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1};
			string Arr1[] = {"NNNN", "NNNN", "NNNN", "NNNN" };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,3,3};
			string Arr1[] = {"NYY", "YNY", "YYN" };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,4,4,4,4};

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1;
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			string Arr1[] = {"N" };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5 };
			string Arr1[] = { "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNYNNNNNNNNNNNNNNNNNNNN", "NNNNNYNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNYNNNNNNNNNNNNNNNNNN", "NNNNNNNYNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNYNNNNNNNNNNNNNNNN", "NNNNNNNNNYNYNNNNNNNNNNNNNNN", "NNNNNNNNNNYNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNYNNNNNNNNNNNNN", "NNNNNNNNNNNNYNYNNNNNNNNNNNN", "NNNNNNNNNNNNNYNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNYNNNNNNNNNN", "NNNNNNNNNNNNNNNYNYNNNNNNNNN", "NNNNNNNNNNNNNNNNYNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNYNNNNNNN", "NNNNNNNNNNNNNNNNNNYNYNNNNNN", "NNNNNNNNNNNNNNNNNNNYNYNNNNN", "NNNNNNNNNNNNNNNNNNNNYNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNYNNN", "NNNNNNNNNNNNNNNNNNNNNNYNYNN", "NNNNNNNNNNNNNNNNNNNNNNNYNYN", "NNNNNNNNNNNNNNNNNNNNNNNNYNY", "NNNNNNNNNNNNNNNNNNNNNNNNNYN" };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ConnectedComponentConstruction ___test;
	___test.run_test(-1);
}
// END CUT HERE
