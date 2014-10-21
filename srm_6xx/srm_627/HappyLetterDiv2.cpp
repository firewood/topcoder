// BEGIN CUT HERE
/*
SRM 627 Div2 Medium (500)

問題
-文字列が与えられる
-1ターンに異なる文字を消していく
-同じ文字だけが残るかどうかを求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class HappyLetterDiv2 {
public:
	char getHappyLetter(string letters) {
		int N = (int)letters.size();
		char ans = '.';
		int cnt[256] = {};
		for (char c : letters) {
			cnt[c] += 1;
			if (cnt[c] > N / 2) {
				ans = c;
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const char &Expected, const char &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aacaaa";
			char Arg1 = 'a';

			verify_case(n, Arg1, getHappyLetter(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "dcdjx";
			char Arg1 = '.';

			verify_case(n, Arg1, getHappyLetter(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "bcbbbbba";
			char Arg1 = 'b';

			verify_case(n, Arg1, getHappyLetter(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aabc";
			char Arg1 = '.';

			verify_case(n, Arg1, getHappyLetter(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	HappyLetterDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
