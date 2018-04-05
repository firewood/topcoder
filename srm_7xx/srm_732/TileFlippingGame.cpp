// BEGIN CUT HERE
/*
SRM 732 Div1 Easy (250)

問題
-N行M列のマス目がある
-マス目にはタイルを置ける
-タイルは表が白、裏が黒
-1ターンに、任意のタイルをひっくり返せる
-上下左右のいずれかが隣接するタイルが同じ色ならば、連鎖的にひっくり返せる
-すべてを同じ色にするのに必要な手数の最小値を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

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

class TileFlippingGame {
	vector<int> nodes;
	set<int> g[400];

public:
	int HowManyMoves(int n, int m, vector <string> X) {
		nodes.clear();
		UnionFind common(n*m), neighbor(n*m);
		const int dx[4] = { -1,1,0,0 };
		const int dy[4] = { 0,0,-1,1 };
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				g[i * m + j].clear();
				if (X[i][j] != 'e') {
					for (int d = 0; d < 4; ++d) {
						int r = i + dy[d], c = j + dx[d];
						if (r >= 0 && r < n && c >= 0 && c < m && X[r][c] == X[i][j]) {
							neighbor.unite(i * m + j, r * m + c);
							common.unite(i * m + j, r * m + c);
						}
					}
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (X[i][j] != 'e') {
					int p = common.root(i * m + j);
					if (p == i * m + j) {
						nodes.push_back(p);
					}
					for (int d = 0; d < 4; ++d) {
						int r = i + dy[d], c = j + dx[d];
						if (r >= 0 && r < n && c >= 0 && c < m && X[r][c] != 'e' && X[i][j] != X[r][c]) {
							int q = common.root(r * m + c);
							neighbor.unite(p, q);
							g[p].insert(q);
							g[q].insert(p);
						}
					}
				}
			}
		}
		int mcost[2][400] = {};
		for (int node : nodes) {
			if (neighbor.root(node) == node) {
				mcost[0][node] = 1 << 30;
				mcost[1][node] = 1 << 30;
			}
		}
		for (int node : nodes) {
			int vis[400] = {};
			vis[node] = 1;
			vector<int> q;
			for (int next : g[node]) {
				vis[next] = 1;
				q.push_back(next);
			}
			int cost = 0;
			while (q.size()) {
				++cost;
				vector<int> nq;
				for (int v : q) {
					for (int next : g[v]) {
						if (!vis[next]) {
							vis[next] = 1;
							nq.push_back(next);
						}
					}
				}
				q = nq;
			}
			bool white = X[node / m][node % m] == 'w';
			int nr = neighbor.root(node);
			mcost[white][nr] = min(mcost[white][nr], cost + (cost % 2));
			mcost[!white][nr] = min(mcost[!white][nr], cost + !(cost % 2));
		}
		int cost[2] = {};
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < n * m; ++j) {
				if (neighbor.root(j) == j) {
					cost[i] += mcost[i][j];
				}
			}
		}
		return min(cost[0], cost[1]);
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
			int Arg1 = 3;
			string Arr2[] = {"bbb","eee","www"};
			int Arg3 = 1;

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, HowManyMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			string Arr2[] = {"bwe","wbw","ewb"};
			int Arg3 = 2;

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, HowManyMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			string Arr2[] = {"beww","beww","beww","wewe"};
			int Arg3 = 1;

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, HowManyMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 8;
			string Arr2[] = {"ewewbbbb","bwebewww"};
			int Arg3 = 3;

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, HowManyMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 5;
			string Arr2[] = {"bwebw","wbebb","eeeee","bbebb","bbebb"};
			int Arg3 = 3;

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, HowManyMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 7;
			string Arr2[] = {"bwbbbbb","bwbwwwb","bwbwewb","bwbbbwb","bwwwwwb","bbbbbbb"};
			int Arg3 = 1;

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, HowManyMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 7;
			string Arr2[] = {"bwbbbbb","bwbwwwb","eeeeeee","bwbbbwb","bwwwwwb","bbbbbbb"};
			int Arg3 = 3;

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, HowManyMoves(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TileFlippingGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
