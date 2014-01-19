// BEGIN CUT HERE
/*
// SRM 506 Div2 Hard (1000)

問題
-文字で表された2次元のフィールドがある
-フィールドに勇者(あなた)とゾンビスライムが何匹かいる
-ゾンビスライムは1～9の数字で表され、数字のターン後に復活する
-ゾンビスライムと交差すると倒せる
-倒されたゾンビスライムに交差すると、復活してその場で倒したことになる
-全てのゾンビスライムを倒す瞬間が生み出せればOK
-最小のターン数を求める

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
