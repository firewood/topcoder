// BEGIN CUT HERE
/*
SRM 591 Div2 Medium (500)

問題
-2つの文字列が与えられる
-Aの文字セットを置換することでBにする
-成立させるために削除する必要がある文字数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ConvertibleStrings {
public:
	int leastRemovals(string A, string B) {
		int len = (int)A.length();
		int ans = len;
		char seq[] = {'A','B','C','D','E','F','G','H','I'};
		do {
			int cnt = 0;
			for (int i = 0; i < len; ++i) {
				cnt += seq[B[i]-'A'] != A[i];
			}
			ans = min(ans, cnt);
		} while(next_permutation(seq, seq + 9));
		return ans < len ? ans : -1;
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
			string Arg0 = "DD";
			string Arg1 = "FF";
			int Arg2 = 0;

			verify_case(n, Arg2, leastRemovals(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAAA";
			string Arg1 = "ABCD";
			int Arg2 = 3;

			verify_case(n, Arg2, leastRemovals(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAIAIA";
			string Arg1 = "BCDBEE";
			int Arg2 = 3;

			verify_case(n, Arg2, leastRemovals(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABACDCECDCDAAABBFBEHBDFDDHHD";
			string Arg1 = "GBGCDCECDCHAAIBBFHEBBDFHHHHE";
			int Arg2 = 9;

			verify_case(n, Arg2, leastRemovals(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ConvertibleStrings ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
