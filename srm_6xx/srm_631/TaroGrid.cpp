// BEGIN CUT HERE
/*
SRM 631 Div2 Easy (250)

問題
-黒か白に塗られた升目がある
-縦に同じ色が連続する最大の個数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TaroGrid {
public:
	int getNumber(vector <string> grid) {
		int ans = 1;
		int N = (int)grid.size();
		for (int c = 0; c < N; ++c) {
			int cnt = 1;
			for (int r = 1; r < N; ++r) {
				if (grid[r - 1][c] == grid[r][c]) {
					++cnt;
					ans = max(ans, cnt);
				} else {
					cnt = 1;
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
			string Arr0[] = {"W"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"WB",
 "BW"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"BWW",
 "BBB",
 "BWB"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"BWBW",
 "BBWB",
 "WWWB",
 "BWWW"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"BWB",
 "BBW",
 "BWB"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"BBWWBBWW",
 "BBWWBBWW",
 "WWBBWWBB",
 "WWBBWWBB",
 "BBWWBBWW",
 "BBWWBBWW",
 "WWBBWWBB",
 "WWBBWWBB"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TaroGrid ___test;
	___test.run_test(-1);
}
// END CUT HERE
