// BEGIN CUT HERE
/*
SRM 609 Div1 Easy (250)

問題
-'<'と'>'だけからなる文字列がある
-何文字か削除して、連続するk個の'>'と連続するk個の'<'だけからなる文字列にしたい
-得られる最大の長さを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class MagicalStringDiv1 {
public:
	int getLongest(string S) {
		int N = S.length();
		int ans = 0;
		for (int i = 1; i < N; ++i) {
			int a = count_if(S.begin(), S.begin() + i, [](char c){ return c == '>'; });
			int b = count_if(S.begin() + i, S.end(), [](char c){ return c == '<'; });
			ans = max(ans, min(a, b)*2);
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
			string Arg0 = "<><><<>";
			int Arg1 = 4;

			verify_case(n, Arg1, getLongest(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = ">>><<<";
			int Arg1 = 6;

			verify_case(n, Arg1, getLongest(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "<<<>>>";
			int Arg1 = 0;

			verify_case(n, Arg1, getLongest(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "<<<<><>>><>>><>><>><>>><<<<>><>>>>><<>>>>><><<<<>>";
			int Arg1 = 24;

			verify_case(n, Arg1, getLongest(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicalStringDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
