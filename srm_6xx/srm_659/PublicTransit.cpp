// BEGIN CUT HERE
/*
SRM 659 Div2 Medium (500)

問題
-R×Cのセルがある
-1個だけテレポーターを設置でき、その2点間の距離は0になる
-マンハッタン距離の最大値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class PublicTransit {
public:
	int minimumLongestDistance(int R, int C) {
		if (R * C <= 2) {
			return 0;
		}
		int ans = 1 << 30;
		for (int i = 0; i < R*C; ++i) {
			for (int j = i + 1; j < R*C; ++j) {
				int m = 0;
				for (int k = 0; k < R*C; ++k) {
					for (int l = k + 1; l < R*C; ++l) {
						int a = abs(k / C - l / C) + abs((k % C) - (l % C));
						int b = abs(i / C - k / C) + abs((i % C) - (k % C));
						int c = abs(j / C - l / C) + abs((j % C) - (l % C));
						int d = abs(i / C - l / C) + abs((i % C) - (l % C));
						int e = abs(j / C - k / C) + abs((j % C) - (k % C));
						m = max(m, min(a, min(b + c, d + e)));
					}
				}
				ans = min(ans, m);
			}
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
			int Arg1 = 1;
			int Arg2 = 1;

			verify_case(n, Arg2, minimumLongestDistance(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 1;

			verify_case(n, Arg2, minimumLongestDistance(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 3;
			int Arg2 = 4;

			verify_case(n, Arg2, minimumLongestDistance(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arg1 = 2;
			int Arg2 = 4;

			verify_case(n, Arg2, minimumLongestDistance(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 7;
			int Arg2 = 4;

			verify_case(n, Arg2, minimumLongestDistance(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PublicTransit ___test;
	___test.run_test(-1);
}
// END CUT HERE
