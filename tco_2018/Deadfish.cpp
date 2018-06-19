// BEGIN CUT HERE
/*
TCO18 R1A Hard (1000)

問題
-加算、減算、2乗、値の10進表記をソート、という4つのコマンドが実行できる
-値の初期値は0である
-値をNにするための手数の最小値を求めよ

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

static const int MAX = 400000;

class Deadfish {

	int memo[MAX + 4];

	void init() {
		fill(memo, memo + MAX + 4, -1);
		memo[0] = 0;
		vector<LL> q;
		q.push_back(0);
		for (int c = 1; q.size() > 0; ++c) {
			vector<LL> nx;
			for (LL v : q) {
				LL a = v + 1;
				if (a > 0 && a <= MAX && memo[a] < 0) {
					memo[a] = c;
					nx.push_back(a);
				}
				a = v - 1;
				if (a > 0 && a <= MAX && memo[a] < 0) {
					memo[a] = c;
					nx.push_back(a);
				}
				a = v * v;
				if (a > 0 && a <= MAX && memo[a] < 0) {
					memo[a] = c;
					nx.push_back(a);
				}
				string s = to_string(v);
				sort(s.rbegin(), s.rend());
				a = stoll(s);
				if (a > 0 && a <= MAX && memo[a] < 0) {
					memo[a] = c;
					nx.push_back(a);
				}
			}
			q = nx;
		}
	}

public:
	int shortestCode(int N) {
		if (memo[1] != 1) {
			init();
		}
		return memo[N];
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
			int Arg0 = 3;
			int Arg1 = 3;

			verify_case(n, Arg1, shortestCode(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 4;

			verify_case(n, Arg1, shortestCode(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15;
			int Arg1 = 5;

			verify_case(n, Arg1, shortestCode(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 61;
			int Arg1 = 5;

			verify_case(n, Arg1, shortestCode(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 200000;
			int Arg1 = 207;

			verify_case(n, Arg1, shortestCode(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Deadfish ___test;
	___test.run_test(-1);
}
// END CUT HERE
