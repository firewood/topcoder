// BEGIN CUT HERE
/*
SRM 677 Div1 Easy (250)

問題
-数aとbが与えられる
-一回の操作で+1または2倍にできる
-数aをnewAに、数bをnewBにするための最小操作回数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class DoubleOrOneEasy {
public:
	int minimalSteps(int a, int b, int newA, int newB) {
		if (a > b) {
			swap(a, b);
			swap(newA, newB);
		}
		int ans = 0;
		while (newA >= a * 2 && newB >= b * 2) {
			if (newA % 2 || newB % 2) {
				++ans;
				--newA, --newB;
				if (newA % 2 || newB % 2) {
					break;
				}
			}
			if ((newA / 2 - a) <= (newB / 2 - b)) {
				++ans;
				newA /= 2, newB /= 2;
			} else {
				break;
			}
		}
		int d = newA - a;
		ans += d;
		return d >= 0 && (b + d) == newB ? ans : -1;
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
			int Arg0 = 100;
			int Arg1 = 1000;
			int Arg2 = 101;
			int Arg3 = 1001;
			int Arg4 = 1;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 1000;
			int Arg2 = 202;
			int Arg3 = 2002;	
			int Arg4 = 2;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 1;
			int Arg3 = 1;
			int Arg4 = -1;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 111111111;
			int Arg2 = 8;
			int Arg3 = 888888888;
			int Arg4 = 3;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 111111111;
			int Arg2 = 9;
			int Arg3 = 999999999;
			int Arg4 = -1;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;




		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 2;
			int Arg2 = 4;
			int Arg3 = 3;
			int Arg4 = -1;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			int Arg2 = 3;
			int Arg3 = 4;
			int Arg4 = -1;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 999999999;
			int Arg3 = 999999999;
			int Arg4 = 49;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 17;
			int Arg2 = 999934463;
			int Arg3 = 999999999;
			int Arg4 = 244145;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 2;
			int Arg3 = 4;
			int Arg4 = -1;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 800;
			int Arg3 = 800;
			int Arg4 = 3;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 899;
			int Arg3 = 899;
			int Arg4 = 17;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 2;
			int Arg2 = 999999999;
			int Arg3 = 1000000000;
			int Arg4 = 999999998;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 2;
			int Arg2 = 4;
			int Arg3 = 7;
			int Arg4 = -1;

			verify_case(n, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DoubleOrOneEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
