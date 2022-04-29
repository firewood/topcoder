// BEGIN CUT HERE
/*
SRM 828 Div1 Easy (300)

PROBLEM STATEMENT
Time limit: 3.5 seconds.

We have an established company called companyName.

We have an issue with the name: it shows too late in alphabetical listings of similar companies, so we don't get all the clients we could.

At the same time, if we just rename the company, we would risk losing many old clients.

The way to go is to just tweak the company name a little: we will select exactly K characters in the company name and rearrange them, while keeping the rest of the name intact.
Our goal is to end with any name that is lexicographically smaller than the current name.

For example, if our company name is "TOPCODER" and K = 3, one of the many ways how to improve this name starts by selecting the three vowels. 

Rearranging the characters can be imagined as a two-step process:

First we take the selected characters (in our example: 'O', 'O', and 'E') out, leaving gaps in the string (in our example: "T_PC_D_R").
Then we reinsert the removed characters back into the gaps - one into each gap, in any order we like. (In our example: we can get either the original "TOPCODER", or "TOPCEDOR", or "TEPCODOR".)

A set of K characters (more precisely, a set of K distinct indices into the company name) is called good if we can improve the company name by rearranging those characters.
Count all good sets.
Return their count modulo 10^9 + 7.


DEFINITION
Class:ImproveName
Method:improve
Parameters:string, int
Returns:int
Method signature:int improve(string companyName, int K)


CONSTRAINTS
-companyName will contain between 1 and 2,000 characters, inclusive.
-Each character in companyName will be an uppercase English letter ('A'-'Z').
-K will be between 1 and length(companyName), inclusive.


EXAMPLES

0)
"ABCDE"
2

Returns: 0

There is no way to improve this company name by swapping two of its characters.


1)
"AABCCDEEEFZ"
3

Returns: 0

Again, a company name that cannot be improved.


2)
"EEDDCCBBAA"
3

Returns: 120

Regardless of what three letters we select, it is always possible to make the company name lexicographically smaller. For example, if we choose the first three characters, we can rename the company to "EDEDCCBBAA". Thus, the answer is (10 choose 3).


3)
"TOPCODER"
8

Returns: 1

There is only one way of selecting 8 letters out of 8. This set of eight letters is good: if we can rearrange all eight letters in the name, we can choose between many names that are lexicographically smaller than the original. One of those is "CODERPOT".


4)
"TOPCODER"
3

Returns: 49

Some of the triples of characters are good, others are bad. As we have seen in the problem statement, the three vowels (i.e., characters at 0-based indices 1, 4, 6) form one of those 49 good triples.

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

const int64_t MOD = 1000000007;

struct modint {
	int64_t x;
	modint() { }
	modint(int _x) : x(_x) { }
	operator int() const { return (int)x; }
	modint operator+(int y) { return (x + y + MOD) % MOD; }
	modint operator+=(int y) { x = (x + y + MOD) % MOD; return *this; }
	modint operator-(int y) { return (x - y + MOD) % MOD; }
	modint operator-=(int y) { x = (x - y + MOD) % MOD; return *this; }
	modint operator*(int y) { return (x * y) % MOD; }
	modint operator*=(int y) { x = (x * y) % MOD; return *this; }
	modint operator/(int y) { return (x * modpow(y, MOD - 2)) % MOD; }
	modint operator/=(int y) { x = (x * modpow(y, MOD - 2)) % MOD; return *this; }
	static modint modinv(int a) { return modpow(a, MOD - 2); }
	static modint modpow(int a, int b) {
		modint x = a, r = 1;
		for (; b > 0; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

class ImproveName {
public:
	int improve(string companyName, int K) {
		int N = (int)companyName.length();
		vector<vector<modint>> dp(K + 1, vector<modint>(27, 0));
		vector<modint> dp2(K + 1, 0);
		dp[0][0] = 1;
		for (int i = 0; i < N; ++i) {
			int c = companyName[i] - 'A' + 1;
			vector<vector<modint>> next = dp;
			vector<modint> next2 = dp2;
			for (int j = max(0, i - (N - K)); j < min(i + 1, K); ++j) {
				for (int k = 0; k <= 26; ++k) {
					if (c < k) {
						next2[j + 1] += dp[j][k];
					} else {
						next[j + 1][c] += dp[j][k];
					}
				}
				next2[j + 1] += dp2[j];
			}
			dp = next;
			dp2 = next2;
		}
		return dp2[K];
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
			string Arg0 = "ABCDE";
			int Arg1 = 2;
			int Arg2 = 0;

			verify_case(n, Arg2, improve(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AABCCDEEEFZ";
			int Arg1 = 3;
			int Arg2 = 0;

			verify_case(n, Arg2, improve(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "EEDDCCBBAA";
			int Arg1 = 3;
			int Arg2 = 120;

			verify_case(n, Arg2, improve(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "TOPCODER";
			int Arg1 = 8;
			int Arg2 = 1;

			verify_case(n, Arg2, improve(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "TOPCODER";
			int Arg1 = 3;
			int Arg2 = 49;

			verify_case(n, Arg2, improve(Arg0, Arg1));
		}
		n++;


		// test_case_4
		if ((Case == -1) || (Case == n)) {
			string Arg0 = "WASKJSBILLLFCXICPRQOVKTMFJDONSVIHXHZYBFBYJUNPHGBWIZSSGQBKIENDDHQFWXTYFTDMKIAWZWQRIXFQAUQSJSJVNSSLKHJGVWKMZWLVXGEYLQAOERLMCCCRNZZQEVFFOCGLVMGPWCURPGBAKRGMAERVMLHDHGMISOZXZMNPBFEGLTYXRLEWBUBEUFFBAWLGAQEAXKXIJNZXEOZXOFVFQNAEFPZENLAASOGJFIQXYJVTNFKDSLZRVYHXGTOOFHZUIAYUDMBLSUBOBDIKVGLALHGGFKHMBVDEZTQTNKLOPOZPSFYBNSQROKLNFQURRHPNYXBLJTHZPHZGCPVMSGPAKHGKXSQHAMWBQSKRRKLUQOZTBSTFYDGCISIMSZVAZDQQYVLXNIYLIWEPYRVUETZTREJJBTNLRYTMWTYSUZVZORTXAIJPIYRXVMFGMNWUOBJPDQUZJWLQRHCSCBEIWKNCGTSJGKDRGZYPYFCPBGCLBOCYXWRCPZYXGFCFCGGFSZXVGMXRPMBZRFGYRTBVKCIQOZONHPGITQFVYZMJSZTFXSFJABYRRUWGGSCUNRHRAQEHWONCQYYYQBZTTZFVXMJKJMPCJJJPTSDXKZQKKOGBTAAXPQOVRJNKUEUCVZDLGIPXJTLXKGGGFFGPLTJFMVKSMDDNXAAGMFVWVVVPDBHVAGCNNWGHSEPROYCFZJCVNVSZMJQFEVGLQLICERVCHTJLOXUFUQOTNDFWXRBEPZTJZTVNOQNVQQNQHQIFNTDDXYYKMGHMWZZBECYTFLLUNJWTBONWAWXYRBAWBTDBDRDRHAREJQPACQTRTZSIYPFGGZKWYCVTSPDAOVOABPOGXYDSMKNLZXYFJNYVPSHJOKZMQJNTYKOAEXHTLHDJZCYWPKDKAMGYQIRHEXZUBBJETPZQJDPNGXNDLUMOZFIYJBSSVJHBJKAPSMWVIUNTFVDSAMURYRLXCRVWGSOQRYQWXVEHTLZRPUYMLNJMFFGPLRTINYLMIFMZBTYBMROKBIWVYMMHMHLADJDRTWDWNUUMILMLBKZYVNFUQFNWWYAIILWBWSXPHTDJVRYCNPRQMLQGUSOGMPKHMIRWMMDLAWAHIBZDOKOXHNZSAIOMKFLKLYLHKXWINBZXGJXZRBTFMCIPDBBEJSZFPQVMQVVCHPXKNQSHHJJDEPVCGQMPQNVGIIBMTMJZUQQVVZWFANZKCFYINFEWEOGGYZRMNIDJJUOPBAGANADRNYUFOJOXKNZOOYDTPRHIBYASMBUVQZAVQDYETBSOHKOLXOLCVYNORIDWKAPSQQVKRODVGOCHGSUIFYPWOGOKITXQFWOLHBQAJFPFPJQEUXRUUWOWWLPUYGXZCWUHNQDWHKVABQQKDBTBOKQPXLEDHEBCHITEEHDLKMNTMMGHMNIWYSENUFVWPHZFOWYAZEWUVABUUBGKUWZXFLWMKZGDNLFCKMDWYQXGDXJRIRFTLUJIWMAIATJNEICKNOPQYKEVLDDFXWXKJMUCXVTDTXATPQPLREFMSXYXTKFMZRGHAOGRCZRKCSACHQDPMYRUETLWJAQKNPEYATDJZXIRQCBMTCDBSURDJDOZPSUKGOKXHFLBDFACISOHPJQZNVEJSKYNUIZCSOLFYLBLUQGBAAHQJSVIVXYDVZAGQOYUHHMNUZLLQIOIJISVFUJHRSQYBWIZEYRQKZBOXXCASCJHVXVGHDWCZKFQQVIFINCMNXJDCAGRTFQPLRLKNAIBKTBBDNJPNMZMIVRXJTEJHHXMWLOOOZOKSZGKAZKBZQICDXYSMRPPQRIMOLVRRCULMIDRYRTOESPEWUYRLBJPPFYSEPXYBHRXMTYJIBOBIDZRFVTRAKOOGOBNNAIHKKFTPQNSVJKTLQSBPPJCUOFGIBQQLLJFDGKYESM";
			int Arg1 = 1912;
			int Arg2 = 1;

			verify_case(n, Arg2, improve(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ImproveName ___test;
	___test.run_test(-1);
}
// END CUT HERE
