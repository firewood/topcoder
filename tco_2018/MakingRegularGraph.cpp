// BEGIN CUT HERE
/*
TCO18 R1A Medium (500)

問題
-N個の頂点と、いくつかの辺が与えられる
-辺を足して、次数が2の正則グラフにせよ。
-可能なグラフのうち、辞書順最小のものを求めよ。

*/
// END CUT HERE

#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>

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


class MakingRegularGraph { 
public: 
  vector <int> addEdges(int n, vector <int> x, vector <int> y) { 
    int rv = n; 
    vector<int> e[1000]; 
    int u[1000] = {}; 
    UnionFind uf(n); 
    for (int i = 0; i != x.size(); ++i) { 
      e[x[i]].push_back(y[i]); 
      e[y[i]].push_back(x[i]); 
      bool same = uf.root(x[i]) == uf.root(y[i]); 
      uf.unite(x[i], y[i]); 
      if (same) { 
        int r = uf.root(x[i]); 
        for (int i = 0; i < n; ++i) { 
          if (uf.root(i) == r) { 
            --rv; 
            u[i] = 1; 
          } 
        } 
      } 
    } 
    if (rv == 0) { 
      return vector <int>(); 
    } 
    if (rv < 3) { 
      return { -1 }; 
    } 
    vector <int> ans; 
    while (rv > 0) { 
      bool done = false; 
      for (int i = 0; !done && i < n; ++i) { 
        if (e[i].size() < 2) { 
          for (int j = 0; j < n; ++j) { 
            if (i == j || e[j].size() >= 2 || u[j]) { 
              continue; 
            } 
            bool same = uf.root(i) == uf.root(j); 
            if (same) { 
              int sz = uf.size(i); 
              if (sz == 2 || ((rv - sz) > 0 && (rv - sz) < 3)) { 
                continue; 
              } 
            } 
            uf.unite(i, j); 
            e[i].push_back(j); 
            e[j].push_back(i); 
            ans.push_back(i); 
            ans.push_back(j); 
            if (same) { 
              int r = uf.root(i); 
              for (int k = 0; k < n; ++k) { 
                if (uf.root(k) == r) { 
                  --rv; 
                  u[k] = 1; 
                } 
              } 
            } 
            done = true; 
            break; 
          } 
        } 
      } 
    } 
    return ans; 
  } 

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arr1[] = {0,2};
			int Arr2[] = {2,3};
			int Arr3[] = {0, 1, 1, 4, 3, 5, 4, 5 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addEdges(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {1,2,1};
			int Arr2[] = {2,3,3};
			int Arr3[] = {-1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addEdges(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			// int Arr1[] = {};
			// int Arr2[] = {};
			int Arr3[] = {0, 1, 0, 2, 1, 2 };

			vector <int> Arg1;
			vector <int> Arg2;
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addEdges(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {0};
			int Arr2[] = {4};
			int Arr3[] = {0, 1, 1, 2, 2, 3, 3, 4 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addEdges(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {2};
			int Arr2[] = {3};
			int Arr3[] = {0, 1, 0, 2, 1, 4, 3, 4 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addEdges(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  MakingRegularGraph ___test;
  ___test.run_test(-1);
}
// END CUT HERE
