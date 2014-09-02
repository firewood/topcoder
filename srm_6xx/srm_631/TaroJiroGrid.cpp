// BEGIN CUT HERE
/*
SRM 631 Div1 Easy (250)

問題
-N×Nの升目があり、それぞれの升目は黒か白である
-1回の操作で、1行全部を白に塗るか、または全部を黒に塗ることができる
-それぞれの列について、N/2個より多くの連続する升目がないようにしたい
-最小の操作回数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TaroJiroGrid {

	bool check(const vector <string> &grid) {
		int N = (int)grid.size();
		int t = N / 2;
		for (int i = 0; i < N; ++i) {
			int cnt = 1;
			for (int j = 1; j < N; ++j) {
				if (grid[j-1][i] == grid[j][i]) {
					++cnt;
					if (cnt > t) {
						return false;
					}
				} else {
					cnt = 1;
				}
			}
		}
		return true;
	}

public:
	int getNumber(vector <string> grid) {
		int N = (int)grid.size();
		if (check(grid)) {
			return 0;
		}
		for (int i = 0; i < N; ++i) {
			vector <string> x = grid;
			x[i] = string(N, 'B');
			if (check(x)) {
				return 1;
			}
			x[i] = string(N, 'W');
			if (check(x)) {
				return 1;
			}
		}
		return 2;
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
			string Arr0[] = {"WB",
 "BB"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"WB",
 "WW"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"WB",
 "WB"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"WBBW",
 "WBWB",
 "WWBB",
 "BWWW"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"WBBWBB",
 "BBWBBW",
 "WWBWBW",
 "BWWBBB",
 "WBWBBW",
 "WWWBWB"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
				"WW",
				"BB" };
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TaroJiroGrid ___test;
	___test.run_test(-1);
}
// END CUT HERE
