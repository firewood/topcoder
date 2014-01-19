// BEGIN CUT HERE
/*
// SRM 548 Div1 Easy (250)

問題
N本の高さがばらばらな木がある。
パワーXの魔法を使うと、木の高さを最大±X変化させることができる。
木の高さを昇順にするための最小のパワーを求める。

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class KingdomAndTrees {

	int sz;
	int v[60];

	bool rec(int n) {
		int i;
		int prev = 0;
		for (i = 0; i < sz; ++i) {
			int x = v[i];
			int next = max(min(prev+1, x+n), x-n);
			if (next <= prev) {
				return false;
			}
			prev = next;
		}
		return true;
	}

public:
	int minLevel(vector <int> heights) {
		sz = (int)heights.size();
		int i;
		for (i = 0; i < sz; ++i) {
			v[i] = heights[i];
		}

#if 0
		int low = 0;
		int high = 1000000001;
		while (low < high) {
			int mid = (low + high) / 2;
			if (rec(mid)) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
#else
		int low = -1;
		int high = 1000000001;
		while ((high - low) > 1) {
			int mid = (low + high) / 2;
			if (rec(mid)) {
				high = mid;
			} else {
				low = mid;
			}
		}
#endif

		return high;
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
			int Arr0[] = {9, 5, 11};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minLevel(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 8};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minLevel(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1, 1, 1};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minLevel(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {548, 47, 58, 250, 2012};
			int Arg1 = 251;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minLevel(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int Arg1 = 49;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minLevel(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000000,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int Arg1 = 500000024;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minLevel(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	KingdomAndTrees ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
