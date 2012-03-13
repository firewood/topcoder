// BEGIN CUT HERE
/*
// SRM 506 Div2 Hard (1000)

// PROBLEM STATEMENT
// You are playing a game titled Resident Slime. You will play the role of the hero and exterminate undead slimes.


You are on a level that is represented by an RxC rectangular grid of cells given in vector <string> field. Rows are numbered 0 through R-1 from top to bottom, and columns are numbered 0 through C-1 from left to right. field[r][c] represents the content of the cell located at row r and column c and is one of the following:

'.' : an empty cell.
'#' : a wall.
'$' : an empty cell where you initially reside.
'1'-'9' : a stationary undead slime whose regenerative power is equal to the digit representing it.

You are going to exterminate all the slimes in this level. Unfortunately, after each slime is killed, it only stays dead for a limited time before it gets revived. Your goal is to get the level into a state where every slime is dead. At that point, they will no longer come back to life. More specifically, the game works as follows.

You start at the cell denoted by '$'.
At the beginning of each turn, you either wait or move to one of the four adjacent cells (those which share a side with your current location). You cannot move to a cell which contains a wall.
Next, if there's a dead slime in your new location, it will get revived.
Next, if your new location is occupied by an undead slime, that slime gets killed. The killed slime will remain in the cell.
Next, each slime is revived if its regenerative power is equal to the number of turns ago it was last killed.
Finally, if at this moment all undead slimes are killed, you win the level. Otherwise, the turn advances and the game continues.

What is the minimum number of turns required to win this level? Return -1 if it is impossible.

DEFINITION
Class:SlimeXResidentSlime
Method:exterminate
Parameters:vector <string>
Returns:int
Method signature:int exterminate(vector <string> field)


CONSTRAINTS
-field will contain between 1 and 50 elements, inclusive.
-Each element of field will contain between 1 and 50 characters, inclusive.
-All the elements of field will contain the same number of characters.
-Each character in field will be '.', '#', '$', or '1'-'9'.
-There will be exactly one '$' in field.
-There will be at least one digit (i.e., a slime) in field.


EXAMPLES

0)

{
"#1$",
".2."}

Returns: 3

Go down, then go left (killing the slime denoted by '2'). Finally, go up (killing the slime denoted by '1') and since no slime gets revived during this turn, you win the level.

1)
{
"$",
"1",
"1"}

Returns: -1

It's impossible to defeat this level. Each time you kill a slime, the other slime gets revived.

2)
{
"$124"}

Returns: 5

Go right, kill the slime denoted by '1'. 
Go right, kill the slime denoted by '2'. (After this, the slime denoted by '1' gets revived). 
Go right, kill the slime denoted by '4'. 
Go left, (the slime denoted by '2' immediately revives), and kill the slime denoted by '2'.
Go left, kill the slime denoted by '1', and win the level.

3)
{"$.#2"
,"#..1"}

Returns: 6



#line 89 "SlimeXResidentSlime.cpp"
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

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;
typedef pair<int, int> II;
typedef vector<II> IIVec;

struct Slime {
	II pos;
	int life;
};


class SlimeXResidentSlime {
	vector <string> fld;
	int W;
	int H;
	int slimes;
	Slime S[10];
	int dist[10][10];

	int get_dist(const II &st, const II &ed) {
		if (st == ed) {
			return -1;
		}
		int d[64][64];
		memset(d, -1, sizeof(d));
		II dirs[4] = {II(-1,0),II(1,0),II(0,-1),II(0,1)};
		IIVec q;
		d[st.second][st.first] = 0;
		q.push_back(st);
		while (q.size() > 0) {
			IIVec nq;
			int i, j;
			for (i = 0; i < (int)q.size(); ++i) {
				const II &current = q[i];
				if (current == ed) {
					return d[current.second][current.first];
				}
				for (j = 0; j < 4; ++j) {
					int x = current.first + dirs[j].first;
					int y = current.second + dirs[j].second;
					if (x >= 0 && x < W && y >= 0 && y < H &&
							d[y][x] < 0 && fld[y][x] != '#') {
						nq.push_back(II(x, y));
						d[y][x] = d[current.second][current.first] + 1;
					}
				}
			}
			q = nq;
		}
		return -1;
	}

public:
	int exterminate(vector <string> field) {
		int res = -1;
		slimes = 1;
		fld = field;
		W = field[0].length();
		H = field.size();
		int i, j;
		for (i = 0; i < H; ++i) {
			for (j = 0; j < W; ++j) {
				if (field[i][j] == '$') {
					S[0].pos = II(j, i);
					S[0].life = 9999;
				}
				if (isdigit(field[i][j])) {
					if (slimes >= 10) {
						return -1;
					}
					S[slimes].pos = II(j, i);
					S[slimes].life = field[i][j] - '0';
					++slimes;
				}
			}
		}

		for (i = 0; i < slimes; ++i) {
			for (j = 0; j < slimes; ++j) {
				dist[i][j] = dist[j][i] = get_dist(S[i].pos, S[j].pos);
			}
		}

		int seq[10];
		for (i = 0; i < 10; ++i) {
			seq[i] = i;
		}
		do {
			int t = 0;
			for (i = slimes-1; i >= 1; --i) {
				int d = dist[seq[i-1]][seq[i]];
				if (d < 0) {
					t = -1;
					break;
				}
				t += d;
				if (t >= S[seq[i-1]].life) {
					t = -1;
					break;
				}
			}
			if (t > 0) {
				res = res < 0 ? t : min(res, t);
			}
		} while (next_permutation(seq +1, seq +slimes));

		return res;
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
			string Arr0[] = 
{
"#1$",
".2."};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, exterminate(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"$",
"1",
"1"};
			int Arg1 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, exterminate(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"$124"};
			int Arg1 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, exterminate(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"$.#2"
,"#..1"};
			int Arg1 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, exterminate(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"$123456789"};
			int Arg1 = 17;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, exterminate(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SlimeXResidentSlime ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
