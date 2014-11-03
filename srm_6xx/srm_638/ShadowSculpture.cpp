// BEGIN CUT HERE
/*
SRM 638 Div1 Easy (300)

問題
-XY平面、YZ平面、ZX平面の影が与えられる
-連続する物体で条件を満たすものがあるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class ShadowSculpture {
	int N;
	vector <string> xy;
	vector <string> yz;
	vector <string> zx;
	vector <string> xy2;
	vector <string> yz2;
	vector <string> zx2;
	int visited[10][10][10];

	void dfs(int x, int y, int z) {
		if (x < 0 || x >= N || y < 0 || y >= N || z < 0 || z >= N) {
			return;
		}
		if (visited[x][y][z]) {
			return;
		}
		visited[x][y][z] = 1;
		if (xy[x][y] == 'N' || yz[y][z] == 'N' || zx[z][x] == 'N') {
			return;
		}
		xy2[x][y] = 'Y', yz2[y][z] = 'Y', zx2[z][x] = 'Y';
		dfs(x - 1, y, z);
		dfs(x + 1, y, z);
		dfs(x, y - 1, z);
		dfs(x, y + 1, z);
		dfs(x, y, z - 1);
		dfs(x, y, z + 1);
	}

	bool check(void) {
		vector <string> e = xy;
		for (int x = 0; x < N; ++x) {
			for (int y = 0; y < N; ++y) {
				e[x][y] = 'N';
			}
		}

		for (int x = 0; x < N; ++x) {
			for (int y = 0; y < N; ++y) {
				for (int z = 0; z < N; ++z) {
					xy2 = e, yz2 = e, zx2 = e;
					memset(visited, 0, sizeof(visited));
					dfs(x, y, z);
					if (xy == xy2 && yz == yz2 && zx == zx2) {
						return true;
					}
				}
			}
		}

		return false;
	}

public:
	string possible(vector <string> XY, vector <string> YZ, vector <string> ZX) {
		N = (int)XY.size();
		xy = XY, yz = YZ, zx = ZX;
		return check() ? "Possible" : "Impossible";
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
			string Arr0[] = {"YN","NN"};
			string Arr1[] = {"YN","NN"};
			string Arr2[] = {"YN","NN"};
			string Arg3 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, possible(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"YN","NY"};
			string Arr1[] = {"YN","NY"};
			string Arr2[] = {"YN","NY"};
			string Arg3 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, possible(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"YYY","YNY","YYY"};
			string Arr1[] = {"YYY","YNY","YYY"};
			string Arr2[] = {"YYY","YNY","YYY"};
			string Arg3 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, possible(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"YYY","YNY","YYY"};
			string Arr1[] = {"NYY","YNY","YYY"};
			string Arr2[] = {"YYY","YNY","YYN"};
			string Arg3 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, possible(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"N"};
			string Arr1[] = {"N"};
			string Arr2[] = {"N"};
			string Arg3 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, possible(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "NN", "NN" };
			string Arr1[] = { "NN", "NN" };
			string Arr2[] = { "NN", "NN" };
			string Arg3 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, possible(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "N" };
			string Arr1[] = { "N" };
			string Arr2[] = { "Y" };
			string Arg3 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, possible(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "YYY", "YYY", "YNY" };
			string Arr1[] = { "YYY", "YYY", "YNY" };
			string Arr2[] = { "YNY", "YYY", "YYY" };
			string Arg3 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, possible(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "NNN", "NNN", "NYN" };
			string Arr1[] = { "NNN", "YNN", "NNN" };
			string Arr2[] = { "NNY", "NNN", "NNN" };
			string Arg3 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, possible(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};


// BEGIN CUT HERE
int main() {
	ShadowSculpture ___test;
	___test.run_test(-1);
}
// END CUT HERE
