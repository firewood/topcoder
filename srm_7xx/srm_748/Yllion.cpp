// BEGIN CUT HERE
/*
SRM 748 Div2 Medium (500)

PROBLEM STATEMENT

The -yllion notation is an alternate notation for powers of 10 designed by Donald Knuth.
The main feature of this notation is that the grouping of digits is exponential, not linear.
That is, each new name is used to double the number of digits.
Equivalently, each new name represents a power of ten whose exponent is twice the previous one.
Below we explain this in more detail.

Knuth's names for the powers of 10 are constructed as follows:

As usual, 10^0 is called "one" and 10^1 is called "ten".
The next two powers of ten are the hundreds: 10^2 is "one hundred" and 10^3 is "ten hundred".
The following four powers are the myriads. That is, 10^4 is "one myriad", and the others follow logically: 10^5 is "ten myriad", 10^6 is "one hundred myriad", and 10^7 is "ten hundred myriad".
The eight powers that follow are the myllions: 10^8 is "one myllion", 10^9 is "ten myllion", ..., and 10^15 is "ten hundred myriad myllion".
...


The next names used after "myllion" are the following ones: "byllion", "tryllion", "quadryllion", "quintyllion", "sextyllion", "septyllion", "octyllion", "nonyllion", and "decyllion".
Each is appended after all the previous ones, and the value of each is the square of the previous one.
That is, "one byllion" is 10^16, "one tryllion" is 10^32, "one quadryllion" is 10^64, and so on.


You are given the strings a and b that each describe a valid power of 10 in Knuth's notation.
Return a string containing Knuth's name for their product.


DEFINITION
Class:Yllion
Method:getPower
Parameters:string, string
Returns:string
Method signature:string getPower(string a, string b)


CONSTRAINTS
-a and b will be valid powers of 10 in Knuth's notation.
-a and b will each be strictly smaller than "one decyllion".


EXAMPLES

0)
"one"
"one"

Returns: "one"

One times one is one.


1)
"one"
"ten"

Returns: "ten"


2)
"one hundred"
"one hundred"

Returns: "one myriad"

Remember that you have to express the answer in Knuth's notation as well. Our 10,000 (ten thousand) is called "one myriad".


3)
"ten hundred"
"one hundred"

Returns: "ten myriad"


4)
"ten hundred myriad myllion"
"one hundred myllion tryllion"

Returns: "ten myllion byllion tryllion"


5)
"ten hundred myriad myllion byllion tryllion quadryllion quintyllion sextyllion septyllion octyllion nonyllion"
"ten"

Returns: "one decyllion"

This a is the largest possible number that can appear in the input.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Yllion {
public:
	string getPower(string a, string b) {
		vector<string> t({ "one", "ten", "hundred", "myriad", "myllion", "byllion", "tryllion", "quadryllion", "quintyllion", "sextyllion", "septyllion", "octyllion", "nonyllion", "decyllion" });
		vector<string> s({ a, b });
		int sum = 0;
		for (string u : s) {
			stringstream ss(u);
			while (true) {
				string c;
				ss >> c;
				if (c.empty()) {
					break;
				}
				int base = 1;
				for (const string &s : t) {
					if (c == s) {
						break;
					}
					base *= 2;
				}
				sum += base / 2;
			}
		}
		sum *= 2;
		if (!(sum & 2)) {
			sum |= 1;
		}
		string ans, delim;
		int base = 1;
		for (const string &s : t) {
			if ((sum & base) != 0) {
				ans += delim;
				ans += s;
				delim = " ";
			}
			base *= 2;
		}
		return ans;
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
			string Arg0 = "one";
			string Arg1 = "one";
			string Arg2 = "one";

			verify_case(n, Arg2, getPower(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "one";
			string Arg1 = "ten";
			string Arg2 = "ten";

			verify_case(n, Arg2, getPower(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "one hundred";
			string Arg1 = "one hundred";
			string Arg2 = "one myriad";

			verify_case(n, Arg2, getPower(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ten hundred";
			string Arg1 = "one hundred";
			string Arg2 = "ten myriad";

			verify_case(n, Arg2, getPower(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ten hundred myriad myllion";
			string Arg1 = "one hundred myllion tryllion";
			string Arg2 = "ten myllion byllion tryllion";

			verify_case(n, Arg2, getPower(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ten hundred myriad myllion byllion tryllion quadryllion quintyllion sextyllion septyllion octyllion nonyllion";
			string Arg1 = "ten";
			string Arg2 = "one decyllion";

			verify_case(n, Arg2, getPower(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Yllion ___test;
	___test.run_test(-1);
}
// END CUT HERE
