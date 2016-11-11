// BEGIN CUT HERE
/*
SRM 700 Div2 Medium (450)

問題
-升目状の盤面で宝探しゲームをする
-各升目は、目印がついているか、何もないか、どちらか不明の三通り
-宝は、最も上にある目印の行から最も下にある目印の行まで、最も左にある目印の列から最も右にある目印の列までのどこかにある
-どちらか不明のものについて全ての有無のパターンを列挙するとき、宝がある可能性のある面積の総和を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> IIVec;

class XMarksTheSpot {
public:
	int countArea(vector <string> board) {
		IIVec v;
		int H = (int)board.size(), W = (int)board[0].length();
		int L = W, R = -1, T = H, B = -1;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				switch (board[i][j]) {
				case 'O':
					T = min(T, i);
					B = max(B, i);
					L = min(L, j);
					R = max(R, j);
					break;
				case '?':
					v.push_back(II(i, j));
					break;
				}
			}
		}
		int ans = 0;
		int m = 1 << v.size();
		for (int i = 0; i < m; ++i) {
			int t = T, b = B, l = L, r = R;
			for (int j = 0; j != v.size(); ++j) {
				if (i & (1 << j)) {
					t = min(t, v[j].first);
					b = max(b, v[j].first);
					l = min(l, v[j].second);
					r = max(r, v[j].second);
				}
			}
			ans += (b - t + 1) * (r - l + 1);
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
			string Arr0[] = {
"?.",
".O"
};
			int Arg1 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countArea(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"???",
"?O?",
"???"
};
			int Arg1 = 1952;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countArea(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"...?.",
"?....",
".O...",
"..?..",
"....?"
};
			int Arg1 = 221;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countArea(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"OOOOOOOOOOOOOOOOOOOOO"};
			int Arg1 = 21;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countArea(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"?????????OO??????????"};
			int Arg1 = 9963008;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countArea(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"OOO",
"O?O",
"OOO",
"..."
};
			int Arg1 = 18;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countArea(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	XMarksTheSpot ___test;
	___test.run_test(-1);
}
// END CUT HERE
