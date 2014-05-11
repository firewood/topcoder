// BEGIN CUT HERE
/*
SRM 616 Div2 Hard (1000)

問題
-LL株式会社は、ロゴをデザインしようとしている
-N×Mの升目の中に二つのLを含む必要がある
-それぞれの升目は白か黒に塗られている
-白い部分にLを二つ配置する組み合わせの総数を求める

*/
// END CUT HERE

#include <string> 
#include <vector> 
#include <iostream> 
#include <sstream> 
#include <string.h> 

using namespace std; 

typedef long long LL;
typedef pair<int, int> II; 
typedef vector<II> IIVec; 

class TwoLLogo {

	int H;
	int W;
	int v[32][32];
	int h[32][32];

	int count(int x, int y, int hl, int vl) {
		int c = 0;
		int i, j;
		i = y;
		for (j = x + hl; j < W - 1; ++j) {
			c += h[i][j] * v[i][j];
		}
		for (--i; i > 0; --i) {
			if (i <= y-vl) {
				for (j = 0; j < W-1; ++j) {
					c += h[i][j] * v[i][j];
				}
			} else {
				for (j = 0; j <= x-2; ++j) {
					c += min(h[i][j], x-j-1) * v[i][j];
				}
				for (j = x+1; j < W-1; ++j) {
					c += h[i][j] * v[i][j];
				}
			}
		}
		return c;
	}

	public:
	long long countWays(vector <string> grid) {
		H = (int)grid.size();
		W = (int)grid[0].length();
		memset(v, 0, sizeof(v));
		memset(h, 0, sizeof(h));
		for (int i = 1; i < H; ++i) {
			const string &s = grid[i];
			for (int j = 0; j < W - 1; ++j) {
				if (s[j] == '.' && grid[i-1][j] == '.' && s[j+1] == '.') {
					for (int k = i-1; k >= 0; --k) {
						if (grid[k][j] != '.') {
							break;
						}
						v[i][j] += 1;
					}
					for (int k = j+1; k < W; ++k) {
						if (s[k] != '.') {
							break;
						}
						h[i][j] += 1;
					}
				}
			}
		}

		LL ans = 0;
		for (int i = H - 1; i >= 0; --i) {
			for (int j = 0; j < W - 1; ++j) {
				if (v[i][j] > 0) {
					for (int vl = 1; vl <= v[i][j]; ++vl) {
						for (int hl = 1; hl <= h[i][j]; ++hl) {
							ans += count(j, i, hl+1, vl+1);
						}
					}
				}
			}
		}
		return ans;
	}


// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
 "....",
 "...."};
			long long Arg1 = 1LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
 ".##..",
 "...#.",
 ".#.#.",
 "#...#"};
			long long Arg1 = 3LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
 "..#.",
 "#.#.",
 "....",
 "..#."};
			long long Arg1 = 4LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
 "..",
 ".."};
			long long Arg1 = 0LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
 ".#.#",
 "....",
 ".#.#",
 "...."};
			long long Arg1 = 34LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
 "##############",
 "##############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.#####.######",
 "#.#####.######",
 "#.#####.######",
 "#....##.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######......#",
 "##############"};
			long long Arg1 = 1350LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
 "#......",
 ".#....#",
 ".#.#...",
 "#....#.",
 ".##..#.",
 ".#.....",
 ".....#.",
 ".#.#...",
 ".#...#.",
 "..##..."};
			long long Arg1 = 2386LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
 "...#..........................",
 "..............................",
 "..............................",
 "..................#...#.......",
 "..................#...........",
 "..............................",
 "...........#..................",
 "..............................",
 ".....#..#.....................",
 ".......................#......",
 "..................#.....#.....",
 "..............................",
 "..............................",
 "..............................",
 "..............................",
 "..#...........................",
 "..............................",
 "..............................",
 "..............................",
 "#............................#",
 "..............................",
 ".....#.........#............#.",
 "..............................",
 ".........................#....",
 ".#............................",
 ".............#................",
 "..............................",
 "..............................",
 ".......................#......",
 ".............#................"};
			long long Arg1 = 5020791386LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, countWays(Arg0));
		}
		n++;

	}

// END CUT HERE


};
// BEGIN CUT HERE 
int main() {
	TwoLLogo ___test;
	___test.run_test(-1);

}
// END CUT HERE

