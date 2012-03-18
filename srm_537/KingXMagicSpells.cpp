// BEGIN CUT HERE
/*
// SRM 537 Div1 Medium (500)

問題
アヒル王国の王宮に部屋がN室ある。
それぞれの部屋にはducks[i]匹のアヒルがある。
国王は一日一回、魔法の呪文を唱えることができる。
呪文はSpell 1とSpell 2の二種類で、唱える確率は1/2ずつである。
Spell 1の効果は、各部屋のアヒルの数がXORされる。
Spell 2の効果は、各部屋のアヒルが一斉に部屋spellTwo[i]に移動する。
K日後のゼロ番目の部屋のアヒルの数の期待値を求めよ。

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

typedef vector<int> IntVec;
typedef vector<double> DoubleVec;
typedef vector<DoubleVec> DVV;

class KingXMagicSpells {

public:
	double expectedNumber(vector <int> ducks, vector <int> spellOne, vector <int> spellTwo, int K) {
		int c = ducks.size();
		DVV v(c);
		int i, j;
		for (i = 0; i < c; ++i) {
			v[i].resize(30);
		}
		for (i = 0; i < c; ++i) {
			for (j = 0; j < 30; ++j) {
				if (ducks[i] & (1 << j)) {
					v[i][j] = 1.0;
				}
			}
		}

		int day;
		for (day = 0; day < K; ++day) {
			DVV next(c);

			for (i = 0; i < c; ++i) {
				const DoubleVec &src = v[i];
				next[spellTwo[i]] = src;
			}

			for (i = 0; i < c; ++i) {
				const DoubleVec &x = v[i];
				DoubleVec &y = next[i];
				int one = spellOne[i];
				for (j = 0; j < 30; ++j) {
					double n = x[j];
					if (one & (1 << j)) {
						n = 1.0 - n;
					}
					y[j] = 0.5 * (y[j] + n);
				}
			}

			v = next;
		}

		double res = 0;
		for (j = 0; j < 30; ++j) {
			double d = 1 << j;
			res += d * v[0][j];
		}
		return res;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 3, 7};
			int Arr1[] = {1, 7, 4};
			int Arr2[] = {1, 0, 2};
			int Arg3 = 1;
			double Arg4 = 3.5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 8};
			int Arr1[] = {53, 7};
			int Arr2[] = {1, 0};
			int Arg3 = 2;
			double Arg4 = 21.5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {123, 456, 789, 1234, 56789};
			int Arr1[] = {0, 0, 0, 0, 0};
			int Arr2[] = {0, 1, 2, 3, 4};
			int Arg3 = 50;
			double Arg4 = 123.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {83291232, 3124231, 192412, 3813249, 629231, 9998989};
			int Arr1[] = {58, 37, 44, 66, 72, 19};
			int Arr2[] = {2, 0, 1, 5, 4, 3};
			int Arg3 = 11;
			double Arg4 = 2.888186784716797E7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, expectedNumber(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	KingXMagicSpells ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
