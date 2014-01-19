// BEGIN CUT HERE
/*
SRM 583 Div1 Easy (250)

問題
-火星にN個の駅がある電車が走っている
-駅は円周上になっていて0とN-1がつながっている
-ある駅から直通で移動できる駅の数が与えられる
-始点と終点が与えられたとき、直通電車の最小乗車回数を求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TravelOnMars {
public:
	int minTimes(vector <int> range, int startCity, int endCity) {
		int N = (int)range.size();
		int dist[50][50];
		memset(dist, 0x3f, sizeof(dist));
		int i, j, k;
		for (i = 0; i < N; ++i) {
			for (j = -range[i]; j <= range[i]; ++j) {
				dist[i][(((i+j)%N)+N)%N] = 1;
			}
//			for (j = 0; j < N; ++j) {
//				if (min(abs(i-j), abs(i+N-j)) <= range[i]) {
//					dist[i][j] = 1;
//				}
//			}
		}
		for (k = 0; k < N; ++k) {
			for (i = 0; i < N; ++i) {
				for (j = 0; j < N; ++j) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		return dist[startCity][endCity];
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
			int Arr0[] = {2,1,1,1,1,1};
			int Arg1 = 1;
			int Arg2 = 4;
			int Arg3 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, minTimes(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,1,1,1,1,1};
			int Arg1 = 4;
			int Arg2 = 1;
			int Arg3 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, minTimes(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,1,1,2,1,2,1,1};
			int Arg1 = 2;
			int Arg2 = 6;
			int Arg3 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, minTimes(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,2,1,1,3,1,2,2,1,1,2,2,2,2,3};
			int Arg1 = 6;
			int Arg2 = 13;
			int Arg3 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, minTimes(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50,50};
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, minTimes(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TravelOnMars ___test;
	___test.run_test(-1);
}
// END CUT HERE
