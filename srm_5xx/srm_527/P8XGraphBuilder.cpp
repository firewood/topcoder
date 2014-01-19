// BEGIN CUT HERE
/*
// SRM 527 Div1 Easy (275)

問題

N個のノード(node)をN-1本の辺(edge)でつないだグラフを作る。
グラフは連結グラフである。すなわち、任意の2つのノードは辺により接続されている。
あるノードから別のノードで出ている辺の本数を次数(degree)とする。
次数毎のスコアの配列が与えられる。
グラフのスコアは、各ノードの次数に応じたスコアの和である。
最大スコアを求めよ。
なお次数のスコア表のサイズ+1がノード総数である。

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;

class P8XGraphBuilder {
	int _m[64];		// メモ化テーブル

	int rec(const IntVec &scores, bool is_root, int nodes) {
		int &res = _m[nodes];
		if (res >= 0) {
			return res;
		}

		// 節+全て葉のときのスコア
		// 葉の枚数はノード総数-1
		res = scores[!is_root + (nodes-1) -1] + scores[0]*(nodes-1);

		// 木のノード総数が3以上の場合
		// 節+i枚の葉+木
		int i;
		for (i = 0; i < (nodes - 2); ++i) {
			// 節の次数は1(根)+i(葉)+1(木)
			int node_score = scores[!is_root + i + 1 -1];
			// 木のノード数は、ノード総数-(1+i)
			int subtree_score = rec(scores, false, nodes - (i+1));
			// 節のスコア+葉のスコア+木のスコアの最大値
			res = max(res, node_score + scores[0]*i + subtree_score);
		}

		return res;
	}

public:
	int solve(vector <int> scores) {
		memset(_m, -1, sizeof(_m));
		// ノード総数はscores.size()+1
		return rec(scores, true, scores.size() +1);
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
			int Arr0[] = {1, 3, 0};
			int Arg1 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 10};
			int Arg1 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4, 5, 6};
			int Arg1 = 12;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 0, 0};
			int Arg1 = 15;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 3, 2, 5, 3, 7, 5};
			int Arg1 = 20;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	P8XGraphBuilder ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
