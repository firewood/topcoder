// BEGIN CUT HERE
/*
SRM 578 Div1 Easy (250)

問題
-檻の中にガチョウとアヒルがいる
-ガチョウは1匹以上、合計で偶数匹いる
-あるガチョウからマンハッタン距離dist以内にいる鳥はガチョウである
-ガチョウとアヒルの取りうる組み合わせを求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

#define MOD 1000000007

class GooseInZooDivOne {
	vector <string> _field;
	int _dist;
	int _visited[50][50];

	int dfs(int x, int y) {
		if (_visited[y][x] || _field[y][x] == '.') {
			return 0;
		}
		int birds = _visited[y][x] = 1;
		int i, j;
		for (i = -_dist; i <= _dist; ++i) {
			for (j = -_dist; j <= _dist; ++j) {
				if ((abs(i)+abs(j)) <= _dist &&
					(y+i) >= 0 && (y+i) < (int)_field.size() &&
					(x+j) >= 0 && (x+j) < (int)_field[0].length()) {
						birds += dfs(x+j, y+i);
				}
			}
		}
		return birds;
	}

public:
	int count(vector <string> field, int dist) {
		_field = field;
		_dist = dist;
		memset(_visited, 0, sizeof(_visited));
		int groups = 0;
		int i, x, y;
		int geese[50*50];
		for (y = 0; y < (int)field.size(); ++y) {
			for (x = 0; x < (int)field[0].length(); ++x) {
				int birds = dfs(x, y);
				if (birds > 0) {
					geese[groups++] = birds;
				}
			}
		}
		int dp[2] = {1, 0};
		for (i = 0; i < groups; ++i) {
			int even = dp[0];
			int odd = dp[1];
			if ((geese[i] % 2) == 0) {
				even *= 2;
				odd *= 2;
			} else {
				even += odd;
				odd = even;
			}
			dp[0] = even % MOD;
			dp[1] = odd % MOD;
		}
		return (dp[0] - 1 + MOD) % MOD;
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
			string Arr0[] = {"vvv"};
			int Arg1 = 0;
			int Arg2 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"."};
			int Arg1 = 100;
			int Arg2 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"vvv"};
			int Arg1 = 1;
			int Arg2 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"v.v..................v............................"
,".v......v..................v.....................v"
,"..v.....v....v.........v...............v......v..."
,".........vvv...vv.v.........v.v..................v"
,".....v..........v......v..v...v.......v..........."
,"...................vv...............v.v..v.v..v..."
,".v.vv.................v..............v............"
,"..vv.......v...vv.v............vv.....v.....v....."
,"....v..........v....v........v.......v.v.v........"
,".v.......v.............v.v..........vv......v....."
,"....v.v.......v........v.....v.................v.."
,"....v..v..v.v..............v.v.v....v..........v.."
,"..........v...v...................v..............v"
,"..v........v..........................v....v..v..."
,"....................v..v.........vv........v......"
,"..v......v...............................v.v......"
,"..v.v..............v........v...............vv.vv."
,"...vv......v...............v.v..............v....."
,"............................v..v.................v"
,".v.............v.......v.........................."
,"......v...v........................v.............."
,".........v.....v..............vv.................."
,"................v..v..v.........v....v.......v...."
,"........v.....v.............v......v.v............"
,"...........v....................v.v....v.v.v...v.."
,"...........v......................v...v..........."
,"..........vv...........v.v.....................v.."
,".....................v......v............v...v...."
,".....vv..........................vv.v.....v.v....."
,".vv.......v...............v.......v..v.....v......"
,"............v................v..........v....v...."
,"................vv...v............................"
,"................v...........v........v...v....v..."
,"..v...v...v.............v...v........v....v..v...."
,"......v..v.......v........v..v....vv.............."
,"...........v..........v........v.v................"
,"v.v......v................v....................v.."
,".v........v................................v......"
,"............................v...v.......v........."
,"........................vv.v..............v...vv.."
,".......................vv........v.............v.."
,"...v.............v.........................v......"
,"....v......vv...........................v........."
,"....vv....v................v...vv..............v.."
,".................................................."
,"vv........v...v..v.....v..v..................v...."
,".........v..............v.vv.v.............v......"
,".......v.....v......v...............v............."
,"..v..................v................v....v......"
,".....v.....v.....................v.v......v......."};
			int Arg1 = 3;
			int Arg2 = 898961330;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"vv"};
			int Arg1 = 1;
			int Arg2 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"vv"};
			int Arg1 = 0;
			int Arg2 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"vvvv"};
			int Arg1 = 0;
			int Arg2 = 7;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GooseInZooDivOne ___test;
	___test.run_test(-1);
}
// END CUT HERE
