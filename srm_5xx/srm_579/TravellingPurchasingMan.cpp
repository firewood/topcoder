// BEGIN CUT HERE
/*
SRM 579 Div1 Medium (450)

問題
-店がN個、興味のある店がM個ある
-それぞれの店の開店時間、閉店時間、買い物にかかる時間が与えられる
-店Aと店Bが道路で結ばれている場合、かかる時間が与えられる
-同じ店では1度しか買い物できない
-閉店時間ちょうどに入店してもよい
-店(N-1)からスタートして、買い物ができる最大数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

static inline int popcount(unsigned int b)
{
#ifdef __GNUC__
		return __builtin_popcount(b);
#elif _MSC_VER >= 1400
		return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	b += b >> 16;
	return b & 0x3F;
#endif
}

class TravellingPurchasingMan {
	int op[50];
	int cl[50];
	int du[50];
	int dist[50][50];
	int dp[1<<16][16];

public:
	int maxStores(int N, vector <string> interestingStores, vector <string> roads) {
		int i, j, k;
		int M = (int)interestingStores.size();
		for (i = 0; i < M; ++i) {
			sscanf(interestingStores[i].c_str(), "%d %d %d", op+i, cl+i, du+i);
		}
		memset(dist, 0x3f, sizeof(dist));
		for (i = 0; i < (int)roads.size(); ++i) {
			int s, e, d;
			sscanf(roads[i].c_str(), "%d %d %d", &s, &e, &d);
			dist[s][e] = d, dist[e][s] = d;
		}
		for (k = 0; k < N; ++k) {
			dist[k][k] = 0;
			for (i = 0; i < N; ++i) {
				for (j = 0; j < N; ++j) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		memset(dp, 0x3f, sizeof(dp));
		for (i = 0; i < M; ++i) {
			if (dist[N-1][i] <= cl[i]) {
				dp[1<<i][i] = max(dist[N-1][i], op[i]) + du[i];
			}
		}
		int visited;
		for (visited = 1; visited < (1<<M); ++visited) {
			for (i = 0; i < M; ++i) {
				if (visited & (1<<i)) {
					for (j = 0; j < M; ++j) {
						int next = visited | (1<<j);
						if (visited != next && (dp[visited][i] + dist[i][j]) <= cl[j]) {
							dp[next][j] = min(dp[next][j], max(dp[visited][i] + dist[i][j], op[j]) + du[j]);
						}
					}
				}
			}
		}

		int ans = 0;
		for (visited = 1; visited < (1<<M); ++visited) {
			for (i = 0; i < M; ++i) {
				if (dp[visited][i] < 0x3f3f3f3f) {
					ans = max(ans, popcount(visited));
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
			int Arg0 = 3;
			string Arr1[] = {"1 10 10" , "1 55 31", "10 50 100" };
			string Arr2[] = {"1 2 10"};
			int Arg3 = 1;

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, maxStores(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			string Arr1[] = {"1 10 10" , "1 55 30", "10 50 100" };
			string Arr2[] = {"1 2 10"};
			int Arg3 = 2;

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, maxStores(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			string Arr1[] = {"0 1000 17"};
			string Arr2[] = {"2 3 400", "4 1 500", "4 3 300", "1 0 700", "0 2 400"};
			int Arg3 = 0;

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, maxStores(Arg0, Arg1, Arg2));
		}
		n++;



		// 156
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			string Arr1[] = {"143 1560 45", "882 11205 99", "652 6352 22", "558 28451 77", "390 11103 76", "601 21605 11", "870 15559 62", "402 15658 90", "424 11010 3", "183 27272 86", "427 24185 18", "833 5003 33", "155 17345 22", "977 3346 30", "693 11249 26", "435 7877 50"};
			string Arr2[] = {"41 17 134", "0 19 124", "28 8 162", "14 5 145", "31 27 161", "41 45 142", "27 36 191", "4 2 153", "42 32 21", "16 18 95", "47 26 171", "38 19 112", "17 49 35", "44 3 11", "22 33 73", "14 41 111", "3 18 147", "44 12 157", "37 9 123", "41 29 178", "16 35 190", "42 38 106", "40 42 64", "48 46 5", "40 29 170", "0 6 101", "43 48 29", "23 34 154", "16 26 131", "8 44 39", "26 23 137", "38 18 82", "33 15 39", "8 4 130", "27 6 73", "36 21 145", "24 22 70", "40 11 36", "5 24 31", "30 7 191", "7 37 57", "37 3 183", "22 46 106", "30 13 168", "10 9 24", "20 46 21", "35 1 5", "9 39 102", "25 33 69"};
			int Arg3 = 16;

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, maxStores(Arg0, Arg1, Arg2));
		}
		n++;

		// 167
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			string Arr1[] = {"0 100000 1000", "0 100000 1000", "0 100000 1000", "0 100000 1000", "0 100000 1000", "0 100000 1000", "0 100000 1000", "0 100000 1000", "0 100000 1000", "0 100000 1000", "0 100000 1000", "0 100000 1000", "0 100000 1000", "0 100000 1000", "0 100000 1000", "0 100000 1000"};
			string Arr2[] = {"0 1 1000", "1 2 1000", "2 3 1000", "3 4 1000", "4 5 1000", "5 6 1000", "6 7 1000", "7 8 1000", "8 9 1000", "9 10 1000", "10 11 1000", "11 12 1000", "12 13 1000", "13 14 1000", "14 15 1000", "15 16 1000", "16 17 1000", "17 18 1000", "18 19 1000", "19 20 1000", "20 21 1000", "21 22 1000", "22 23 1000", "23 24 1000", "24 25 1000", "25 26 1000", "26 27 1000", "27 28 1000", "28 29 1000", "29 30 1000", "30 31 1000", "31 32 1000", "32 33 1000", "33 34 1000", "34 35 1000", "35 36 1000", "36 37 1000", "37 38 1000", "38 39 1000", "39 40 1000", "40 41 1000", "41 42 1000", "42 43 1000", "43 44 1000", "44 45 1000", "45 46 1000", "46 47 1000", "47 48 1000", "48 49 1000", "49 0 1000"};
			int Arg3 = 16;

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, maxStores(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TravellingPurchasingMan ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
