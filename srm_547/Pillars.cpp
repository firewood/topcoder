// BEGIN CUT HERE
/*
// SRM 547 Div1 Easy (250)

問題
-2本の柱があり、柱間の距離はwである。
-それぞれの柱の高さは、1からx、および、1からyのいずれかである。
-柱の上端をまっすぐなロープで結ぶとき、ロープの長さの期待値を求める。

*/
// END CUT HERE
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class Pillars {

	double WW;
	LL c;
	double res;

	void add(int d, int n) {
		double D = d;
		res += sqrt(WW + D*D) * (double)n;
		c += n;
	}

public:
	double getExpectedLength(int w, int x, int y) {
		res = 0;
		WW = (double)w * (double)w;
		c = 0;

		int a = min(x, y);
		int b = max(x, y);

		add(0, a);
		int d;
		for (d = 1; d < b; ++d) {
			int Min = d+1;
			int Max = min(b, d + a);
			int n = Max - Min + 1;
			add(d, n);
		}
		for (d = 1; d < a; ++d) {
			int n = a - d;
			add(d, n);
		}

		return res / (double)c;
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
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1;
			double Arg3 = 1.0;

			verify_case(n, Arg3, getExpectedLength(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 5;
			int Arg2 = 1;
			double Arg3 = 2.387132965131785;

			verify_case(n, Arg3, getExpectedLength(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 3;
			int Arg2 = 15;
			double Arg3 = 6.737191281760445;

			verify_case(n, Arg3, getExpectedLength(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 15;
			int Arg2 = 23;
			double Arg3 = 12.988608956320535;

			verify_case(n, Arg3, getExpectedLength(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 10000;
			int Arg2 = 10000;
			double Arg3 = 12.988608956320535;

			verify_case(n, Arg3, getExpectedLength(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Pillars ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
