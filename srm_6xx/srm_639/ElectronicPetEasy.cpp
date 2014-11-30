// BEGIN CUT HERE
/*
SRM 639 Div2 Easy (250)

問題
-二匹の電子ペットに餌をやる
-餌やりは時刻stから周期pでt回
-同時に2匹の餌やりが発生するかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;
typedef set<int> IntSet;

class ElectronicPetEasy {
public:
	string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2) {
		IntVec v;
		for (int i = 0; i < t1; ++i) {
			v.push_back(st1 + p1 * i);
		}
		IntSet s(v.begin(), v.end());
		for (int i = 0; i < t2; ++i) {
			if (s.find(st2 + p2 * i) != s.end()) {
				return "Difficult";
			}
		}
		return "Easy";
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
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 3;
			int Arg3 = 5;
			int Arg4 = 2;
			int Arg5 = 3;
			string Arg6 = "Difficult";

			verify_case(n, Arg6, isDifficult(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 3;
			int Arg3 = 5;
			int Arg4 = 2;
			int Arg5 = 2;
			string Arg6 = "Easy";

			verify_case(n, Arg6, isDifficult(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 4;
			int Arg2 = 7;
			int Arg3 = 1;
			int Arg4 = 4;
			int Arg5 = 7;
			string Arg6 = "Difficult";

			verify_case(n, Arg6, isDifficult(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1000;
			int Arg2 = 1000;
			int Arg3 = 2;
			int Arg4 = 1000;
			int Arg5 = 1000;
			string Arg6 = "Easy";

			verify_case(n, Arg6, isDifficult(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 2;
			int Arg4 = 2;
			int Arg5 = 2;
			string Arg6 = "Easy";

			verify_case(n, Arg6, isDifficult(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ElectronicPetEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
