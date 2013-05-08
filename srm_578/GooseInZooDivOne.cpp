// BEGIN CUT HERE
/*
SRM 578 Div1 Easy (250)

PROBLEM STATEMENT
Crow Keith is looking at the goose cage in the zoo.
The bottom of the cage is divided into a grid of square cells.
There are some birds sitting on those cells (with at most one bird per cell).
Some of them are geese and all the others are ducks.

Keith wants to know which birds are geese.
He knows the following facts about them:

There is at least one goose in the cage.
The number of geese is even.
Each bird within Manhattan distance dist of any goose is also a goose.

 
You are given a vector <string> field and the int dist.
The array field describes the bottom of the cage.
Each character of each element of field describes one of the cells.
The meaning of individual characters follows.

The character 'v' represents a cell that contains a bird.
The character '.' represents an empty cell.


Return the number of possible sets of geese in the cage, modulo 1,000,000,007.
Note that for some of the test cases there can be no possible sets of geese.

DEFINITION
Class:GooseInZooDivOne
Method:count
Parameters:vector <string>, int
Returns:int
Method signature:int count(vector <string> field, int dist)


NOTES
-The Manhattan distance between cells (a,b) and (c,d) is |a-c| + |b-d|, where || denotes absolute value. In words, the Manhattan distance is the smallest number of steps needed to get from one cell to the other, given that in each step you can move to a cell that shares a side with your current cell.


CONSTRAINTS
-field will contain between 1 and 50 elements, inclusive.
-Each element of field will contain between 1 and 50 characters, inclusive.
-Each element of field will contain the same number of characters.
-Each character of each element of field will be 'v' or '.'.
-dist will be between 0 and 100, inclusive.


EXAMPLES

0)
{"vvv"}
0

Returns: 3

There are three possible sets of positions of geese: "ggd", "gdg", or "dgg" ('g' are geese and 'd' are ducks).


1)
{"."}
100

Returns: 0

The number of geese must be positive, but there are no birds in the cage.


2)
{"vvv"}
1

Returns: 0


3)
{"v.v..................v............................"
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
,".....v.....v.....................v.v......v......."}
3

Returns: 898961330

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
