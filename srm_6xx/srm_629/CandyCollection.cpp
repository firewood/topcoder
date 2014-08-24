// BEGIN CUT HERE
/*
SRM 629 Div1 Medium (500)

問題
-形がN種類の飴がある
-それぞれの形で2種類の味がある
-味は全部でN種類
-それぞれの種類で、それぞれの味の在庫の数が与えられる
-買うときには形しか指定することができない
-全ての種類の味の飴を集めるのに買う必要のある個数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class CandyCollection {
public:
	int solve(vector <int> Type1, vector <int> Number1, vector <int> Type2, vector <int> Number2) {
		int TypeToIndex[1000][2];
		memset(TypeToIndex, -1, sizeof(TypeToIndex));
		int N = (int)Type1.size();
		for (int i = 0; i < N; ++i) {
			bool f = TypeToIndex[Type1[i]][0] < 0;
			TypeToIndex[Type1[i]][!f] = i;
			f = TypeToIndex[Type2[i]][0] < 0;
			TypeToIndex[Type2[i]][!f] = i;
		}

		int ans = 0;

		bool vis[1000] = {};
		for (int i = 0; i < N; ++i) {
			if (!vis[i]) {
				vis[i] = true;
				int start_type = Type1[i];
				int current_type = Type2[i];

				int dp[2][2][2] = {};
				dp[0][0][1] = Number1[i] + 1;
				dp[0][1][0] = Number2[i] + 1;
				dp[0][1][1] = max(dp[0][0][1], dp[0][1][0]);
				int r = 0, w = 1;

				while (current_type != start_type) {
					int j = TypeToIndex[current_type][0];
					if (vis[j]) {
						j = TypeToIndex[current_type][1];
					}
					vis[j] = true;

					bool f = Type1[j] == current_type;
					int a = f ? (Number2[j] + 1) : (Number1[j] + 1);
					int b = f ? (Number1[j] + 1) : (Number2[j] + 1);

					for (int k = 0; k < 2; ++k) {
						dp[w][k][0] = min(dp[r][k][0] + a, dp[r][k][1]);
						dp[w][k][1] = min(dp[r][k][0] + max(a, b), dp[r][k][1] + b);
					}

					current_type = f ? Type2[j] : Type1[j];
					r ^= 1, w ^= 1;
				}

				ans += min(dp[r][0][1], dp[r][1][0]);
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
			int Arr0[] = {0,0};
			int Arr1[] = {1,1};
			int Arr2[] = {1,1};
			int Arr3[] = {1,1};
			int Arg4 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, solve(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0};
			int Arr1[] = {2,5};
			int Arr2[] = {1,1};
			int Arr3[] = {2,5};
			int Arg4 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, solve(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,2,3};
			int Arr1[] = {1,1,2,2};
			int Arr2[] = {1,1,3,2};
			int Arr3[] = {1,1,2,2};
			int Arg4 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, solve(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,2,3};
			int Arr1[] = {5,5,10,13};
			int Arr2[] = {1,2,3,0};
			int Arr3[] = {8,8,10,15};
			int Arg4 = 20;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, solve(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {12,9,0,16,9,18,12,3,6,0,8,2,10,6,5,2,14,10,5,13};
			int Arr1[] = {895,704,812,323,334,674,665,142,712,254,869,548,645,663,758,38,860,724,742,530};
			int Arr2[] = {1,4,7,11,15,8,18,13,17,17,19,14,7,11,4,1,15,19,3,16};
			int Arr3[] = {779,317,36,191,843,289,107,41,943,265,649,447,806,891,730,371,351,7,102,394};
			int Arg4 = 5101;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, solve(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CandyCollection ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
