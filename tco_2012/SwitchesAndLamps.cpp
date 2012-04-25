// BEGIN CUT HERE
/*
// TCO 2012 R2A Easy (300)

問題
N個のスイッチとN個の電灯がある。
それぞれのスイッチと電灯との位置関係はばらばらである。
どのスイッチが接続されているか何回かチェックした。
あと何回チェックすれば対応関係がわかるかを求める。

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

static int popcount(LL bits) {
	bits = (bits & 0x5555555555555555) + (bits >>  1 & 0x5555555555555555);
	bits = (bits & 0x3333333333333333) + (bits >>  2 & 0x3333333333333333);
	bits = (bits & 0x0f0f0f0f0f0f0f0f) + (bits >>  4 & 0x0f0f0f0f0f0f0f0f);
	bits = (bits & 0x00ff00ff00ff00ff) + (bits >>  8 & 0x00ff00ff00ff00ff);
	bits = (bits & 0x0000ffff0000ffff) + (bits >> 16 & 0x0000ffff0000ffff);
	bits = (bits & 0x00000000ffffffff) + (bits >> 32 & 0x00000000ffffffff);
	return (int)bits;
}

class SwitchesAndLamps {

public:
	int theMin(vector <string> switches, vector <string> lamps) {
		int H = switches.size();
		int W = switches[0].length();

		LL b, sw[64] = {}, la[64] = {};
		int i, j;
		for (i = 0; i < H; ++i) {
			b = 1;
			for (j = 0; j < W; ++j, b <<= 1) {
				if (switches[i][j] == 'Y') {
					sw[i] |= b;
				}
				if (lamps[i][j] == 'Y') {
					la[i] |= b;
				}
			}
		}

		LL mask = (1LL << W) - 1;
		int Max = 0;
		b = 1;
		for (j = 0; j < W; ++j, b <<= 1) {
			LL s = -1, l = -1;
			for (i = 0; i < H; ++i) {
				if (sw[i] & b) {
					s &= sw[i];
					l &= la[i];
				} else {
					s &= ~sw[i];
					l &= ~la[i];
				}
			}
			int ps = popcount(s & mask);
			int pl = popcount(l & mask);
			if (ps != pl) {
				return -1;
			}
			Max = max(Max, ps);
		}

		int res = 0;
		while (Max > 1) {
			Max -= Max / 2;
			++res;
		}
		return res;
	}

// BEGIN CUT HERE
private:
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYNN", "NNYN"};
			string Arr1[] = {"NNNY", "NNYN"};
			int Arg2 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, theMin(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"YYN", "YNY", "YYN"};
			string Arr1[] = {"YNY", "NYY", "YNY"};
			int Arg2 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, theMin(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYYYNYNNYYYNYNNNNY", "NYYYNYNNYYYNYNNNNY"};
			string Arr1[] = {"YYYNNNYNNYNYNYNYNY", "YYYNNNYNNYNYYNNYNY"};
			int Arg2 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, theMin(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"YYNNN", "NNYYN"};
			string Arr1[] = {"NYNNY", "NNNYY"};
			int Arg2 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, theMin(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"YNNYNNYNYY", "NYNNYNYNYN", "YNYNYYYYYN", "NNYYNYNYNN"};
			string Arr1[] = {"NYYNYNNYNY", "NYYYNNYNNN", "YYYYNYNNYY", "YNNNNYNYYN"};
			int Arg2 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, theMin(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SwitchesAndLamps ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
