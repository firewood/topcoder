// BEGIN CUT HERE
/*
SRM 689 Div2 Medium (500)

問題
-文字0と1だけからなる文字列A、文字0、1、?だけからなる文字列Bがある
-Bの?を0か1に変更した文字列をCとする
-CがAの部分文字列となる場合の総数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef set<string> StrSet;

class NonDeterministicSubstring {
public:
	long long ways(string A, string B) {
		long long ans = 0;
		StrSet m;
		int a_len = (int)A.length(), b_len = (int)B.length();
		for (int i = 0; i + b_len <= a_len; ++i) {
			string c = A.substr(i, b_len);
			if (m.find(c) == m.end()) {
				m.insert(c);
				int j;
				for (j = 0; j < b_len; ++j) {
					if (B[j] != '?' && A[i + j] != B[j]) {
						break;
					}
				}
				ans += j >= b_len;
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "00010001";
			string Arg1 = "??";
			long long Arg2 = 3LL;

			verify_case(n, Arg2, ways(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "00000000";
			string Arg1 = "??0??0";
			long long Arg2 = 1LL;

			verify_case(n, Arg2, ways(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "001010101100010111010";
			string Arg1 = "???";
			long long Arg2 = 8LL;

			verify_case(n, Arg2, ways(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "00101";
			string Arg1 = "??????";
			long long Arg2 = 0LL;

			verify_case(n, Arg2, ways(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "1101010101111010101011111111110001010101";
			string Arg1 = "???????????????????????????????????";
			long long Arg2 = 6LL;

			verify_case(n, Arg2, ways(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NonDeterministicSubstring ___test;
	___test.run_test(-1);
}
// END CUT HERE
