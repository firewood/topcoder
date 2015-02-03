// BEGIN CUT HERE
/*
SRM 648 Div1 Easy (250)

問題
-'A'か'B'だけからなる長さNの文字列Sについて考える
-i<jで位置iが'A'、位置jが'B'の個数がK個のものを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class AB {
public:
	string createString(int N, int K) {
		int a, b;
		for (a = 1; a <= N; ++a) {
			b = N - a;
			if (a * b >= K) {
				int c = K / b;
				string s(c, 'A');
				int R = K - c*b;
				s += string(b - R, 'B');
				s += string(a - c, 'A');
				s += string(R, 'B');
				return s;
			}
		}
		return "";
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
			int Arg1 = 2;
			string Arg2 = "ABB";

			verify_case(n, Arg2, createString(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 0;
			string Arg2 = "BA";

			verify_case(n, Arg2, createString(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 8;
			string Arg2 = "";

			verify_case(n, Arg2, createString(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 12;
			string Arg2 = "BAABBABAAB";

			verify_case(n, Arg2, createString(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arg1 = 25*25;
			string Arg2 = "AAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBBBBB";

			verify_case(n, Arg2, createString(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AB ___test;
	___test.run_test(-1);

	for (int N = 50; N <= 50; ++N) {
		for (int K = 0;; ++K) {
			int x = (N + 1) / 2;
			int y = N - x;
			if (K > x*y) {
				break;
			}
			string s = ___test.createString(N, K);
			if (s.length() == N) {
				int c = 0;
				for (int i = 0; i < N; ++i) {
					if (s[i] == 'A') {
						for (int j = i + 1; j < N; ++j) {
							c += s[j] == 'B';
						}
					}
				}
				if (c == K) {
					continue;
				}
			}
			printf("FAILED: %d, %d\n", N, K);
			break;
		}
	}
}
// END CUT HERE
