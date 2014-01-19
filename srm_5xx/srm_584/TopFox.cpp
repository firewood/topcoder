// BEGIN CUT HERE
/*
SRM 584 Div2 Easy (250)

問題
-TopFoxに参加するためにハンドルネームを決めたい
-姓と名のそれぞれ先頭から1文字以上取って連結する
-何通り作れるか求める

*/
// END CUT HERE
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef set<string> StrSet;

class TopFox {
public:
	int possibleHandles(string familyName, string givenName) {
		StrSet s;
		for (int i = 1; i <= (int)familyName.size(); ++i) {
			for (int j = 1; j <= (int)givenName.size(); ++j) {
				s.insert(familyName.substr(0, i) + givenName.substr(0, j));
			}
		}
		return (int)s.size();
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
			string Arg0 = "ab";
			string Arg1 = "cd";
			int Arg2 = 4;

			verify_case(n, Arg2, possibleHandles(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abb";
			string Arg1 = "bbc";
			int Arg2 = 7;

			verify_case(n, Arg2, possibleHandles(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "fox";
			string Arg1 = "ciel";
			int Arg2 = 12;

			verify_case(n, Arg2, possibleHandles(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abbbb";
			string Arg1 = "bbbbbbbc";
			int Arg2 = 16;

			verify_case(n, Arg2, possibleHandles(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abxy";
			string Arg1 = "xyxyxc";
			int Arg2 = 21;

			verify_case(n, Arg2, possibleHandles(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ababababab";
			string Arg1 = "bababababa";
			int Arg2 = 68;

			verify_case(n, Arg2, possibleHandles(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TopFox ___test;
	___test.run_test(-1);
}
// END CUT HERE
