// BEGIN CUT HERE
/*
// SRM 540 Div1 Easy (250)

問題
N+1個の数値からなる数列があり、各数値の間に+か-を書いた。
演算子と計算結果のN個の数値からなる数列が与えられる。
元の数列の組み合わせの個数を求める。

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> LLLL;
typedef vector<LLLL> LLLLVec;

class ImportantSequence {

public:
	int getCount(vector <int> B, string operators) {
		int sz = B.size();
		LLLLVec v;
		LL op = 1;
		LL x = 0;
		int i;
		for (i = 0; i < sz; ++i) {
			LL n = B[i];
			if (operators[i] == '+') {
				op = -op;
				x = n - x;
			} else {
				x = x - n;
			}
			v.push_back(LLLL(op, x));
		}
		LL Min = 1;
		LL Max = 1LL << 60;
		for (i = 0; i < sz; ++i) {
			if (v[i].first > 0) {
				Min = max(Min, -v[i].second + 1);
			} else {
				Max = min(Max, v[i].second - 1);
			}
		}

		if (Max >= (1LL << 60)) {
			return -1;
		}
		if (Max < Min) {
			return 0;
		}
		return (int)(Max - Min) + 1;
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
			int Arr0[] = {3, -1, 7};
			string Arg1 = "+-+";
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			string Arg1 = "-";
			int Arg2 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			string Arg1 = "+";
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10};
			string Arg1 = "+";
			int Arg2 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {540, 2012, 540, 2012, 540, 2012, 540};
			string Arg1 = "-+-+-+-";
			int Arg2 = 1471;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 999999999, 1234, 4311};
			string Arg1 = "-------+--";
			int Arg2 = 999994453;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = {380363427, 583629335, -681431183, -219398108, 24128364, 933370503, 476023070, -401987717, -625916565, 496045772, 908035426, -895357751, 464638908, -115569799, -905531819, -393481688, 203364448, 48324176, -36670007, -531426289, -460125068, 629279122, -733410707, -159928285, -562938483, -878488131, 560719010, -466275382, -312074009, -445541791, 320972323, -477210673, 514950353, -252233737, -599779031, 819400249, 364282240, 530984231, 981313465, 353217366, 118458547, -491592609, 190379345, 187993123, 299990918, 968081798, 212935226, 448245418};
			string Arg1 = "-++-+----+-++-+--++--+-+---++-------++-+--++-+-+";
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ImportantSequence ___test;
//	___test.run_test(6);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
