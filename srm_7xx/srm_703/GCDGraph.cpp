// BEGIN CUT HERE
/*
SRM 703 Div2 Medium (500)

問題
-数NとKが与えられる
-N個の頂点があり、1からNまで番号が振られている
-頂点iとjのGCDがKより大きいとき、iとjは行き来できる
-頂点xからyに行けるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

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

class GCDGraph {
	public:
	string possible(int n, int k, int x, int y) {
		UnionFind uf(n + 1);
		for (int i = k + 1; i <= n; ++i) {
			for (int j = i * 2; j <= n; j += i) {
				uf.unite(i, j);
			}
		}
		if (uf.root(x) == uf.root(y)) {
			return "Possible";
		}
		return "Impossible";
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
			int Arg0 = 12;
			int Arg1 = 2;
			int Arg2 = 8;
			int Arg3 = 9;
			string Arg4 = "Possible";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 12;
			int Arg1 = 2;
			int Arg2 = 11;
			int Arg3 = 12;
			string Arg4 = "Impossible";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 12;
			int Arg1 = 2;
			int Arg2 = 11;
			int Arg3 = 11;
			string Arg4 = "Possible";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 2;
			int Arg2 = 8;
			int Arg3 = 9;
			string Arg4 = "Impossible";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000;
			int Arg1 = 1000;
			int Arg2 = 12345;
			int Arg3 = 54321;
			string Arg4 = "Possible";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000;
			int Arg1 = 2000;
			int Arg2 = 12345;
			int Arg3 = 54321;
			string Arg4 = "Impossible";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 0;
			int Arg2 = 1;
			int Arg3 = 2;
			string Arg4 = "Possible";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GCDGraph ___test;
	___test.run_test(-1);
}
// END CUT HERE
