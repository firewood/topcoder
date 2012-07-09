// BEGIN CUT HERE
/*
// SRM 534 Div2 Hard (1000)

問題
Ellyたちは5人でゲームをする。
円陣を組み、それぞれ数値を持つ。
1ターンでは隣同士の任意の2人の数値をピックアップする。
両方の数値が奇数であれば「りんごアクション」で両方の数値から1を引くことができる。
両方の数値が1以上であれば「オレンジアクション」で両方の数値を1/2できる。
全員の数値がゼロになると勝利となる。
何通りの勝利パターン数があるかを求める。

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

#define MOD 1000000007

typedef vector<int> IntVec;

static int memo[26][26][26][26][26];

class EllysFiveFriends {
	int val2key[5][10001];
	int key2val[5][10001];

	int rec(IntVec &state) {
		int &res = memo[state[0]][state[1]][state[2]][state[3]][state[4]];
		if (res >= 0) {
			return res;
		}
		res = 0;
		int i, j;
		for (i = 0; i < 5; ++i) {
			j = (i+1) % 5;
			int si = state[i], sj = state[j];
			if (si == 0 || sj == 0) {
				continue;
			}
			IntVec next = state;
			int ni = key2val[i][si], nj = key2val[j][sj];
			if ((ni & 1) & (nj & 1)) {
				next[i] -= 1;
				next[j] -= 1;
				res = (res + rec(next)) % MOD;
			}
			next[i] = val2key[i][ni / 2];
			next[j] = val2key[j][nj / 2];
			res = (res + rec(next)) % MOD;
		}
		return res;
	}

public:
	int getZero(vector <int> numbers) {
		IntVec state(5);
		int i, j;
		for (i = 0; i < 5; ++i) {
			IntVec vars(1);
			j = numbers[i];
			while (j > 0) {
				vars.push_back(j);
				if (j & 1) {
					j &= ~1;
				} else {
					j >>= 1;
				}
			}
			sort(vars.begin(), vars.end());
			for (j = 0; j < (int)vars.size(); ++j) {
				val2key[i][vars[j]] = j;
				key2val[i][j] = vars[j];
			}
			state[i] = (int)vars.size() - 1;
		}
		memset(memo, -1, sizeof(memo));
		memo[0][0][0][0][0] = 1;
		int res = rec(state);
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
			int Arr0[] = {5, 1, 1, 2, 3};
			int Arg1 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getZero(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 1, 1, 1, 2};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getZero(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3, 4, 1, 4, 5};
			int Arg1 = 520;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getZero(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {42, 666, 1337, 666, 42};
			int Arg1 = 549119981;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getZero(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8792, 9483, 6787, 9856, 6205};
			int Arg1 = 165501353;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getZero(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10000, 10000, 10000, 10000, 10000};
			int Arg1 = 952019520;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getZero(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8191, 8191, 8191, 8191, 8191};
			int Arg1 = 996154957;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getZero(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysFiveFriends ___test;
//	___test.run_test(6);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
