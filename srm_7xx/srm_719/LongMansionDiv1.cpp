// BEGIN CUT HERE
/*
SRM 719 Div1 Easy (250)

問題
-N行無限列のマス目がある
-各マスでは、行の位置に応じた滞在コストがかかる
-行sX,列sYから行eX,列eYへの滞在コストの合計の最小値を求める

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

class LongMansionDiv1 {
public:
	long long minimalTime(vector <int> t, int sX, int sY, int eX, int eY) {
		LL ans = 1LL << 60;
		int n = (int)t.size();
		for (int c = 0; c < n; ++c) {
			LL cost = 0;
			for (int x = sX; x < c; ++x) {
				cost += t[x];
			}
			for (int x = sX; x > c; --x) {
				cost += t[x];
			}
			for (int x = eX; x < c; ++x) {
				cost += t[x];
			}
			for (int x = eX; x > c; --x) {
				cost += t[x];
			}
			cost += (abs(eY - sY) + 1) * (LL)t[c];
			ans = min(ans, cost);
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
			int Arr0[] = {5, 3, 10};
			int Arg1 = 2;
			int Arg2 = 0;
			int Arg3 = 2;
			int Arg4 = 2;
			long long Arg5 = 29LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg5, minimalTime(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 3, 10};
			int Arg1 = 0;
			int Arg2 = 2;
			int Arg3 = 0;
			int Arg4 = 0;
			long long Arg5 = 15LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg5, minimalTime(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {137, 200, 184, 243, 252, 113, 162};
			int Arg1 = 0;
			int Arg2 = 2;
			int Arg3 = 4;
			int Arg4 = 2;
			long long Arg5 = 1016LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg5, minimalTime(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {995, 996, 1000, 997, 999, 1000, 997, 996, 1000, 996, 1000, 997, 999, 996, 1000, 998, 999, 995, 995, 998, 995, 998, 995, 997, 998, 996, 998, 996, 997, 1000, 998, 997, 995, 1000, 996, 997, 1000, 997, 997, 999, 998, 995, 999, 999, 1000, 1000, 998, 997, 995, 999};
			int Arg1 = 18;
			int Arg2 = 433156521;
			int Arg3 = 28;
			int Arg4 = 138238863;
			long long Arg5 = 293443080673LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg5, minimalTime(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 0;
			int Arg4 = 0;
			long long Arg5 = 1LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg5, minimalTime(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LongMansionDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
