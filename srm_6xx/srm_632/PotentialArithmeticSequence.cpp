// BEGIN CUT HERE
/*
SRM 632 Div1 Easy (300)

問題
-N個の正の整数からなる配列aがある
-aの各要素を2進表現したときの末尾のゼロの個数の配列dが与えられる
-1個以上の連続する要素が1ずつ増加する等差数列になっている部分集合の総数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class PotentialArithmeticSequence {
public:
	int numberOfSubsequences(vector <int> d) {
		int N = (int)d.size();
		int a[257];
		for (int i = 0; i <= 8; ++i){
			a[1 << i] = i;
		}
		char b[384];
		for (int i = 0; i < 384; ++i) {
			b[i] = a[i&-i];
		}






		char c[256];
		for (int i = 0; i < N; ++i) {
			c[i] = min(d[i], 7);
		}
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			for (int len = 1; len <= N - i; ++len) {
				for (int j = 1; j <= 256; ++j) {
					if (memcmp(c + i, b + j, len) == 0) {
						++ans;
						break;
					}
				}
			}
		}
		return ans;
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
			int Arr0[] = {0,1,0,2,0,1,0};
			int Arg1 = 28;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, numberOfSubsequences(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0,0,0,0,0};
			int Arg1 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, numberOfSubsequences(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0,0,1,1,1};
			int Arg1 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, numberOfSubsequences(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,100,0,2,0};
			int Arg1 = 11;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, numberOfSubsequences(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,11,3,0,1,0,1,0,1,0,1,0,3,0,2,0,0,0,0,1,2,3,20};
			int Arg1 = 49;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, numberOfSubsequences(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PotentialArithmeticSequence ___test;
	___test.run_test(-1);
}
// END CUT HERE
