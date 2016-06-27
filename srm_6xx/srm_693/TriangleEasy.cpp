// BEGIN CUT HERE
/*
SRM 693 Div2 Easy (250)

PROBLEM STATEMENT
You are given an undirected graph with n vertices numbered 0 through n-1.
For each valid i, there is an undirected edge connecting two different vertices x[i] and y[i].
No two edges connect the same pair of vertices.

A triangle is a set of three distinct vertices such that each pair of those vertices is connected by an edge.
Formally, three distinct vertices u,v,w are a triangle if the graph contains the edges (u,v), (v,w), and (w,u).

You are given the description of the graph: the int n and the vector <int>s x and y.
You are allowed to add edges to this graph.
You may add as many edges as you want, and each of them may connect any two vertices.
Your goal is to produce a graph that contains at least one triangle.
Compute and return the smallest number of edges you need to add.

DEFINITION
Class:TriangleEasy
Method:find
Parameters:int, vector <int>, vector <int>
Returns:int
Method signature:int find(int n, vector <int> x, vector <int> y)


CONSTRAINTS
-n will be between 3 and 50, inclusive.
-x will have between 0 and n*(n-1)/2 elements, inclusive.
-y will have the same number of elements as x.
-Each element of x and y will be between 0 and n-1, inclusive.
-For each valid i, x[i] != y[i].
-No two edges will connect the same pair of vertices.


EXAMPLES

0)
3
{}
{}

Returns: 3

The graph has three vertices but no edges. You need to add edges (0,1), (1,2), and (2,0) to make it a triangle.


1)
4
{0,2,1,2}
{3,0,2,3}

Returns: 0

Note that the edges are undirected. The graph already has a triangle: (2,0),(0,3),(2,3), so we don't have to add anything.


2)
6
{0,0,2}
{3,1,4}

Returns: 1


3)
4
{0,2}
{1,3}

Returns: 2


4)
20
{16,4,15,6,1,0,10,12,7,15,2,4,8,1,10,15,13,10,1,16,3,19,8,7,13,1,15,15,15,5,16,7,5,6,4,18,3,8,6,2,16,8,19,14,17,16,4,6,9,17,4,10,8,12,2,3,18,9,13,17,4,7,10,0,13,11,15,17,11,15,11,19,19,4,10,14,16,6,3,17,1,4,14,9,7,18,10,11,5,0,5,9,9,7,16,12,4,10,17,3}
{17,18,6,16,18,6,11,2,15,10,1,15,17,8,5,9,7,0,0,4,16,1,9,0,9,5,17,14,1,12,14,11,9,18,0,12,11,3,19,14,7,6,3,19,0,1,19,5,11,19,2,13,12,0,6,2,14,16,14,18,5,5,19,3,6,14,12,5,17,3,1,12,7,11,8,8,10,11,13,2,13,13,0,18,2,7,2,12,14,9,3,19,2,8,12,13,8,18,13,18}

Returns: 1

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

class TriangleEasy {
public:
	int find(int n, vector <int> x, vector <int> y) {
		int ans = 3;
		int c[64][64] = {};
		for (int i = 0; i != x.size(); ++i) {
			ans = 2;
			c[x[i]][y[i]] = 1;
			c[y[i]][x[i]] = 1;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				for (int k = j + 1;k < n;++k) {
					if (c[i][k] && c[j][k]) {
						ans = 1;
					}
					if (c[i][j]) {
						if (c[i][k] || c[j][k]) {
							ans = 1;
						}
						if (c[i][k] && c[j][k]) {
							return 0;
						}
					}
				}
			}
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
			int Arg0 = 3;
			// int Arr1[] = {};
			// int Arr2[] = {};
			int Arg3 = 3;

			vector <int> Arg1;
			vector <int> Arg2;
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {0,2,1,2};
			int Arr2[] = {3,0,2,3};
			int Arg3 = 0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arr1[] = {0,0,2};
			int Arr2[] = {3,1,4};
			int Arg3 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {0,2};
			int Arr2[] = {1,3};
			int Arg3 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arr1[] = {16,4,15,6,1,0,10,12,7,15,2,4,8,1,10,15,13,10,1,16,3,19,8,7,13,1,15,15,15,5,16,7,5,6,4,18,3,8,6,2,16,8,19,14,17,16,4,6,9,17,4,10,8,12,2,3,18,9,13,17,4,7,10,0,13,11,15,17,11,15,11,19,19,4,10,14,16,6,3,17,1,4,14,9,7,18,10,11,5,0,5,9,9,7,16,12,4,10,17,3};
			int Arr2[] = {17,18,6,16,18,6,11,2,15,10,1,15,17,8,5,9,7,0,0,4,16,1,9,0,9,5,17,14,1,12,14,11,9,18,0,12,11,3,19,14,7,6,3,19,0,1,19,5,11,19,2,13,12,0,6,2,14,16,14,18,5,5,19,3,6,14,12,5,17,3,1,12,7,11,8,8,10,11,13,2,13,13,0,18,2,7,2,12,14,9,3,19,2,8,12,13,8,18,13,18};
			int Arg3 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TriangleEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
