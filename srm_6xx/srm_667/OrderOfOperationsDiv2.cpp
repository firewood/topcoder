// BEGIN CUT HERE
/*
SRM 667 Div2 Medium (500)

問題
-N個の命令セットとM個のメモリセルがある
-ひとつの命令はいくつかのメモリにアクセスする
-命令の実行時間は、アクセスされたことのないメモリの2乗である
-各命令を1回ずつ全て実行するとき、実行時間の最小値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

static inline int popcount(unsigned int b)
{
#ifdef __GNUC__
	return __builtin_popcount(b);
#elif _MSC_VER >= 1400
	return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	b += b >> 16;
	return b & 0x3F;
#endif
}

class OrderOfOperationsDiv2 {
	int N;
	int W;
	int M[50];
	int m[1048576];

	void dfs(int bits, int cost) {
		m[bits] = cost;
		for (int i = 0; i < N; ++i) {
			int a = bits & M[i];
			if (a) {
				int cnt = popcount(a);
				int b = bits ^ a;
				int c = cost + cnt * cnt;
				if (m[b] > c) {
					dfs(b, c);
				}
			}
		}
	}

public:
	int minTime(vector <string> s) {
		N = 0;
		W = (int)s[0].length();
		int final_bits = 0;
		for (string a : s) {
			int c = 0;
			for (int i = 0; i < W; ++i) {
				c |= ((a[i] - '0') << i);
			}
			M[N++] = c;
			final_bits |= c;
		}
		memset(m, 0x3f, sizeof(m));
		dfs(final_bits, 0);
		return m[0];
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
			string Arr0[] = {
 "111",
 "001",
 "010"
};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minTime(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
 "11101",
 "00111",
 "10101",
 "00000",
 "11000"
};
			int Arg1 = 9;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minTime(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
  "11111111111111111111"
};
			int Arg1 = 400;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minTime(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
  "1000",
  "1100",
  "1110"
};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minTime(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
  "111",
  "111",
  "110",
  "100"
};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minTime(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OrderOfOperationsDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
