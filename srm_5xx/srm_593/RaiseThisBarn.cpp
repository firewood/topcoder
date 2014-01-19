// BEGIN CUT HERE
/*
SRM 593 Div2 Easy (250)

問題
-牛舎に何頭かの牛がいる
-壁をつくって二つの部分にわけたい
-同じ数だけ牛がいるようにしたい

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class RaiseThisBarn {

	int count(string s)
	{
		int cow = 0;
		for (int i = 0; i < (int)s.length(); ++i) {
			if (s[i] == 'c') {
				++cow;
			}
		}
		return cow;
	}

public:
	int calc(string str) {
		int ans = 0;
		for (int i = 1; i < (int)str.length(); ++i) {
			int cl = count(str.substr(0, i));
			int cr = count(str.substr(i));
			if (cl == cr) {
				++ans;
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
			string Arg0 = "cc..c.c";
			int Arg1 = 3;

			verify_case(n, Arg1, calc(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "c....c....c";
			int Arg1 = 0;

			verify_case(n, Arg1, calc(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "............";
			int Arg1 = 11;

			verify_case(n, Arg1, calc(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = ".c.c...c..ccc.c..c.c.cc..ccc";
			int Arg1 = 3;

			verify_case(n, Arg1, calc(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RaiseThisBarn ___test;
	___test.run_test(-1);
}
// END CUT HERE
