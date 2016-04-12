// BEGIN CUT HERE
/*
SRM 665 Div2 Medium (500)

問題
-木が与えられる
-それぞれの辺の重みは4か7である
-新しい辺を一つだけ追加して、4と7の個数が同数の閉路が作れるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class LuckyCycle {
public:
	vector <int> getEdge(vector <int> edge1, vector <int> edge2, vector <int> weight) {
		int cnt[100][100][2];
		memset(cnt, -1, sizeof(cnt));
		int N = (int)edge1.size() + 1;
		for (int i = 0; i < N - 1; ++i) {
			cnt[edge1[i] - 1][edge2[i] - 1][0] = weight[i] == 4;
			cnt[edge1[i] - 1][edge2[i] - 1][1] = weight[i] == 7;
			cnt[edge2[i] - 1][edge1[i] - 1][0] = weight[i] == 4;
			cnt[edge2[i] - 1][edge1[i] - 1][1] = weight[i] == 7;
		}
		for (int k = 0; k < N; ++k) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					if (cnt[i][j][0] < 0 && cnt[i][k][0] >= 0 && cnt[k][j][0] >= 0) {
						cnt[i][j][0] = cnt[i][k][0] + cnt[k][j][0];
						cnt[i][j][1] = cnt[i][k][1] + cnt[k][j][1];
					}
				}
			}
		}

		vector <int> ans;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (cnt[i][j][0] > 0 && cnt[i][j][1] > 0) {
					if (cnt[i][j][0] + 1 == cnt[i][j][1]) {
						ans.resize(3);
						ans[0] = i + 1;
						ans[1] = j + 1;
						ans[2] = 4;
						return ans;
					}
					if (cnt[i][j][0] == cnt[i][j][1] + 1) {
						ans.resize(3);
						ans[0] = i + 1;
						ans[1] = j + 1;
						ans[2] = 7;
						return ans;
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
			int Arr0[] = {1};
			int Arr1[] = {2};
			int Arr2[] = {4};

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3;
			verify_case(n, Arg3, getEdge(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 3, 2, 4};
			int Arr1[] = {2, 2, 4, 5};
			int Arr2[] = {4, 7, 4, 7};
			int Arr3[] = {1, 5, 7 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, getEdge(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
			int Arr1[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
			int Arr2[] = {4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7};
			int Arr3[] = {1, 12, 7 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, getEdge(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 5, 6};
			int Arr1[] = {2, 3, 4, 3, 5};
			int Arr2[] = {4, 7, 7, 7, 7};
			int Arr3[] = {1, 4, 4 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, getEdge(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LuckyCycle ___test;
	___test.run_test(-1);
}
// END CUT HERE
