// BEGIN CUT HERE
/*
SRM 692 Div2 Medium (500)

問題
-LからRまでの範囲に、最後の2桁が同じ数が何個あるか求める

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

typedef long long LL;

class Dubs {
public:
	long long count(long long L, long long R) {
		long long ans = 0;
		LL a = ((L + 99) / 100) * 100;
		while (L < a && L < R) {
			ans += ((L % 100) % 11) == 0;
			++L;
		}
		a = ((R - 1) / 100) * 100;
		if (a > L) {
			ans += (a - L) / 10;
			L = a;
		}
		while (L <= R) {
			ans += ((L % 100) % 11) == 0;
			++L;
		}
		return ans;
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
			long long Arg0 = 10LL;
			long long Arg1 = 10LL;
			long long Arg2 = 0LL;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 10LL;
			long long Arg1 = 20LL;
			long long Arg2 = 1LL;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 49LL;
			long long Arg1 = 101LL;
			long long Arg2 = 6LL;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1111111LL;
			long long Arg1 = 111111111LL;
			long long Arg2 = 11000001LL;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 91750002841LL;
			long long Arg1 = 91751522033LL;
			long long Arg2 = 151920LL;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Dubs ___test;
	___test.run_test(-1);
}
// END CUT HERE
