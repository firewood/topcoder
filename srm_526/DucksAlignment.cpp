// BEGIN CUT HERE
/*
// SRM 526 Div1 Easy (250)

問題

升目状の盤面にアヒルが何匹かいる。
位置はばらばらで、列または行に最大でも1匹しかいない。
水平または垂直に、連続するように並べたい。
1回に1マスずつ動かすとして、最小の手数を求める。

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <algorithm>
#include <numeric>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;

class DucksAlignment {

	int _calc(const IntVec &h, const IntVec &v) {
		int result = 0;		// コスト
		int i, j;

		// 垂直位置を揃える
		int sum = accumulate(v.begin(), v.end(), 0);
		// 揃える位置の計算 (四捨五入)
		int mid = (sum + v.size() / 2) / v.size();
		for (i = 0; i < (int)v.size(); ++i) {
			// 位置midに揃える
			result += abs(mid - v[i]);
		}

		// 水平位置を揃える
		int min_cost = 1000000;
		for (i = h[0]; ; ++i) {
			int cost = 0;
			for (j = 0; j < (int)h.size(); ++j) {
				// 水平位置iから揃える
				cost += abs(i + j - h[j]);
			}
			if (cost >= min_cost) {
				// コストが増加したら終了
				break;
			}
			min_cost = cost;
		}
		result += min_cost;

		return result;
	}

public:
	int minimumTime(vector <string> grid) {
		int height = grid.size();
		int width = grid[0].length();

		// 水平位置と垂直位置は独立して計算可能なので、別に持っておく
		IntVec h;
		IntVec v;
		int x, y;
		for (y = 0; y < height; ++y) {
			const string &s = grid[y];
			for (x = 0; x < width; ++x) {
				if (s[x] != '.') {
					h.push_back(x);
					v.push_back(y);
				}
			}
		}
		sort(h.begin(), h.end());
		sort(v.begin(), v.end());

		// 水平と水平を入れ替えて、少ないほうが答え
		return min(_calc(h, v), _calc(v, h));
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
			string Arr0[] = {".o",
 "o."};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumTime(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".o...",
 "..o..",
 "....o"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumTime(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"o..........",
 "..o........",
 ".......o...",
 "...........",
 "...........",
 "...........",
 "........o..",
 "..........."};
			int Arg1 = 16;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumTime(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".........",
 "....o....",
 "........."};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumTime(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...o..........................",
 "............................o.",
 ".o............................",
 "............o.................",
 ".................o............",
 "......................o.......",
 "......o.......................",
 "....o.........................",
 "...............o..............",
 ".......................o......",
 "...........................o..",
 ".......o......................"};
			int Arg1 = 99;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minimumTime(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DucksAlignment ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
