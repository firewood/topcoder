// BEGIN CUT HERE
/*
SRM 609 Div2 Medium (500)

問題
-R,G,B 3色のボールがある
-3個以内にパッケージングしたい
-1つのパッケージは全部同じ色か、全部異なる色のいずれかであること
-最小のパッケージ数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class PackingBallsDiv2 {
public:
	int minPacks(int R, int G, int B) {
		int ans = R + G + B;
		int m = max(R, max(G, B));
		for (int i = 0; i <= m; ++i) {
			int t = i + (R - i + 2) / 3 + (G - i + 2) / 3 + (B - i + 2) / 3;
			ans = min(ans, t);
		}
		return ans;
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
			int Arg0 = 4;
			int Arg1 = 2;
			int Arg2 = 4;
			int Arg3 = 4;

			verify_case(n, Arg3, minPacks(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 7;
			int Arg2 = 1;
			int Arg3 = 3;

			verify_case(n, Arg3, minPacks(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 3;
			int Arg2 = 5;
			int Arg3 = 4;

			verify_case(n, Arg3, minPacks(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 78;
			int Arg1 = 53;
			int Arg2 = 64;
			int Arg3 = 66;

			verify_case(n, Arg3, minPacks(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 100;
			int Arg3 = 100;

			verify_case(n, Arg3, minPacks(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PackingBallsDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
