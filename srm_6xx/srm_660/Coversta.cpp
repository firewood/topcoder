// BEGIN CUT HERE
/*
SRM 660 Div1 Easy (250)

問題
-N×Mのセルが与えられる
-各セルはスコアを持つ
-任意の2つのセルにステーションを建設する
-ステーションは、建設した位置を中心に、特定のパターンでセルを覆う
-1つ以上のステーションで覆われたセルの合計スコアの最大値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Coversta {
public:
	int place(vector <string> a, vector <int> x, vector <int> y) {
		int ans = 0;
		int H = (int)a.size();
		int W = (int)a[0].length();
		int K = (int)x.size();
		vector<pair<int, pair<int, int> > > v;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				int sum = 0;
				for (int k = 0; k < K; ++k) {
					int p = i + x[k], q = j + y[k];
					if (p >= 0 && p < H && q >= 0 && q < W) {
						sum += a[p][q] - '0';
					}
				}
				v.push_back(make_pair(sum, make_pair(i, j)));
			}
		}
		sort(v.rbegin(), v.rend());
		for (int z = 0; z < 100 && z != v.size(); ++z) {
			int i = v[z].second.first, j = v[z].second.second;
			int u[128][128] = {};
			for (int k = 0; k < K; ++k) {
				int p = i + x[k], q = j + y[k];
				if (p >= 0 && p < H && q >= 0 && q < W) {
					u[p][q] = 1;
				}
			}
			for (i = 0; i < H; ++i) {
				for (j = 0; j < W; ++j) {
					int sum = v[z].first;
					for (int k = 0; k < K; ++k) {
						int p = i + x[k], q = j + y[k];
						if (p >= 0 && p < H && q >= 0 && q < W && !u[p][q]) {
							sum += a[p][q] - '0';
						}
					}
					ans = max(ans, sum);
				}
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
			string Arr0[] = {"11",
 "11"};
			int Arr1[] = {0,0};
			int Arr2[] = {0,1};
			int Arg3 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, place(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"11",
 "11"};
			int Arr1[] = {0,1};
			int Arr2[] = {0,1};
			int Arg3 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, place(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"15",
 "61"};
			int Arr1[] = {0};
			int Arr2[] = {0};
			int Arg3 = 11;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, place(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"151",
 "655",
 "661"};
			int Arr1[] = {0,0,-1};
			int Arr2[] = {0,1,0};
			int Arg3 = 33;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, place(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"303",
 "333",
 "000"};
			int Arr1[] = {-1,-1};
			int Arr2[] = {-1,1};
			int Arg3 = 12;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, place(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0000000",
 "1010101"}
;
			int Arr1[] = {-1,-1};
			int Arr2[] = {-1,1};
			int Arg3 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, place(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Coversta ___test;
	___test.run_test(-1);
}
// END CUT HERE
