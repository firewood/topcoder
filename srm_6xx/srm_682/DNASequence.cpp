// BEGIN CUT HERE
/*
SRM 682 Div2 Easy (250)

問題
-DNA配列はA,C,G,Tからなる
-与えられた文字列の部分文字列のうち、最長のDNA配列の長さを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class DNASequence {
public:
	int longestDNASequence(string sequence) {
		char a[256] = {};
		a['A'] = a['C'] = a['G'] = a['T'] = 1;
		int ans = 0, cnt = 0;
		for (char c : sequence) {
			if (a[c]) {
				ans = max(ans, ++cnt);
			} else {
				cnt = 0;
			}
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
			string Arg0 = "TOPBOATER";
			int Arg1 = 2;

			verify_case(n, Arg1, longestDNASequence(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "SUSHI";
			int Arg1 = 0;

			verify_case(n, Arg1, longestDNASequence(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "GATTACA";
			int Arg1 = 7;

			verify_case(n, Arg1, longestDNASequence(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "GOODLUCK";
			int Arg1 = 1;

			verify_case(n, Arg1, longestDNASequence(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "VVZWKCSIQEGANULDLZESHUYHUQGRKUMFCGTATGOHMLKBIRCA";
			int Arg1 = 6;

			verify_case(n, Arg1, longestDNASequence(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DNASequence ___test;
	___test.run_test(-1);
}
// END CUT HERE
