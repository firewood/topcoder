// BEGIN CUT HERE
/*
// SRM 516 Div2 Medium (500)

問題

ワンタイムパッドは、最もよく知られた暗号方式の一つである。
平文と同じ長さの鍵を用意して、メッセージと鍵でXORをとったものを暗号文とする。

鍵の強度を調べたい。
平文と暗号文の組が与えられるので、何種類の鍵が生成可能かを求める。
鍵とは、全ての平文から全ての暗号文が生成できるものをいう。


#line 72 "NetworkXOneTimePad.cpp"
*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

typedef long long LL;
typedef vector<LL> LLV;
typedef set<LL> LLS;

class NetworkXOneTimePad {
public:

	static long long ston(string s) {
		long long n = 0;
		size_t i;
		for (i = 0; i < s.length(); ++i) {
			n = (n << 1) | (s[i] != '0');
		}
		return n;
	}

	int crack(vector <string> plaintexts, vector <string> ciphertexts) {
		LLV p, c;
		LLS ps;
		size_t i, j;
		for (i = 0; i < plaintexts.size(); ++i) {
			LL n = ston(plaintexts[i]);
			p.push_back(n);
			ps.insert(n);
		}
		for (i = 0; i < ciphertexts.size(); ++i) {
			LL n = ston(ciphertexts[i]);
			c.push_back(n);
		}

		// key candidates
		LLS ks;
		for (i = 0; i < p.size(); ++i) {
			for (j = 0; j < c.size(); ++j) {
				ks.insert(p[i] ^ c[j]);
			}
		}

		// check if all of restored messages are in plaintexts
		int count = 0;
		LLS::const_iterator k;
		for (k = ks.begin(); k != ks.end(); ++k) {
			int ok = 1;
			for (i = 0; i < c.size(); ++i) {
				LL x = *k ^ c[i];
				if (ps.find(x) == ps.end()) {
					ok = 0;
					break;
				}
			}
			count += ok;
		}

		return count;
	}
};

// BEGIN CUT HERE
template <typename T> static T __str_to_val(const char *p)
{
	return p;
}
template <> static int __str_to_val(const char *p)
{
	return atoi(p);
}
template <typename T> vector<T> getVector(const char *s)
{
	static const int buffer_size = 1024000;
	static char buffer[buffer_size];
	strcpy(buffer, s);
	vector <T> v;
	char *p = strtok(buffer, " ,");
	while (p) {
		v.push_back(__str_to_val<T>(p));
		p = strtok(NULL, " ,");
	}
	return v;
}

static void Test(const char *p, const char *c, int expected)
{
	vector <string> pv = getVector<string>(p);
	vector <string> cv = getVector<string>(c);
	NetworkXOneTimePad ___test;
	int result = ___test.crack(pv, cv);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	// example 0
	Test("110,001", "101,010", 2);

	// example 1
	Test("00,01,10,11", "00,01,10,11", 4);

	// example 2
	Test("01,10", "00", 2);

	// example 3
	Test("000,111,010,101,110,001", "011,100", 6);

	return 0;
}
// END CUT HERE
