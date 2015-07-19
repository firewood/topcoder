// BEGIN CUT HERE
/*
SRM 656 Div1 Easy (250)

問題
-N枚のパンケーキがある
-それぞれの大きさは1からNで、それぞれのおいしさが与えられる
-1枚ずつランダムに選んで積んでいく
-ただし、一つ前に積んだものより大きければ、それを積まないで終了
-詰まれたパンケーキのおいしさの合計の期待値を求める

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
typedef long double LD;

class RandomPancakeStack {

public:
	double expectedDeliciousness(vector <int> d) {
		LD factorial[1024];
		factorial[0] = 1;
		for (LL i = 1; i < 1024; ++i) {
			factorial[i] = factorial[i - 1] * i;
		}
		LL N = d.size();
		LD ans = 0;
		for (LL i = 0; i < N; ++i) {
			LL g = N - i - 1;
			LD p = 0;
			for (LL j = 0; j <= g && j < N; ++j) {
				LL r = N - j - 1;
				p += (factorial[g] / factorial[j]) * (factorial[r] / factorial[g - j]);
			}
			ans += p * d[i];
		}
		return ans / factorial[N];
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
			int Arr0[] = {1,1,1};
			double Arg1 = 1.6666666666666667;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedDeliciousness(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,6,10,9,2};
			double Arg1 = 9.891666666666667;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedDeliciousness(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,9,8,7,6,5,4,3,2,1};
			double Arg1 = 10.999999724426809;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedDeliciousness(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6,7,8,9,10};
			double Arg1 = 7.901100088183421;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedDeliciousness(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,7,1,8,2,8,1,8,2,8,4,5,90,4,5,2,3,5,60,2,8,74,7,1};
			double Arg1 = 19.368705050402465;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedDeliciousness(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			double Arg1 = 1.718281828459045;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, expectedDeliciousness(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RandomPancakeStack ___test;
	___test.run_test(-1);
}
// END CUT HERE
