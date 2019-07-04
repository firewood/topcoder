// BEGIN CUT HERE
/*
SRM 761 Div1 Easy (250)

PROBLEM STATEMENT

You are given two strings A and B, each containing the representation of a nonnegative periodic decimal.
More precisely, A and B are each given in the form "X.Y(Z)", where:

X, Y, Z are sequences of digits
X and Z are non-empty
X is either "0" or it starts with a nonzero digit.

Y is called the pre-period and Z is called the period.
For example, "0.(3)" and "0.33(333)" are two valid representations of the number 1/3, and
"12.(0)" and "11.(9)" are two valid representations of the number twelve.

Let C = A + B.
Return a string containing a representation of C in the same format.
Minimize the length of the pre-period and also the length of the period in the representation of C.
If the period can be either 0 or 9, use 0.


DEFINITION
Class:AddPeriodic
Method:add
Parameters:string, string
Returns:string
Method signature:string add(string A, string B)


CONSTRAINTS
-A and B will each have between 5 and 12 characters, inclusive.
-A and B will each have the form from the problem statement.


EXAMPLES

0)
"0.33(333)"
"0.(66)"

Returns: "1.(0)"

1/3 + 2/3 = 1


1)
"2.41(5)"
"5.36(22)"

Returns: "7.(7)"

2.41555555... + 5.362222222... = 7.77777777...


2)
"685.4(757)"
"45.356(43)"

Returns: "730.832(210119)"


3)
"0.(101)"
"0.(23)"

Returns: "0.(333424)"


4)
"0.0(999999)"
"1.5(00000)"

Returns: "1.6(0)"

The input may contain a number whose period consists of all nines, but in order to have a unique correct output the output is not allowed to contain such a period.
This test case is the addition 0.1 + 1.5 = 1.6

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

pair<string, int> stradd(const string& a, const string& b, int carry) {
	string r = a;
	for (int i = a.length() - 1; i >= 0; --i) {
		int d = a[i] - '0' + b[i] - '0' + carry;
		r[i] = '0' + (d % 10);
		carry = d / 10;
	}
	return { r, carry };
}

string shorten(const string& s) {
	int len = (int)s.length();
	for (int i = 1; i <= len / 2; ++i) {
		int j = len / i;
		if (i * j == len) {
			string a = s.substr(0, i);
			int cnt;
			for (cnt = 1; cnt < j; ++cnt) {
				if (a != s.substr(i * cnt, i)) {
					break;
				}
			}
			if (cnt >= j) {
				return a;
			}
		}
	}
	return s;
}

class AddPeriodic {
	void parse(const string &s, string& x, string& y, string& z) {
		int pos;
		for (pos = 0; pos < (int)s.length(); ++pos) {
			if (s[pos] == '.') {
				break;
			}
			x += s[pos];
		}
		for (++pos; pos < (int)s.length(); ++pos) {
			if (s[pos] == '(') {
				break;
			}
			y += s[pos];
		}
		for (++pos; pos < (int)s.length(); ++pos) {
			if (s[pos] == ')') {
				break;
			}
			z += s[pos];
		}
	}

public:
	string add(string A, string B) {
		string xa, ya, za, xb, yb, zb;
		parse(A, xa, ya, za);
		parse(B, xb, yb, zb);
		if (ya.length() > yb.length()) {
			swap(xa, xb);
			swap(ya, yb);
			swap(za, zb);
		}
		while (ya.length() < yb.length()) {
			ya += za[0];
			za = za.substr(1) + za[0];
		}
		string aa = za, bb = zb;
		while (aa.length() != bb.length()) {
			if (aa.length() < bb.length()) {
				aa += za;
			} else {
				bb += zb;
			}
		}
		auto z = stradd(aa, bb, 0);
		z = stradd(aa, bb, z.second);
		string zz = shorten(z.first);
		if (zz == "9") {
			zz = "0";
			++z.second;
		}
		auto y = stradd(ya, yb, z.second);
		LL ia = atoll(xa.c_str());
		LL ib = atoll(xb.c_str());
		string xx = to_string(ia + ib + y.second);
		string yy = y.first;
		while (!yy.empty() && yy.back() == zz.back()) {
			yy.resize(yy.length() - 1);
			zz = zz.substr(zz.length() - 1) + zz.substr(0, zz.length() - 1);
		}
		return xx + "." + yy + "(" + zz + ")";
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
			string Arg0 = "0.33(333)";
			string Arg1 = "0.(66)";
			string Arg2 = "1.(0)";

			verify_case(n, Arg2, add(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "2.41(5)";
			string Arg1 = "5.36(22)";
			string Arg2 = "7.(7)";

			verify_case(n, Arg2, add(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "685.4(757)";
			string Arg1 = "45.356(43)";
			string Arg2 = "730.832(210119)";

			verify_case(n, Arg2, add(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "0.(101)";
			string Arg1 = "0.(23)";
			string Arg2 = "0.(333424)";

			verify_case(n, Arg2, add(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "0.0(999999)";
			string Arg1 = "1.5(00000)";
			string Arg2 = "1.6(0)";

			verify_case(n, Arg2, add(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			string Arg0 = "0.5(9903)";
			string Arg1 = "57.(50)";
			string Arg2 = "58.1(0409)";

			verify_case(n, Arg2, add(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			string Arg0 = "0.9(9)";
			string Arg1 = "0.(9)";
			string Arg2 = "2.(0)";

			verify_case(n, Arg2, add(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			string Arg0 = "0.(9)";
			string Arg1 = "0.(9)";
			string Arg2 = "2.(0)";

			verify_case(n, Arg2, add(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			string Arg0 = "0.(9)";
			string Arg1 = "0.99(9)";
			string Arg2 = "2.(0)";

			verify_case(n, Arg2, add(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			string Arg0 = "0.9(9)";
			string Arg1 = "0.99(9)";
			string Arg2 = "2.(0)";

			verify_case(n, Arg2, add(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			string Arg0 = "0.(00000001)";
			string Arg1 = "0.0(0000001)";
			string Arg2 = "0.0(00000020000001100000101000010010001000100100001010000011)";

			verify_case(n, Arg2, add(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AddPeriodic ___test;
	___test.run_test(-1);
}
// END CUT HERE
