// BEGIN CUT HERE
/*
// SRM 538 Div1 Medium (450)

問題
左右の回転と前後の移動が可能なスパイロボットがある。
N個のコマンド列が与えられ、それぞれを1回ずつ実行する。
最も遠くに移動できるような順番で実行したときの距離を求める。

*/
// END CUT HERE
#define _USE_MATH_DEFINES
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;

class TurtleSpy {

public:
	double maxDistance(vector <string> commands) {
		double res = 0;
		IntVec angles;

		double back = 0;
		int i, j;
		for (i = 0; i < (int)commands.size(); ++i) {
			stringstream s(commands[i]);
			string c;
			int v;
			s >> c >> v;
			if (c.compare("forward") == 0) {
				res += v;
			}
			if (c.compare("backward") == 0) {
				back += v;
			}
			if (c.compare("left") == 0) {
				angles.push_back(v);
			}
			if (c.compare("right") == 0) {
				angles.push_back(-v);
			}
		}

		IntVec f(360);
		f[0] = 1;
		if (angles.size() > 0) {
			for (i = 0; i < (int)angles.size(); ++i) {
				IntVec next = f;
				for (j = 0; j < 360; ++j) {
					if (f[j]) {
						int a = (j + angles[i] + 360) % 360;
						next[a] = 1;
					}
				}
				f = next;
			}
		}
		int Max = 0;
		for (j = 0; j < 360; ++j) {
			if (f[j]) {
				if (abs(180 - j) < abs(180 - Max)) {
					Max = j;
				}
			}
		}

		if (back > 0) {
				double rad = ((double)Max * M_PI * 2.0) / 360.0;
				double x = res - back * cos(rad);
				double y = back * sin(rad);
				res = sqrt(x*x + y*y);
		}

		return res;
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
			string Arr0[] = {"forward 100", "backward 100", "left 90" };
			double Arg1 = 141.4213562373095;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"left 45", "forward 100", "right 45", "forward 100"};
			double Arg1 = 200.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"left 10", "forward 40",  "right 30", "left 10", "backward 4", "forward 4" };
			double Arg1 = 40.58520737741619;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"forward 1", "backward 1", "left 2", "left 3", "left 5", "left 7"};
			double Arg1 = 0.29561882225922065;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TurtleSpy ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
