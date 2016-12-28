// BEGIN CUT HERE
/*
SRM 697 Div1 Easy (300)

問題
-N個の正の整数からなる配列bが与えられる
-以下の条件を全て満たす配列aが存在するかどうかを求める
-aの要素a[0],a[1],...a[N-1]は全て異なる
-各要素は1以上の整数
-a[i]^b[i]は、a[i]以外の全てのaの要素の積で割り切れる

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef vector<int> IntVec;

class DivisibleSetDiv1 {
	bool possible(IntVec b) {
		sort(b.rbegin(), b.rend());
		IntVec a(b.size());
		iota(a.begin(), a.end(), 1);
		int sum = accumulate(a.begin(), a.end(), 0);
		for (int t = 0; t < 1000000; ++t) {
			bool ok = true;
			for (int i = 0; i != a.size(); ++i) {
				if ((a[i] * (b[i] + 1)) < sum) {
					for (int j = i; j != a.size(); ++j) {
						++a[j], ++sum;
					}
					ok = false;
				}
				if (ok) {
					return true;
				}
			}
		}
		return false;
	}

public:
	string isPossible(vector <int> b) {
		return possible(b) ? "Possible" : "Impossible";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,1};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1};
			string Arg1 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7, 7, 7};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,3,5,4,6,1,3,7,9,6,2,5,4,1,1,9,6,10,10,6,10,7,7,8};
			string Arg1 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 2,2,3 };
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 2,3,4,5 };
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 3,1,3 };
			string Arg1 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 1,2,5 };
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DivisibleSetDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
