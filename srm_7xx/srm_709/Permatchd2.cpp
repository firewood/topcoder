// BEGIN CUT HERE
/*
SRM 709 Div2 Medium (500)

問題
-N個の頂点からなるグラフがあり、0本以上の辺がある
-任意の2頂点について、複数の辺は張れない
-グラフに存在する全ての連結成分の辺の数が偶数になるように辺を追加する
-最低何本の辺を追加する必要があるかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	std::vector<int> _edges;
	UnionFind(int size) : _parent(size, -1), _size(size, 1), _edges(size) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] >= _size[rb]) {
			_parent[rb] = ra, _size[ra] += _size[rb], _edges[ra] += _edges[rb];
		} else {
			_parent[ra] = rb, _size[rb] += _size[ra], _edges[rb] += _edges[ra];
		}
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
	int &edges(int root) { return _edges[root]; }
};

class Permatchd2 {
public:
	int fix(vector <string> graph) {
		int N = (int)graph.size();
		UnionFind uf(N);
		int ans = 0, cnt = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				if (graph[i][j] == 'Y') {
					uf.unite(i, j);
					uf.edges(uf.root(i)) += 1;
					++cnt;
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			int root = uf.root(i);
			if (i == root) {
				ans += uf.edges(root) % 2;
			}
		}
		return (ans + cnt) <= ((N * (N - 1)) / 2) ? ans : -1;
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
			string Arr0[] = {"NYN",
 "YNN",
 "NNN"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, fix(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYY",
 "YNN",
 "YNN"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, fix(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYY",
 "YNY",
 "YYN"};
			int Arg1 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, fix(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYYY",
 "YNYY",
 "YYNN",
 "YYNN"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, fix(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYNNNN",
 "YNNNNN",
 "NNNYNN",
 "NNYNNN",
 "NNNNNY",
 "NNNNYN"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, fix(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"N"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, fix(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Permatchd2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
