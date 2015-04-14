// BEGIN CUT HERE
/*
TCO 2015 Round 1A Medium (500)

問題
-N個の場所とN個のトークンとN個の矢印がある
-トークンを0個以上場所に置く
-各ターンでは、各場所のトークンを、矢印で指示された先に移動する
-トークンが同じ場所に置かれるとゲームオーバー
-ゲームオーバーにならないトークンの置き方の総数を求める

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

typedef long long LL;
const LL MOD = 1000000007;

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] >= _size[rb]) { _parent[rb] = ra, _size[ra] += _size[rb]; } else { _parent[ra] = rb, _size[rb] += _size[ra]; }
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

class Autogame {
public:
	int wayscnt(vector <int> a, int K) {
		int N = (int)a.size();
		UnionFind g(64);
		int dp[2][64] = {};
		for (int i = 0; i < N; ++i) {
			dp[0][i] = i + 1;
		}
		int t = min(K, N);
		for (int i = 1; i <= t; ++i) {
			int current = i % 2;
			int previous = current ^ 1;
			for (int i = 0; i < N; ++i) {
				dp[current][i] = 0;
			}
			for (int i = 0; i < N; ++i) {
				if (dp[previous][i]) {
					int next = a[i] - 1;
					if (dp[current][next]) {
						g.unite(dp[current][next], dp[previous][i]);
					} else {
						dp[current][next] = dp[previous][i];
					}
				}
			}
		}

		LL ans = 1;
		for (int i = 1; i <= N; ++i) {
			if (g.root(i) == i) {
				LL sz = g.size(i);
				ans = (ans * (sz + 1)) % MOD;
			}
		}
		return (int)ans;
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
			int Arr0[] = {1,2,3};
			int Arg1 = 5;
			int Arg2 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, wayscnt(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1};
			int Arg1 = 1;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, wayscnt(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,1}	;
			int Arg1 = 42;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, wayscnt(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,3,4,3};
			int Arg1 = 3;
			int Arg2 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, wayscnt(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,4,3,2,1};
			int Arg1 = 3;
			int Arg2 = 18;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, wayscnt(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Autogame ___test;
	___test.run_test(-1);
}
// END CUT HERE
