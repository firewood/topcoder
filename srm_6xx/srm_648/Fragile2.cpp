// BEGIN CUT HERE
/*
SRM 648 Div2 Medium (500)

問題
-N個の頂点と、いくつかの辺がある
-2点を除去したときに連結な集合の個数が増える場合の数を求める

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

class Fragile2 {
public:
	int countPairs(vector <string> graph) {
		int N = (int)graph.size();
		int orig_size = 0;
		{
			UnionFind uf(N);
			for (int i = 0; i < N; ++i) {
				for (int j = i + 1; j < N; ++j) {
					if (graph[i][j] == 'Y') {
						uf.unite(i, j);
					}
				}
			}
			for (int i = 0; i < N; ++i) {
				orig_size += uf.root(i) == i;
			}
		}
		int ans = 0;
		for (int p = 0; p < N; ++p) {
			for (int q = p + 1; q < N; ++q) {
				UnionFind uf(N);
				for (int i = 0; i < N; ++i) {
					if (i != p && i != q) {
						for (int j = i + 1; j < N; ++j) {
							if (j != p && j != q) {
								if (graph[i][j] == 'Y') {
									uf.unite(i, j);
								}
							}
						}
					}
				}
				int g = 0;
				for (int i = 0; i < N; ++i) {
					if (i != p && i != q) {
						g += uf.root(i) == i;
					}
				}
				ans += g > orig_size;
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
			string Arr0[] = {"NYNN", "YNYN", "NYNY", "NNYN"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countPairs(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYNNNN", "YNYNNN", "NYNNNN", "NNNNYN", "NNNYNY", "NNNNYN"};
			int Arg1 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countPairs(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNN", "NNN", "NNN"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countPairs(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYNYNNYYNN", "YNNNYNYYNN", "NNNNYNNNYN", "YNNNYYNNNN", "NYYYNNNNYN",
 "NNNYNNNNYN", "YYNNNNNNNN", "YYNNNNNNYN", "NNYNYYNYNY", "NNNNNNNNYN"};
			int Arg1 = 9;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countPairs(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNNYNNYNNNNNNNYYNNNY", "NNNNNNNNYNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNN", "YNNNNNNNNNYNNNNNNNNN", "NNNNNNNYNNNNNYNNNNYN",
 "NNNNNNNNNNNNNNNNYNNY", "YNNNNNNNNNNNNYYYNYNN", "NNNNYNNNNNNNNYYNNNNN", "NYNNNNNNNYNNNNNNNNNN", "NNNNNNNNYNNNYNNNNNYN",
 "NNNYNNNNNNNNNNYNNNNN", "NNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNYNNNNNNNYNN", "NNNNYNYYNNNNNNNNNNNN", "YNNNNNYYNNYNNNNNNNNN",
 "YNNNNNYNNNNNNNNNYNNN", "NNNNNYNNNNNNNNNYNYNN", "NNNNNNYNNNNNYNNNYNNN", "NNNNYNNNNYNNNNNNNNNN", "YNNNNYNNNNNNNNNNNNNN"};
			int Arg1 = 42;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countPairs(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Fragile2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
