// BEGIN CUT HERE
/*
SRM 594 Div2 Easy (250)

問題
-座席がN×Mある
-ひとつずつうしろと右にずれていったとき、全ての座席に座れるかどうかを答える

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

class FoxAndClassroom {
public:
	string ableTo(int n, int m) {
		return gcd(n, m) == 1 ? "Possible" : "Impossible";
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
			string Arg2 = "Possible";

			verify_case(n, Arg2, ableTo(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableTo(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 6;
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableTo(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 6;
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableTo(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 7;
			string Arg2 = "Possible";

			verify_case(n, Arg2, ableTo(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 10;
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableTo(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndClassroom ___test;
	___test.run_test(0);
}
// END CUT HERE
