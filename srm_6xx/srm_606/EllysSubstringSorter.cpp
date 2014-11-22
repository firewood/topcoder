// BEGIN CUT HERE
/*
SRM 606 Div2 Easy (250)

問題
-文字列Sが与えられる
-任意の位置から連続するL文字を選んで、その部分をソートできる
-辞書順最小の文字列を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class EllysSubstringSorter {
public:
	string getMin(string S, int L) {
		string ans = S;
		for (int i = 0; i <= (int)S.length() - L; ++i) {
			string a = S.substr(0, i);
			string b = S.substr(i, L);
			string c = S.substr(i + L);
			sort(b.begin(), b.end());
			ans = min(ans, a + b + c);
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
			string Arg0 = "TOPCODER";
			int Arg1 = 4;
			string Arg2 = "COPTODER";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ESPRIT";
			int Arg1 = 3;
			string Arg2 = "EPRSIT";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAAAAAAAA";
			int Arg1 = 2;
			string Arg2 = "AAAAAAAAA";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABRACADABRA";
			int Arg1 = 5;
			string Arg2 = "AAABCRDABRA";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BAZINGA";
			int Arg1 = 6;
			string Arg2 = "ABGINZA";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
			int Arg1 = 21;
			string Arg2 = "AAAAAABDDDEEIIIJOOSUWWWWDBPOAWDUISAWDOOPAWD";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysSubstringSorter ___test;
	___test.run_test(-1);
}
// END CUT HERE
