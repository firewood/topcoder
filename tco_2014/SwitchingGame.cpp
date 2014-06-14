// BEGIN CUT HERE
/*
TCO 2014 Round 2B Easy (350)

PROBLEM STATEMENT
-M個のランプがあり初期状態は消灯している
-何個かのランプをONにする、OFFにする、次のレベルに行くボタンを押す、のいずれかに1秒かかる
-設定すべきランプの状態がONまたはOFFまたはどちらでもよい、で与えられる
-レベルを一つずつクリアしていくとき、最短秒数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SwitchingGame {
public:
	int timeToWin(vector <string> states) {
		int N = (int)states.size();
		int M = (int)states[0].length();
		int ans = N;
		char st[64] = "---------------------------------------------------------------";
		for (int i = 0; i < N; ++i) {
			bool on = false, off = false;
			for (int j = 0; j < M; ++j) {
				if (states[i][j] == '+' && st[j] == '-') {
					on = true;
				}
				if (states[i][j] == '-' && st[j] == '+') {
					off = true;
				}
			}
			for (int j = 0; j < M; ++j) {
				if (states[i][j] == '?') {
					if ((on && st[j] == '-') || (off && st[j] == '+')) {
						st[j] = '?';
					}
				} else {
					st[j] = states[i][j];
				}
			}
			ans += on + off;
		}
		return ans;
	}

// BEGIN CUT HERE
	int timeToWin2(vector <string> states) {
		int N = (int)states.size();
		int M = (int)states[0].length();
		int ans = N;
		int st[64] = {};
		int off[64] = {};
		int on[64] = {};
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (states[i][j] == '-' && st[j] != 0) {
					int x = 1;
					for (int k = i - 1; k >= 0; --k) {
						if (states[k][j] != '?') {
							break;
						}
						if (off[k]) {
							x = 0;
						}
					}
					off[i] |= x;
				}
				if (states[i][j] == '+' && st[j] == 0) {
					int x = 1;
					for (int k = i - 1; k >= 0; --k) {
						if (states[k][j] != '?') {
							break;
						}
						if (on[k]) {
							x = 0;
						}
					}
					on[i] |= x;
				}
			}
			ans += off[i] + on[i];
			for (int j = 0; j < M; ++j) {
				if (states[i][j] == '-') {
					st[j] = 0;
				}
				if (states[i][j] == '+') {
					st[j] = 1;
				}
			}
		}

		return ans;
	}

private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"++--",
 "--++"};
			int Arg1 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, timeToWin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"+-++",
 "+-++"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, timeToWin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"++",
 "+?",
 "?+",
 "++"};
			int Arg1 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, timeToWin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"+", 
 "?",
 "?",
 "?",
 "-"};
			int Arg1 = 7;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, timeToWin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"+??+++",
 "++??+-",
 "?++??+",
 "?-+-??",
 "??+?++",
 "++-?+?",
 "?++?-+",
 "?--+++",
 "-??-?+"}
;
			int Arg1 = 20;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, timeToWin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SwitchingGame ___test;
	___test.run_test(-1);

	vector<string> v(3);
	v[0] = "???";
	v[1] = "???";
	v[2] = "???";

	for (int a = 0; a < 19683; ++a) {
		const char ch[] = "?-+";
		int r = a;
		for (int b = 0; b < 9; ++b) {
			v[b / 3][b % 3] = ch[r % 3];
			r /= 3;
		}
		int p = ___test.timeToWin2(v);
		int q = ___test.timeToWin(v);
		if (p != q) {
			cout << "mine:" << p << ",target:" << q << endl;
			for (int i = 0; i < 3; ++i) {
				printf("%s\n", v[i].c_str());
			}
			break;
		}
	}
}
// END CUT HERE
