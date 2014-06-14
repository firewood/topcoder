// BEGIN CUT HERE
/*
SRM 622 Div1 Easy (250)

問題
-N個の都市があり、それぞれの都市間経路の距離が与えられる
-ある日、それぞれの都市から、別の全てのそれぞれの都市へ一斉にバスが走る
-バスは最短経路のどれかを通る
-バスが最大T台以上通る可能性がある経路は危険
-危険な経路の合計の長さを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class BuildingRoutes {
public:
	int build(vector <string> dist, int T) {
		int N = (int)dist.size();

		int d[50][50] = {};
		int i, j, k;
		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				d[i][j] = dist[i][j] - '0';
			}
		}
		for (k = 0; k < N; ++k) {
			for (i = 0; i < N; ++i) {
				for (j = 0; j < N; ++j) {
					if (i != j) {
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					}
				}
			}
		}

		int ans = 0;

		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				if (i != j) {
					int cnt = 0;
					for (int p = 0; p < N; ++p) {
						for (int q = 0; q < N; ++q) {
							if (p != q) {
								if (d[p][i] + (dist[i][j] - '0') + d[j][q] == d[p][q]) {
									++cnt;
								}
							}
						}
					}
					if (cnt >= T) {
						ans += dist[i][j] - '0';
					}
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
			string Arr0[] = {"011",
 "101",
 "110"};
			int Arg1 = 1;
			int Arg2 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, build(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"033",
 "309",
 "390"};
			int Arg1 = 1;
			int Arg2 = 12;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, build(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0123",
 "1023",
 "1203",
 "1230"};
			int Arg1 = 2;
			int Arg2 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, build(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"05789654",
 "10347583",
 "65085479",
 "55602398",
 "76590934",
 "57939045",
 "12345608",
 "68647640"};
			int Arg1 = 3;
			int Arg2 = 40;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, build(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BuildingRoutes ___test;
	___test.run_test(-1);
}
// END CUT HERE
