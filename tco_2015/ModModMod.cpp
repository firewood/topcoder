// BEGIN CUT HERE
/*
TCO 2015 Round 2A Easy (300)

問題
-配列mの各要素でmodを取る関数f(x)がある
-f(1)からf(R)までの合計を求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;

class ModModMod {
public:
	long long findSum(vector <int> m, int R) {
		int N = (int)m.size();
		LL cnt[10000001];
		for (LL i = 1; i <= R; ++i) {
			cnt[i] = 1;
		}
		LL u = R + 1;
		for (LL p : m) {
			if (p < u) {
				for (LL i = p; i < u; ++i) {
					cnt[i % p] += cnt[i];
					cnt[i] = 0;
				}
				u = p;
			}
		}
		LL ans = 0;
		for (LL i = 1; i <= R; ++i) {
			ans += i * cnt[i];
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
			int Arr0[] = {5,3,2};
			int Arg1 = 10;
			long long Arg2 = 4LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findSum(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {33, 15, 7, 10, 100, 9, 5};
			int Arg1 = 64;
			long long Arg2 = 92LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findSum(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {995,149,28,265,275,107,555,241,702,462,519,212,362,478,783,381,602,546,183,886,59,317,977,612,328,91,771,131};
			int Arg1 = 992363;
			long long Arg2 = 12792005LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findSum(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
			int Arg1 = 100;
			long long Arg2 = 4950LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findSum(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2934};
			int Arg1 = 10000000;
			long long Arg2 = 14664070144LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findSum(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ModModMod ___test;
	___test.run_test(-1);
}
// END CUT HERE
