// BEGIN CUT HERE
/*
// SRM 531 Div2 Hard (950)

// PROBLEM STATEMENT
// This problem statement contains subscripts and may not be shown properly
outside of the applet.

The greatest king of all times, Michael IV, is going to make big changes
in his kingdom. The kingdom is composed of N cities (for simplicity numbered
from 0 to N-1). Some pairs of cities are connected by bidirectional roads.
We say that there is a path between different cities A and B if there exists
a sequence of unique cities {C1, C2, ..., CM}, such that C1 = A and CM = B
and for each index i < M, there is a road between cities Ci and Ci+1.

The current state of the kingdom is miserable. Some pairs of cities are not
connected by any path. On the other hand, other pairs of cities are connected
by multiple different paths, and that leads to complicated traffic routing.
Michael wants to build some new roads and destroy some of the already
existing roads in the kingdom so that after the reconstruction there will
exist exactly one path between every pair of distinct cities. As building
new roads and destroying old ones costs a lot of money, Michael wants to
minimize the total cost spent on the reconstruction.

You are given a vector <string> kingdom describing the current state of the
kingdom. There is a road between the cities i and j if and only if
kingdom[i][j] = '1' and kingdom[j][i] = '1'. You are also given
a vector <string> build and a vector <string> destroy. If no road exists
between cities i and j, then the cost of building it is encoded by build[i][j].
If there already is a road between cities i and j, then the cost of destroying
it is encoded by destroy[i][j]. The costs in both vector <string>s are encoded
as characters, where 'A', 'B', ..., 'Z' represent the costs 0, 1, ..., 25,
respectively and 'a', 'b', ..., 'z' represent the costs 26, 27, ..., 51,
respectively. Your task is to find and return the minimal cost needed for
the kingdom reconstruction.


DEFINITION
Class:KingdomReorganization
Method:getCost
Parameters:vector <string>, vector <string>, vector <string>
Returns:int
Method signature:int getCost(vector <string> kingdom, vector <string> build, vector <string> destroy)


NOTES
-N, the number of cities in the kingdom can be determined as the number of
 elements of kingdom.
-Two paths {A1, A2, ..., AR} and {B1, B2, ..., BS} are considered different
 if either R is not equal to S or there exists i <= R, such that Ai is not
  equal to Bi.
-There can never exist a road leading from some city to itself.
-The values in build that correspond to existing roads can simply be ignored.
 Similarly, ignore the values in destroy that correspond to nonexistent roads.


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-kingdom, build and destroy will each contain N elements.
-Each of the elements of kingdom, build and destroy will contain N characters.
-Each character in each element of kingdom will be either '0' or '1'.
-For each i, kingdom[i][i] will be '0'.
-For each i and j, kingdom[i][j] will be equal to kingdom[j][i].
-Each character in each element of build and destroy will be either an
 uppercase letter ('A'-'Z') or a lowercase letter ('a'-'z').
-For each i, build[i][i] and destroy[i][i] will be 'A'.
-For each i and j, build[i][j] will be equal to build[j][i].
-For each i and j, destroy[i][j] will be equal to destroy[j][i].


EXAMPLES

0)
{"000","000","000"}
{"ABD","BAC","DCA"}
{"ABD","BAC","DCA"}

Returns: 3

There are three cities in the kingdom, totally disconnected. 
The only optimal solution is to build the roads between cities 0-1 (cost 1) and 1-2 (cost 2).


1)
{"011","101","110"}
{"ABD","BAC","DCA"}
{"ABD","BAC","DCA"}

Returns: 1

Now the three cities form a connected triangle and we need to destroy one road. 
Optimal solution is to destroy the road between the cities 0-1 (cost 1).


2)
{"011000","101000","110000","000011","000101","000110"}
{"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"}
{"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"}

Returns: 7

We have six cities forming two separate triangles. 
Like in the Example 1, destroy one road in each triangle (costs 1 for each road) and then join the triangles by a new road (costs 5).


3)
{"0"}
{"A"}
{"A"}

Returns: 0

One city is okay just as it is.


4)
{"0001","0001","0001","1110"}
{"AfOj","fAcC","OcAP","jCPA"}
{"AWFH","WAxU","FxAV","HUVA"}

Returns: 0

We have four cities, which are connected in such a way that there is exactly one path between each two cities. 
Thus there is nothing to reconstruct.


5)
{"0000000000","0000000011","0001010000","0010010000","0000001000","0011000000","0000100000","0000000011","0100000101","0100000110"}
{"AhPEqkSFMM","hAfKPtsDad","PfAyGQkaqN","EKyAeLpRpm","qPGeASfNwo","ktQLSAnCAK","SskpfnAdJS","FDaRNCdAZz","MaqpwAJZAn","MdNmoKSznA"}
{"AgTqWWxEYH","gAXPgjzIRA","TXAleTmWvT","qPlAQkwxRO","WgeQAqgbJJ","WjTkqAiTzl","xzmwgiAuHb","EIWxbTuAwk","YRvRJzHwAn","HATOJlbknA"}

Returns: 65

*/
// END CUT HERE
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef pair<int, int> II;
typedef pair<int, II> III;
typedef priority_queue<III> Queue;

