// BEGIN CUT HERE
/*
SRM 655 Div1 Easy (250)

問題
-碁盤があり、各升目の初期状態はWである
-K×Kの大きさ単位でBまたはWで塗りつぶす
-与えられた碁盤の状態に書き換え可能かどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef vector<string> StrVec;

class BichromePainting {

	int N;
	int K;
	StrVec b;

	bool possible() {
		bool next = true;
		while (next) {
			next = false;
			for (int i = 0; i <= N - K; ++i) {
				for (int j = 0; j <= N - K; ++j) {
					int cnt[256] = {};
					for (int k = 0; k < K; ++k) {
						for (int l = 0; l < K; ++l) {
							cnt[(int)b[i + k][j + l]] += 1;
						}
					}
					if ((cnt['B'] == 0 && cnt['W'] > 0) || (cnt['B'] > 0 && cnt['W'] == 0)) {
						next = true;
						for (int k = 0; k < K; ++k) {
							for (int l = 0; l < K; ++l) {
								b[i + k][j + l] = '.';
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (b[i][j] == 'B') {
					return false;
				}
			}
		}
		return true;
	}

public:
	string isThatPossible(vector <string> board, int k) {
		N = (int)board.size();
		K = k;
		b = board;
		return possible() ? "Possible" : "Impossible";
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
			string Arr0[] = {"BBBW",
 "BWWW",
 "BWWW",
 "WWWW"};
			int Arg1 = 3;
			string Arg2 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isThatPossible(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"BW",
 "WB"}
;
			int Arg1 = 2;
			string Arg2 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isThatPossible(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"BWBWBB",
 "WBWBBB",
 "BWBWBB",
 "WBWBBB",
 "BBBBBB",
 "BBBBBB"}
;
			int Arg1 = 2;
			string Arg2 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isThatPossible(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "BBBBBB"}
;
			int Arg1 = 2;
			string Arg2 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isThatPossible(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "BBBBBB"}
;
			int Arg1 = 1;
			string Arg2 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isThatPossible(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"BB",
 "BB"};
			int Arg1 = 2;
			string Arg2 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isThatPossible(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "WBB", "BBB", "WBB" };
			int Arg1 = 3;
			string Arg2 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isThatPossible(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BichromePainting ___test;
	___test.run_test(-1);
}
// END CUT HERE
