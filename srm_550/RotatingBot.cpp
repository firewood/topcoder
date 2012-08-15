// BEGIN CUT HERE
/*
// SRM 550 Div1 Easy (250)

問題
直進と左90℃ターンを交互に行うロボットがW×Hの升目を移動する。
ロボットは初期状態で東を向いていて、壁か一度でも通ったところの手前でターンする。
ターンしても進めなくなるか、途中で停止したログが与えられる。
W×Hを求める。不正なログの場合は-1を返す。

*/
// END CUT HERE
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

static const int dx[4] = {1,0,-1,0};
static const int dy[4] = {0,-1,0,1};

class RotatingBot {

public:
	int minArea(vector <int> moves) {
		int x = 64, y = 64;
		int minX = x, maxX = x, minY = y, maxY = y;
		int sz = (int)moves.size();
		int i, j;
		for (i = 0; i < sz; ++i) {
			x += dx[i%4] * moves[i];
			y += dy[i%4] * moves[i];
			minX = min(minX, x);
			maxX = max(maxX, x);
			minY = min(minY, y);
			maxY = max(maxY, y);
		}
		int W = maxX - minX;
		int H = maxY - minY;
		if (W > 50 || H > 50) {
			return -1;
		}
		int f[128][128] = {};
		for (i = 0; i < 128; ++i) {
			f[minY-1][i] = 1;
			f[maxY+1][i] = 1;
			f[i][minX-1] = 1;
			f[i][maxX+1] = 1;
		}
		x = 64, y = 64;
		f[y][x] = 1;
		for (i = 0; i < sz; ++i) {
			for (j = 0; j < moves[i]; ++j) {
				x += dx[i%4];
				y += dy[i%4];
				if (f[y][x]) {
					return -1;
				}
				f[y][x] = 1;
			}
			if (i == (sz-1)) {
				break;
			}
			if (!f[y + dy[i%4]][x + dx[i%4]]) {
				return -1;
			}
		}
		return (W+1)*(H+1);
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
			int Arr0[] = {15};
			int Arg1 = 16;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minArea(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,10};
			int Arg1 = 44;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minArea(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1};
			int Arg1 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minArea(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9,5,11,10,11,4,10};
			int Arg1 = 132;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minArea(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15};
			int Arg1 = 420;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minArea(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8,6,6,1};
			int Arg1 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minArea(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8,6,6};
			int Arg1 = 63;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minArea(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,4,5,3,3};
			int Arg1 = 30;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minArea(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RotatingBot ___test;
	___test.run_test(3);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
