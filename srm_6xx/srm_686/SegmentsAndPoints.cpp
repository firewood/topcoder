// BEGIN CUT HERE
/*
SRM 686 Div2 Medium (500)

PROBLEM STATEMENT

You are given n points (i.e., values on the real axis) and n segments (i.e., intervals on the real axis).
You are given their description: vector <int>s p, l, and r with n elements each.
For each valid i, there is a point at p[i].
For each valid i, there is a segment that starts at l[i] and ends at r[i].
Each segments contains both its endpoints and all points between them.

Note that multiple points may share the same location.
Also note that some segments may have zero length: if l[i] = r[i], the segment consists of a single point.

You want to pair the points to the segments in such a way that each segment will contain the point it's paired to.
Return "Possible" (quotes for clarity) if the given points can be paired to the given segments.
Otherwise, return "Impossible".


DEFINITION
Class:SegmentsAndPoints
Method:isPossible
Parameters:vector <int>, vector <int>, vector <int>
Returns:string
Method signature:string isPossible(vector <int> p, vector <int> l, vector <int> r)


CONSTRAINTS
-p, l and r will contain the same number of elements.
-p will contain between 1 and 100 elements, inclusive.
-l[i] will be not greater that r[i] for each valid i.
-Each element of p, l and r will be between -500 and 500, inclusive.


EXAMPLES

0)
{1, 2}
{0, 0}
{1, 3}

Returns: "Possible"

There are two points: one at 1 and the other at 2.
There are two segments: [0,1] and [0,3].
We can pair the points to the segments in the given order: 1 lies in [0,1] and 2 lies in [0,3].


1)
{0}
{2}
{3}

Returns: "Impossible"

The point 0 does not lie in [2,3].


2)
{0, 1, 2}
{0, 0, 1}
{1, 2, 1}

Returns: "Possible"

Here, note that the point that lies at 1 must be assigned to the segment [1,1].


3)
{0, 1}
{-1, 0}
{0, 0}

Returns: "Impossible"


4)
{434, 63, 241, 418, -380, -46, 397, -205, -262, -282, 260, -106, -389, -286, 422, -75, 127, 382, 52, -383}
{-447, -226, -411, 287, -83, -228, -390, 358, 422, 395, -461, -112, 49, 75, -160, -152, 372, -447, -337, -362}
{-102, 348, -70, 466, 168, -61, -389, 469, 433, 471, -75, -41, 52, 236, 299, -48, 383, -353, 346, -217}

Returns: "Possible"

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

class SegmentsAndPoints {

	IntVec G[200];
	int match[200];
	bool used[200];

	void add_edge(int u, int v) {
		G[u].push_back(v);
		G[v].push_back(u);
	}

	bool dfs(int v) {
		used[v] = true;
		int i;
		for (i = 0; i < (int)G[v].size(); ++i) {
			int u = G[v][i];
			int w = match[u];
			if (w < 0 || (!used[w] && dfs(w))) {
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
		return false;
	}

public:
	string isPossible(vector <int> p, vector <int> l, vector <int> r) {
		int N = (int)p.size();
		for (int i = 0; i != sizeof(G)/sizeof(G[0]); ++i) {
			G[i].clear();
		}
		memset(match, -1, sizeof(match));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (p[i] >= l[j] && p[i] <= r[j]) {
					add_edge(i, 100 + j);
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			if (match[i] < 0) {
				memset(used, 0, sizeof(used));
				cnt += dfs(i);
			}
		}
		return cnt >= N ? "Possible" : "Impossible";
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
			int Arr0[] = {1, 2};
			int Arr1[] = {0, 0};
			int Arr2[] = {1, 3};
			string Arg3 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, isPossible(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arr1[] = {2};
			int Arr2[] = {3};
			string Arg3 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, isPossible(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 1, 2};
			int Arr1[] = {0, 0, 1};
			int Arr2[] = {1, 2, 1};
			string Arg3 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, isPossible(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 1};
			int Arr1[] = {-1, 0};
			int Arr2[] = {0, 0};
			string Arg3 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, isPossible(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {434, 63, 241, 418, -380, -46, 397, -205, -262, -282, 260, -106, -389, -286, 422, -75, 127, 382, 52, -383};
			int Arr1[] = {-447, -226, -411, 287, -83, -228, -390, 358, 422, 395, -461, -112, 49, 75, -160, -152, 372, -447, -337, -362};
			int Arr2[] = {-102, 348, -70, 466, 168, -61, -389, 469, 433, 471, -75, -41, 52, 236, 299, -48, 383, -353, 346, -217};
			string Arg3 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, isPossible(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SegmentsAndPoints ___test;
	___test.run_test(-1);
}
// END CUT HERE
