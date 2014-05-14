// BEGIN CUT HERE
/*
TCO 2014 Round 1A Medium (500)

問題
-文字列と、移動可能な距離Dが与えられる
-各文字は、左右どちらか距離Dまで移動可能
-移動結果のうち辞書順最小を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class EllysScrabble {
public:
	string getMin(string letters, int maxDistance) {
		int used[64] = {};
		char w[64] = {};
		int N = (int)letters.size();
		for (int i = 0; i < N; ++i) {
			int pos = i - maxDistance;
			if (pos >= 0 && !used[pos]) {
				;
			} else {
				pos = -1;
				int s = max(0, i - maxDistance);
				int e = min(N - 1, i + maxDistance);
				for (int j = s; j <= e; ++j) {
					if (!used[j]) {
						if (pos < 0 || letters[j] < letters[pos]) {
							pos = j;
						}
					}
				}
			}
			used[pos] = 1;
			w[i] = letters[pos];
		}
		return w;
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
			string Arg0 = "TOPCODER";
			int Arg1 = 3;
			string Arg2 = "CODTEPOR";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ESPRIT";
			int Arg1 = 3;
			string Arg2 = "EIPRST";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BAZINGA";
			int Arg1 = 8;
			string Arg2 = "AABGINZ";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			int Arg1 = 9;
			string Arg2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "GOODLUCKANDHAVEFUN";
			int Arg1 = 7;
			string Arg2 = "CADDGAHEOOFLUKNNUV";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
			int Arg1 = 6;
			string Arg2 = "AAAADDEIBWAEUIODWADSBIAJWODIAWDOPOAWDUOSPWW";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABRACADABRA";
			int Arg1 = 2;
			string Arg2 = "AABARACBDAR";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysScrabble ___test;
	___test.run_test(-1);
}
// END CUT HERE
