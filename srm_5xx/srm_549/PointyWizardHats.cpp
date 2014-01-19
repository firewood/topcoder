// BEGIN CUT HERE
/*
// SRM 549 Div1 Easy (250)

問題
上用のコーンと下用のコーンを使って帽子を作りたい。
下コーンに上コーンを載せたとき、下コーンの頂点が上コーンに当たらず、かつ、下コーンが隠れないようにしたい。
最大でいくつの帽子が作れるか求める。

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;

class PointyWizardHats {
	IntVec G[100];
	int match[100];
	bool used[100];

	void add_edge(int u, int v) {
		G[u].push_back(v);
		G[v].push_back(u);
	}

	bool dfs(int v) {
		used[v] = true;
		int i;
		for (i = 0; i < (int)G[v].size(); ++i) {
			int u = G[v][i];
			int w = match[u];
			if (w < 0 || !used[w] && dfs(w)) {
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
		return false;
	}

public:
	int getNumHats(vector <int> topHeight, vector <int> topRadius, vector <int> bottomHeight, vector <int> bottomRadius) {
		int V = (int)topHeight.size();
		int U = (int)bottomHeight.size();
		int i, j;

		for (i = 0; i < 100; ++i) {
			G[i].clear();
		}
		memset(match, -1, sizeof(match));

		for (i = 0; i < V; ++i) {
			double th = topHeight[i];
			double tr = topRadius[i];
			for (j = 0; j < U; ++j) {
				double bh = bottomHeight[j];
				double br = bottomRadius[j];
				if (tr < br && (th/tr) > (bh/br)) {
					add_edge(i, 50+j);
				}
			}
		}

		int result = 0;
		int v;
		for (v = 0; v < V; ++v) {
			if (match[v] < 0) {
				memset(used, 0, sizeof(used));
				if (dfs(v)) {
					++result;
				}
			}
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
			int Arr0[] = {30};
			int Arr1[] = {3};
			int Arr2[] = {3};
			int Arr3[] = {30};
			int Arg4 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,4};
			int Arr1[] = {4,3};
			int Arr2[] = {5,12};
			int Arr3[] = {5,4};
			int Arg4 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3};
			int Arr1[] = {3};
			int Arr2[] = {1,1};
			int Arr3[] = {2,4};
			int Arg4 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,10};
			int Arr1[] = {2,5};
			int Arr2[] = {2,9};
			int Arr3[] = {3,6};
			int Arg4 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,4,5};
			int Arr1[] = {5,4,3};
			int Arr2[] = {3,4,5};
			int Arr3[] = {3,8,5};
			int Arg4 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5};
			int Arr1[] = {2,3,4,5,6};
			int Arr2[] = {2,3,4,5,6};
			int Arr3[] = {1,2,3,4,5};
			int Arg4 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {123,214,232,323,342,343};
			int Arr1[] = {123,123,232,123,323,434};
			int Arr2[] = {545,322,123,545,777,999};
			int Arr3[] = {323,443,123,656,767,888};
			int Arg4 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {999,999,999,10000,10000,10000};
			int Arr1[] = {10000,10000,10000,1,2,3};
			int Arr2[] = {2324,2323,234,5454,323,232};
			int Arr3[] = {1,2,3222,434,5454,23};
			int Arg4 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, getNumHats(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PointyWizardHats ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
