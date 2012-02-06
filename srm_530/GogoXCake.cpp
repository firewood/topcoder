// BEGIN CUT HERE
/*
// SRM 530 Div2 Medium (500)

問題
ケーキとケーキカッターがある。
ケーキカッターには刃が有効な部分と無効な部分があり、刃をあてるときには有効な部分にケーキがなければならない。
食い散らかしたケーキの結果から、ケーキカッターでその結果が生成可能か求める。

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

// cake: 'X' = contains, '.' = not exist
// cutter: '.' = used, 'X' = ignored

class GogoXCake {

	bool check(int left, int top, StrVec &k, const StrVec &c, bool modify) {
		int height = c.size();
		int width = c[0].length();
		int x, y;
		for (y = 0; y < height; ++y) {
			for (x = 0; x < width; ++x) {
				if (c[y][x] == '.') {
					if (k[top+y][left+x] == '.') {
						if (modify) {
							k[top+y][left+x] = 'X';
						}
					} else {
						return false;
					}
				}
			}
		}
		return true;
	}

public:
	string solve(vector <string> cake, vector <string> cutter) {
		int cake_height = cake.size();
		int cake_width = cake[0].length();
		int cutter_height = cutter.size();
		int cutter_width = cutter[0].length();
		int x, y;
		for (y = 0; y <= (cake_height-cutter_height); ++y) {
			for (x = 0; x <= (cake_width-cutter_width); ++x) {
				if (check(x, y, cake, cutter, false)) {
					// restore cakes if cutter fits
					check(x, y, cake, cutter, true);
				}
			}
		}
		for (y = 0; y < cake_height; ++y) {
			for (x = 0; x < cake_width; ++x) {
				if (cake[y][x] != 'X') {
					return "NO";
				}
			}
		}
		return "YES";
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
			string Arr0[] = {"X.X"
,"..."
,"..."
,"X.X"};
			string Arr1[] = {".X"
,".."
,"X."};
			string Arg2 = "YES";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, solve(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..XX"
,"...X"
,"X..."
,"XX.."};
			string Arr1[] = {".."
,".."};
			string Arg2 = "NO";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, solve(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...X..."};
			string Arr1[] = {"..."};
			string Arg2 = "YES";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, solve(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".X."
,"X.X"
,".X."};
			string Arr1[] = {"."};
			string Arg2 = "YES";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, solve(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"XXXXXXX"
,"X.....X"
,"X.....X"
,"X.....X"
,"XXXXXXX"};
			string Arr1[] = {".X."
,"XXX"
,".X."};
			string Arg2 = "NO";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, solve(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".."
,"X."
,".X"};
			string Arr1[] = {".."
,".X"
,"X."};
			string Arg2 = "NO";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, solve(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"X.."
,".XX"
,".XX"};
			string Arr1[] = {".XX"
,".XX"
,"X.."};
			string Arg2 = "NO";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, solve(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GogoXCake ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
