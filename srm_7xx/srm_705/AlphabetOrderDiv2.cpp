// BEGIN CUT HERE
/*
SRM 705 Div2 Medium (500)

問題
-aからzまで26種類の文字を使う言語がある
-便宜的にaからzで表すが、各文字の序列は不明である
-ある単語の文字が、文字の序列順になっているものを、良い単語とする
-N個の単語が与えられる
-全ての単語が良い単語になるような文字セットが存在するかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class AlphabetOrderDiv2 {
public:
	string isOrdered(vector <string> words) {
		int d[26][26] = {};
		for (int i = 0; i != words.size(); ++i) {
			for (int j = 1; j != words[i].length(); ++j) {
				if (words[i][j - 1] != words[i][j]) {
					d[words[i][j - 1] - 'a'][words[i][j] - 'a'] = 1;
				}
			}
		}
		for (int k = 0; k < 26; ++k) {
			for (int i = 0; i < 26; ++i) {
				for (int j = 0; j < 26; ++j) {
					if (d[i][k] && d[k][j]) {
						d[i][j] = 1;
					}
				}
			}
		}
		for (int i = 0; i < 26; ++i) {
			if (d[i][i]) {
				return "Impossible";
			}
		}
		return "Possible";
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
			string Arr0[] = {"single","round","match"};
			string Arg1 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"topcoder","topcoder"};
			string Arg1 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"algorithm", "contest"};
			string Arg1 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"pink","floyd"};
			string Arg1 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"gimnasia","y","esgrima","la","plata"};
			string Arg1 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"hello","hello"};
			string Arg1 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
			string Arg1 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"abc","bca"};
			string Arg1 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

		// test_case_8
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"aaaaa","eeeee","iiiii","ooooo","uuuuu"} ;
			string Arg1 = "Possible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

		// test_case_9
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ab","bc","ca"};
			string Arg1 = "Impossible";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isOrdered(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AlphabetOrderDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
