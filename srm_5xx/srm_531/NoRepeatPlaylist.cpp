// BEGIN CUT HERE
/*
// SRM 531 Div2 Medium (600)

問題

N種類の曲がある。
P曲からなるプレイリストを作りたい。
同じ曲は間隔Mだけ空ける必要がある。
何通りのプレイリストが作れるかを求める。

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

#define MOD 1000000007LL

class NoRepeatPlaylist {

	int numPlaylists(int N, int M, int P) {
		LL dp[120][120] = {0};
		dp[0][0] = 1;
		int i, j;
		for (i = 1; i <= P; ++i) {
			for (j = 1; j <= N; ++j) {
				dp[i][j] = (dp[i-1][j-1]*(N-j+1) + dp[i-1][j]*max(0, j-M)) % MOD;
			}
		}
		return (int)dp[P][N];
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
			int Arg0 = 1;
			int Arg1 = 0;
			int Arg2 = 3;
			int Arg3 = 1;

			verify_case(n, Arg3, numPlaylists(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 3;
			int Arg3 = 0;

			verify_case(n, Arg3, numPlaylists(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 0;
			int Arg2 = 3;
			int Arg3 = 6;

			verify_case(n, Arg3, numPlaylists(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 0;
			int Arg2 = 4;
			int Arg3 = 24;

			verify_case(n, Arg3, numPlaylists(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			int Arg2 = 4;
			int Arg3 = 2;

			verify_case(n, Arg3, numPlaylists(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arg1 = 5;
			int Arg2 = 100;
			int Arg3 = 222288991;

			verify_case(n, Arg3, numPlaylists(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NoRepeatPlaylist ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
