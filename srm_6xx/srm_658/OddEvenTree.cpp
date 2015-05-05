// BEGIN CUT HERE
/*
SRM 658 Div1 Easy (300)

PROBLEM STATEMENT
In a tree, the distance between two nodes is the number of edges on the (only) simple path that connects them.

You are given a vector <string> x with N elements, each containing N characters.
Draw a tree with N nodes, numbered 0 through N-1.
The tree must have the following properties:
For each i and j, if x[i][j] is 'E' the distance between i and j must be even, and if it is 'O' (uppercase o) this distance must be odd.

If there is no tree with these properties, return {-1}.
Otherwise, return a vector <int> with 2N-2 elements: the list of edges in one such tree.
For example, if N=3 and your tree contains the edges 0-2 and 1-2, return {0,2,1,2}.
If there are multiple correct outputs you may output any of them.


DEFINITION
Class:OddEvenTree
Method:getTree
Parameters:vector <string>
Returns:vector <int>
Method signature:vector <int> getTree(vector <string> x)


NOTES
-If you use plugins to test your solution, be careful. Plugins cannot tell you whether your solution is correct -- they'll just tell you whether it matches the example output exactly.


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-x will contain exactly n elements.
-Each element in x will have exactly n characters.
-Each character in x will be 'O' or 'E'.


EXAMPLES

0)
{"EOE",
 "OEO",
 "EOE"}

Returns: {0, 1, 2, 1 }

The tree: 0-1-2 is a valid answer.


1)
{"EO",
 "OE"}

Returns: {0, 1 }


2)
{"OO",
 "OE"}

Returns: {-1 }

dist[0][0] must be 0, and it should be an even number, so it is impossible.


3)
{"EO",
 "EE"}

Returns: {-1 }

dist[0][1] should be same with dist[1][0].


4)
{"EOEO",
 "OEOE",
 "EOEO",
 "OEOE"}

Returns: {0, 1, 0, 3, 2, 1 }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef vector<int> IntVec;

class OddEvenTree {

	vector <int> gt(const vector <string> &x) {
		int N = (int)x.size();
		int oa = -1, ob = -1, ec = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (i == j) {
					if (x[i][j] != 'E') {
						return IntVec();
					}
				} else {
					if (x[i][j] == 'O') {
						if (oa < 0) {
							oa = i, ob = j;
						}
					} else {
						++ec;
					}
					if ((x[0][i] == x[i][i]) != (x[0][j] == x[i][j])) {
						return IntVec();
					}
				}
			}
		}
		IntVec ans;
		ans.push_back(oa);
		ans.push_back(ob);
		if (oa < 0 || (N > 2 && ec <= 0)) {
			return IntVec();
		}
		int used[64] = {};
		used[oa] = 1, used[ob] = 1;
		for (int i = 0; i < N; ++i) {
			if (!used[i]) {
				if (x[0][oa] == x[0][i]) {
					ans.push_back(ob);
					ans.push_back(i);
				} else {
					ans.push_back(oa);
					ans.push_back(i);
				}
			}
		}
		return ans;
	}

public:
	vector <int> getTree(vector <string> x) {
		IntVec ans = gt(x);
		if (ans.empty()) {
			ans.push_back(-1);
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
			string Arr0[] = {"EOE",
 "OEO",
 "EOE"};
			int Arr1[] = {0, 1, 2, 1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getTree(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"EO",
 "OE"};
			int Arr1[] = {0, 1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getTree(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"OO",
 "OE"};
			int Arr1[] = {-1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getTree(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"EO",
 "EE"};
			int Arr1[] = {-1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getTree(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"EOEO",
 "OEOE",
 "EOEO",
 "OEOE"};
			int Arr1[] = {0, 1, 0, 3, 2, 1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getTree(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "EE",
				"EE" };
			int Arr1[] = { -1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getTree(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "EOO",
				"OEO",
				"OOE" };
			int Arr1[] = { -1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getTree(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OddEvenTree ___test;
	___test.run_test(-1);
}
// END CUT HERE
