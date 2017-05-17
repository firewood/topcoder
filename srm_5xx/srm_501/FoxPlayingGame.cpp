// BEGIN CUT HERE
/*
SRM 501 Div2 Medium (500)

問題
-数nA,nB,scoreA,scoreBが与えられる
-数xに対して、操作Aまたは操作Bが可能である
-操作AはxにscoreAを加算する
-操作BはxにscoreBを乗算する
-初期値0、順不同の操作をしたとき、最大値を求める

*/
// END CUT HERE

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <sstream>

using namespace std;

class FoxPlayingGame {
	public:
	double theMax(int nA, int nB, int paramA, int paramB) {
        double a = 0.001 * paramA, b = 0.001 * paramB;
        double ans = a * nA;
        if (nA && nB) {
            ans = max(ans, (a * nA) * b);
            if (nB >= 2) {
                ans = max(ans, (a * nA) * b * b);
                ans = max(ans, (a * nA) * pow(b, nB - 1));
                ans = max(ans, (a * nA) * pow(b, nB));
            }
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
			int Arg0 = 5;
			int Arg1 = 4;
			int Arg2 = 3000;
			int Arg3 = 2000;
			double Arg4 = 240.0;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 2000;
			int Arg3 = 100;
			double Arg4 = 6.0;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 3;
			int Arg2 = -2000;
			int Arg3 = 2000;
			double Arg4 = -8.0;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 5;
			int Arg2 = 2000;
			int Arg3 = -2000;
			double Arg4 = 160.0;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arg1 = 50;
			int Arg2 = 10000;
			int Arg3 = 2000;
			double Arg4 = 5.62949953421312E17;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 41;
			int Arg1 = 34;
			int Arg2 = 9876;
			int Arg3 = -1234;
			double Arg4 = 515323.9982341775;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

        
        if ((Case == -1) || (Case == n)){
            int Arg0 = 23;
            int Arg1 = 34;
            int Arg2 = -9422;
            int Arg3 = -180;
            double Arg4 = 39.00708;
            verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
        }
        n++;

        if ((Case == -1) || (Case == n)){
            int Arg0 = 1;
            int Arg1 = 1;
            int Arg2 = 10000;
            int Arg3 = 2000;
            double Arg4 = 20.0;
            verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
        }
        n++;
        
	}

// END CUT HERE
};

// BEGIN CUT HERE
int main() {
	FoxPlayingGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
