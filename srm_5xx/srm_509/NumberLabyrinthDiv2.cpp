// BEGIN CUT HERE
/*
// SRM 509 Div2 Hard (1000)

問題
縦R×横Cのマス目があり、空または数字が書いてある。
数字が書いてあるコマからは、その数値だけ縦または横にジャンプできる。
空のマスには全体でK個だけ数字を書くことができる。
始点と終点が与えられるとき、最小のジャンプ回数を求める。

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

struct P {
	int x;
	int y;
	int z;
	P(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};
typedef vector<P> PVec;

const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};

class NumberLabyrinthDiv2 {

public:
	int getMinimumNumberOfMoves(vector <string> board, int r1, int c1, int r2, int c2, int K) {
		int W = board[0].length();
		int H = board.size();
		int dist[50][50];
		memset(dist, -1, sizeof(dist));
		PVec q;
		int a, b, d, dir, i, k, x, y, z;
		q.push_back(P(c1, r1, 0));
		for (k = 0; k <= K; ++k) {
			PVec kq;
			while (q.size() > 0) {
				PVec next;
				for (i = 0; i < (int)q.size(); ++i) {
					x = q[i].x;
					y = q[i].y;
					z = q[i].z;
					if (dist[y][x] >= 0 && dist[y][x] < z) {
						continue;
					}
					dist[y][x] = z++;
					if (board[y][x] == '.') {
						board[y][x] = '1';
						for (d = 1; d <= 9; ++d) {
							for (dir = 0; dir < 4; ++dir) {
								a = x + dx[dir] * d;
								b = y + dy[dir] * d;
								if (a >= 0 && a < W && b >= 0 && b < H) {
									kq.push_back(P(a, b, z));
								}
							}
						}
					} else {
						d = board[y][x] - '0';
						if (d <= 0) {
							continue;
						}
						for (dir = 0; dir < 4; ++dir) {
							a = x + dx[dir] * d;
							b = y + dy[dir] * d;
							if (a >= 0 && a < W && b >= 0 && b < H) {
								next.push_back(P(a, b, z));
							}
						}
					}
				}
				q = next;
			}
			q = kq;
		}

		return dist[r2][c2];
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
			string Arr0[] = {"...2",
 "....",
 "3..."};
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 2;
			int Arg4 = 3;
			int Arg5 = 0;
			int Arg6 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...2",
 "....",
 "3..."};
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 2;
			int Arg4 = 3;
			int Arg5 = 1;
			int Arg6 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...3",
 "....",
 "2..."};
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 2;
			int Arg4 = 3;
			int Arg5 = 3;
			int Arg6 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"55255",
 ".0.0.",
 "..9..",
 "..3..",
 "3.9.3",
 "44.44"};
			int Arg1 = 3;
			int Arg2 = 2;
			int Arg3 = 4;
			int Arg4 = 2;
			int Arg5 = 10;
			int Arg6 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"920909949",
 "900020000",
 "009019039",
 "190299149",
 "999990319",
 "940229120",
 "000409399",
 "999119320",
 "009939999"};
			int Arg1 = 7;
			int Arg2 = 3;
			int Arg3 = 1;
			int Arg4 = 1;
			int Arg5 = 50;
			int Arg6 = 10;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"4...0"};
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 0;
			int Arg4 = 4;
			int Arg5 = 0;
			int Arg6 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"49.18846913023488.09377.", "2943667.250.2430780.0468", "575.31.7.3.5.540.6.2.226", ".36.9083921.507357.31450", ".42.8777.168331.54.0473.", "12346856197.515420056160", "550.13.58193.39125.776..", "616.4.2962986703..6.25.6", "..04315.2.06.244421..328", "1.5533.021772.65.609.723", "9338875.5.4833.865286823", "3312.4669935592.98810896", "2.28940272666.22.5731.3.", "70199.3..57..71897149376", "93..41.02090....65852.2.", "53519..74868.58357356132", "909....3137.466.10627470", "..761.8..4.84.0619772156", "3...55.52605594221.9.242", "..93.294364.0343.4.42295", "5.141582555793.1.20.8447", "810.5.5..82.20177815.28.", "48.114.97090.3..020223.9", ".21.490.40.74.4..2..6..6", "1..41.0214480487591987.7", "..75.70.5.58.701.4.18680", "4..089978515.1662.418446", "8473.4445360.297..290852", "99640..84703049772997534", "2525399.525744480501...8", "1748.9144697278..2436.07", "50.3.7.114.31295871.1.90", "0338152661.79...3946.2.8", "9170.40176...15633112.26"
			};

			int Arg1 = 31;
			int Arg2 = 21;
			int Arg3 = 1;
			int Arg4 = 0;
			int Arg5 = 2;
			int Arg6 = 8;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NumberLabyrinthDiv2 ___test;
//	___test.run_test(1);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
