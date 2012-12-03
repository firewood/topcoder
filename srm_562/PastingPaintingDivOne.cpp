// BEGIN CUT HERE
/*
// SRM 562 Div1 Easy (250)

問題
きゅうり君は絵を描くのが大好きである。
クリップボードにRGBの点で描かれた絵が格納されている。
絵を横1縦1ピクセルずつずらしてキャンバスに貼り付ける。
絵の点がある部分は上書きされ、ない部分はそのままである。
T回ペーストしたときのRGBの点の総数を求める。

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;

class PastingPaintingDivOne {

public:
	vector<long long> countColors(vector <string> clipboard, int T) {
		LLVec res(3);

		int tbl[128];
		tbl['.'] = -1;
		tbl['R'] = 0;
		tbl['G'] = 1;
		tbl['B'] = 2;

		int i, j, k, color;
		for (i = 0; i < (int)clipboard.size(); ++i) {
			for (j = 0; j < (int)clipboard[0].length(); ++j) {
				color = tbl[clipboard[i][j]];
				if (color >= 0) {
					int cnt = T;
					for (k = 1; k <= T; ++k) {
						if (k > i || k > j) {
							break;
						}
						if (tbl[clipboard[i-k][j-k]] >= 0) {
							cnt = k;
							break;
						}
					}
					res[color] += cnt;
				}
			}
		}

		return res;
	}


// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"..G",
"R..",
"BG."
};
			int Arg1 = 3;
			long Arr2[] = {3, 4, 3 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, countColors(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"R...",
"....",
"....",
"...R"
};
			int Arg1 = 2;
			long Arr2[] = {4, 0, 0 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, countColors(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"RGB"};
			int Arg1 = 100000;
			long Arr2[] = {100000, 100000, 100000 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, countColors(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"."};
			int Arg1 = 1000000000;
			long Arr2[] = {0, 0, 0 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, countColors(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"RB.",
".G."
}
;
			int Arg1 = 100;
			long Arr2[] = {100, 1, 100 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, countColors(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"..........G..........",
".........G.G.........",
"........G...G........",
".......G.....G.......",
"......G..B.B..G......",
".....G...B.B...G.....",
"....G...........G....",
"...G...R.....R...G...",
"..G.....RRRRRR....G..",
".G..........RR.....G.",
"GGGGGGGGGGGGGGGGGGGGG"
};
			int Arg1 = 1000000000;
			LL Arr2[] = {2000000018LL, 17000000048LL, 2000000005LL };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, countColors(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PastingPaintingDivOne ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
