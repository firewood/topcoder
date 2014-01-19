// BEGIN CUT HERE
/*
// SRM 524 Div2 Hard (1000)

問題

0から9のうち、0から9個だけ禁止されている。
禁止された文字を使わずに、与えられたnの倍数の最小値を10進数表記を求める。


#line 79 "MultiplesWithLimit.cpp"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef pair<LL, LL> LLPair;
typedef queue<LLPair> IIQueue;

class MultiplesWithLimit {

public:
	string minMultiples(int N, vector <int> forbiddenDigits) {
		LL _N = N;
		int f[10] = {0};
		int i;
		for (i = 0; i < (int)forbiddenDigits.size(); ++i) {
			f[forbiddenDigits[i] % 10] = 1;
		}
		IntSet allowed;
		for (i = 0; i < 10; ++i) {
			if (!f[i]) {
				allowed.insert(i);
			}
		}

		const LL Max = 1000000000;
		LL ans = Max;
		IntSet M;
		IIQueue Q;
		IntSet::const_iterator it;
		for (it = allowed.begin(); it != allowed.end(); ++it) {
			Q.push(LLPair(*it, 10));
		}
		while (!Q.empty()) {
			LLPair p = Q.front();
			Q.pop();
			LL n = p.first;
			if (n != 0) {
				int r = (int)(n % N);
				if (r == 0) {
					ans = min(ans, n);
					continue;
				} else if (M.find(r) != M.end()) {
					continue;
				} else {
					M.insert(r);
				}
			}
			if (ans < Max) {
				continue;
			}
			for (it = allowed.begin(); it != allowed.end(); ++it) {
				Q.push(LLPair(p.second * *it + n, p.second * 10));
			}
		}

		if (ans < Max) {
			char res[32];
			if (ans <= 99999999) {
				sprintf(res, "%lld", ans);
			} else {
				sprintf(res, "%lld", ans);
				int digits = strlen(res);
				sprintf(res + 3, "...%d(%d digits)", (int)(ans % 1000), digits);
			}
			return res;
		}

		return "IMPOSSIBLE";
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arr1[] = {2,3,4,5,6,7,8,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "1000"; verify_case(0, Arg2, minMultiples(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 9; int Arr1[] = {1,3,4,5,6,7,8,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "222...222(9 digits)"; verify_case(1, Arg2, minMultiples(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 524; int Arr1[] = {5,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "3668"; verify_case(2, Arg2, minMultiples(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10000; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "IMPOSSIBLE"; verify_case(3, Arg2, minMultiples(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arr1[] = {0,1,2,3,4,5,6,7,8,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "IMPOSSIBLE"; verify_case(4, Arg2, minMultiples(Arg0, Arg1)); }
// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MultiplesWithLimit ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