// union find tree
// http://www.prefield.com/algorithm/container/union_find.html
struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

class KingdomReorganization {

public:
	int getCost(vector <string> kingdom, vector <string> build, vector <string> destroy) {
		int i, j, cost;
		int res = 0;
		const char CostChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		int Costs[128] = {};
		int sz = (int)kingdom.size();
		for (i = 0; i < sizeof(CostChars); ++i) {
			Costs[CostChars[i]] = i;
		}
		Queue b, d;
		for (i = 0; i < sz; ++i) {
			for (j = i+1; j < sz; ++j) {
				if (kingdom[i][j] == '0') {
					cost = Costs[build[i][j]];
					b.push(III(-cost, II(i, j)));
				} else {
					cost = Costs[destroy[i][j]];
					d.push(III(cost, II(i, j)));
				}
			}
		}
		UnionFind roads(sz);
		while (!d.empty()) {
			III x = d.top();
			d.pop();
			cost = x.first;
			II edge = x.second;
			if (roads.findSet(edge.first, edge.second)) {
				res += cost;
			} else {
				roads.unionSet(edge.first, edge.second);
			}
		}
		while (!b.empty()) {
			III x = b.top();
			b.pop();
			cost = -x.first;
			II edge = x.second;
			if (!roads.findSet(edge.first, edge.second)) {
				res += cost;
				roads.unionSet(edge.first, edge.second);
			}
		}
		return res;
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
			string Arr0[] = {"000","000","000"};
			string Arr1[] = {"ABD","BAC","DCA"};
			string Arr2[] = {"ABD","BAC","DCA"};
			int Arg3 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"011","101","110"};
			string Arr1[] = {"ABD","BAC","DCA"};
			string Arr2[] = {"ABD","BAC","DCA"};
			int Arg3 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"011000","101000","110000","000011","000101","000110"};
			string Arr1[] = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"};
			string Arr2[] = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"};
			int Arg3 = 7;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0"};
			string Arr1[] = {"A"};
			string Arr2[] = {"A"};
			int Arg3 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0001","0001","0001","1110"};
			string Arr1[] = {"AfOj","fAcC","OcAP","jCPA"};
			string Arr2[] = {"AWFH","WAxU","FxAV","HUVA"};
			int Arg3 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0000000000","0000000011","0001010000","0010010000","0000001000","0011000000","0000100000","0000000011","0100000101","0100000110"};
			string Arr1[] = {"AhPEqkSFMM","hAfKPtsDad","PfAyGQkaqN","EKyAeLpRpm","qPGeASfNwo","ktQLSAnCAK","SskpfnAdJS","FDaRNCdAZz","MaqpwAJZAn","MdNmoKSznA"};
			string Arr2[] = {"AgTqWWxEYH","gAXPgjzIRA","TXAleTmWvT","qPlAQkwxRO","WgeQAqgbJJ","WjTkqAiTzl","xzmwgiAuHb","EIWxbTuAwk","YRvRJzHwAn","HATOJlbknA"};
			int Arg3 = 65;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getCost(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	KingdomReorganization ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
