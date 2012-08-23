// BEGIN CUT HERE
/*
// SRM 553 Div1 Easy (250)

問題
Suminatorは加算だけ可能なスタックマシンである。
プログラムとして非負の整数の配列が与えられ、順番に実行する。
スタックへは、プログラムが0なら2値を足して格納し、0以外ならそのまま格納する。
最後にスタックの先頭を表示して終了する。
一箇所だけ書き換えて結果をwantedResultにするための最小の数値を求める。

*/
// END CUT HERE
#include <algorithm>
#include <deque>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> LLPair;
typedef deque<LLPair> LLPairQueue;
typedef vector<int> IntVec;

class Suminator {

	LLPair eval(const IntVec &program, size_t pos) {
		int sz = (int)program.size();
		size_t i;
		LLPairQueue q;
		for (i = 0; i <= sz*2; ++i) {
			q.push_front(LLPair(0, 0));
		}
		for (i = 0; i < sz; ++i) {
			LLPair c(program[i], i == pos);
			if (program[i] == 0) {
				LLPair a = q.front();
				q.pop_front();
				LLPair b = q.front();
				q.pop_front();
				c.first = a.first + b.first;
				c.second = a.second + b.second;
			}
			q.push_front(c);
		}
		return q.front();
	}

public:
	int findMissing(vector <int> program, int wantedResult) {
		size_t pos = find(program.begin(), program.end(), -1) - program.begin();
		program[pos] = 0;
		LLPair x = eval(program, pos);
		if (x.first == wantedResult) {
			return 0;
		}
		program[pos] = 1;
		x = eval(program, pos);
		if (x.first == wantedResult) {
			return 1;
		}
		if (x.first < wantedResult && x.second == 1) {
			return (int)(wantedResult - x.first + 1);
		}
		return -1;
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
			int Arr0[] = {7,-1,0};
			int Arg1 = 10;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findMissing(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, 200, 300, 0, 100, -1};
			int Arg1 = 600;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findMissing(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1, 7, 3, 0, 1, 2, 0, 0};
			int Arg1 = 13;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findMissing(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1, 8, 4, 0, 1, 2, 0, 0};
			int Arg1 = 16;
			int Arg2 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findMissing(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0};
			int Arg1 = 1000000000;
			int Arg2 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findMissing(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7, -1, 3, 0};
			int Arg1 = 3;
			int Arg2 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findMissing(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Suminator ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
