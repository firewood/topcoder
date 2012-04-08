// BEGIN CUT HERE
/*
// TCO12 Round 1B Medium (500)

問題
のび太くんは夏休みの宿題がたまっているが、一つこなすのがやっとである。
そんなのび太くんにドラえもんが分身ハンマーを出してくれた。
分身ハンマーを使うとのび太くんは二人になる。
それぞれののび太くんは最大でも一つしか宿題をこなさないが、
分裂したのび太くんも分身ハンマーを使うことができる。
分身ハンマーの準備時間と宿題の処理時間が与えられる。
宿題が終わる最短時間を求める。

*/
// END CUT HERE
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;
typedef pair<int, int> II;
typedef map<II, int> IIMap;

class FoxAndDoraemon {
	IntVec w;
	int c;
	IIMap m;

public:
	int rec(int n, int e) {
		II key(n, e);
		if (m.count(key) > 0) {
			return m[key];
		}
		int &res = m[key];
		if (e <= n) {
			res = w[e-1];
		} else {
			res = 999999999;
			int i;
			for (i = 0; i < n; ++i) {
				res = min(res, max(w[e-1], c + rec((n - i) * 2, e - i)));
			}
		}
		return res;
	}

	int minTime(vector <int> workCost, int splitCost) {
		w = workCost;
		c = splitCost;
		m.clear();
		sort(w.begin(), w.end());
		int res = rec(1, w.size());
		return res;
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
			int Arr0[] = {1,2};
			int Arg1 = 1000;
			int Arg2 = 1002;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minTime(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,6,9,12};
			int Arg1 = 1000;
			int Arg2 = 2012;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minTime(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000,100,10,1};
			int Arg1 = 1;
			int Arg2 = 1001;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minTime(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1712,1911,1703,1610,1697,1612};
			int Arg1 = 100;
			int Arg2 = 2012;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minTime(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3000,3000,3000,3000,3000,3000,3000,3000,3000,3000};
			int Arg1 = 3000;
			int Arg2 = 15000;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minTime(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {58};
			int Arg1 = 3600;
			int Arg2 = 58;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minTime(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndDoraemon ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
