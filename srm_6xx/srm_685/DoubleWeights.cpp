// BEGIN CUT HERE
/*
SRM 685 Div2 Medium (500)

PROBLEM STATEMENT
We have a simple undirected graph G with n nodes, labeled 0 through n-1.
Each edge of this graph has two weights.
You are given the description of G encoded into vector <string>s weight1 and weight2.
If nodes i and j are connected by an edge, both weight1[i][j] and weight2[i][j] are nonzero digits ('1'-'9'), and these represent the two weights of this edge.
Otherwise, both weight1[i][j] and weight2[i][j] are periods ('.').

Your task is to find the cheapest path from node 0 to node 1.
The cost of a path is calculated as (W1 * W2), where W1 is the sum of all first weights and W2 is the sum of all second weights of the edges on your path.
Return the smallest possible cost of a path from node 0 to node 1.
If there is no such path, return -1 instead.


DEFINITION
Class:DoubleWeights
Method:minimalCost
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int minimalCost(vector <string> weight1, vector <string> weight2)


CONSTRAINTS
-n will be between 2 and 20, inclusive.
-weight1 and weight2 will contain exactly n elements, each.
-Each element in weight1 and weight2 will contain exactly n characters.
-Each character in weight1 and weight2 will be '.' or '1' - '9'.
-For each i, weight1[i][i] = weight2[i][i] = '.'.
-For each i and j, weight1[i][j] = weight1[j][i].
-For each i and j, weight2[i][j] = weight2[j][i].
-weight1[i][j] = '.' if and only if weight2[i][j] = '.'.


EXAMPLES

0)
{"..14",
 "..94",
 "19..",
 "44.."}
{"..94",
 "..14",
 "91..",
 "44.."}

Returns: 64

The best path is 0 -> 3 -> 1.
The cost of this path is (4+4) * (4+4) = 64.

Note that the other possible path (0 -> 2 -> 1) is more expensive.
Its cost is (1+9) * (9+1) = 100.


1)
{"..14",
 "..14",
 "11..",
 "44.."}
{"..94",
 "..94",
 "99..",
 "44.."}

Returns: 36

This time the best path is 0->2->1, the cost is (1+1) * (9+9) = 36.


2)
{"..",
 ".."}
{"..",
 ".."}

Returns: -1

There is no path between node 0 and node 1, so you should return -1.


3)
{".....9",
 "..9...",
 ".9.9..",
 "..9.9.",
 "...9.9",
 "9...9."}
{".....9",
 "..9...",
 ".9.9..",
 "..9.9.",
 "...9.9",
 "9...9."}

Returns: 2025


4)
{".4...1",
 "4.1...",
 ".1.1..",
 "..1.1.",
 "...1.1",
 "1...1."}
{".4...1",
 "4.1...",
 ".1.1..",
 "..1.1.",
 "...1.1",
 "1...1."}

Returns: 16

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, int> II;
typedef pair<II, II> IIII;
typedef vector<string> StrVec;

class DoubleWeights {

public:
	int minimalCost(vector <string> weight1, vector <string> weight2) {
		int N = (int)weight1.size();
		int mx[2][20];
		memset(mx, 0x3f, sizeof(mx));
		mx[0][0] = 0, mx[1][0] = 0;
		priority_queue<IIII> Queue;
		Queue.push(IIII(II(0, 0), II(0, 0)));
		unsigned int ans = -1;
		while (Queue.size() > 0) {
			IIII top = Queue.top();
			Queue.pop();
			int n = top.first.second;
			int first = top.second.first;
			int second = top.second.second;
			for (int i = 0; i < N; ++i) {
				if (weight1[n][i] != '.') {
					int a = first + weight1[n][i] - '0';
					int b = second + weight2[n][i] - '0';
					 int nc = a * b;
					if (i == 1) {
						ans = min(ans, (unsigned int)nc);
					} else if (a <= mx[0][i] || b <= mx[1][i]) {
						mx[0][i] = min(mx[0][i], a);
						mx[1][i] = min(mx[1][i], b);
						Queue.push(IIII(II(-nc, i), II(a, b)));
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
			string Arr0[] = {"..14",
 "..94",
 "19..",
 "44.."};
			string Arr1[] = {"..94",
 "..14",
 "91..",
 "44.."};
			int Arg2 = 64;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalCost(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..14",
 "..14",
 "11..",
 "44.."};
			string Arr1[] = {"..94",
 "..94",
 "99..",
 "44.."};
			int Arg2 = 36;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalCost(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..",
 ".."};
			string Arr1[] = {"..",
 ".."};
			int Arg2 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalCost(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".....9",
 "..9...",
 ".9.9..",
 "..9.9.",
 "...9.9",
 "9...9."};
			string Arr1[] = {".....9",
 "..9...",
 ".9.9..",
 "..9.9.",
 "...9.9",
 "9...9."};
			int Arg2 = 2025;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalCost(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".4...1",
 "4.1...",
 ".1.1..",
 "..1.1.",
 "...1.1",
 "1...1."};
			string Arr1[] = {".4...1",
 "4.1...",
 ".1.1..",
 "..1.1.",
 "...1.1",
 "1...1."};
			int Arg2 = 16;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimalCost(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DoubleWeights ___test;
	___test.run_test(-1);
}
// END CUT HERE
