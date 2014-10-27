// BEGIN CUT HERE
/*
SRM 637 Div2 Medium (500)

問題
-幅が2の通路がある
-#の部分は通れない
-左から右に通れるようにしながら、#が埋められる個数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class PathGameDiv2 {
public:
	int calc(vector <string> board) {
		int ans = 0;
		int N = (int)board[0].size();
		board[0] += "..";
		board[1] += "..";
		for (int pos = 1; pos < N; ++pos) {
			if (board[0][pos] == '.' && board[1][pos] == '.') {
				if (board[0][pos-1] != '.' && board[1][pos + 1] == '.') {
					++ans;
					board[0][pos] = '#';
				}
				if (board[1][pos-1] != '.' && board[0][pos + 1] == '.') {
					++ans;
					board[1][pos] = '#';
				}
			}
		}

		int a = board[0].find('#');
		int b = board[1].find('#');
		int c = min((a >= 0 ? a : N), (b >= 0 ? b : N));
		ans += c;

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
			string Arr0[] = {"#...."
,"...#."};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, calc(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#"
,"."};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, calc(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"."
,"."};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, calc(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"....#.##.....#..........."
,"..#......#.......#..#...."};
			int Arg1 = 13;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, calc(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PathGameDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
