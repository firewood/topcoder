// BEGIN CUT HERE
/*
SRM 627 Div1 Medium (500)

問題
-N個の頂点とN本の辺が与えられる
-グラフには自己ループはなく、連結である
-それぞれの頂点は値を持つ
-異なる頂点をK個以上通るパスについて、通った順に値を並べる
-それらのパスのうち、転倒数の総数の最小値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<IntVec> IVV;

class BIT {
	std::vector<int> bit;
	int size;
public:
	BIT() { }
	BIT(int sz) { init(sz); }
	void init(int sz) {
		bit = std::vector<int>((size = sz) + 1);
	}
	int sum(int i) {
		++i;
		int s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int i, int x) {
		++i;
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

class GraphInversions {
	int n;
	IntVec vertex;
	IVV edge;
	int visited[1000];
	BIT bit;

	int dfs(int c, int k) {
		int iv = bit.sum(1000) - bit.sum(vertex[c]);
		if (k <= 1) {
			return iv;
		}

		visited[c] = 1;
		bit.add(vertex[c], 1);

		int res = 1 << 30;

		if (k > 1) {
			for (int v : edge[c]) {
				if (!visited[v]) {
					res = min(res, iv + dfs(v, k - 1));
				}
			}
		}

		bit.add(vertex[c], -1);
		visited[c] = 0;
		return res;
	}

public:
	int getMinimumInversions(vector <int> A, vector <int> B, vector <int> V, int K) {
		n = (int)A.size();
		edge = IVV(n);
		vertex = V;
		for (int i = 0; i < n; ++i) {
			edge[A[i]].push_back(B[i]);
			edge[B[i]].push_back(A[i]);
		}

		int ans = 1e6;
		for (int i = 0; i < n; ++i) {
			memset(visited, 0, sizeof(visited));
			bit.init(1001);
			ans = min(ans, dfs(i, K));
		}
		return (ans < 1e6) ? ans : -1;
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
			int Arr0[] = {0,1,2};
			int Arr1[] = {1,2,0};
			int Arr2[] = {40,50,60};
			int Arg3 = 3;
			int Arg4 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,2,3};
			int Arr1[] = {1,2,3,0};
			int Arr2[] = {60,40,50,30};
			int Arg3 = 3;
			int Arg4 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,2,3,0};
			int Arr1[] = {1,2,3,0,4};
			int Arr2[] = {10,10,10,5,5};
			int Arg3 = 5;
			int Arg4 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,2,3,0,2};
			int Arr1[] = {1,2,3,0,4,5};
			int Arr2[] = {10,2,5,3,7,1};
			int Arg3 = 6;
			int Arg4 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,7,7,5,5,7,6,4};
			int Arr1[] = {2,0,2,0,1,4,7,3};
			int Arr2[] = {15,10,5,30,22,10,5,2};
			int Arg3 = 6;
			int Arg4 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GraphInversions ___test;
	___test.run_test(-1);
}
// END CUT HERE
