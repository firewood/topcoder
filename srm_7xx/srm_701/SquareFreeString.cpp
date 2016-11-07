// BEGIN CUT HERE
/*
SRM 701 Div2 Easy (250)

問題
-文字列が二つの文字列の繰り返しになっているとき、平方文字列と呼ぶ
-文字列sの部分文字列に平方文字列があるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class SquareFreeString {
public:
	string isSquareFree(string s) {
		for (int i = 0; i != s.length(); ++i) {
			for (int j = 1; (i + j * 2) <= (int)s.length(); ++j) {
				if (s.substr(i, j).compare(s.substr(i + j, j)) == 0) {
					return "not square-free";
				}
			}
		}
		return "square-free";
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
			string Arg0 = "bobo";
			string Arg1 = "not square-free";

			verify_case(n, Arg1, isSquareFree(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "apple";
			string Arg1 = "not square-free";

			verify_case(n, Arg1, isSquareFree(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "pen";
			string Arg1 = "square-free";

			verify_case(n, Arg1, isSquareFree(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aydyamrbnauhftmphyrooyq";
			string Arg1 = "not square-free";

			verify_case(n, Arg1, isSquareFree(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "qwertyuiopasdfghjklzxcvbnm";
			string Arg1 = "square-free";

			verify_case(n, Arg1, isSquareFree(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SquareFreeString ___test;
	___test.run_test(-1);
}
// END CUT HERE
