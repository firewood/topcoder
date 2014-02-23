// BEGIN CUT HERE
/*
SRM 598 Div1 Medium (550)

問題
-1直線状の升目があり2人でゲームを行う
-二つの駒を距離d離して配置する
-それぞれの速度と射程が与えられる
-それぞれが最善手でプレイするときの勝者を求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class FoxAndFencing {

	int solve(int mov1, int mov2, int rng1, int rng2, int d) {
		if (rng1+mov1 >= d) {
			return 1;
		}
		if (rng2+mov2 >= d+mov1) {
			return 2;
		}
		if (mov1 > mov2) {
			if (mov1 > mov2*2+rng2-rng1) {
				return 1;
			}
		}
		if (mov1 < mov2) {
			if (mov2 > mov1*2+rng1-rng2) {
				return 2;
			}
		}
		return 0;
	}

public:
	string WhoCanWin(int mov1, int mov2, int rng1, int rng2, int d) {
		const char *result[] = {"Draw", "Ciel", "Liss"};
		return result[solve(mov1, mov2, rng1, rng2, d)];
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
			int Arg0 = 1;
			int Arg1 = 58;
			int Arg2 = 1;
			int Arg3 = 58;
			int Arg4 = 2;
			string Arg5 = "Ciel";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 100;
			int Arg4 = 50;
			string Arg5 = "Liss";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 100;
			int Arg4 = 150;
			string Arg5 = "Draw";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 100;
			int Arg3 = 100;
			int Arg4 = 100000000;
			string Arg5 = "Draw";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 1;
			int Arg2 = 100;
			int Arg3 = 1;
			int Arg4 = 100000000;
			string Arg5 = "Ciel";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 1;
			int Arg2 = 100;
			int Arg3 = 250;
			int Arg4 = 100000000;
			string Arg5 = "Draw";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 1;
			int Arg2 = 100;
			int Arg3 = 150;
			int Arg4 = 100000000;
			string Arg5 = "Ciel";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 50;
			int Arg2 = 100;
			int Arg3 = 1;
			int Arg4 = 100000000;
			string Arg5 = "Ciel";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_8
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 150;
			int Arg2 = 100;
			int Arg3 = 1;
			int Arg4 = 100000000;
			string Arg5 = "Draw";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 8162034;
			int Arg1 = 9177151;
			int Arg2 = 906682;
			int Arg3 = 4158573;
			int Arg4 = 9228270;
			string Arg5 = "Draw";

			verify_case(n, Arg5, WhoCanWin(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndFencing ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
