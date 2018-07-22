// BEGIN CUT HERE
/*
TCO18 Round 3B Easy (250)

問題
-Xanaduと呼ばれる無限の大きさの2次元グリッドがある
-一か所だけ正方形の形で黒く塗りつぶされていて、そのほかの部分は白である
-Xanaduの一部分を切り取った盤面が与えられる
-もしXanaduとしての条件を満たす場合、正方形の最小の大きさを求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class SquareCutout {
public:
	int verify(vector <string> cutout) {
		int H = (int)cutout.size(), W = (int)cutout[0].length();
		int sx = 0, sy = 0, ex = 1, ey = 1;
		bool done = false;
		for (int y = 0; y < H; ++y) {
			for (int x = 0; x < W; ++x) {
				if (cutout[y][x] == '#') {
					if (done) {
						return 0;
					}
					sx = ex = x;
					sy = ey = y;
					done = true;
					while (ey < H && cutout[ey][x] == '#') {
						++ey;
					}
					while (ex < W && cutout[y][ex] == '#') {
						++ex;
					}
					for (int yy = sy; yy < ey; ++yy) {
						for (int xx = sx; xx < ex; ++xx) {
							if (cutout[yy][xx] != '#') {
								return 0;
							}
							cutout[yy][xx] = '-';
						}
					}
				}
			}
		}
		int width = ex - sx, height = ey - sy;
		if ((!sx || ex >= W) && width < height) {
			width = height;
		}
		if ((!sy || ey >= H) && height < width) {
			height = width;
		}
		return width == height ? width : 0;
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
			string Arr0[] = {".....",
 "..##.",
 "..##.",
 ".....",
 "....."};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, verify(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...",
 "..."};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, verify(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".....",
 ".###.",
 ".#.#.",
 ".###.",
 "....."};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, verify(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..####",
 "..####",
 "......"};
			int Arg1 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, verify(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..#..",
 ".###.",
 "#####",
 ".###.",
 "..#.."};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, verify(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SquareCutout ___test;
	___test.run_test(-1);
}
// END CUT HERE
