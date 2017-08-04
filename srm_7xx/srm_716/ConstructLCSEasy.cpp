// BEGIN CUT HERE
/*

問題
-文字列から0文字以上の任意の個数の文字を取り除いた文字列を、部分文字列と呼ぶ。
-文字列Aと文字列Bの最長共通部分列(LCS)は、文字列Aの部分文字列と文字列Bの部分文字列の中で共通なもののうちの最長のものである。
-文字0か1だけからなる文字列A,B,Cについて、
-文字列A,BのLCSの長さ
-文字列B,CのLCSの長さ
-文字列C,AのLCSの長さ
-が与えられるので、A,B,Cを求めよ。

*/
// END CUT HERE

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <sstream>

using namespace std;

typedef pair<int, int> II;

class ConstructLCSEasy {
	public:
	string construct(int ab, int bc, int ca) {
        int abc[3] = { ab,bc,ca };
        sort(abc, abc + 3);
        II v[3];
        v[0].first = abc[2];
        v[1].first = abc[0];
        v[1].second = abc[1] - abc[0];
        v[2].first = abc[2];
        v[2].second = abc[1] - abc[0];
        int seq[3] = { 0,1,2 };
        do {
            if (min(v[seq[0]].first, v[seq[1]].first) + min(v[seq[0]].second, v[seq[1]].second) == ab &&
                min(v[seq[1]].first, v[seq[2]].first) + min(v[seq[1]].second, v[seq[2]].second) == bc &&
                min(v[seq[2]].first, v[seq[0]].first) + min(v[seq[2]].second, v[seq[0]].second) == ca) {
                break;
            }
        } while (next_permutation(seq, seq + 3));
        string ans;
        for (int i = 0; i < 3; ++i) {
            if (i) {
                ans += " ";
            }
            ans += string(v[seq[i]].first, '0');
            ans += string(v[seq[i]].second, '1');
        }
        return ans;
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
			int Arg0 = 2;
			int Arg1 = 3;
			int Arg2 = 4;
			string Arg3 = "1111 101 1010101";

			verify_case(n, Arg3, construct(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			int Arg2 = 7;
			string Arg3 = "10101010 1011 1010101";

			verify_case(n, Arg3, construct(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 7;
			int Arg2 = 8;
			string Arg3 = "10101010 1111010 110101010";

			verify_case(n, Arg3, construct(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 8;
			int Arg2 = 8;
			string Arg3 = "10101010 010101101 110101001011";

			verify_case(n, Arg3, construct(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15;
			int Arg1 = 17;
			int Arg2 = 19;
			string Arg3 = "000100101101111011000 11110111010011101010 100100001010101001010101000011111";

			verify_case(n, Arg3, construct(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arg1 = 50;
			int Arg2 = 50;
			string Arg3 = "11111111111111111111111111111111111111111111111111 11111111111111111111111111111111111111111111111111 11111111111111111111111111111111111111111111111111";

			verify_case(n, Arg3, construct(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE
};

// BEGIN CUT HERE
int main() {
	ConstructLCSEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
