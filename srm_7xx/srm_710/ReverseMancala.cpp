// BEGIN CUT HERE
/*
SRM 710 Div1 Easy (300)

問題
-マンカラはコマを穴から穴へと動かして遊ぶゲームである。ここではコマを石、穴をスロットとする
-N個のスロットがあり、円環状に並んでいる
-ゲームは1ターンずつ進行する
-操作Aまたは操作Bのいずれかの操作が可能である
-操作Aは、まずひとつ以上の石が入ったスロットを選び、石を全て手に移す
-次に、時計回りで隣にあるスロットに、石をひとつずつ置いていく
-石がなくなったら終了
-操作Bは、まず石が一つ以上存在するスロットを選ぶ
-次に、反時計回りで、石をひとつずつ取っていく
-スロットに石が入っていなかったら、そこに手持ちの石をすべて置いて終了
-状態startとtargetが与えられる
-startからtargetにするための手順を求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <cstring>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ReverseMancala {
	vector <int> moveToFirstSlot(vector <int> start, bool former) {
		int N = (int)start.size();
		vector<int> v = start;
		int total = accumulate(v.begin(), v.end(), 0);
		vector <int> ans;
		int pos = N;
		while (v[0] != total) {
			do {
				if (++pos >= N) {
					pos = 1;
				}
			} while (!v[pos]);
			if (former) {
				ans.push_back(pos);
			}
			int x = v[pos];
			v[pos] = 0;
			int j;
			for (j = pos + 1; x--; ++j) {
				++v[j % N];
			}
			if (!former) {
				ans.push_back(N + ((j - 1) % N));
			}
		}
		return ans;
	}

public:
	vector <int> findMoves(vector <int> start, vector <int> target) {
		vector <int> ans = moveToFirstSlot(start, true);
		vector <int> latter = moveToFirstSlot(target, false);
		ans.insert(ans.end(), latter.rbegin(), latter.rend());
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {6, 3, 4, 0};
			int Arr1[] = {1, 5, 6, 1};
			int Arr2[] = {0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMoves(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 5, 6, 1};
			int Arr1[] = {6, 3, 4, 0};
			int Arr2[] = {6 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMoves(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 0, 1, 2, 3};
			int Arr1[] = {10, 0, 0, 2, 4};
			int Arr2[] = {2, 4, 8 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMoves(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 0, 1, 7};
			int Arr1[] = {0, 2, 1, 7};
			int Arr2[] = {2, 0, 1, 7 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMoves(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3, 2, 4, 5};
			int Arr1[] = {0, 1, 6, 7};
			int Arr2[] = {7, 1, 0, 7, 1, 0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMoves(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 1, 6, 4, 5, 2, 4, 5, 3, 0};
			int Arr1[] = {6, 4, 8, 0, 2, 6, 0, 1, 3, 2};
			int Arr2[] = {10, 8, 2, 16, 19, 2, 4, 11, 7, 6, 12, 19, 14, 14, 15, 3, 4, 17, 11, 3, 9, 16, 4, 8, 13, 12, 11, 9, 17, 12, 19, 4, 9, 8, 10, 2, 0, 17, 10, 3, 4, 8, 16, 0, 19, 15, 7, 6, 17, 6 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMoves(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3, 4, 6, 7, 2, 2, 3, 9, 4, 6};
			int Arr1[] = {6, 0, 5, 10, 10, 3, 1, 2, 8, 1};
			int Arr2[] = {8, 14, 1, 12, 11, 4, 9, 10, 15, 16, 2, 19, 2, 16, 17, 11, 16, 0, 12, 7, 4, 5, 17, 14, 0, 5, 13, 3, 7, 10, 12, 1, 16, 14, 1, 9, 1, 8, 7, 5, 5, 11, 19, 16, 18, 1, 15, 10, 16, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMoves(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ReverseMancala ___test;
	___test.run_test(-1);
}
// END CUT HERE
