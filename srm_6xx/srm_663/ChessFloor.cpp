// BEGIN CUT HERE
/*
SRM 663 Div2 Easy (250)

問題
-格子状の床がある
-各格子の色が文字で与えられる
-2色のチェッカー模様にするための最小変更個数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ChessFloor {
	public:
	int minimumChanges(vector <string> floor) {
		int N = (int)floor.size();
		int ans = N * N;
		for (int a = 'a'; a <= 'z'; ++a) {
			for (int b = 'a'; b <= 'z'; ++b) {
				if (a != b) {
					int c = 0;
					for (int i = 0; i < N; ++i) {
						for (int j = 0; j < N; ++j) {
							c += floor[i][j] != (((i + j) % 2) ? a : b);
						}
					}
					ans = min(ans, c);
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
			string Arr0[] = {"aba",
 "bbb",
 "aba"}
;
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumChanges(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"wbwbwbwb",
 "bwbwbwbw",
 "wbwbwbwb",
 "bwbwbwbw",
 "wbwbwbwb",
 "bwbwbwbw",
 "wbwbwbwb",
 "bwbwbwbw"}
 ;
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumChanges(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"zz",
 "zz"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumChanges(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"helloand",
 "welcomet",
 "osingler",
 "oundmatc",
 "hsixhund",
 "redandsi",
 "xtythree",
 "goodluck"};
			int Arg1 = 56;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumChanges(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"jecjxsengslsmeijrmcx",
 "tcfyhumjcvgkafhhffed",
 "icmgxrlalmhnwwdhqerc",
 "xzrhzbgjgabanfxgabed",
 "fpcooilmwqixfagfojjq",
 "xzrzztidmchxrvrsszii",
 "swnwnrchxujxsknuqdkg",
 "rnvzvcxrukeidojlakcy",
 "kbagitjdrxawtnykrivw",
 "towgkjctgelhpomvywyb",
 "ucgqrhqntqvncargnhhv",
 "mhvwsgvfqgfxktzobetn",
 "fabxcmzbbyblxxmjcaib",
 "wpiwnrdqdixharhjeqwt",
 "xfgulejzvfgvkkuyngdn",
 "kedsalkounuaudmyqggb",
 "gvleogefcsxfkyiraabn",
 "tssjsmhzozbcsqqbebqw",
 "ksbfjoirwlmnoyyqpbvm",
 "phzsdodppzfjjmzocnge"};
			int Arg1 = 376;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumChanges(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ChessFloor ___test;
	___test.run_test(-1);
}
// END CUT HERE
