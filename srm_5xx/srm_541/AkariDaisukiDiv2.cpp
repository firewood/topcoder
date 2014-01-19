// BEGIN CUT HERE
/*
// SRM 541 Div2 Easy (250)

問題
以下のような形式に文字列を分解するあかり関数f(X)を考える。
「わーい ○○ あかり ○○ 大好き」
ここで「わーい」「○○」「あかり」「大好き」は、それぞれ1文字以上の文字列である。
「○○」には同じ文字列が入る。
与えられた文字列に対して、あかり関数を満たすのは何通りか求める。

*/
// END CUT HERE
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class AkariDaisukiDiv2 {

public:
	int countTuples(string S) {
		int result = 0;
		int i, j, k;
		int N = S.length();
		const char *s = S.c_str();
		for (i = 1; i <= (N-4); ++i) {
			for (j = 1; j <= (N-i-3); ++j) {
				for (k = i+j+1; k <= (N-j-1); ++k) {
					if (memcmp(s+i, s+k, j) == 0) {
						++result;
					}
				}
			}
		}
		return result;
	}

// BEGIN CUT HERE
private:
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "topcoderdivtwo";
			int Arg1 = 2;

			verify_case(n, Arg1, countTuples(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "foxciel";
			int Arg1 = 0;

			verify_case(n, Arg1, countTuples(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "magicalgirl";
			int Arg1 = 4;

			verify_case(n, Arg1, countTuples(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "waaiusushioakariusushiodaisuki";
			int Arg1 = 75;

			verify_case(n, Arg1, countTuples(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
			int Arg1 = 8924;

			verify_case(n, Arg1, countTuples(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AkariDaisukiDiv2 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
