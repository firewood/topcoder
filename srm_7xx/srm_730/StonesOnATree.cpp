// BEGIN CUT HERE
/*
SRM 730 Div1 Easy (250)

問題
-N個の頂点からなる木がある
-各頂点iには重みw[i]がある
-1ターンに、一つ石を置くか、一つの石を取り除ける
-子を持つ頂点には、全ての子に石が置かれているときだけ石を置ける
-葉には常に石を置ける
-根に石を置いたらゴール
-ゴールまでの全ての状態における重みの合計の最大値を最小化するとき、その値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class StonesOnATree {
	vector<int> edges[1024];
	vector<int> values;

	int dfs(int n) {
		int cost = 0, costs[2] = {}, max_costs[2] = {};
		for (int i = 0; i < (int)edges[n].size(); ++i) {
			costs[i] = values[edges[n][i]];
			max_costs[i] = dfs(edges[n][i]);
			cost = max(cost, max_costs[i]);
		}
		cost = max(cost, values[n] + costs[0] + costs[1]);
		return max(cost, min(costs[0] + max_costs[1], costs[1] + max_costs[0]));
	}

public:
	int minStones(vector <int> p, vector <int> w) {
		for (auto &v : edges) {
			v.clear();
		}
		values = w;
		for (int i = 0; i < (int)p.size(); ++i) {
			edges[p[i]].push_back(i + 1);
		}
		return dfs(0);
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
			int Arr0[] = {0,1,2,3};
			int Arr1[] = {1,2,2,4,4};
			int Arg2 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minStones(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0};
			int Arr1[] = {1,2,3};
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minStones(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arr1[] = {100000,100000};
			int Arg2 = 200000;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minStones(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,1,1,2,2};
			int Arr1[] = {1,1,1,1,1,1,1};
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minStones(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,1,2,3,4,4,2,1,3,6,7};
			int Arr1[] = {1,2,3,4,5,6,6,7,8,8,8,9,10};
			int Arg2 = 22;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minStones(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StonesOnATree ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
