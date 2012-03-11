// BEGIN CUT HERE
/*
// SRM 505 Div2 Hard (900)

問題
大きさW×Hの四角形がある。
四角形はN個の水平位置X[n]と、M個の垂直位置Y[m]で区切られている。
位置X[i]Y[j]のサイズが既知であるかどうかが与えられる。
四角形全体のサイズを既知とするための最小の質問回数を求める。

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;


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


class RectangleArea {

public:
	int minimumQueries(vector <string> known) {
		int result = 0;
		int W = known[0].length();
		int H = known.size();
		UnionFind w(W);
		IntVec h(H, 1);
		int i, j, p = -1;
		for (i = 0; i < H; ++i) {
			int pos = -1;
			for (j = 0; j < W; ++j) {
				if (known[i][j] == 'Y') {
					if (pos >= 0) {
						w.unionSet(pos, j);
					} else {
						pos = j;
						p = j;
						h[i] = 0;
					}
				}
			}
		}
		if (p < 0) {
			result = W + H - 1;
		} else {
			for (j = 0; j < W; ++j) {
				if (!w.findSet(j, p)) {
					++result;
					w.unionSet(j, p);
				}
			}
			result += accumulate(h.begin(), h.end(), 0);
		}
		return result;
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
			string Arr0[] = {"NN",
 "NN"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumQueries(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"YNY",
 "NYN",
 "YNY"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumQueries(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"YY",
 "YY",
 "YY",
 "YY"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumQueries(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNNNNNNNNN"};
			int Arg1 = 10;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumQueries(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNYYYNN",
 "NNNNNYN",
 "YYNNNNY",
 "NNNYNNN",
 "YYNNNNY"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumQueries(Arg0));
		}
		n++;




		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"YY", "NN", "NN", "NN"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumQueries(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RectangleArea ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
