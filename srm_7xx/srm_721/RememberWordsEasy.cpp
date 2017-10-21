// BEGIN CUT HERE
/*
SRM 721 Div2 Medium (500)

問題
-d1日からなる1学期と、d2日からなる2学期がある
-1学期と2学期は休みがなく連続している
-毎日いくつかの単語を覚えることができる
-ある日に覚える個数と、次の日に覚える個数の差が1以内であること
-1学期にw1個、2学期にw2個覚えることが可能かどうかを求めよ

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

void get_bounds(LL v, LL d, LL &l, LL &h) {
	l = 0, h = 0;
	if (v >= (d * (d - 1)) / 2) {
		LL r = v - (d * (d - 1) / 2);
		l = h = r / d;
		v -= l * d;
	}
	LL a, b = 0;
	for (a = 1; ; ++a) {
		b = ((a + 1) * a) / 2;
		if (b >= v) {
			break;
		}
	}
	if (v) {
		if (v >= b) {
			h += a;
		} else {
			h += a - 1;
			v -= (a - 1);
			if (v && a >= d) {
				++l;
			}
		}
	}
}

bool possible(LL d1, LL d2, LL w1, LL w2) {
	LL p, q, r, s;
	get_bounds(w1, d1, p, q);
	get_bounds(w2, d2, r, s);
	return abs(p - r) <= 1 || abs(p - s) <= 1 || abs(q - r) <= 1 || abs(q - s) <= 1 ||
		(p >= r && p <= s) || (q >= r && q <= s) || (r >= p && r <= q) || (s >= p && s <= q);
}

class RememberWordsEasy {
public:
	string isPossible(int d1, int d2, int w1, int w2) {
		return possible(d1, d2, w1, w2) ? "Possible" : "Impossible";
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
			int Arg2 = 7;
			int Arg3 = 18;
			string Arg4 = "Possible";

			verify_case(n, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 3;
			int Arg3 = 5;
			string Arg4 = "Impossible";

			verify_case(n, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 5;
			int Arg2 = 300;
			int Arg3 = 500;
			string Arg4 = "Possible";

			verify_case(n, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 1;
			int Arg2 = 0;
			int Arg3 = 2;
			string Arg4 = "Impossible";

			verify_case(n, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000;
			int Arg1 = 1000000;
			int Arg2 = 1000000;
			int Arg3 = 1000000;
			string Arg4 = "Possible";

			verify_case(n, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 4;
			int Arg1 = 9090;
			int Arg2 = 439;
			int Arg3 = 91156;
			string Arg4 = "Possible";

			verify_case(n, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RememberWordsEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
