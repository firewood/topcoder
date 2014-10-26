// BEGIN CUT HERE
/*
SRM 637 Div1 Easy (250)

問題
-1から2×Nまでの数が書かれた2×N枚のカードがある
-2人のプレーヤーにそれぞれN枚のカードを配る
-それぞれのプレーヤーの手札の配列が与えられる
-相手は順番に出す手札と、順番が決まっていない手札がある
-出した数値が大きいほうが1点得る
-一人目のプレーヤーの点数の期待値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef set<int> IntSet;

class GreaterGame {
public:
	double calc(vector <int> hand, vector <int> sothe) {
		IntSet a(hand.begin(), hand.end());
		IntSet b(sothe.begin(), sothe.end());
		IntSet r;
		int N = (int)hand.size();
		for (int i = 1; i <= 2*N; ++i) {
			r.insert(i);
		}
		for (int i = 0; i < N; ++i) {
			r.erase(hand[i]);
			r.erase(sothe[i]);
		}

		double ans = 0;
		while (b.size() > 0) {
			int x = *b.begin();
			b.erase(b.begin());
			if (x >= 1) {
				IntSet::iterator it = a.lower_bound(x);
				if (it == a.end()) {
					a.erase(a.begin());
				} else {
					ans += 1;
					a.erase(it);
				}
			}
		}

		IntSet::const_iterator p, q;
		for (p = r.begin(); p != r.end(); ++p) {
			double sum = 0;
			for (q = a.begin(); q != a.end(); ++q) {
				if (*q > *p) {
					sum += 1;
				}
			}
			ans += sum / r.size();
		}

		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,2};
			int Arr1[] = {-1,-1};
			double Arg2 = 1.5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, calc(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,2};
			int Arr1[] = {1,3};
			double Arg2 = 2.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, calc(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2};
			int Arr1[] = {-1};
			double Arg2 = 1.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, calc(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,3,5,7};
			int Arr1[] = {8,-1,4,-1};
			double Arg2 = 2.5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, calc(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {6,12,17,14,20,8,16,7,2,15};
			int Arr1[] = {-1,-1,4,-1,11,3,13,-1,-1,18};
			double Arg2 = 8.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, calc(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GreaterGame ___test;
	___test.run_test(-1);

}
// END CUT HERE
