// BEGIN CUT HERE
/*
SRM 689 Div2 Easy (250)

問題
-いくつかのハンドル名が与えられる
-Oと0、および、1とlとIは似ているものとする
-似ている文字を同一視したときに同じハンドル名があるかどうかを求める

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

class SimilarUserDetection {
public:
	string haveSimilar(vector <string> handles) {
		set<string> m;
		for (string h : handles) {
			for (int i = 0; i != h.length(); ++i) {
				if (h[i] == '0') h[i] = 'O';
				if (h[i] == '1') h[i] = 'I';
				if (h[i] == 'l') h[i] = 'I';
			}
			m.insert(h);
		}
		return handles.size() == m.size() ? "Similar handles not found" : "Similar handles found";
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
			string Arr0[] = {"top", "coder", "TOPCODER", "TOPC0DER"};
			string Arg1 = "Similar handles found";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, haveSimilar(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"Topcoder", "topcoder", "t0pcoder", "topcOder"};
			string Arg1 = "Similar handles not found";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, haveSimilar(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"same", "same", "same", "different"};
			string Arg1 = "Similar handles found";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, haveSimilar(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0123", "0I23", "0l23", "O123", "OI23", "Ol23"};
			string Arg1 = "Similar handles found";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, haveSimilar(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"i23", "123", "456", "789", "000", "o", "O"};
			string Arg1 = "Similar handles not found";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, haveSimilar(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SimilarUserDetection ___test;
	___test.run_test(-1);
}
// END CUT HERE
