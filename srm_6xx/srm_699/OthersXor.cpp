// BEGIN CUT HERE
/*
SRM 699 Div1 Easy (250)

問題
-N匹の狼がいる
-それぞれの狼は0から2^30-1までの任意の数値を選ぶ
-それぞれの狼は、情報を開示しないか、あるいは、自分以外の全ての狼の数値のXORを開示する
-開示された情報が正しい場合、狼の数値の合計の最小値を求める
-開示された情報に一貫性がない場合は-1とする

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

class OthersXor {
public:
	long long minSum(vector <int> x) {
		LL zc = count(x.begin(), x.end(), -1);
		LL ans = 0;
		for (LL b = 1 << 29; b > 0; b >>= 1) {
			LL cnt[2] = {};
			for (int a : x) {
				if (a >= 0) {
					cnt[a & b ? 1 : 0] += 1;
				}
			}
			if (cnt[1] <= 0) {
				continue;
			}
			LL m = 1 << 30;
			if (cnt[0] & 1) {
				m = min(m, cnt[0]);
			} else if (zc) {
				m = min(m, cnt[0] + 1);
			}
			if ((cnt[1] & 1) == 0) {
				m = min(m, cnt[1]);
			} else if (zc) {
				m = min(m, cnt[1] + 1);
			}
			if (m == 1 << 30) {
				return -1;
			}
			ans += m * b;
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,-1,3};
			long long Arg1 = 3LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSum(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,1};
			long long Arg1 = -1LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSum(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {70,100};
			long long Arg1 = 170LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSum(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,0,-1,100,36};
			long long Arg1 = 164LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSum(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,
0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,
1073741823,1073741823,1073741823,123456789,987654321,804289383};
			long long Arg1 = 11992352010LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSum(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1287325,424244444,92759185,812358213,1000000000,825833522,749092703};
			long long Arg1 = -1LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSum(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,-1};
			long long Arg1 = 0LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSum(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OthersXor ___test;
	___test.run_test(-1);
}
// END CUT HERE
