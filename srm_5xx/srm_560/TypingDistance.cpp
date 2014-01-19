// BEGIN CUT HERE
/*
// SRM 560 Div2 Easy (250)

問題
-指1本でキーボードを打つ
-キーボードの配列が与えられる
-指の移動距離を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TypingDistance {

public:
	int minDistance(string keyboard, string word) {
		int res = 0;
		const char *k = keyboard.c_str();
		int i, prev = 0;
		for (i = 0; i < (int)word.size(); ++i) {
			int x = (int)(strchr(k, word[i]) - k);
			if (i > 0) {
				res += abs(prev - x);
			}
			prev = x;
		}
		return res;
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
			string Arg0 = "qwertyuiop";
			string Arg1 = "potter";
			int Arg2 = 8;

			verify_case(n, Arg2, minDistance(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "tc";
			string Arg1 = "tctcttccctccccttc";
			int Arg2 = 9;

			verify_case(n, Arg2, minDistance(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "a";
			string Arg1 = "aaaaaaaaaaa";
			int Arg2 = 0;

			verify_case(n, Arg2, minDistance(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "kwadrutove";
			string Arg1 = "rowerowe";
			int Arg2 = 39;

			verify_case(n, Arg2, minDistance(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "qwertyuiopasdfghjklzxcvbnm";
			string Arg1 = "topcodersingleroundmatchgoodluckhavefun";
			int Arg2 = 322;

			verify_case(n, Arg2, minDistance(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TypingDistance ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
