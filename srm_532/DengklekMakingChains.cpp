// BEGIN CUT HERE
/*
// SRM 532 Div2 Medium (600)

// PROBLEM STATEMENT
// Mr. Dengklek lives in the Kingdom of Ducks, where humans and ducks
live together in peace and harmony. 

Mr. Dengklek works as a chain maker. Today, he would like to make
a beautiful chain as a decoration for one of his lovely ducks.
He will produce the chain from leftovers he found in his workshop.
Each of the leftovers is a chain piece consisting of exactly 3 links.
Each link is either clean or rusty. Different clean links may have
different degrees of beauty.

You are given a vector <string> chains describing the leftovers.
Each element of chains is a 3-character string describing one of
the chain pieces. A rusty link is represented by a period ('.'),
whereas a clean link is represented by a digit ('0'-'9'). The value
of the digit in the clean link is the beauty of the link. For example,
chains = {".15", "7..", "532", "..3"} means that Mr. Dengklek has
4 chain pieces, and only one of these ("532") has no rusty links.

All links have the same shape, which allows Mr. Dengklek to concatenate
any two chain pieces. However, the link shape is not symmetric, therefore
he may not reverse the chain pieces. E.g., in the above example he is
able to produce the chain "532.15" or the chain ".15..37..", but he
cannot produce "5323..".

To produce the chain, Mr. Dengklek will follow these steps:

Concatenate all chain pieces in any order.
Pick a contiguous sequence of links that contains no rusty links.
Remove and discard all the remaining links.

The beauty of the new chain is the total beauty of all the links picked
in the second step. Of course, Mr. Dengklek would like to create
the most beautiful chain possible.

Return the largest possible beauty a chain can have according to the above rules.

DEFINITION
Class:DengklekMakingChains
Method:maxBeauty
Parameters:vector <string>
Returns:int
Method signature:int maxBeauty(vector <string> chains)


NOTES
-Mr. Dengklek is not allowed to remove and discard individual links
 before concatenating the chain pieces.
-If all links in the input are rusty, Mr. Dengklek is forced to select
 an empty sequence of links. The beauty of an empty sequence is 0.


CONSTRAINTS
-chains will contain between 1 and 50 elements, inclusive.
-Each element of chains will contain exactly 3 characters.
-Each character in each element of chains will be either a '.' or one of '0'-'9'.


EXAMPLES

0)
{".15", "7..", "402", "..3"}

Returns: 19

One possible solution:


In the first step, concatenate the chain pieces in the order "..3", ".15", "402", "7.." to obtain the chain "..3.154027..".
In the second step, pick the subsequence "154027".

The beauty of the chain in this solution is 1+5+4+0+2+7 = 19.

1)
{"..1", "7..", "567", "24.", "8..", "234"}

Returns: 36

One possible solution is to concatenate the chain pieces in this order:

"..1", "234", "567", "8..", "24.", "7.." -> "..12345678..24.7..",

and then to pick the subsequence "12345678". Its beauty is 1+2+3+4+5+6+7+8 = 36.

2)
{"...", "..."}

Returns: 0

Mr. Dengklek cannot pick any links.

3)
{"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"}

Returns: 28



4)
{"..1", "3..", "2..", ".7."}

Returns: 7



5)
{"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"}

Returns: 58

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<string> StrVec;
typedef pair<int, int> II;
typedef vector<II> IIVec;

class DengklekMakingChains {

	static int a(const StrVec &chains) {
		int res = 0;
		IIVec v;
		int i, j;
		for (i = 0; i < (int)chains.size(); ++i) {
			const char *s = chains[i].c_str();
			int len = chains[i].length();
			if (strchr(s, '.') == 0) {
				for (j = 0; j < len; ++j) {
					res += (s[j] - '0');
				}
			} else {
				int _f = 0;
				int _b = 0;
				for (j = 0; j < len; ++j) {
					if (s[j] == '.') {
						break;
					}
					_f += (s[j] - '0');
				}
				for (j = len-1; j >= 0; --j) {
					if (s[j] == '.') {
						break;
					}
					_b += (s[j] - '0');
				}
				v.push_back(II(_f, _b));
			}
		}
		v.push_back(II(0, 0));
		int m = 0;
		for (i = 0; i < (int)v.size(); ++i) {
			for (j = 0; j < (int)v.size(); ++j) {
				if (i == j) {
					continue;
				}
				m = max(m, v[i].first + v[j].second);
			}
		}
		res += m;
		return res;
	}

	static int b(const StrVec &chains) {
		int res = 0;
		int i, j;
		for (i = 0; i < (int)chains.size(); ++i) {
			const char *s = chains[i].c_str();
			int len = chains[i].length();
			int sum = 0;
			for (j = 0; j < len; ++j) {
				if (s[j] == '.') {
					res = max(res, sum);
					sum = 0;
				} else {
					sum += (s[j] - '0');
				}
			}
			res = max(res, sum);
		}
		return res;
	}

public:
	int maxBeauty(vector <string> chains) {
		int res = a(chains);
		res = max(res, b(chains));
		return res;
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
			string Arr0[] = {".15", "7..", "402", "..3"};
			int Arg1 = 19;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..1", "7..", "567", "24.", "8..", "234"};
			int Arg1 = 36;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...", "..."};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"};
			int Arg1 = 28;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..1", "3..", "2..", ".7."};
			int Arg1 = 7;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"};
			int Arg1 = 58;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"99....", "....99", "..999...", ".7."};
			int Arg1 = 36;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"99....", "....89", "..9999...", ".2."};
			int Arg1 = 36;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..1", "123"};
			int Arg1 = 7;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"6.9"};
			int Arg1 = 9;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DengklekMakingChains ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
