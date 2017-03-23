// BEGIN CUT HERE
/*
SRM 699 Div2 Medium (500)

問題
-黒板に数Xを書き、最下位の桁をひとつずつ消す
-黒板に現れた全ての数の合計がSのとき、Xを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

class LastDigit {
	LL sum(LL n) {
		LL s = 0;
		while (n) {
			s += n;
			n /= 10;
		}
		return s;
	}

public:
	long long findX(long long S) {
		LL low = S / 2, high = S + 1;
		while (high - low > 1) {
			LL mid = (low + high) / 2;
			if (sum(mid) > S) {
				high = mid;
			} else {
				low = mid;
			}
		}
		return sum(low) == S ? low : -1;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 564LL;
			long long Arg1 = 509LL;

			verify_case(n, Arg1, findX(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 565LL;
			long long Arg1 = -1LL;

			verify_case(n, Arg1, findX(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 3000LL;
			long long Arg1 = 2701LL;

			verify_case(n, Arg1, findX(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 137174210616796LL;
			long long Arg1 = 123456789555123LL;

			verify_case(n, Arg1, findX(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 837592744927492746LL;
			long long Arg1 = -1LL;

			verify_case(n, Arg1, findX(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 999999999999999999LL;
			long long Arg1 = 900000000000000000LL;

			verify_case(n, Arg1, findX(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			long long Arg0 = 1;
			long long Arg1 = 1;

			verify_case(n, Arg1, findX(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LastDigit ___test;
	___test.run_test(-1);
}
// END CUT HERE
