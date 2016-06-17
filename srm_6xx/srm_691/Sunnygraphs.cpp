// BEGIN CUT HERE
/*
SRM 691 Div1 Easy (250)

問題
-0～N-1までのN個の頂点がある
-各頂点iは、頂点a[i]と辺を持つ
-0本以上の任意の辺を頂点Nとつなぎ直すとき、頂点0と1が連結である場合の総数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;

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

class Sunnygraphs {
public:
	long long count(vector <int> a) {
		int N = (int)a.size();
		IntVec vis(N);
		for (int n = 0; (vis[n] & 1) == 0; n = a[n]) {
			vis[n] |= 1;
		}
		for (int n = 1; (vis[n] & 2) == 0; n = a[n]) {
			vis[n] |= 2;
		}
		LL w = 1LL << std::count(vis.begin(), vis.end(), 0);
		LL x = 1LL << std::count(vis.begin(), vis.end(), 1);
		LL y = 1LL << std::count(vis.begin(), vis.end(), 2);
		LL z = 1LL << std::count(vis.begin(), vis.end(), 3);
		LL ans = (x + y - 2) * (z - 1) + (x - 1) * (y - 1) * z;
		if (z > 1) {
			ans += z;
		}
		return ans * w;
	}

	long long count2(vector <int> a) {
		long long ans = 0;
		int sz = (int)a.size();
		if (sz <= 16) {
			int m = 1 << sz;
			for (int b = 0; b < m; ++b) {
				UnionFind uf(sz+1);
				for (int i = 0; i < sz; ++i) {
					if (b & (1 << i)) {
						uf.unite(i, sz);
					} else {
						uf.unite(i, a[i]);
					}
				}
				ans += uf.root(0) == uf.root(1);
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,0};
			long long Arg1 = 4LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,0};
			long long Arg1 = 7LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,3,0,1};
			long long Arg1 = 9LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,3,4,3};
			long long Arg1 = 30LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {18,18,20,28,7,27,8,13,40,3,7,21,30,17,13,34,29,16,15,11,0,9,39,36,38,23,24,8,4,9,29,22,35,5,13,23,3,27,34,23,8};
			long long Arg1 = 2198754820096LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Sunnygraphs ___test;
	___test.run_test(-1);

	for (int t = 0; t < 100; ++t) {
		int N = 8;
		IntVec v(N);
		for (int i = 0; i < N; ++i) {
			while (true) {
				v[i] = rand() % N;
				if (v[i] != i) {
					break;
				}
			}
		}
		LL p = ___test.count(v);
		LL q = ___test.count2(v);
		if (p != q) {
			printf("%lld, %lld\n", p, q);
			for (int i = 0; i < N; ++i) {
				printf(" %d", v[i]);
			}
			printf("\n");
			break;
		}
	}
}
// END CUT HERE
