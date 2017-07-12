// BEGIN CUT HERE
/*
SRM 716 Div2 Easy (250)

問題
-数値xの各桁の数値を入れ替えて、x以外のxの倍数にできるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Permutiple {
public:
	string isPossible(int x) {
		stringstream a;
		a << x;
		string p;
		a >> p;
		sort(p.begin(), p.end());
		for (int n = x * 2; n <= 999999; n += x) {
			stringstream b;
			b << n;
			string q;
			b >> q;
			sort(q.begin(), q.end());
			if (p == q) {
				return "Possible";
			}
			if (q.length() > p.length()) {
				break;
			}
		}
		return "Impossible";
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
			int Arg0 = 142857;
			string Arg1 = "Possible";

			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 14;
			string Arg1 = "Impossible";

			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1035;
			string Arg1 = "Possible";

			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000;
			string Arg1 = "Impossible";

			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100035;
			string Arg1 = "Possible";

			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			string Arg1 = "Impossible";

			verify_case(n, Arg1, isPossible(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Permutiple ___test;
	___test.run_test(-1);
}
// END CUT HERE
